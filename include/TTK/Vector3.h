//////////////////////////////////////////////////////////////////////////
//
// This header is a part of the Tutorial Tool Kit (TTK) library. 
// You may not use this header in your GDW games.
//
// This is the complete Vector3 class
//
// Michael Gharbharan 2015
//
//////////////////////////////////////////////////////////////////////////

#ifndef TTK_VECTOR3_H
#define TTK_VECTOR3_H

#ifdef TTK_EXPORTS
#define TTK_API __declspec(dllexport)
#else
#define TTK_API __declspec(dllimport)
#endif

namespace TTK
{
	class TTK_API Vector3
	{
	public:
		static float dot(Vector3 a, Vector3 b);
		static Vector3 cross(Vector3 a, Vector3 b);
		static Vector3 normalize(Vector3 a);
		static float magnitude(Vector3 a);

		// Returns squared magnitude (same as magnitude function without the sqrt()).
		// This is a lot faster than calling the magnitude function because sqrt() is a very slow operation.
		static float magnitudeSqrd(Vector3 a);

		// Handy utility functions
		static Vector3 zero();	// 0,0,0
		static Vector3 up();	// 0,1,0
		static Vector3 right();	// 1,0,0

		void print();

		Vector3();	// Initializes Vector to (0,0,0)
		Vector3(float xyz);	// Initializes x,y,z to specified value
		Vector3(float _x, float _y, float _z);
		~Vector3();

		Vector3 operator*(float s) const;
		//Vector3 operator/(float s) const;
		Vector3 operator+(const Vector3& b) const;

		// Pass by value example
		//Vector3 operator-(Vector3 b) const;

		
		// Pass by reference example
		Vector3 operator-(const Vector3& b) const;
		Vector3 operator-() const; // negates xyz, unary subtract or unary negate

		//Vector3 &operator-=(const Vector3 &b); // assigns to itself and returns itself

		//float operator[](unsigned int index) const;
		//float &operator[](unsigned int index);

		// Allows us to access data as independent elements or as an array
		union
		{
			struct
			{
				float x, y, z;
			};
			struct  
			{
				float r, g, b;
			};
			float values[3];
		};
	};
}

#endif