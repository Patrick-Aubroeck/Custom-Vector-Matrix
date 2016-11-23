#include "pch.h"
#include "CppUnitTest.h"
#include "Vector3.h"
#include "Matrix4x4.h"
#include <d3d11.h>
#include <directxmath.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsZyphMath
{
	TEST_CLASS(vector3test)
	{
	public:
		TEST_METHOD(TransformCoordinate)
		{
			DirectX::XMVECTOR coords = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
			DirectX::XMMATRIX identityMatrix = DirectX::XMMatrixIdentity();
			DirectX::XMVECTOR result = DirectX::XMVector3TransformCoord(coords, identityMatrix);

			ZyphMaths::Vector3 zyphCoords = ZyphMaths::Vector3(0.0f, 0.0f, 0.0f);
			ZyphMaths::Matrix4x4 zyphIdentityMatrix = ZyphMaths::Matrix4x4::IDENTITY;
			ZyphMaths::Vector3 zyphResult = ZyphMaths::Vector3::TransformCoordinate(zyphCoords, zyphIdentityMatrix);

			Assert::IsTrue(compareXMVectorAndZyphVector(result, zyphResult));
		}

		TEST_METHOD(Normalize)
		{
			DirectX::XMVECTOR defaultVector = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
			DirectX::XMVECTOR result = DirectX::XMVector3Normalize(defaultVector);

			ZyphMaths::Vector3 zyphResult = ZyphMaths::Vector3::ZERO;
			zyphResult = zyphResult.Normalize();

			Assert::IsTrue(compareXMVectorAndZyphVector(result, zyphResult));
		}

		TEST_METHOD(TransformNormal)
		{
			DirectX::XMVECTOR vec1 = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
			DirectX::XMMATRIX identityMatrix = DirectX::XMMatrixIdentity();
			DirectX::XMVECTOR result = DirectX::XMVector3TransformNormal(vec1, identityMatrix);

			ZyphMaths::Vector3 zyphvec1 = ZyphMaths::Vector3(0.0f, 0.0f, 0.0f);
			ZyphMaths::Matrix4x4 zyphIdentityMatrix = ZyphMaths::Matrix4x4::IDENTITY;
			ZyphMaths::Vector3 zyphResult = ZyphMaths::Vector3::TransformNormal(zyphvec1, zyphIdentityMatrix);

			Assert::IsTrue(compareXMVectorAndZyphVector(result, zyphResult));
		}

		TEST_METHOD(Dot)
		{
			DirectX::XMVECTOR vec1 = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
			DirectX::XMVECTOR vec2 = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
			DirectX::XMVECTOR result = DirectX::XMVector3Dot(vec1, vec2);

			ZyphMaths::Vector3 zyphvec1 = ZyphMaths::Vector3(0.0f, 0.0f, 0.0f);
			ZyphMaths::Vector3 zyphvec2 = ZyphMaths::Vector3(0.0f, 0.0f, 0.0f);
			ZyphMaths::Vector3 zyphResult = ZyphMaths::Vector3::Dot(zyphvec1, zyphvec2);

			Assert::IsTrue(compareXMVectorAndZyphVector(result, zyphResult));
		}

		bool compareXMVectorAndZyphVector(DirectX::XMVECTOR vector, ZyphMaths::Vector3 zyphVector)
		{
			if (!approximatelyEqual(vector.m128_f32[0], zyphVector.x, 0.00001f))
				return false;
			if (!approximatelyEqual(vector.m128_f32[1], zyphVector.y, 0.00001f))
				return false;
			if (!approximatelyEqual(vector.m128_f32[2], zyphVector.z, 0.00001f))
				return false;
			else
				return true;
		}

		bool approximatelyEqual(float a, float b, float epsilon)
		{
			return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
		}
	};
}