#include"vec2.hpp"

Vec2& Vec2::operator+=(Vec2 const& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2& Vec2::operator*=(float s)
{
    x *= s;
    y *= s;
    return *this;
}

Vec2& Vec2::operator/=(float s)
{  
    x /= s;
    y /= s;
    return *this;
}


Vec2 operator+(Vec2 const& u, Vec2 const& v)
{
    Vec2 c;
    c.x = u.x + v.x;
    c.y = u.y + v.y;
    return c;
}

Vec2 operator-(Vec2 const& u, Vec2 const& v)
{
    Vec2 c;
    c.x = u.x - v.x;
    c.y = u.y - v.y;
    return c;
}

Vec2 operator*(Vec2 const& v, float s)
{
    Vec2 c;
    c.x = v.x * s;
    c.y = v.y * s;
    return c;
}

Vec2 operator/(Vec2 const& v, float s)
{
    Vec2 c;
    c.x = v.x / s;
    c.y = v.y / s;
    return c;
}

Vec2 operator*(float s, Vec2 const& v)
{
    Vec2 c;
    c.x = v.x * s;
    c.y = v.y * s;
    return c;
}
