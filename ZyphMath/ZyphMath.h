#ifndef _ZYPHMATH_H_
#define _ZYPHMATH_H_

#include "Vector3.h"

namespace ZyphMaths
{
	class ZyphMath
	{
	public:
		const static float PI; // PI value.
		const static float MAX_FLOAT_VALUE; // Maximum float value.
		const static float CLAMP(float value, float minValue = 0, float maxValue = 1); // Clamp the value between the min and max value given as param.
		const static float MIN(float a, float b); // Get the minimum value between the 2 float's given as param.
		const static float MAX(float a, float b); // Gets the maximum value between the 2 float's given as param.
		const static float INTERPOLATE(float min, float max, float gradient); // Interpolating the value between 2 vertices. min is the starting point, max the ending point, and gradient the % between the 2 points.
		const static float COMPUTENDOTL(ZyphMaths::Vector3 position, ZyphMaths::Vector3 normal, ZyphMaths::Vector3 lightPosition); // Compute the cosine of the angle between the light vector and the normal vector.
	};
}
#endif
