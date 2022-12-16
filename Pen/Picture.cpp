#include "pch.h"
#include "Picture.h"
#include "OpenGLcode/OpenGLPicture.h"

namespace Pen
{
	Picture::Picture(const std::string& sourceFile)
	{
#ifdef PEN_OPENGL
		mImplementation = new OpenGLPicture{sourceFile};
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}

	Picture::Picture(const std::string&& sourceFile)
	{
#ifdef PEN_OPENGL
		mImplementation = new OpenGLPicture{ sourceFile };
#else
		#OpenGL_is_the_only_option_right_now
#endif
	}

	int Picture::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	int Picture::GetWidth() const
	{
		return mImplementation->GetWidth();;
	}

	void Picture::Activate()
	{
		mImplementation->Activate();
	}
}