#include "pch.h"
#include "CppUnitTest.h"
#include "Matrix4x4.h"
#include <d3d11.h>
#include <directxmath.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsZyphMath
{
	TEST_CLASS(matrix4x4test)
    {
    public:
		
        TEST_METHOD(LookAtLH)
        {
			 DirectX::XMVECTOR lookat = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
			 DirectX::XMVECTOR cameraPos = DirectX::XMVectorSet(0.0f, 0.0f, 10.0f, 1.0f);
			 DirectX::XMMATRIX matrix = DirectX::XMMatrixLookAtLH(cameraPos, lookat, DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 1.0f));

			 DirectX::XMFLOAT4X4 xmfloat4x4;
			 DirectX::XMStoreFloat4x4(&xmfloat4x4, matrix);

			 ZyphMaths::Vector3 zyphLookat = ZyphMaths::Vector3::ZERO;
			 ZyphMaths::Vector3 zyphCameraPos = ZyphMaths::Vector3(0.0f, 0.0f, 10.0f);
			 ZyphMaths::Matrix4x4 zyphMatrix = ZyphMaths::Matrix4x4::LookAtLH(zyphCameraPos, zyphLookat, ZyphMaths::Vector3::UPVECTOR);

			 Assert::IsTrue(compareXMMatrixAndZyphMatrix(xmfloat4x4, zyphMatrix));
        }

		TEST_METHOD(PerspectiveFovRH)
		{
			float angle = 0.78f;
			float aspect = 100.0f;
			float Znear = 0.01f; 
			float zFar = 1.0f;

			DirectX::XMMATRIX matrix = DirectX::XMMatrixPerspectiveFovRH(angle, aspect, Znear, zFar);
			DirectX::XMFLOAT4X4 xmfloat4x4;
			DirectX::XMStoreFloat4x4(&xmfloat4x4, matrix);

			ZyphMaths::Matrix4x4 zyphMatrix = ZyphMaths::Matrix4x4::PerspectiveFovRH(angle, aspect, Znear, zFar);

			Assert::IsTrue(compareXMMatrixAndZyphMatrix(xmfloat4x4, zyphMatrix));
		}

		TEST_METHOD(Translation)
		{
			DirectX::XMMATRIX matrix = DirectX::XMMatrixTranslation(11.0f, 1.0f, 0.0f);
			DirectX::XMFLOAT4X4 xmfloat4x4;
			DirectX::XMStoreFloat4x4(&xmfloat4x4, matrix);


			ZyphMaths::Vector3 position = ZyphMaths::Vector3(11.0f, 1.0f, 0.0f);

			ZyphMaths::Matrix4x4 zyphMatrix = ZyphMaths::Matrix4x4::Translation(position);

			Assert::IsTrue(compareXMMatrixAndZyphMatrix(xmfloat4x4, zyphMatrix));
		}

		TEST_METHOD(Multiply)
		{
			DirectX::XMMATRIX multiplyMatrix = DirectX::XMMATRIX(10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f, 17.0f, 18.0f, 19.0f, 18.0f, 17.0f, 16.0f, 15.0f, 14.0f, 13.0f);
			DirectX::XMMATRIX multiplyMatrix2 = DirectX::XMMATRIX(20.0f, 21.0f, 22.0f, 23.0f, 24.0f, 25.0f, 26.0f, 27.0f, 28.0f, 29.0f, 28.0f, 27.0f, 26.0f, 25.0f, 24.0f, 23.0f);
			DirectX::XMMATRIX matrix = multiplyMatrix * multiplyMatrix2;

			DirectX::XMFLOAT4X4 xmfloat4x4;
			DirectX::XMStoreFloat4x4(&xmfloat4x4, matrix);

			ZyphMaths::Matrix4x4 zyphMultiplyMatrix = ZyphMaths::Matrix4x4(10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f, 17.0f, 18.0f, 19.0f, 18.0f, 17.0f, 16.0f, 15.0f, 14.0f, 13.0f);
			ZyphMaths::Matrix4x4 zyphMultiplyMatrix2 = ZyphMaths::Matrix4x4(20.0f, 21.0f, 22.0f, 23.0f, 24.0f, 25.0f, 26.0f, 27.0f, 28.0f, 29.0f, 28.0f, 27.0f, 26.0f, 25.0f, 24.0f, 23.0f);

			ZyphMaths::Matrix4x4 zyphMatrix = zyphMultiplyMatrix * zyphMultiplyMatrix2;

			Assert::IsTrue(compareXMMatrixAndZyphMatrix(xmfloat4x4, zyphMatrix));
		}
		TEST_METHOD(PerspectiveFovLH)
		{
			float angle = 0.78f;
			float aspect = 100.0f;
			float Znear = 0.01f;
			float zFar = 1.0f;

			DirectX::XMMATRIX matrix = DirectX::XMMatrixPerspectiveFovLH(angle, aspect, Znear, zFar);
			DirectX::XMFLOAT4X4 xmfloat4x4;
			DirectX::XMStoreFloat4x4(&xmfloat4x4, matrix);

			ZyphMaths::Matrix4x4 zyphMatrix = ZyphMaths::Matrix4x4::PerspectiveFovLH(angle, aspect, Znear, zFar);

			Assert::IsTrue(compareXMMatrixAndZyphMatrix(xmfloat4x4, zyphMatrix));
		}

		TEST_METHOD(RotationYawPitchRoll)
		{
			float pitch = 0.1f;
			float yaw = 0.1f;
			float roll = 0.1f;

			DirectX::XMMATRIX matrix = DirectX::XMMatrixRotationRollPitchYaw(pitch, yaw, roll);
			DirectX::XMFLOAT4X4 xmfloat4x4;
			DirectX::XMStoreFloat4x4(&xmfloat4x4, matrix);

			ZyphMaths::Matrix4x4 zyphMatrix = ZyphMaths::Matrix4x4::RotationYawPitchRoll(yaw, pitch, roll);

			Assert::IsTrue(compareXMMatrixAndZyphMatrix(xmfloat4x4, zyphMatrix));
		}

		TEST_METHOD(RotateX)
		{
			float pitch = 0.1f;

			DirectX::XMMATRIX matrix = DirectX::XMMatrixRotationX(pitch);
			DirectX::XMFLOAT4X4 xmfloat4x4;
			DirectX::XMStoreFloat4x4(&xmfloat4x4, matrix);

			ZyphMaths::Matrix4x4 zyphMatrix = ZyphMaths::Matrix4x4::RotateX(pitch);

			Assert::IsTrue(compareXMMatrixAndZyphMatrix(xmfloat4x4, zyphMatrix));
		}

		TEST_METHOD(RotateY)
		{
			float yaw = 0.1f;

			DirectX::XMMATRIX matrix = DirectX::XMMatrixRotationY(yaw);
			DirectX::XMFLOAT4X4 xmfloat4x4;
			DirectX::XMStoreFloat4x4(&xmfloat4x4, matrix);

			ZyphMaths::Matrix4x4 zyphMatrix = ZyphMaths::Matrix4x4::RotateY(yaw);

			Assert::IsTrue(compareXMMatrixAndZyphMatrix(xmfloat4x4, zyphMatrix));
		}

		TEST_METHOD(RotateZ)
		{
			float roll = 0.1f;

			DirectX::XMMATRIX matrix = DirectX::XMMatrixRotationZ(roll);
			DirectX::XMFLOAT4X4 xmfloat4x4;
			DirectX::XMStoreFloat4x4(&xmfloat4x4, matrix);

			ZyphMaths::Matrix4x4 zyphMatrix = ZyphMaths::Matrix4x4::RotateZ(roll);

			Assert::IsTrue(compareXMMatrixAndZyphMatrix(xmfloat4x4, zyphMatrix));
		}

		bool compareXMMatrixAndZyphMatrix(DirectX::XMFLOAT4X4 xmfloat4x4, ZyphMaths::Matrix4x4 zyphMatrix)
		{
			bool result = true;
			int index = 0;
			for (size_t i = 0; i < 4; i++)
			{
				for (size_t j = 0;  j < 4;  j++)
				{
					//0.00001f epsilon value (float value 6 accuracy).
					result = approximatelyEqual(xmfloat4x4.m[i][j], zyphMatrix.mValues[index + j], 0.00001f);
					if (!result)
					{
						return result;
					}
				}
				index += 4;
			}
			return result;
		}

		bool approximatelyEqual(float a, float b, float epsilon)
		{
			return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
		}

    };
}