#ifndef _VECTOR3_H_
#define _VECTOR3_H_

namespace ZyphMaths
{
	class Matrix4x4;

	class Vector3
	{
	public:
		const static Vector3 ONE; // Returns a vector3 with all values set to 1.
		const static Vector3 ZERO; // Returns a vector3 with all values set to 0.
		const static Vector3 UPVECTOR; // Returns a vector3 with the y value set to 1, the x and z set to 0.

		float x; // x value.
		float y; // y value.
		float z; // z value.

		Vector3(); // Default constructor sets values to 0.
		Vector3(float xyz); // Constructor creates a vector3 with the x, y, and z value set to the value given as param.
		Vector3(float x, float y, float z); // Constructor creates a vector3 with the x, y, and z value given as param.
		~Vector3();

		Vector3 operator-(void) const;
		Vector3 operator-(const float scalar) const;
		Vector3 operator-(const Vector3 &vec) const;
		Vector3& operator-=(const Vector3 &vec);

		Vector3 operator+(const float scalar) const;
		Vector3 operator+(const Vector3 &vec) const;
		Vector3& operator+=(const Vector3 &vec);

		Vector3 operator*(const float scalar) const;
		Vector3 operator*(const Vector3 &vec) const;
		Vector3& operator*=(const float scalar);
		Vector3& operator*=(const Vector3 &vec);

		Vector3 operator/(const float scalar) const;
		Vector3 operator/(const Vector3 &vec) const;
		Vector3& operator/=(const float scalar);
		Vector3& operator/=(const Vector3 &vec);

		bool operator==(const Vector3 &vec) const;
		bool operator!=(const Vector3 &vec) const;
		bool operator<(const Vector3 &vec) const;
		float operator[](int index) const;
		float& operator[](int index);
		double operator|(const Vector3 &vec) const;

		static Vector3 TransformCoordinate(Vector3 &coords, Matrix4x4 &transformMatrix); // Transforms the vector given as param with the matrix given as param. Returns a new vector3.
		static Vector3 TransformNormal(Vector3 &normal, Matrix4x4 &transformMatrix);
	    Vector3 Normalize(); // Normalize this vector3.
		static float Dot(const Vector3 &vec1, const Vector3 &vec2); // Creates a dot product from the vector3 given as param.	
	};
}
#endif