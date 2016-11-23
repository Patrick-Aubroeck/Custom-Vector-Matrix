#include "Vector3.h"
#include "Matrix4x4.h"
#include <math.h>

namespace ZyphMaths
{
	const Vector3 Vector3::ONE = Vector3(1.0f, 1.0f, 1.0f);
	const Vector3 Vector3::ZERO = Vector3(0.0f, 0.0f, 0.0f);
	const Vector3 Vector3::UPVECTOR = Vector3(0.0f, 1.0f, 0.0f);


	/// <summary> Default constructor sets values to 0.</summary>
	Vector3::Vector3() :
		x(0), y(0), z(0)
	{
	}

	/// <summary> Constructor creates a vector3 with the x, y, and z value set to the value given as param.</summary>
	Vector3::Vector3(float xyz) :
		x(xyz), y(xyz), z(xyz)
	{
	}

	/// <summary> Constructor creates a vector3 with the x, y, and z value given as param.</summary>
	Vector3::Vector3(float xValue, float yValue, float zValue) :
		x(xValue), y(yValue), z(zValue)
	{
	}

	/// <summary> Destructor.</summary>
	Vector3::~Vector3()
	{
	}

	Vector3 Vector3::operator-(void) const
	{
		return Vector3(-x, -y, -z);
	}

	Vector3 Vector3::operator-(const float scalar) const
	{
		return Vector3(x - scalar, y - scalar, z - scalar);
	}

	Vector3 Vector3::operator-(const Vector3 &vec) const
	{
		return Vector3(x - vec.x, y - vec.y, z - vec.z);
	}

	Vector3& Vector3::operator-=(const Vector3 &vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;

		return *this;
	}

	Vector3 Vector3::operator+(const float scalar) const
	{
		return Vector3(x + scalar, y + scalar, z + scalar);
	}

	Vector3 Vector3::operator+(const Vector3 &vec) const
	{
		return Vector3(x + vec.x, y + vec.y, z + vec.z);
	}

	Vector3& Vector3::operator+=(const Vector3 &vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;

		return *this;
	}
	Vector3 Vector3::operator*(const float scalar) const
	{
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	Vector3 Vector3::operator*(const Vector3 &vec) const
	{
		return Vector3(x * vec.x, y * vec.y, z * vec.z);
	}

	Vector3& Vector3::operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;

		return *this;
	}

	Vector3& Vector3::operator*=(const Vector3 &vec)
	{
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;

		return *this;
	}

	Vector3 Vector3::operator/(const float scalar) const
	{
		return Vector3(x / scalar, y / scalar, z / scalar);
	}

	Vector3 Vector3::operator/(const Vector3 &vec) const
	{
		return Vector3(x / vec.x, y / vec.y, z / vec.z);
	}

	Vector3& Vector3::operator/=(const float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;

		return *this;
	}

	Vector3& Vector3::operator/=(const Vector3 &vec)
	{
		x /= vec.x;
		y /= vec.y;
		z /= vec.z;

		return *this;
	}

	bool Vector3::operator==(const Vector3 &vec) const
	{
		return (x == vec.x) && (y == vec.y) && (z == vec.z);
	}

	bool Vector3::operator!=(const Vector3 &vec) const
	{
		return (x != vec.x) && (y != vec.y) && (z != vec.z);
	}

	bool Vector3::operator<(const Vector3 &vec) const
	{
		if (x < vec.x) return true;
		if (x > vec.x) return false;
		if (y < vec.y) return true;
		if (y > vec.y) return false;
		if (z < vec.z) return true;
		if (z > vec.z) return false;
		return false;
	}

	double Vector3::operator|(const Vector3 &vec) const
	{
		return ((x * vec.x) + (y * vec.y) + (z * vec.z));
	}

	float Vector3::operator[](int index) const
	{
		return (&x)[index];
	}

	float& Vector3::operator[](int index)
	{
		return (&x)[index];
	}

	/// <summary>Transforms the vector given as param with the matrix given as param.</summary>
	/// <returns>A vector3 with the coordinates transformed.</returns>
	Vector3 Vector3::TransformCoordinate(Vector3 &coords, Matrix4x4 &transformMatrix)
	{
		Vector4 vector;
		vector.x = (transformMatrix.mValues[0] * coords.x) + (transformMatrix.mValues[4] * coords.y) + (transformMatrix.mValues[8] * coords.z) + transformMatrix.mValues[12];
		vector.y = (transformMatrix.mValues[1] * coords.x) + (transformMatrix.mValues[5] * coords.y) + (transformMatrix.mValues[9] * coords.z) + transformMatrix.mValues[13];
		vector.z = (transformMatrix.mValues[2] * coords.x) + (transformMatrix.mValues[6] * coords.y) + (transformMatrix.mValues[10] * coords.z) + transformMatrix.mValues[14];
		vector.w = 1.0f / ((coords.x * transformMatrix.mValues[3]) + (coords.y * transformMatrix.mValues[7]) + (coords.z * transformMatrix.mValues[8]) + transformMatrix.mValues[15]);
		return Vector3(vector.x * vector.w, vector.y * vector.w, vector.z * vector.w);
	}

	Vector3 Vector3::TransformNormal(Vector3 &normal, Matrix4x4 &transformMatrix)
	{
		return Vector3((normal.x * transformMatrix.mValues[0]) + (normal.y * transformMatrix.mValues[4]) + (normal.z * transformMatrix.mValues[8]),
					   (normal.x * transformMatrix.mValues[1]) + (normal.y * transformMatrix.mValues[5]) + (normal.z * transformMatrix.mValues[9]),
				   	   (normal.x * transformMatrix.mValues[2]) + (normal.y * transformMatrix.mValues[6]) + (normal.z * transformMatrix.mValues[10]));
	}

	/// <summary> Normalize this vector3.</summary>
	Vector3 Vector3::Normalize()
	{
		Vector3 vector;
		float length = sqrt((this->x * this->x)+ (this->y * this->y) + (this->z * this->z));
		if (length != 0) {
			vector.x = this->x / length;
			vector.y = this->y / length;
			vector.z = this->z / length;
		}
		return vector;
	}

	/// <summary>  Creates a dot product from the vector3's given as param.</summary>
	float Vector3::Dot(const Vector3 &vec1, const Vector3 &vec2)
	{
		return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
	}
}