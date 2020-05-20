#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#define _USE_MATH_DEFINES
#include <math.h>




TEST_CASE("describeVec2Tests", "{Vec2}")
{
	Vec2 a;
	Vec2 b{ 5.1f, -9.3f };
	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);
	REQUIRE(b.x == Approx(5.1f));
	REQUIRE(b.y == Approx(-9.3f));
}

TEST_CASE("operator +=", "{Vec2}")
{
	Vec2 a{ 5.3f , 7.2f };
	Vec2 b{ 2.0f , 3.0f };
	a += b;
	REQUIRE(a.x == Approx(7.3f));
	REQUIRE(a.y == Approx(10.2f));

}

TEST_CASE("operator -=", "{Vec2}")
{
	Vec2 a{ 5.0f , 3.0f };
	Vec2 b{ 2.0f , 1.0f };
	a -= b;
	REQUIRE(a.x == Approx(3.0f));
	REQUIRE(a.y == Approx(2.0f));
}


TEST_CASE("operator *=", "{Vec2}")
{
	Vec2 a{ 5.0f , 3.0f };
	float b = 2.0f;
	a *= b;
	REQUIRE(a.x == Approx(10.0f));
	REQUIRE(a.y == Approx(6.0f));
}


TEST_CASE("operator /=", "{Vec2}")
{
	Vec2 a{ 6.0f , 4.0f };
	float b = 2.0f;
	a /= b;
	REQUIRE(a.x == Approx(3.0f));
	REQUIRE(a.y == Approx(2.0f));
}

TEST_CASE("operator +", "{Vec2}")
{
	Vec2 a{ 6.0f , 4.0f };
	Vec2 b{ 2.0f , 3.0f };
	Vec2 c;
	c = a + b;
	REQUIRE(c.x == Approx(8.0f));
	REQUIRE(c.y == Approx(7.0f));
}

TEST_CASE("operator -", "{Vec2}")
{
	Vec2 a{ 6.0f , 4.0f };
	Vec2 b{ 3.0f , 3.0f };
	Vec2 c;
	c = a - b;
	REQUIRE(c.x == Approx(3.0f));
	REQUIRE(c.y == Approx(1.0f));
}

TEST_CASE("operator *", "{Vec2}")
{
	Vec2 a{ 6.0f , 4.0f };
	float b = 3.0f;
	Vec2 c;
	c = a * b;
	REQUIRE(c.x == Approx(18.0f));
	REQUIRE(c.y == Approx(12.0f));
}

TEST_CASE("operator /", "{Vec2}")
{
	Vec2 a{ 6.0f , 9.0f };
	float b = 3.0f;
	Vec2 c;
	c = a / b;
	REQUIRE(c.x == Approx(2.0f));
	REQUIRE(c.y == Approx(3.0f));
}

TEST_CASE("operator *_args_in_different_order", "{Vec2}")
{
	Vec2 a{ 6.0f , 4.0f };
	float b = 3.0f;
	Vec2 c;
	c = b * a;
	REQUIRE(c.x == Approx(18.0f));
	REQUIRE(c.y == Approx(12.0f));
}

TEST_CASE("operator *=_matrix", "{Mat2}")
{
	Mat2 s;
	Mat2 d{ 2.0f , 1.0f , 2.0f , 8.0f };
	Mat2 c{ 3.0f , 2.0f , 4.0f , 3.0f };
	s *= d;
	
	REQUIRE(s.e_00 == Approx(2.0f));
	REQUIRE(s.e_10 == Approx(1.0f));
	REQUIRE(s.e_01 == Approx(2.0f));
	REQUIRE(s.e_11 == Approx(8.0f));

	d *= c;
	REQUIRE(d.e_00 == Approx(10.0f));
	REQUIRE(d.e_10 == Approx(7.0f));
	REQUIRE(d.e_01 == Approx(38.0f));
	REQUIRE(d.e_11 == Approx(28.0f));
}

TEST_CASE("operator *_two_matrices" , "{Mat2}")
{

	Mat2 m1{ 2.0f , 3.0f , 2.0f , 1.0f };
	Mat2 m2{ 3.0f , 2.0f , 4.0f , 2.0f };
	Mat2 m3;
	m3 = m1 * m2;
	REQUIRE(m3.e_00 == Approx(18.0f));
	REQUIRE(m3.e_10 == Approx(10.0f));
	REQUIRE(m3.e_01 == Approx(10.0f));
	REQUIRE(m3.e_11 == Approx(6.0f));
}


TEST_CASE("determinant_of_matrix" , "{Mat2}")
{

	Mat2 m1{ 2.0f , 3.0f , 2.0f , 1.0f };
	REQUIRE(m1.det() == Approx(-4.0f));
}

TEST_CASE("Matrix_Vector_Multiplication", "{Mat2}")
{
	Vec2 a;
	Mat2 m1{ 2.0f , 3.0f , 2.0f , 1.0f };
	Vec2 b{ 2.0f , 3.0f };
	a = m1 * b;
	REQUIRE(a.x == Approx(13.0f));
	REQUIRE(a.y == Approx(7.0f));
}

TEST_CASE("Inverse_Matrix", "{Mat2}")
{
	Mat2 m1{ 2.0f , 3.0f , 2.0f , 1.0f };
	Mat2 m2 = inverse(m1);

	REQUIRE( m2.e_00 == Approx(-0.25f));
	REQUIRE( m2.e_01 == Approx(0.5f));
	REQUIRE( m2.e_10 == Approx(0.75f));
	REQUIRE(m2.e_11 == Approx(-0.5f));
} 

TEST_CASE("Transpose_Matrix", "{Mat2}")
{
	Mat2 m1{ 2.0f , 3.0f , 5.0f , 1.0f };
	Mat2 m2 = transpose(m1);

	REQUIRE(m2.e_00 == Approx(2.0f));
	REQUIRE(m2.e_01 == Approx(3.0f));
	REQUIRE(m2.e_10 == Approx(5.0f));
	REQUIRE(m2.e_11 == Approx(1.0f));
}

TEST_CASE("Rotation_Matrix", "{Mat2}")
{
	Mat2 x;
	float phi = M_PI; //180 degrees
	x = make_rotation_mat2(phi);
	REQUIRE(x.e_00 == Approx(-0.59846f));
	REQUIRE(x.e_10 == Approx(0.80115f));
	REQUIRE(x.e_01 == Approx(-0.80115f));
	REQUIRE(x.e_11 == Approx(-0.59846f));
}







int main(int argc, char *argv[])
{

  return Catch::Session().run(argc, argv);
}
