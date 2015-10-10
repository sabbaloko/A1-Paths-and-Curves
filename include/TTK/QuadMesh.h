//////////////////////////////////////////////////////////////////////////
//
// This header is a part of the Tutorial Tool Kit (TTK) library. 
// You may not use this header in your GDW games.
//
//
// Michael Gharbharan 2015
//
//////////////////////////////////////////////////////////////////////////

#pragma once

#ifdef TTK_EXPORTS
#define TTK_API __declspec(dllexport)
#else
#define TTK_API __declspec(dllimport)
#endif


#include "TTK/MeshBase.h"

namespace TTK
{
	class TTK_API QuadMesh : public TTK::MeshBase
	{
	public:
		QuadMesh();
		~QuadMesh();

		void setUVbottomLeft(float u, float v);
		void setUVtopLeft(float u, float v);
		void setUVbottomRight(float u, float v);
		void setUVtopRight(float u, float v);
	};
}