//////////////////////////////////////////////////////////////////////////
//
// This header is a part of the Tutorial Tool Kit (TTK) library. 
// You may not use this header in your GDW games.
//
// This is the main TTK header. This header simply included all the other
// TTK headers.
//
// Michael Gharbharan 2015
//
//////////////////////////////////////////////////////////////////////////

#ifndef TTK_H
#define TTK_H

#include "TTK/GraphicsUtils.h"
#include "TTK/Vector3.h"
#include "TTK/Matrix3x3.h"
#include "TTK/Matrix4x4.h"
#include "TTK/Texture2D.h"
#include "TTK/MeshBase.h"
#include "TTK/QuadMesh.h"
#include "TTK/SpriteSheetQuad.h"

#ifdef TTK_EXPORTS
#define TTK_API __declspec(dllexport)
#else
#define TTK_API __declspec(dllimport)
#endif

namespace TTK
{
	TTK_API void InitializeTTK();
}

#endif