#ifndef QAttribute_H
#define QAttribute_H

#include "general\define.h"

#include <QtGui>

class QBinder;

class EXPOSURE_RENDER_DLL QAttribute : public QObject
{
    Q_OBJECT

public:
    QAttribute(const QString& Name, const QString& Description, QObject* Parent = 0);
    virtual ~QAttribute();

	GET_REF_SET_MACRO(HOST, Name, QString);
	GET_REF_SET_MACRO(HOST, Description, QString);

private:
	QString			Name;
	QString			Description;
};

#endif
