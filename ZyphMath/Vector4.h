#ifndef _VECTOR4_H_
#define _VECTOR4_H_

namespace ZyphMaths
{
	class Vector4
	{
	public:
		// ------------------
		// -- Constructors --
		// ------------------
		//Constructs the vector4 with zero(0) values. 
		Vector4(void);
		//Constructs the vector4 with the xyz value. 
		Vector4(float xyzw);
		//Constructs the vector4 with the x, y, z, w value. 
		Vector4(float x, float y, float z, float w);
		//Destructor
		~Vector4();

		Vector4 operator-(void) const;
		Vector4 operator-(const float scalar) const;
		Vector4 operator-(const Vector4 &vec) const;
		Vector4& operator-=(const Vector4 &vec);

		Vector4 operator+(const float scalar) const;
		Vector4 operator+(const Vector4 &vec) const;
		Vector4& operator+=(const Vector4 &vec);

		Vector4 operator*(const float scalar) const;
		Vector4 operator*(const Vector4 &vec) const;
		Vector4& operator*=(const float scalar);
		Vector4& operator*=(const Vector4 &vec);

		Vector4 operator/(const float scalar) const;
		Vector4 operator/(const Vector4 &vec) const;
		Vector4& operator/=(const float scalar);
		Vector4& operator/=(const Vector4 &vec);

		bool operator==(const Vector4 &vec) const;
		bool operator!=(const Vector4 &vec) const;
		bool operator<(const Vector4 &vec) const;
		float operator[](int index) const;
		float& operator[](int index);
		double operator|(const Vector4 &vec) const;

	public:
		const static Vector4 ONE; // Returns a vector4 with all its values set to 1.
		const static Vector4 ZERO; // Returns a vector4 with all its values set to 0.

		float x; // x value.
		float y; // y value.
		float z; // z value.
		float w; // w value.
	};

}
#endif
