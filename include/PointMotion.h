#pragma once

#include "TTK/TTK.h"

class PointMotion
{
public:
	// pointSize is the size of the handle
	// pos is the location of the handle
	PointMotion(float _pointSize, TTK::Vector3 _pos, std::string _label);

	void setPointSize(float _size);

	// Checks if point p is within 
	bool isInside(TTK::Vector3 p);

	void draw();

	TTK::Vector3 pos;
	std::string label;

private:
	float pointSize;
	float radiusSqrd;
};