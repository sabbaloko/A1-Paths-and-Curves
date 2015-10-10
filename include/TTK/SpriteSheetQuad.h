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

#include "TTK/TTK.h"

#include <vector>

namespace TTK
{
	struct TTK_API SpriteCoordinates
	{
	public:
		float xMin, xMax, yMin, yMax; // in pixels
		float uMin, uMax, vMin, vMax; // normalizes texture coordinates

	};

	class TTK_API SpriteSheetQuad
	{
	public:

		SpriteSheetQuad(char* fileName);

		// Description:
		// Calculates the coordinates for each sprite in the sheet
		// Arguments:
		// spriteSizeX is the width of each sprite in the sheet
		// spriteSizeY is the height of each sprite in the sheet
		// numSpritesPerRow is the number of sprites in a single row
		// numRows is the number of rows that make up the sheet
		void sliceSpriteSheet(float spriteSizeX, float spriteSizeY, int numSpritesPerRow, int numRows);

		void nextFrame();

		void setLooping(bool loop);

		// Description:
		// Sets the UVs for the quad and then calls the quad's draw function
		void draw();

		//private:
		int currentFrame;
		bool doesLoop;

		QuadMesh quad;
		TTK::Texture2D texture;

		std::vector<SpriteCoordinates> spriteCoordinates;
	};
}