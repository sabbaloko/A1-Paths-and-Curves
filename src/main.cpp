// Core Libraries
#include <iostream>
#include <string>
#include <math.h>
#include "KeyFrameController.h"
// Libraries
#include "GLUT/glut.h"

#pragma comment(lib, "TTK.lib")
#include "TTK/TTK.h"

// Project specific
#include "AnimationMath.h"
#include "PointMotion.h"

#define FRAMES_PER_SECOND 30
const int FRAME_DELAY_SPRITE = 1000 / FRAMES_PER_SECOND;

int windowWidth = 1000;
int windowHeight = 800;

//Set Paused to false so the program starts unpaused
bool paused = true;


TTK::Vector3 mousePosition;

// Useful conversions
float degToRad = 3.14159f / 180.0f;
float radToDeg = 180.0f / 3.14159f;

float deltaTime = 0.0f;

float t = 0.0f; // interpolation param

TTK::SpriteSheetQuad* ss;

std::vector<PointMotion> ph;

enum InterpolationMode
{
	LINEAR = 0,
	BEZIER,
	CATMULL
};

InterpolationMode interpolationMode;

TTK::Vector3 doLERP()
{
	TTK::Vector3 ret;

	if (ph.size() >= 2)
	{
		// Calculate current position on line
		ret = lerp<TTK::Vector3>(ph[0].pos, ph[1].pos, t);

		// Draw lines
		TTK::Graphics::DrawLine(ph[0].pos.values, ph[1].pos.values);
	}

	return ret;
}

TTK::Vector3 doBezier()
{
	TTK::Vector3 ret;

	if (ph.size() >= 3)
	{
		// Calculate current position on curve
		//ret = bezier<TTK::Vector3>(ph[0].pos, ph[1].pos, ph[2].pos, t);
		ret = bezier<TTK::Vector3>(ph[0].pos, ph[1].pos, ph[2].pos, ph[3].pos, t);

		for (float i = 0.0f; i <= 1.0f; i += 0.016f)
		{
			TTK::Vector3 point;
			//point = bezier<TTK::Vector3>(ph[0].pos, ph[1].pos, ph[2].pos, i);
			point = bezier<TTK::Vector3>(ph[0].pos, ph[1].pos, ph[2].pos, ph[3].pos, i);
			TTK::Graphics::DrawPoint(point.values, 5.0f);
		}
	}
	return ret;
}


TTK::Vector3 doCatmull()
{
	TTK::Vector3 ret;

	if (ph.size() >= 4)
	{
		// Calculate current position on curve
		ret = catmull<TTK::Vector3>(ph[0].pos, ph[1].pos, ph[2].pos, ph[3].pos, t);

		for (float i = 0.0f; i <= 1.0f; i += 0.016f)
		{
			TTK::Vector3 point;
			point = catmull<TTK::Vector3>(ph[0].pos, ph[1].pos, ph[2].pos, ph[3].pos, i);
			TTK::Graphics::DrawPoint(point.values, 5.0f);
		}
	}

	return ret;
}



/* function DisplayCallbackFunction(void)
* Description:
*  - this is the openGL display routine
*  - this draws the sprites appropriately
*/
void DisplayCallbackFunction(void)
{
	TTK::Graphics::SetBackgroundColour(1.0f, 5.0f, 0.0f);
	TTK::Graphics::ClearScreen();

	TTK::Graphics::SetCameraMode2D(windowWidth, windowHeight);

	TTK::Vector3 position;
	

	// Update interpolation parameter 
	t += deltaTime;

	if (t >= 1.0f)
		t = 0.0f;

	// Switch statement for Drawing Which Interpolation Mode as text
	switch (interpolationMode)
	{
	case LINEAR:
		
		TTK::Graphics::DrawText2D(std::string("Linear Interpolation"), 0, 0);
		position = doLERP();
		break;
	case CATMULL:
		
		TTK::Graphics::DrawText2D(std::string("Catmull-Rom"), 0, 0);
		position = doCatmull();
		break;
	case BEZIER:
		
		TTK::Graphics::DrawText2D(std::string("Bezier Interpolation"), 0, 0);
		position = doBezier();
		break;
	default:
		break;
	}

	// Draws point for function
	for (int i = 0; i < ph.size(); i++)
	{
		ph[i].draw();
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	TTK::Matrix4x4 tMat = TTK::Matrix4x4(TTK::Matrix3x3(), position, 100.0f);
	// glMultMatrix multiplies the internal GL matrix with our own matrix
	// TIP: In the future you will be replacing all of the internal GL 
	// matrices with your own.
	glMultMatrixf(tMat.values);

	ss->draw();

	glLoadIdentity();
	glutSwapBuffers();
}

/* function void KeyboardCallbackFunction(unsigned char, int,int)
* Description:
*   - this handles keyboard input when a button is pressed
*/
void KeyboardCallbackFunction(unsigned char key, int x, int y)
{
	std::cout << "Keycode:" << (int)key << std::endl;
	//theGame->keyboardDown(key, x, y);

}
/* function void KeyboardUpCallbackFunction(unsigned char, int,int)
* Description:
*   - this handles keyboard input when a button is lifted
*/

//9 Stops program
//1 toggles lerp
//2 toggles catmull-rom
//3 toggles bezier 

void KeyboardUpCallbackFunction(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '9':

	exit(0);
		break;
	case '1':
	
		interpolationMode = LINEAR;
		break;
	case '2':
	
		interpolationMode = CATMULL;
		break;
	case '3':
	
		interpolationMode = BEZIER;
		break;
	case 'p':
	case 'P':
		paused = !paused;	
	case 'u':
	case 'U':
		paused = paused;
	default:
		break;
	}
	
}

