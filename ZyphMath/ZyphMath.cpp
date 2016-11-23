#include "ZyphMath.h"

namespace ZyphMaths
{
	const float ZyphMath::PI = 3.14159265359f;
	const float ZyphMath::MAX_FLOAT_VALUE = 340282346638528859811704183484516925440.0f;

	/// <summary> Clamp the value between the min and max value given as param.</summary>
	const float ZyphMath::CLAMP(float value, float minValue, float maxValue)
	{
		return MAX(minValue, MIN(value, maxValue));
	}

	/// <summary> Gets the min value from the two float values given as param.</summary>
	const float ZyphMath::MIN(float a, float b)
	{
		return (((a) < (b)) ? (a) : (b));
	}

	/// <summary> Gets the max value from the two float values given as param.</summary>
	const float ZyphMath::MAX(float a, float b)
	{
		return (((a) > (b)) ? (a) : (b));
	}

	/// <summary> 
	/// Interpolating the value between 2 vertices 
	/// min is the starting point, max the ending point
	/// and gradient the % between the 2 points
	/// </summary>
	const float ZyphMath::INTERPOLATE(float min, float max, float gradient)
	{
		return min + (max - min) * CLAMP(gradient);
	}

	/// <summary> Compute the cosine of the angle between the light vector and the normal vector </summary>
	const float ZyphMath::COMPUTENDOTL(ZyphMaths::Vector3 position, ZyphMaths::Vector3 normal, ZyphMaths::Vector3 lightPosition)
	{
		ZyphMaths::Vector3 direction = lightPosition - position;

		normal.Normalize();
		direction.Normalize();

		return MAX(0.0f, ZyphMaths::Vector3::Dot(normal, direction));
	}

}