//////////////////////////////////////////////////////////////////////////
//
// This header is a part of the Tutorial Tool Kit (TTK) library. 
// You may not use this header in your GDW games.
//
// This is the complete Matrix3x3 class
//
// Michael Gharbharan 2015
//
//////////////////////////////////////////////////////////////////////////

#ifndef TTK_MATRIX33_H
#define TTK_MATRIX33_H

#ifdef TTK_EXPORTS
#define TTK_API __declspec(dllexport)
#else
#define TTK_API __declspec(dllimport)
#endif

#include "TTK/Vector3.h"

namespace TTK
{
	class TTK_API Matrix3x3
	{
	public:
		static Matrix3x3 CreateRotationX(float rad);
		static Matrix3x3 CreateRotationY(float rad);
		static Matrix3x3 CreateRotationZ(float rad);

		static Matrix3x3 CreateScale(float s);

		Matrix3x3(); // Initializes to identity
		
		Vector3 operator*(const Vector3 &b) const;
		Matrix3x3 operator*(const Matrix3x3 &b) const;

		Vector3 getRow0() const;
		Vector3 getRow1() const;
		Vector3 getRow2() const;

		// This is a column major matrix
		// The mapping from indices to cells in the matrix is as follows:
		/*
		0   3   6
		1   4   7
		2   5   8
		*/
		// The formula for getting the index is:
		// row + (column*3)

		union
		{
			struct
			{
				Vector3 c0, c1, c2;
			};
			float values[9];
		};
	};
}


#endif