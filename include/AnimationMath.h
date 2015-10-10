#pragma once

// Linear interpolation 

//float lerp(float a0, float a1, float t)
//{
//	return (1 - t) * a0 + t * a1;
//}
//
//TTK::Vector3 lerp(TTK::Vector3 p0, TTK::Vector3 p1, float t)
//{
//	return p0 * (1 - t) + p1 * t;
//}

//Lerp Template 
template <typename T>
T lerp(T d0, T d1, float t)
{
	return d0 * (1 - t) + d1 * t;
}

// Catmull-Rom interpolation

// Returns a point between p1 and p2
template <typename T>
T catmull(T p0, T p1, T p2, T p3, float t)
{
	return	((p1 * 2.0f) + (-p0 + p2) * t +
		((p0 * 2.0f) - (p1 * 5.0f) + (p2 * 4.0f) - p3) * (t * t) +
		(-p0 + (p1 * 3.0f) - (p2 * 3.0f) + p3) * (t * t * t)) * 0.5f;
}

// Bezier interpolation

// Bezier degree 0
template <typename T>
T bezier(T p0, float t)
{
	return p0;
}

// Bezier degree 1
// aka just LERP
template <typename T>
T bezier(T p0, T p1, float t)
{
	return lerp(bezier(p0, t), bezier(p1, t), t);
}

// Bezier degree 2
template <typename T>
T bezier(T p0, T p1, T p2, float t)
{
	return lerp(bezier(p0, p1, t), bezier(p1, p2, t), t);
}

// Bezier degree 3
template <typename T>
T bezier(T p0, T p1, T p2, T p3, float t)
{
	return lerp(bezier(p0, p1, p2, t), bezier(p1, p2, p3, t), t);
}