//////////////////////////////////////////////////////////////////////////
//
// This header is a part of the Tutorial Tool Kit (TTK) library. 
// You may not use this header in your GDW games.
//
// This is the base class for all meshes.
//
// Michael Gharbharan 2015
//
//////////////////////////////////////////////////////////////////////////

#ifndef MESH_BASE_H
#define MESH_BASE_H

#ifdef TTK_EXPORTS
#define TTK_API __declspec(dllexport)
#else
#define TTK_API __declspec(dllimport)
#endif

#include <vector>
#include "TTK/Vector3.h"
#include "TTK/Vector4.h"

namespace TTK
{
	enum PrimitiveType
	{
		Triangles = 1,
		Quads
	};

	class TTK_API MeshBase
	{
	public:
		// Description:
		// Very simple draw function which binds all three buffers
		// Yes, it uses OpenGL 1.0 draw calls... for now.
		void draw();

		// Description:
		// Sets all per-vertex colours to the specified colour
		void setAllColours(TTK::Vector4 colour);

		std::vector<TTK::Vector3> vertices;
		std::vector<TTK::Vector3> textureCoordinates;	// could (should?) be a Vector2
		std::vector<TTK::Vector4> colours;

		PrimitiveType primitiveType;
	};
}

#endif