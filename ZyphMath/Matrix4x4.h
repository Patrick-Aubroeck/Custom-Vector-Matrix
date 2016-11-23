#ifndef _MATRIX4X4_H_
#define _MATRIX4X4_H_

#include "Vector4.h"
#include "Vector3.h"

namespace ZyphMaths
{
	class Matrix4x4
	{
	public:
		// ------------------
		// -- Constructors --
		// ------------------
		Matrix4x4(); // Default Constructor, creates an identity matrix. 
		Matrix4x4(const float values[16]); // Constructor creates a matrix4x4 by using the values given as param.
		Matrix4x4(float xx, float xy, float xz, float xw,
				  float yx, float yy, float yz, float yw,
				  float zx, float zy, float zz, float zw,
				  float wx, float wy, float wz, float ww); // Constructor creates a matrix4x4 by using the values given as param.
		~Matrix4x4();

		Matrix4x4 operator-(const Matrix4x4 &matrix) const;
		Matrix4x4 operator-(const Matrix4x4 &matrix);
		Matrix4x4& operator-=(const Matrix4x4 &matrix);

		Matrix4x4 operator+(const Matrix4x4 &matrix) const;
		Matrix4x4& operator+=(const Matrix4x4 &matrix);

		Vector4 operator*(const Vector4 &vec) const;
		Vector3 operator*(const Vector3 &vec) const;
		Matrix4x4 operator*(const Matrix4x4 &matrix) const;
		Matrix4x4& operator*=(const Matrix4x4 &matrix);

		bool operator==(const Matrix4x4 &matrix) const;
		bool operator!=(const Matrix4x4 &matrix) const;
		float operator[](int index) const;
		float& operator[](int index);

		static Matrix4x4 LookAtLH(Vector3 position, Vector3 target, Vector3 upVector); // Creates a left handed look at matrix using the position, target and upVector as input.
		static Matrix4x4 PerspectiveFovRH(float fieldOfView, float aspect, float zNear, float zFar); // Creates a matrix that uses the right handed projection perspective.
		static Matrix4x4 PerspectiveFovLH(float fieldOfView, float aspect, float zNear, float zFar); // Creates a matrix that uses the left handed projection perspective.
		static Matrix4x4 RotationYawPitchRoll(float yaw, float pitch, float roll); //Rotates the maxtrix by transforming the z(roll) x(pitch) and y(yaw) relative to the objects local coordinates axis.
		static Matrix4x4 Translation(Vector3 position); // Creates a matrix using the specified position offset given as param.
		static Matrix4x4 RotateX(float pitch); // Rotates the matrix over the x axis.
		static Matrix4x4 RotateY(float yaw); // Rotates the matrix over the y axis.
		static Matrix4x4 RotateZ(float roll); // Rotates the matrix over the z axis.
	public:
		const static Matrix4x4 IDENTITY;

		float mValues[16];
	};
}
#endif
