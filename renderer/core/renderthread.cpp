
#include "core\renderthread.h"
#include "core\render.cuh"

#include <QSettings>
#include <QBuffer>
#include <QByteArray>
#include <QTimer>
#include <QDebug>
#include <QFile>

#include <time.h>

QRenderer::QRenderer(QObject* Parent /*= 0*/) :
	QObject(Parent),
	Settings("renderer.ini", QSettings::IniFormat),
	RenderTimer(),
	AvgFps(),
	Renderer()
{
	connect(&this->RenderTimer, SIGNAL(timeout()), this, SLOT(OnRender()));

	Vec3i Block = Vec3i(Settings.value("cuda/blockwidth", 8).toInt(), Settings.value("cuda/blockheight", 8).toInt(), 1);

	this->Renderer.Camera.GetFilm().SetBlock(Block);
	this->Renderer.Camera.GetFilm().SetGrid(Vec3i((int)ceilf(this->Renderer.Camera.GetFilm().GetWidth() / Block[0]), (int)ceilf(this->Renderer.Camera.GetFilm().GetHeight() / Block[1]), 1));

	this->Renderer.Volume.GetTracer().SetStepFactorPrimary(Settings.value("traversal/stepfactorprimary", 3.0).toFloat());
	this->Renderer.Volume.GetTracer().SetStepFactorOcclusion(Settings.value("traversal/stepfactorocclusion", 6.0).toFloat());
	
	this->Renderer.Volume.GetTracer().GetOpacity1D().AddNode(0.0f, 1.0f);
	this->Renderer.Volume.GetTracer().GetOpacity1D().AddNode(10, 1.0f);
	this->Renderer.Volume.GetTracer().GetOpacity1D().AddNode(60000.0f, 0.0f);
}

void QRenderer::Start()
{
	this->RenderTimer.start(Settings.value("rendering/targetfps", 60).toInt());
}

void QRenderer::OnRender()
{
	this->Renderer.Camera.SetApertureSize(0.0f);
	this->Renderer.Camera.SetFocalDistance(0.5f);

	this->Renderer.Camera.Update();
	
	const clock_t Begin = clock();
	
	ExposureRender::Render(&this->Renderer);

	const clock_t End = clock();

	AvgFps.PushValue(1000.0f / (End - Begin));
}