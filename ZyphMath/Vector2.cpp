#include "Vector2.h"
#include <cmath>

namespace ZyphMaths
{
	const Vector2 Vector2::ONE = Vector2(1, 1);
	const Vector2 Vector2::ZERO = Vector2(0, 0);


	/// <summary> Default Constructor, creates a vector2 with both its x and y value set to zero.</summary>
	Vector2::Vector2() :
		x(0), y(0)
	{
	}


	/// <summary> Constructor with both x and y set to the value given as param.</summary>
	Vector2::Vector2(float xy) :
		x(xy), y(xy)
	{

	}


	/// <summary> Constructor that sets that x and y value given as param.</summary>
	Vector2::Vector2(float x, float y) :
		x(x), y(y)
	{

	}


	/// <summary> Destructor.</summary>
	Vector2::~Vector2()
	{
	}

	Vector2 Vector2::operator-(void) const
	{
		return Vector2(-x, -y);
	}

	Vector2 Vector2::operator-(const float scalar) const
	{
		return Vector2(x - scalar, y - scalar);
	}

	Vector2 Vector2::operator-(const Vector2 &vec) const
	{
		return Vector2(x - vec.x, y - vec.y);
	}

	Vector2& Vector2::operator-=(const Vector2 &vec)
	{
		x -= vec.x;
		y -= vec.y;

		return *this;
	}

	Vector2 Vector2::operator+(const float scalar) const
	{
		return Vector2(x + scalar, y + scalar);
	}

	Vector2 Vector2::operator+(const Vector2 &vec) const
	{
		return Vector2(x + vec.x, y + vec.y);
	}

	Vector2& Vector2::operator+=(const Vector2 &vec)
	{
		x += vec.x;
		y += vec.y;

		return *this;
	}

	Vector2 Vector2::operator*(const float scalar) const
	{
		return Vector2(x * scalar, y * scalar);
	}

	Vector2 Vector2::operator*(const Vector2 &vec) const
	{
		return Vector2(x * vec.x, y * vec.y);
	}

	Vector2& Vector2::operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;

		return *this;
	}

	Vector2& Vector2::operator*=(const Vector2 &vec)
	{
		x *= vec.x;
		y *= vec.y;

		return *this;
	}


	Vector2 Vector2::operator/(const float scalar) const
	{
		return Vector2(x / scalar, y / scalar);
	}

	Vector2 Vector2::operator/(const Vector2 &vec) const
	{
		return Vector2(x / vec.x, y / vec.y);
	}

	Vector2& Vector2::operator/=(const float scalar)
	{
		x /= scalar;
		y /= scalar;

		return *this;
	}

	Vector2& Vector2::operator/=(const Vector2 &vec)
	{
		x /= vec.x;
		y /= vec.y;

		return *this;
	}

	bool Vector2::operator==(const Vector2 &vec) const
	{
		return (x == vec.x) && (y == vec.y);
	}

	bool Vector2::operator!=(const Vector2 &vec) const
	{
		return (x != vec.x) && (y != vec.y);
	}

	bool Vector2::operator<(const Vector2 &vec) const
	{
		if (x < vec.x) return true;
		if (x > vec.x) return false;
		if (y < vec.y) return true;
		if (y > vec.y) return false;
		return false;
	}

	double Vector2::operator|(const Vector2 &vec) const
	{
		return ((x * vec.x) + (y * vec.y));
	}

	float Vector2::operator[](int index) const
	{
		return (&x)[index];
	}

	float& Vector2::operator[](int index)
	{
		return (&x)[index];
	}
}