/* function TimerCallbackFunction(int value)
* Description:
*  - this is called many times per second
*  - this enables you to animate things
*  - no drawing, just changing the state
*  - changes the frame number and calls for a redisplay
*  - FRAME_DELAY_SPRITE is the number of milliseconds to wait before calling the timer again
*/
void TimerCallbackFunction(int value)
{
	glutPostRedisplay();
	glutTimerFunc(FRAME_DELAY_SPRITE, TimerCallbackFunction, 0);

	// Calculate new deltaT for potential updates and physics calculations
	static int elapsedTimeAtLastTick = 0;
	int totalElapsedTime = glutGet(GLUT_ELAPSED_TIME);

	deltaTime = totalElapsedTime - elapsedTimeAtLastTick;
	deltaTime /= 1000.0f;
	
	elapsedTimeAtLastTick = totalElapsedTime;
}

/* function WindowReshapeCallbackFunction()
* Description:
*  - this is called whenever the window is resized
*  - and sets up the projection matrix properly
*  - currently set up for an orthographic view (2D only)
*/
void WindowReshapeCallbackFunction(int w, int h)
{
	windowWidth = w;
	windowHeight = h;
	TTK::Graphics::SetCameraMode2D(w, h);
}

//Reset Point Function

void reset(int r, int t)
{

	

}


void MouseClickCallbackFunction(int button, int state, int x, int y)
{
	mousePosition.x = x;
	mousePosition.y = y;

	switch (state)
	{
	case GLUT_DOWN:
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			if (ph.size() < 4)
			{
				ph.push_back(PointMotion(25.0f, mousePosition, std::to_string(ph.size())));
			}
			break;
		default:
			break;
		}
	default:
		break;
	}
}


/* function MouseMotionCallbackFunction()
* Description:
*   - this is called when the mouse is clicked and moves
*/
void MouseMotionCallbackFunction(int x, int y)
{
	mousePosition.x = x;
	mousePosition.y = y;

	// Test for intersection with each handle
	for (int i = 0; i < ph.size(); i++)
	{
		if (ph[i].isInside(mousePosition))
		{
			if (mousePosition.x < windowWidth && mousePosition.y < windowHeight
				&& mousePosition.x > 0 && mousePosition.y > 0)
				ph[i].pos = mousePosition;
		}
	}
}

/* function MousePassiveMotionCallbackFunction()
* Description:
*   - this is called when the mouse is moved in the window
*/
void MousePassiveMotionCallbackFunction(int x, int y)
{

}

/* function main()
* Description:
*  - this is the main function
*  - does initialization and then calls glutMainLoop() to start the event handler
*/
int main(int argc, char **argv)
{
	/* initialize the window and OpenGL properly */
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Gotta Go Faster!");

	/* set up our function callbacks */
	glutDisplayFunc(DisplayCallbackFunction);
	glutKeyboardFunc(KeyboardCallbackFunction);
	glutKeyboardUpFunc(KeyboardUpCallbackFunction);
	glutReshapeFunc(WindowReshapeCallbackFunction);
	glutMouseFunc(MouseClickCallbackFunction);
	glutMotionFunc(MouseMotionCallbackFunction);
	glutPassiveMotionFunc(MousePassiveMotionCallbackFunction);
	glutTimerFunc(1, TimerCallbackFunction, 0);

	/* initialize the image library engine */
	TTK::InitializeTTK();

	ss = new TTK::SpriteSheetQuad("../images/sonic32.png");

	// If sprite is a spritesheet, cut to fit the first sprite
	//ss->sliceSpriteSheet(40, 80, 5, 1);

	/* start the event handler */
	glutMainLoop();
	return 0;
}