/*
*	@file
*	@author  Thomas Kroes <t.kroes at tudelft.nl>
*	@version 1.0
*	
*	@section LICENSE
*	
*	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*	
*	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
*	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
*	Neither the name of the TU Delft nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
*
*	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "core\volume.h"
#include "core\camera.h"
#include "core\prop.h"
#include "core\texture.h"
#include "core\bitmap.h"

namespace ExposureRender
{

#define MAX_NO_PROPS		100
#define MAX_NO_TEXTURES		100
#define MAX_NO_BITMAPS		100

/*! Renderer class */
class EXPOSURE_RENDER_DLL Renderer
{
public:
	/*! Default constructor */
	HOST Renderer() :
		Volume(),
		Camera(),
		NoProps(0),
		NoTextures(0)
	{
	}
	
	Volume				Volume;							/*! Volume parameters */
	Camera				Camera;							/*! Camera parameters */
	Prop				Props[MAX_NO_PROPS];			/*! List of scene props */
	int					NoProps;						/*! Number of props in the scene */
	Texture				Textures[MAX_NO_TEXTURES];		/*! Textures */
	int					NoTextures;						/*! Number of active textures */
	Bitmap				Bitmaps[MAX_NO_BITMAPS];		/*! Array of bitmaps */
	int					NoBitmaps;						/*! Number of active textures */
};

}

