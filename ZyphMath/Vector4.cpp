#include "Vector4.h"

namespace ZyphMaths
{
	const Vector4 Vector4::ONE = Vector4(1, 1, 1, 1);
	const Vector4 Vector4::ZERO = Vector4(0, 0, 0, 0);

	/// <summary> Default Constructor, creates the vector4 with zero(0) values.</summary>
	Vector4::Vector4() :
		x(0.0f), y(0.0f), z(0.0f), w(0.0f)
	{
	}

	/// <summary> Constructs the vector4 with the xyz value. </summary>
	Vector4::Vector4(float xyzw) :
		x(xyzw), y(xyzw), z(xyzw), w(xyzw)
	{
	}

	/// <summary> Constructs the vector4 with the x, y, z, w value. </summary>
	Vector4::Vector4(float x, float y, float z, float w) :
		x(x), y(y), z(z), w(w)
	{
	}

	/// <summary> Destructor.</summary>
	Vector4::~Vector4()
	{
	}

	Vector4 Vector4::operator-(void) const
	{
		return Vector4(-x, -y, -z, -w);
	}

	Vector4 Vector4::operator-(const float scalar) const
	{
		return Vector4(x - scalar, y - scalar, z - scalar, w - scalar);
	}

	Vector4 Vector4::operator-(const Vector4 &vec) const
	{
		return Vector4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
	}

	Vector4& Vector4::operator-=(const Vector4 &vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		w -= vec.w;

		return *this;
	}

	Vector4 Vector4::operator+(const float scalar) const
	{
		return Vector4(x + scalar, y + scalar, z + scalar, w + scalar);
	}

	Vector4 Vector4::operator+(const Vector4 &vec) const
	{
		return Vector4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
	}

	Vector4& Vector4::operator+=(const Vector4 &vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		w += vec.w;

		return *this;
	}

	Vector4 Vector4::operator*(const float scalar) const
	{
		return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	Vector4 Vector4::operator*(const Vector4 &vec) const
	{
		return Vector4(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
	}

	Vector4& Vector4::operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		w *= scalar;

		return *this;
	}

	Vector4& Vector4::operator*=(const Vector4 &vec)
	{
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;
		w *= vec.w;

		return *this;
	}

	Vector4 Vector4::operator/(const float scalar) const
	{
		return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
	}

	Vector4 Vector4::operator/(const Vector4 &vec) const
	{
		return Vector4(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
	}

	Vector4& Vector4::operator/=(const float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		w /= scalar;

		return *this;
	}

	Vector4& Vector4::operator/=(const Vector4 &vec)
	{
		x /= vec.x;
		y /= vec.y;
		z /= vec.z;
		w /= vec.w;

		return *this;
	}

	bool Vector4::operator==(const Vector4 &vec) const
	{
		return (x == vec.x) && (y == vec.y) && (z == vec.z) && (w == vec.w);
	}

	bool Vector4::operator!=(const Vector4 &vec) const
	{
		return (x != vec.x) && (y != vec.y) && (z != vec.z) && (w != vec.w);
	}

	bool Vector4::operator<(const Vector4 &vec) const
	{
		if (x < vec.x) return true;
		if (x > vec.x) return false;
		if (y < vec.y) return true;
		if (y > vec.y) return false;
		if (z < vec.z) return true;
		if (z > vec.z) return false;
		if (w < vec.w) return true;
		if (w > vec.w) return false;
		return false;
	}

	double Vector4::operator|(const Vector4 &vec) const
	{
		return ((x * vec.x) + (y * vec.y) + (z * vec.z) + (w * vec.w));
	}

	float Vector4::operator[](int index) const
	{
		return (&x)[index];
	}

	float& Vector4::operator[](int index)
	{
		return (&x)[index];
	}
}
