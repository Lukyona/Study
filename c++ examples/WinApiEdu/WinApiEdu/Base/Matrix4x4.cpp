#include "Matrix4x4.h"
#include  <iostream>
using namespace std;

#pragma warning (disable: 4244)


Matrix4x4::Matrix4x4()
{
	_11 = 0; _12 = 0; _13 = 0; _14 = 0;
	_21 = 0; _22 = 0; _23 = 0; _24 = 0;
	_31 = 0; _32 = 0; _33 = 0; _34 = 0;
	_41 = 0; _42 = 0; _43 = 0; _44 = 0;
}


Matrix4x4::~Matrix4x4()
{
}
Matrix4x4 Matrix4x4::operator*(float f)
{
	return Matrix4x4(_11*f, _12*f, _13*f, _14*f,
		_21*f, _22*f, _23*f, _24*f,
		_31*f, _32*f, _33*f, _34*f,
		_41*f, _42*f, _43*f, _44*f);
}
Matrix4x4 Matrix4x4::operator/(float f)
{
	return Matrix4x4(_11 / f, _12 / f, _13 / f, _14 / f,
		_21 / f, _22 / f, _23 / f, _24 / f,
		_31 / f, _32 / f, _33 / f, _34 / f,
		_41 / f, _42 / f, _43 / f, _44 / f);
}
Matrix4x4 Matrix4x4::operator+(Matrix4x4 m)
{
	return Matrix4x4(_11 + m._11, _12 + m._12, _13 + m._13, _14 + m._14,
		_21 + m._21, _22 + m._22, _23 + m._23, _24 + m._24,
		_31 + m._31, _32 + m._32, _33 + m._33, _34 + m._34,
		_41 + m._41, _42 + m._42, _43 + m._43, _44 + m._44);
}
Matrix4x4 Matrix4x4::operator-(Matrix4x4 m)
{
	return Matrix4x4(_11 - m._11, _12 - m._12, _13 - m._13, _14 - m._14,
		_21 - m._21, _22 - m._22, _23 - m._23, _24 - m._24,
		_31 - m._31, _32 - m._32, _33 - m._33, _34 - m._34,
		_41 - m._41, _42 - m._42, _43 - m._43, _44 - m._44);
}
Matrix4x4 Matrix4x4::operator * (Matrix4x4 m)
{
	return Matrix4x4(_11*m._11 + _12 * m._21 + _13 * m._31 + _14 * m._41, _11*m._12 + _12 * m._22 + _13 * m._32 + _14 * m._42, _11*m._13 + _12 * m._23 + _13 * m._33 + _14 * m._43, _11*m._14 + _12 * m._24 + _13 * m._34 + _14 * m._44,
		_21*m._11 + _22 * m._21 + _23 * m._31 + _24 * m._41, _21*m._12 + _22 * m._22 + _23 * m._32 + _24 * m._42, _21*m._13 + _22 * m._23 + _23 * m._33 + _24 * m._43, _21*m._14 + _22 * m._24 + _23 * m._34 + _24 * m._44,
		_31*m._11 + _32 * m._21 + _33 * m._31 + _34 * m._41, _31*m._12 + _32 * m._22 + _33 * m._32 + _34 * m._42, _31*m._13 + _32 * m._23 + _33 * m._33 + _34 * m._43, _31*m._14 + _32 * m._24 + _33 * m._34 + _34 * m._44,
		_41*m._11 + _42 * m._21 + _43 * m._31 + _44 * m._41, _41*m._12 + _42 * m._22 + _43 * m._32 + _44 * m._42, _41*m._13 + _42 * m._23 + _43 * m._33 + _44 * m._43, _41*m._14 + _42 * m._24 + _43 * m._34 + _44 * m._44);
}
Matrix4x4& Matrix4x4::operator += (Matrix4x4 m)
{
	_11 += m._11; _12 += m._12; _13 += m._13; _14 += m._14;
	_21 += m._21; _22 += m._22; _23 += m._23; _24 += m._24;
	_31 += m._31; _32 += m._32; _33 += m._33; _34 += m._34;
	_41 += m._41; _42 += m._42; _43 += m._43; _44 += m._44;
	return *this;
}
Matrix4x4& Matrix4x4::operator -= (Matrix4x4 m)
{
	_11 -= m._11; _12 -= m._12; _13 -= m._13; _14 -= m._14;
	_21 -= m._21; _22 -= m._22; _23 -= m._23; _24 -= m._24;
	_31 -= m._31; _32 -= m._32; _33 -= m._33; _34 -= m._34;
	_41 -= m._41; _42 -= m._42; _43 -= m._43; _44 -= m._44;
	return *this;
}
Matrix4x4 Matrix4x4::operator-()
{
	return Matrix4x4(-_11, -_12, -_13, -_14,
		-_21, -_22, -_23, -_24,
		-_31, -_32, -_33, -_34,
		-_41, -_42, -_43, -_44);
}
Matrix4x4 Matrix4x4::NormalVector()
{
	return Matrix4x4(1, 0, 0, 0,
		             0, 1, 0, 0,
		             0, 0, 1, 0,
		             0, 0, 0, 1); // 1이면 위치, 0면 회전에 관함
}
Matrix4x4 Matrix4x4::Translation(float x, float y, float z)
{
	return Matrix4x4(1, 0, 0, 0,
		             0, 1, 0, 0,
		             0, 0, 1, 0,
		             x, y, z, 1); //다렉3d 땜에 바꿔놓음
}
Matrix4x4 Matrix4x4::RotationX(float angle)
{
	return Matrix4x4(1, 0, 0, 0,			// 왜 코사인, 사인이 들어갈까
					 0, cos(angle), sin(angle), 0,
					 0, -sin(angle), cos(angle), 0,
					 0, 0, 0, 1);
}
Matrix4x4 Matrix4x4::RotationY(float angle)
{
	return Matrix4x4(cos(angle), 0, -sin(angle), 0,
		0, 1, 0, 0,
		sin(angle), 0, cos(angle), 0,
		0, 0, 0, 1);
}
Matrix4x4 Matrix4x4::RotationZ(float angle)
{
	return Matrix4x4(cos(angle), sin(angle), 0, 0,
		-sin(angle), cos(angle), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}
Matrix4x4 Matrix4x4::Scale(float sx, float sy, float sz)
{
	return Matrix4x4(sx, 0, 0, 0,
		             0, sy, 0, 0,
		             0, 0, sz, 0,
		             0, 0,  0, 1);
}
Matrix4x4 Matrix4x4::LookAt(Vector3 eye, Vector3 at, Vector3 upVector)
{
	Vector3 forward = at - eye;

	forward.Normalized(&forward);

	Vector3 side;
	side = side.Cross(upVector, forward);
	side.Normalized(&side);

	Vector3 up;
	up = up.Cross(forward, side);

	Vector3 pos(-Vector3::Dot(eye, side), 
		      -Vector3::Dot(eye, up),
		      -Vector3::Dot(eye, forward));

	Matrix4x4 View;

	// 행렬의 초기화

	View._11 = side.x;
	View._12 = up.x;
	View._13 = forward.x;
	View._14 = 0.0f;

	View._21 = side.y;
	View._22 = up.y;
	View._23 = forward.y;
	View._24 = 0.0f;

	View._31 = side.z;
	View._32 = up.z;
	View._33 = forward.z;
	View._34 = 0.0f;

	View._41 = pos.x;
	View._42 = pos.y;
	View._43 = pos.z;
	View._44 = 1.0f;
	return View;
}
Matrix4x4 Matrix4x4::Perspect(float fovy, float aspect, float zn, float zf)
{
	float yScale = 1 / tan(fovy / 2);
	float xScale = yScale / aspect;
	return Matrix4x4(xScale, 0, 0, 0,
		0, yScale, 0, 0,
		0, 0, zf / (zf - zn), 1,
		0, 0, -zn * zf / (zf - zn), 0);
}
////////////////////////////////////////////////////////////////
// 직교사영 Projection Matrix
///////////////////////////////////////////////////////////////
void Matrix4x4::Ortho(Matrix4x4* P,float left, float right, float bottom, float top, float farz, float nearz)
{
	float tx = -(right + left) / (right - left);
	float ty = -(top + bottom) / (top - bottom);
	float tz = -(farz + nearz) / (farz - nearz);

	P->_11 = 2.0f / (right - left);
	P->_12 = 0;
	P->_13 = 0;
	P->_14 = 0;
	P->_21 = 0;
	P->_22 = 2.0f / (top - bottom);
	P->_23 = 0;
	P->_24 = 0;
	P->_31 = 0;
	P->_32 = 0;
	P->_33 = (-2.0f) / (farz - nearz);
	P->_33 = (-2.0f) / (farz - nearz)*0.5f;
	P->_34 = 0;
	P->_41 = tx;
	P->_42 = ty;
	P->_43 = tz;
	P->_43 = (-2.0f) / (farz - nearz)*0.5f;
	P->_44 = 1;
}
Matrix4x4 Matrix4x4::Inverse()
{
	double inv[16], det;
	int i;


	inv[0] =  _22 * _33 * _44 - _22 * _34 * _43 - _32 * _23 * _44 + _32 * _24 * _43 + _42 * _23 * _34 - _42 * _24 * _33;
	inv[1] = -_12 * _33 * _44 + _12 * _34 * _43 + _32 * _13 * _44 - _32 * _14 * _43 - _42 * _13 * _34 + _42 * _14 * _33;
	inv[2] =  _12 * _23  * _44 - _12 * _24   * _43 -  _22 * _13 * _44 +_22 * _14 * _43 +_42 * _13 * _24 -_42 * _14 * _23;
	inv[3] = -_12 * _23 * _34 + _12 * _24 * _33 + _22 * _13 * _34 - _22 * _14 * _33 - _32 * _13 * _24 + _32 * _14 * _23;
	inv[4] = -_21 * _33 * _44 +_21 * _34 * _43 +_31 * _23 * _44 -_31 * _24 * _43 -_41 * _23 * _34 +_41 * _24 * _33;
	inv[5] = _11 * _33 * _44 - _11 * _34 * _43 - _31 * _13 * _44 + _31 * _14 * _43 + _41 * _13 * _34 - _41 * _14 * _33;
	inv[6] = -_11 * _23 * _44 + _11 * _24 * _43 + _21 * _13 * _44 - _21 * _14 * _43 - _41 * _13 * _24 + _41 * _14 * _23;
	inv[7] = _11 * _23 * _34 - _11 * _24 * _33 - _21 * _13 * _34 + _21 * _14 * _33 + _31 * _13 * _24 - _31 * _14 * _23;
	inv[8] = _21 * _32 * _44 -_21 * _34 * _42 -_31 * _22 * _44 +_31 * _24 * _42 +_41 * _22 * _34 -_41 * _24 * _32;
	inv[9] = -_11 * _32 * _44 + _11 * _34 * _42 + _31 * _12 * _44 - _31 * _14 * _42 - _41 * _12 * _34 + _41 * _14 * _32;
	inv[10] = _11 * _22 * _44 - _11 * _24 * _42 - _21 * _12 * _44 + _21 * _14 * _42 + _41 * _12 * _24 - _41 * _14 * _22;
	inv[11] = -_11 * _22 * _34 + _11 * _24 * _32 + _21 * _12 * _34 - _21 * _14 * _32 - _31 * _12 * _24 + _31 * _14 * _22;
	inv[12] = -_21 * _32 * _43 +_21 * _33 * _42 +_31 * _22 * _43 -_31 * _23 * _42 -_41 * _22 * _33 +_41 * _23 * _32;
	inv[13] = _11 * _32 * _43 -_11 * _33 * _42 -_31 * _12 * _43 +_31 * _13 * _42 +_41 * _12 * _33 -_41 * _13 * _32;
	inv[14] = -_11 * _22 * _43 +_11 * _23 * _42 +_21 * _12 * _43 -_21 * _13 * _42 -_41 * _12 * _23 +_41 * _13 * _22;
	inv[15] = _11 * _22 * _33 -_11 * _23 * _32 -_21 * _12 * _33 +_21 * _13 * _32 +_31 * _12 * _23 -_31 * _13 * _22;

	det = _11 * inv[0] + _12 * inv[4] + _13 * inv[8] + _14 * inv[12];

	if (det == 0)
		return NormalVector();

	det = 1.0 / det;

	float invOut[16];
	for (i = 0; i < 16; i++)
		invOut[i] = (float)(inv[i] * det);
	return Matrix4x4(invOut[0], invOut[1], invOut[2], invOut[3],
		             invOut[4], invOut[5], invOut[6], invOut[7],
		             invOut[8], invOut[9], invOut[10], invOut[11],
		             invOut[12], invOut[13], invOut[14], invOut[15]);
}
Vector3 Matrix4x4::Multiply(Vector3& v, Matrix4x4 m)
{
	float x = v.x*m._11 + v.y*m._21 + v.z*m._31 + m._41;
	float y = v.x*m._12 + v.y*m._22 + v.z*m._32 + m._42;
	float z = v.x*m._13 + v.y*m._23 + v.z*m._33 + m._43;
	float w = v.x*m._14 + v.y*m._24 + v.z*m._34 + m._44;

	return Vector3(x, y, z) / w;
}

void Matrix4x4::Out()
{

	cout <<_11 << " " << _12 << " " << _13 << " " << _14 << endl;
	cout <<_21 << " " << _22 << " " << _23 << " " << _24 << endl;
	cout <<_31 << " " << _32 << " " << _33 << " " << _34 << endl;
	cout <<_41 << " " << _42 << " " << _43 << " " << _44 << endl;
}

Matrix4x4 Matrix4x4::GetCenterMatrix(int width, int height) // 윈도우의 너비 높이
{
	Matrix4x4 S, T;

	S = Scale(1.0f, -1.0f, 0.0f);  // Flip Y, 윈도우는 Y 양수면 아래로 내려가기 때문에 -1로 
	T = Translation((float)width*0.5f, (float)height*0.5f, 0.0f);

	return S * T ; // S * T != T * S....
}

void Matrix4x4::Multiply(float & x, float & y, Matrix4x4 m)
{
	x = x*m._11 + y*m._21 + 0.0f*m._31 + m._41;
	y = x*m._12 + y*m._22 + 0.0f*m._32 + m._42;

}

Matrix4x4 Matrix4x4::Inverse2(Matrix4x4 m)
{
	double A2323 = m._33 * m._44 - m._34 * m._43;
	double A1323 = m._32 * m._44 - m._34 * m._42;
	double A1223 = m._32 * m._43 - m._33 * m._42;
	double A0323 = m._31 * m._44 - m._34 * m._41;
	double A0223 = m._31 * m._43 - m._33 * m._41;
	double A0123 = m._31 * m._42 - m._32 * m._41;
	double A2313 = m._23 * m._44 - m._24 * m._43;
	double A1313 = m._22 * m._44 - m._24 * m._42;
	double A1213 = m._22 * m._43 - m._23 * m._42;
	double A2312 = m._23 * m._34 - m._24 * m._33;
	double A1312 = m._22 * m._34 - m._24 * m._32;
	double A1212 = m._22 * m._33 - m._23 * m._32;
	double A0313 = m._21 * m._44 - m._24 * m._41;
	double A0213 = m._21 * m._43 - m._23 * m._41;
	double A0312 = m._21 * m._34 - m._24 * m._31;
	double A0212 = m._21 * m._33 - m._23 * m._31;
	double A0113 = m._21 * m._42 - m._22 * m._41;
	double A0112 = m._21 * m._32 - m._22 * m._31;

	double det = m._11 * (m._22 * A2323 - m._23 * A1323 + m._24 * A1223)
		- m._12 * (m._21 * A2323 - m._23 * A0323 + m._24 * A0223)
		+ m._13 * (m._21 * A1323 - m._22 * A0323 + m._24 * A0123)
		- m._14 * (m._21 * A1223 - m._22 * A0223 + m._23 * A0123);
	det = 1 / det;


	float m11 = det * (m._22 * A2323 - m._23 * A1323 + m._24 * A1223);
	float m12 = det * -(m._12 * A2323 - m._13 * A1323 + m._14 * A1223);
	float m13 = det * (m._12 * A2313 - m._13 * A1313 + m._14 * A1213);
	float m14 = det * -(m._12 * A2312 - m._13 * A1312 + m._14 * A1212);
	float m21 = det * -(m._21 * A2323 - m._23 * A0323 + m._24 * A0223);
	float m22 = det * (m._11 * A2323 - m._13 * A0323 + m._14 * A0223);
	float m23 = det * -(m._11 * A2313 - m._13 * A0313 + m._14 * A0213);
	float m24 = det * (m._11 * A2312 - m._13 * A0312 + m._14 * A0212);
	float m31 = det * (m._21 * A1323 - m._22 * A0323 + m._24 * A0123);
	float m32 = det * -(m._11 * A1323 - m._12 * A0323 + m._14 * A0123);
	float m33 = det * (m._11 * A1313 - m._12 * A0313 + m._14 * A0113);
	float m34 = det * -(m._11 * A1312 - m._12 * A0312 + m._14 * A0112);
	float m41 = det * -(m._21 * A1223 - m._22 * A0223 + m._23 * A0123);
	float m42 = det * (m._11 * A1223 - m._12 * A0223 + m._13 * A0123);
	float m43 = det * -(m._11 * A1213 - m._12 * A0213 + m._13 * A0113);
	float m44 = det * (m._11 * A1212 - m._12 * A0212 + m._13 * A0112);



	return Matrix4x4(m11, m21, m31, m41,
		             m12, m22, m32, m42,
		             m13, m23, m33, m43,
		             m14, m24, m34, m44);
}