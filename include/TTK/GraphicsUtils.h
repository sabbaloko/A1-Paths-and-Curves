//////////////////////////////////////////////////////////////////////////
//
// This header is a part of the Tutorial Tool Kit (TTK) library. 
// You may not use this header in your GDW games.
//
// This header contains utility functions for drawing.
//
// Michael Gharbharan 2015
//
//////////////////////////////////////////////////////////////////////////

#ifndef GRAPHICS_UTILS_H
#define GRAPHICS_UTILS_H

#ifdef TTK_EXPORTS
#define TTK_API __declspec(dllexport)
#else
#define TTK_API __declspec(dllimport)
#endif

#include "TTK/Vector3.h"
#include <string>

namespace TTK
{
	class Graphics
	{
	public:
		// Description:
		// Draws a cube at the specified position in world space.
		// TTK_API static void DrawCube(Vector3 position, float size);

		// Description:
		// Draws text at the specified position on the screen. Make sure
		// you call SetCameraMode2D before you try drawing any text.
		// Arguments:
		// posX, posY are to be specified in pixels. 0, 0 is the top left
		// corner of the window.
		TTK_API static void DrawText2D(std::string text, int posX, int posY);

		// Description:
		// Draws a line from p0 to p1
		TTK_API static void DrawLine(float* p0, float* p1);

		TTK_API static void DrawVector(float* origin, float* vectorToDraw);

		// Description:
		// Draws point at specified position.
		// Arguments:
		// p0 is an array of 3 floats representing position
		// pointSize lets you specify the size of the point, in pixels (p0 is center of point)
		TTK_API static void DrawPoint(float *p0, float pointSize);

		// Description:
		// Clears the current projection matrix and then resets it
		// to an orthographic projection.
		TTK_API static void SetCameraMode2D(int windowWidth, int windowHeight);

		// Description:
		// Clears the current projection matrix and then resets it
		// to an perspective projection with a field of view (FOV) of 60 degrees.
		TTK_API static void SetCameraMode3D(int windowWidth, int windowHeight);

		// Description:
		// Sets the colour of the screen after ClearScreen() has been called.
		TTK_API static void SetBackgroundColour(float r, float g, float b);

		// Description:
		// Removes all content from the screen. This should be called at
		// the beginning of every draw function.
		TTK_API static void ClearScreen();
	};
}

#endif