//////////////////////////////////////////////////////////////////////////
//
// This header is a part of the Tutorial Tool Kit (TTK) library. 
// You may not use this header in your GDW games.
//
// This is the complete Matrix4x4 class
//
// Michael Gharbharan 2015
//
//////////////////////////////////////////////////////////////////////////

#ifndef TTK_MATRIX44_H
#define TTK_MATRIX44_H

#ifdef TTK_EXPORTS
#define TTK_API __declspec(dllexport)
#else
#define TTK_API __declspec(dllimport)
#endif

#include "TTK/Matrix3x3.h"
#include "TTK/Vector3.h"

namespace TTK
{
	class TTK_API Matrix4x4
	{
	public:
		Matrix4x4(); // Initializes to identity
		Matrix4x4(Matrix3x3 rotation, Vector3 translation, float scale);	// Creates homogeneous transformation matrix

	};
}

#endif