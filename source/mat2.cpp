#include "mat2.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

Mat2& Mat2::operator*=(Mat2 const& m)
{
	Mat2 temp = *this;

	e_00 = temp.e_00 * m.e_00 + temp.e_10 * m.e_01;
	e_10 = temp.e_00 * m.e_10 + temp.e_10 * m.e_11;
	e_01 = temp.e_01 * m.e_00 + temp.e_11 * m.e_01;
	e_11 = temp.e_01 * m.e_10 + temp.e_11 * m.e_11;

	return temp;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2)
{
	Mat2 temp{ m1 };
	temp *= m2;

	return temp;
}

float Mat2::det() const
{
	return e_00 * e_11 - e_10 * e_01;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v)
{
	Vec2 Vec;
	Vec.x = m.e_00 * v.x + m.e_10 * v.y;
	Vec.y = m.e_01 * v.x + m.e_11 * v.y;

	return Vec;
}

Mat2 inverse(Mat2 const& m)
{
	Mat2 temp;
	temp.e_00 =   m.e_11 * 1 / m.det();
	temp.e_10 = - m.e_10 * 1 / m.det();
	temp.e_01 = - m.e_01 * 1 / m.det();
	temp.e_11 =   m.e_00 * 1 / m.det();

	return temp;
}

Mat2 transpose(Mat2 const& m)
{
	Mat2 temp;
	temp.e_00 = m.e_00;
	temp.e_10 = m.e_01;
	temp.e_01 = m.e_10;
	temp.e_11 = m.e_11;
	return temp;
}

Mat2 make_rotation_mat2(float phi)
{
	Mat2 rotation_mat;
	float degree = phi * (180 / M_PI);
	rotation_mat.e_00 = cos(degree);
	rotation_mat.e_10 = -sin(degree);
	rotation_mat.e_01 = sin(degree);
	rotation_mat.e_11 = cos(degree);
	return rotation_mat;
}