//////////////////////////////////////////////////////////////////////////
//
// This header is a part of the Tutorial Tool Kit (TTK) library. 
// You may not use this header in your GDW games.
//
// This is the complete Vector4 class
//
// Michael Gharbharan 2015
//
//////////////////////////////////////////////////////////////////////////

#ifndef TTK_VECTOR4_H
#define TTK_VECTOR4_H

#ifdef TTK_EXPORTS
#define TTK_API __declspec(dllexport)
#else
#define TTK_API __declspec(dllimport)
#endif

namespace TTK
{
	class Vector3;

	class TTK_API Vector4
	{
	public:
 		static float dot(Vector4 a, Vector4 b);
 		//static Vector4 cross(Vector4 a, Vector4 b);
 		//static Vector4 normalize(Vector4 a);
 		//static float magnitude(Vector4 a);
 
 		// Handy utility functions
 		//static Vector4 zero();	// 0,0,0,0
 		//static Vector4 up();	// 0,1,0,0
 		//static Vector4 right();	// 1,0,0,0
 
 		void print();
 
 		Vector4();	// Initializes Vector to (0,0,0,0)
 		Vector4(float xyz);	// Initializes x,y,z, w to specified value
 		Vector4(float _x, float _y, float _z, float _w);
		Vector4(Vector3 vec3); // x,y,z is set to vec3, w is set to 0
 		~Vector4();
 
 		Vector4 operator*(float s) const;
 		//Vector4 operator/(float s) const;
 		Vector4 operator+(const Vector4& b) const;
 
 		// Pass by value example
 		//Vector4 operator-(Vector4 b) const;
 
 
 		// Pass by reference example
 		Vector4 operator-(const Vector4& b) const; // Implement with them
 		Vector4 operator-() const; // negatites xyz, unary subtract or unary negate // Implement with them

 		//Vector4 &operator-=(const Vector4 &b); // assigns to itself and returns itself

		//float operator[](unsigned int index) const;
		//float &operator[](unsigned int index);

		// Allows us to access data as independent elements or as an array
		// Implement with them
		union
		{
			struct
			{
				float x, y, z, w;
			};
			struct
			{
				float r, g, b, a;
			};
			float values[4];
		};
	};
}

#endif