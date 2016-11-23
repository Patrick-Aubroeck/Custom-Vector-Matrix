#ifndef _VECTOR2_H_
#define _VECTOR2_H_

namespace ZyphMaths
{
	class Vector2
	{
	public:
		const static Vector2 ONE; // Returns a vector2 with both x and y set to 1.
		const static Vector2 ZERO; // Returns a vector2 with both x and y set to 0.

		float x; // x Value
		float y; // y Value

		Vector2(); // Default Constructor, creates a vector2 with both its x and y value set to zero.
		Vector2(float xy); // Constructor with both x and y set to the value given as param.
		Vector2(float x, float y); // Constructor that sets that x and y value given as param.
		~Vector2(); // Destructor

		/* ***** Operators *****
		   *********************/
		Vector2 operator-(void) const; 
		Vector2 operator-(const float scalar) const;
		Vector2 operator-(const Vector2 &vec) const;
		Vector2& operator-=(const Vector2 &vec);

		Vector2 operator+(const float scalar) const;
		Vector2 operator+(const Vector2 &vec) const;
		Vector2& operator+=(const Vector2 &vec);

		Vector2 operator*(const float scalar) const;
		Vector2 operator*(const Vector2 &vec) const;
		Vector2& operator*=(const float scalar);
		Vector2& operator*=(const Vector2 &vec);

		Vector2 operator/(const float scalar) const;
		Vector2 operator/(const Vector2 &vec) const;
		Vector2& operator/=(const float scalar);
		Vector2& operator/=(const Vector2 &vec);

		bool operator==(const Vector2 &vec) const;
		bool operator!=(const Vector2 &vec) const;
		bool operator<(const Vector2 &vec) const;
		float operator[](int index) const;
		float& operator[](int index);
		double operator|(const Vector2 &vec) const;
	};
}
#endif