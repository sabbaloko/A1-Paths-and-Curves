//////////////////////////////////////////////////////////////////////////
//
// This header is a part of the Tutorial Tool Kit (TTK) library. 
// You may not use this header in your GDW games.
//
// This is a simple Texture2D class
//
// Michael Gharbharan 2015
//
//////////////////////////////////////////////////////////////////////////

#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#ifdef TTK_EXPORTS
#define TTK_API __declspec(dllexport)
#else
#define TTK_API __declspec(dllimport)
#endif

namespace TTK
{
	class TTK_API Texture2D
	{
	public:
		Texture2D();
		Texture2D(char* filename);
		~Texture2D();

		// Returns width / height of texture in pixels
		int width();
		int height();

		// Description:
		// Loads texture at specified location.
		// Note: when program is run through VS, file path is relative to
		// the project directory. When program is ran as a standalone, file path
		// is relative to the executable.
		void loadTexture(char* filename);

		// Description:
		// Calling this before drawing will make the mesh being drawn use
		// this texture, providing the mesh has texture coordinates.
		void bind();

		void unbind();

	private:
		int texWidth;
		int texHeight;
		int texID;
	};
}

#endif