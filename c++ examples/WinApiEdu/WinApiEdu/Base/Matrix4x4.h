#pragma once
#include <math.h>
#include <algorithm>
class Vector3
{
public:
	float x, y, z;
public:
	Vector3() { x = 0; y = 0; z = 0; };
	Vector3(float xx) { x = xx; y = xx; z = xx; };
	Vector3(float xx, float yy, float zz) { x = xx; y = yy; z = zz; };
	~Vector3() {};
	float lengthSq() { return x * x + y * y + z * z; };
	float length() { return (float)sqrt(lengthSq()); };
	Vector3 operator * (float f)
	{
		return Vector3(x*f, y*f, z*f);
	}
	Vector3 operator / (float f)
	{
		return Vector3(x / f, y / f, z / f);
	}
	Vector3 operator + (Vector3 v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}
	Vector3 operator - (Vector3 v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}
	Vector3& operator += (Vector3 v)
	{
		x += v.x, y += v.y, z += v.z; return *this;
	}
	Vector3& operator -= (Vector3 v)
	{
		x -= v.x, y -= v.y, z -= v.z; return *this;
	}
	Vector3 operator - ()
	{
		return Vector3(-x, -y, -z);
	}

static 	float Dot(Vector3& v1, Vector3& v2)
	{
		return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
	}
	Vector3 Cross(Vector3& v1, Vector3& v2)
	{
		return Vector3(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
	}
	Vector3 Normalized(Vector3 *v)
	{
		float magSq = v->lengthSq();

		return magSq > 0 ? *v / sqrt(magSq) : Vector3();
	}
};
class Matrix4x4
{
public:
	float _11, _12, _13, _14;
	float _21, _22, _23, _24;
	float _31, _32, _33, _34;
	float _41, _42, _43, _44;

public:
	Matrix4x4();
	~Matrix4x4();
	Matrix4x4(float i_11, float i_12, float i_13, float i_14,
		float i_21, float i_22, float i_23, float i_24,
		float i_31, float i_32, float i_33, float i_34,
		float i_41, float i_42, float i_43, float i_44)
	{
		_11 = i_11; _12 = i_12; _13 = i_13; _14 = i_14;
		_21 = i_21; _22 = i_22; _23 = i_23; _24 = i_24;
		_31 = i_31; _32 = i_32; _33 = i_33; _34 = i_34;
		_41 = i_41; _42 = i_42; _43 = i_43; _44 = i_44;
	};
	Matrix4x4  operator*(float f);
	Matrix4x4  operator/(float f);
	Matrix4x4  operator+(Matrix4x4 m);
	Matrix4x4  operator-(Matrix4x4 m);
	Matrix4x4  operator*(Matrix4x4 m);
	Matrix4x4& operator += (Matrix4x4 m);
	Matrix4x4& operator -= (Matrix4x4 m);
	Matrix4x4  operator-();
	static     Matrix4x4  NormalVector();
	static     Matrix4x4  Translation(float x, float y, float z);
	static     Matrix4x4  RotationX(float angle);
	static     Matrix4x4  RotationY(float angle);
	static     Matrix4x4  RotationZ(float angle);
	static     Matrix4x4  Scale(float sx, float sy, float sz);
	static     Matrix4x4  LookAt(Vector3 eye, Vector3 at, Vector3 up);
	static     Matrix4x4  Perspect(float fovy, float aspect, float zn, float zf);
	static     void       Ortho(Matrix4x4* P, float left, float right, float bottom, float top,  float farz, float nearz);
	Matrix4x4  Inverse();
	Matrix4x4  Inverse2(Matrix4x4 m);
	Vector3    Multiply(Vector3& v, Matrix4x4 m);
    void       Out();
	static     Matrix4x4  GetCenterMatrix(int width, int height);
	static     void  Multiply(float& x, float& y, Matrix4x4 m);
};

