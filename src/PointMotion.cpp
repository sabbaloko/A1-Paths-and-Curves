#include "PointMotion.h"

PointMotion::PointMotion(float _pointSize, TTK::Vector3 _pos, std::string _label)
{
	setPointSize(_pointSize);
	pos = _pos;
	label = _label;
}

void PointMotion::setPointSize(float _size)
{
	pointSize = _size;
	radiusSqrd = (_size / 2.0f) * (_size / 2.0f);
}

bool PointMotion::isInside(TTK::Vector3 p)
{
	return TTK::Vector3::magnitudeSqrd(p - pos) < radiusSqrd;
}

void PointMotion::draw()
{
	TTK::Graphics::DrawPoint(pos.values, pointSize);
	TTK::Graphics::DrawText2D(label, pos.x, pos.y + pointSize * 0.5f);
}