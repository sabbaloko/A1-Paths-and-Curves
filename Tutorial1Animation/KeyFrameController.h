#pragma once

#include <vector>

template <typename T>
class KeyFrameController
{
public:

	KeyFrameController()
	{
		doesLoop = true;
		keyLocalTime = 0.0f;
		currentFrame = 1.0f;
	}

	T update(float dt)
	{
		keyLocalTime += dt;

		if (keyLocalTime >= 1.0f)
		{
			currentFrame = getNextFrame();
			keyLocalTime = 0.0f;
		}

		T p0 = keys[currentFrame];
		T p1 = keys[getNextFrame()];

		return lerp<T>(p0, p1, keyLocalTime);
	}

	int getNextFrame()
	{
		int nextFrame = currentFrame + 1;
		int numKeys = keys.size();

		if (nextFrame >= numKeys)
		{
			if (doesLoop) // if loops go back to start
			{
				nextFrame = 0;
			}
			else // if not stay at last frame
			{
				nextFrame = numKeys - 1;
			}
		}

		return nextFrame;
	}

	int currentFrame;
	std::vector<T> keys;
	float keyLocalTime;
	bool doesLoop;
};
