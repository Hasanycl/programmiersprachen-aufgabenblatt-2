#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

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

int main(int argc, char *argv[])
{

  return Catch::Session().run(argc, argv);
}
