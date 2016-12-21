#include "Matrix4x4.h"
#include <math.h>

namespace ZyphMaths
{
	
	const Matrix4x4 Matrix4x4::IDENTITY = Matrix4x4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);


	/// <summary> Default constructor, creates a identity matrix</summary>
	Matrix4x4::Matrix4x4()
	{
			mValues[0] = 1, mValues[1] = 0, mValues[2] = 0, mValues[3] = 0,
			mValues[4] = 0, mValues[5] = 1, mValues[6] = 0, mValues[7] = 0,
			mValues[8] = 0, mValues[9] = 0, mValues[10] = 1, mValues[11] = 0,
			mValues[12] = 0, mValues[13] = 0, mValues[14] = 0, mValues[15] = 1;
	}

	/// <summary> Constructor, creates a matrix with the values given as param</summary>
	Matrix4x4::Matrix4x4(const float values[16])
	{
			mValues[0] = values[0], mValues[1] = values[1], mValues[2] = values[2], mValues[3] = values[3],
			mValues[4] = values[4], mValues[5] = values[5], mValues[6] = values[6], mValues[7] = values[7],
			mValues[8] = values[8], mValues[9] = values[9], mValues[10] = values[10], mValues[11] = values[11],
			mValues[12] = values[12], mValues[13] = values[13], mValues[14] = values[14], mValues[15] = values[15];
	}

	/// <summary> Constructor, creates a matrix with the values given as param</summary>
	Matrix4x4::Matrix4x4(float xx, float xy, float xz, float xw,
						 float yx, float yy, float yz, float yw,
						 float zx, float zy, float zz, float zw,
						 float wx, float wy, float wz, float ww)
	{
			mValues[0] = xx, mValues[1] = xy, mValues[2] = xz, mValues[3] = xw,
			mValues[4] = yx, mValues[5] = yy, mValues[6] = yz, mValues[7] = yw,
			mValues[8] = zx, mValues[9] = zy, mValues[10] = zz, mValues[11] = zw,
			mValues[12] = wx, mValues[13] = wy, mValues[14] = wz, mValues[15] = ww;
	}


	/// <summary> Destructor.</summary>
	Matrix4x4::~Matrix4x4()
	{
	}
	
	Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &matrix) const
	{
		return Matrix4x4(mValues[0] - matrix[0], mValues[1] - matrix[1], mValues[2] - matrix[2], mValues[3] - matrix[3],
					     mValues[4] - matrix[4], mValues[5] - matrix[5], mValues[6] - matrix[6], mValues[7] - matrix[7],
						 mValues[8] - matrix[8], mValues[9] - matrix[9], mValues[10] - matrix[10], mValues[11] - matrix[11],
						 mValues[12] - matrix[12], mValues[13] - matrix[13], mValues[14] - matrix[14], mValues[15] - matrix[15]);
	}


	Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &matrix)
	{
		return Matrix4x4(-matrix[0], -matrix[1], -matrix[2], -matrix[3],
					     -matrix[4], -matrix[5], -matrix[6], -matrix[7],
						 -matrix[8], -matrix[9], -matrix[10], -matrix[11],
						 -matrix[12], -matrix[13], -matrix[14], -matrix[15]);
	}


	Matrix4x4& Matrix4x4::operator-=(const Matrix4x4 &matrix)
	{
		mValues[0] -= matrix[0];    mValues[1] -= matrix[1];    mValues[2] -= matrix[2];    mValues[3] -= matrix[3];
		mValues[4] -= matrix[4];    mValues[5] -= matrix[5];    mValues[6] -= matrix[6];    mValues[7] -= matrix[7];
		mValues[8] -= matrix[8];    mValues[9] -= matrix[9];    mValues[10] -= matrix[10];  mValues[11] -= matrix[11];
		mValues[12] -= matrix[12];  mValues[13] -= matrix[13];  mValues[14] -= matrix[14];  mValues[15] -= matrix[15];

		return *this;
	}

	Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &matrix) const
	{
		return Matrix4x4(mValues[0] + matrix[0], mValues[1] + matrix[1], mValues[2] + matrix[2], mValues[3] + matrix[3],
						 mValues[4] + matrix[4], mValues[5] + matrix[5], mValues[6] + matrix[6], mValues[7] + matrix[7],
						 mValues[8] + matrix[8], mValues[9] + matrix[9], mValues[10] + matrix[10], mValues[11] + matrix[11],
						 mValues[12] + matrix[12], mValues[13] + matrix[13], mValues[14] + matrix[14], mValues[15] + matrix[15]);
	}

	Matrix4x4& Matrix4x4::operator+=(const Matrix4x4 &matrix)
	{
		mValues[0] += matrix[0];    mValues[1] += matrix[1];    mValues[2] += matrix[2];    mValues[3] += matrix[3];
		mValues[4] += matrix[4];    mValues[5] += matrix[5];    mValues[6] += matrix[6];    mValues[7] += matrix[7];
		mValues[8] += matrix[8];    mValues[9] += matrix[9];    mValues[10] += matrix[10];  mValues[11] += matrix[11];
		mValues[12] += matrix[12];  mValues[13] += matrix[13];  mValues[14] += matrix[14];  mValues[15] += matrix[15];

		return *this;
	}

	Vector4 Matrix4x4::operator*(const Vector4 &vec) const
	{
		return Vector4(mValues[0] * vec.x + mValues[1] * vec.y + mValues[2] * vec.z + mValues[3] * vec.w,
					   mValues[4] * vec.x + mValues[5] * vec.y + mValues[6] * vec.z + mValues[7] * vec.w,
					   mValues[8] * vec.x + mValues[9] * vec.y + mValues[10] * vec.z + mValues[11] * vec.w,
					   mValues[12] * vec.x + mValues[13] * vec.y + mValues[14] * vec.z + mValues[15] * vec.w);
	}

	Vector3 Matrix4x4::operator*(const Vector3 &vec) const
	{
		return Vector3(mValues[0] * vec.x + mValues[1] * vec.y + mValues[2] * vec.z,
					   mValues[4] * vec.x + mValues[5] * vec.y + mValues[6] * vec.z,
					   mValues[8] * vec.x + mValues[9] * vec.y + mValues[10] * vec.z);
	}

	Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &matrix) const
	{
		return Matrix4x4(mValues[0] * matrix[0] + mValues[1] * matrix[4] + mValues[2] * matrix[8] + mValues[3] * matrix[12],
						 mValues[0] * matrix[1] + mValues[1] * matrix[5] + mValues[2] * matrix[9] + mValues[3] * matrix[13],
						 mValues[0] * matrix[2] + mValues[1] * matrix[6] + mValues[2] * matrix[10] + mValues[3] * matrix[14],
						 mValues[0] * matrix[3] + mValues[1] * matrix[7] + mValues[2] * matrix[11] + mValues[3] * matrix[15],
						 mValues[4] * matrix[0] + mValues[5] * matrix[4] + mValues[6] * matrix[8] + mValues[7] * matrix[12],
						 mValues[4] * matrix[1] + mValues[5] * matrix[5] + mValues[6] * matrix[9] + mValues[7] * matrix[13],
						 mValues[4] * matrix[2] + mValues[5] * matrix[6] + mValues[6] * matrix[10] + mValues[7] * matrix[14],
						 mValues[4] * matrix[3] + mValues[5] * matrix[7] + mValues[6] * matrix[11] + mValues[7] * matrix[15],
						 mValues[8] * matrix[0] + mValues[9] * matrix[4] + mValues[10] * matrix[8] + mValues[11] * matrix[12],
						 mValues[8] * matrix[1] + mValues[9] * matrix[5] + mValues[10] * matrix[9] + mValues[11] * matrix[13],
						 mValues[8] * matrix[2] + mValues[9] * matrix[6] + mValues[10] * matrix[10] + mValues[11] * matrix[14],
						 mValues[8] * matrix[3] + mValues[9] * matrix[7] + mValues[10] * matrix[11] + mValues[11] * matrix[15],
						 mValues[12] * matrix[0] + mValues[13] * matrix[4] + mValues[14] * matrix[8] + mValues[15] * matrix[12],
						 mValues[12] * matrix[1] + mValues[13] * matrix[5] + mValues[14] * matrix[9] + mValues[15] * matrix[13],
						 mValues[12] * matrix[2] + mValues[13] * matrix[6] + mValues[14] * matrix[10] + mValues[15] * matrix[14],
						 mValues[12] * matrix[3] + mValues[13] * matrix[7] + mValues[14] * matrix[11] + mValues[15] * matrix[15]);
	}

	Matrix4x4& Matrix4x4::operator*=(const Matrix4x4 &matrix)
	{
		*this = *this * matrix;
		return *this;
	}

	bool Matrix4x4::operator==(const Matrix4x4 &matrix) const
	{
		return (mValues[0] == matrix[0]) && (mValues[1] == matrix[1]) && (mValues[2] == matrix[2]) && (mValues[3] == matrix[3]) &&
			   (mValues[4] == matrix[4]) && (mValues[5] == matrix[5]) && (mValues[6] == matrix[6]) && (mValues[7] == matrix[7]) &&
			   (mValues[8] == matrix[8]) && (mValues[9] == matrix[9]) && (mValues[10] == matrix[10]) && (mValues[11] == matrix[11]) &&
			   (mValues[12] == matrix[12]) && (mValues[13] == matrix[13]) && (mValues[14] == matrix[14]) && (mValues[15] == matrix[15]);
	}

	bool Matrix4x4::operator!=(const Matrix4x4 &matrix) const
	{
		return (mValues[0] != matrix[0]) || (mValues[1] != matrix[1]) || (mValues[2] != matrix[2]) || (mValues[3] != matrix[3]) ||
			   (mValues[4] != matrix[4]) || (mValues[5] != matrix[5]) || (mValues[6] != matrix[6]) || (mValues[7] != matrix[7]) ||
			   (mValues[8] != matrix[8]) || (mValues[9] != matrix[9]) || (mValues[10] != matrix[10]) || (mValues[11] != matrix[11]) ||
			   (mValues[12] != matrix[12]) || (mValues[13] != matrix[13]) || (mValues[14] != matrix[14]) || (mValues[15] != matrix[15]);
	}

	float Matrix4x4::operator[](int index) const
	{
		return mValues[index];
	}

	float& Matrix4x4::operator[](int index)
	{
		return mValues[index];
	}

	/// <summary> Creates a left handed look at matrix using the position, target and upVector as input.</summary>
	Matrix4x4 Matrix4x4::LookAtLH(Vector3 position, Vector3 target, Vector3 upVector)
	{
		Vector3 zaxis = (target - position).Normalize();
		Vector3 xaxis = Vector3((upVector.y * zaxis.z) - (upVector.z * zaxis.y), (upVector.z * zaxis.x) - (upVector.x * zaxis.z), (upVector.x * zaxis.y) - (upVector.y * zaxis.x)).Normalize();
		Vector3 yaxis = Vector3((zaxis.y * xaxis.z) - (zaxis.z * xaxis.y), (zaxis.z * xaxis.x) - (zaxis.x * xaxis.z), (zaxis.x * xaxis.y) - (zaxis.y * xaxis.x));

		float _41 = ((xaxis.x * position.x) + (xaxis.y * position.y) + (xaxis.z * position.z));
		float _42 = ((yaxis.x * position.x) + (yaxis.y * position.y) + (yaxis.z * position.z));
		float _43 = ((zaxis.x * position.x) + (zaxis.y * position.y) + (zaxis.z * position.z));
			
		return Matrix4x4(xaxis.x, yaxis.x, zaxis.x, 0,
						 xaxis.y, yaxis.y, zaxis.y, 0,
						 xaxis.z, yaxis.z, zaxis.z, 0,
						 -_41, -_42, -_43,  1);
	}

	/// <summary> Creates a matrix that uses the right handed projection perspective.</summary>
	/// <remark> Uses tanges to calculate index m11 and m22</remark>
	Matrix4x4 Matrix4x4::PerspectiveFovRH(float fieldOfView, float aspect, float zNear, float zFar)
	{
		float h = (1 / tan((fieldOfView / 2)));

		return Matrix4x4((h / aspect), 0, 0, 0,
					     0, h, 0, 0,
						 0, 0, zFar / (zNear - zFar), - 1,
						 0, 0, zNear * zFar / (zNear - zFar), 0);
	}

	/// <summary> Creates a matrix that uses the left handed projection perspective.</summary>
	/// <remark> Uses tanges to calculate index m11 and m22.</remark>
	Matrix4x4 Matrix4x4::PerspectiveFovLH(float fieldOfView, float aspect, float zNear, float zFar)
	{
		float h = (1 / tan((fieldOfView / 2)));
		return Matrix4x4((h / aspect), 0, 0, 0,
						  0, h, 0, 0,
						  0, 0, zFar / (zFar - zNear), 1,
						  0, 0, zNear * -(zFar / (zFar - zNear)), 0);
	}


	/// <summary> Rotates the maxtrix by transforming the z(roll) x(pitch) and y(yaw) relative to the objects local coordinates axis.</summary>
	/// <remark> Order of rotation roll -> pitch -> yaw </remark>
	Matrix4x4 Matrix4x4::RotationYawPitchRoll(float yaw, float pitch, float roll)
	{
		return Matrix4x4(RotateZ(roll) * RotateX(pitch) * RotateY(yaw));
	}

	/// <summary> Creates a matrix using the specified position offset given as param.</summary>
	Matrix4x4 Matrix4x4::Translation(Vector3 position)
	{
	    return Matrix4x4(1, 0, 0, 0,
						 0, 1, 0, 0,
						 0, 0, 1, 0,
						 position.x, position.y, position.z, 1);
	}

	/// <summary> Rotates the matrix over the x axis.</summary>
	/// <remark> Uses cos(index m22, m33) and sin(m23, m32) to rotate the matrix on the x axis. </remark>
	Matrix4x4 Matrix4x4::RotateX(float pitch)
	{
		return Matrix4x4(1, 0, 0, 0,
						 0, cos(pitch), sin(pitch), 0,
						 0, -sin(pitch), cos(pitch), 0,
						 0, 0, 0, 1);
	}

	/// <summary> Rotates the matrix over the y axis.</summary>
	/// <remark> Uses cos(index m11, m33) and sin(m13, m31) to rotate the matrix on the y axis.</remark>
	Matrix4x4 Matrix4x4::RotateY(float yaw)
	{
		return Matrix4x4(cos(yaw), 0, -sin(yaw), 0,
						 0, 1, 0, 0,
						 sin(yaw), 0, cos(yaw), 0,
					     0, 0, 0, 1);
	}

	/// <summary> Rotates the matrix over the z axis.</summary>
	/// <remark> Uses cos(index m11, m22) and sin(m12, m21) to rotate the matrix on the z axis.</remark>
	Matrix4x4 Matrix4x4::RotateZ(float roll)
	{
		return Matrix4x4(cos(roll), sin(roll), 0, 0,
						 -sin(roll), cos(roll), 0, 0,
						 0, 0, 1, 0,
						 0, 0, 0, 1);
	}
}