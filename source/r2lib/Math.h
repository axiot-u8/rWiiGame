#ifndef _R2LIB_MATH_H
#define _R2LIB_MATH_H

#include "grrlib.h"
#include <math.h>

#define LERP(a, b, t) (a + t * (b - a))

namespace r2lib {
namespace math {
/// @brief Clamps v to a minimum and a maximum value
template <class T>
inline const T& clamp(const T& v, const T& lo, const T& hi)
{
	return std::min(std::max(v, lo), hi);
}

/// @brief Loops v to be within the range (0, l)
template <class T>
inline const T& repeat(const T& v, const T& length)
{
	return clamp(v - floor(v / length) * length, 0.0f, length);
}

/// @brief Calculates the closest difference between current angle and target (degrees)
/// @param current current angle in degrees
/// @param target  target angle in degrees
template <class T>
inline const T deltaAngle(const T& current, const T& target)
{
	const T input = (target - current);

	// TODO: Check if quicker variant
	// repeat((target - current), 360.0f); Without 'if (delta < 0) delta += 360'
	T delta = input - ((int)(input / 360.0f)) * 360.0f;
	if (delta < 0) {
		delta += 360.0f;
	}

	if (delta > 180.0f) {
		delta -= 360.0f;
	}

	return delta;
}

/// @brief Returns the sign of v
inline const s32 sign(f32 v) { return v >= 0 ? 1 : -1; }

inline const f32 moveTowards(f32 cur, f32 dest, f32 t)
{
	if (abs(dest - cur) <= t) {
		return t;
	}

	return cur + sign(dest - cur) * t;
}
inline const f32 moveTowardsAngle(f32 cur, f32 dest, f32 maxDelta)
{
	f32 deltaAng = deltaAngle(cur, dest);
	if (-maxDelta < deltaAng && deltaAng < maxDelta) {
		return dest;
	}

	return moveTowards(cur, cur + deltaAng, maxDelta);
}

inline const f32 rand_float(f32 range) { return ((float)rand() / (float)(RAND_MAX)) * range; }
} // namespace math

struct Vector3 {
	Vector3(f32 pX, f32 pY, f32 pZ)
	    : x(pX)
	    , y(pY)
	    , z(pZ)
	{
	}

	Vector3()
	    : x(0)
	    , y(0)
	    , z(0)
	{
	}

	Vector3(f32 v)
	    : x(v)
	    , y(v)
	    , z(v)
	{
	}

	operator guVector() { return { x, y, z }; }

	f32 operator[](int index)
	{
		switch (index) {
		case 1:
			return x;
		case 2:
			return y;
		case 3:
			return z;
		default:
			return 0;
		}
	}

	Vector3 operator-(const Vector3& other) { return { x - other.x, y - other.y, z - other.z }; }
	Vector3 operator-(const guVector& other) { return { x - other.x, y - other.y, z - other.z }; }
	Vector3 operator+(const Vector3& other) { return { x + other.x, y + other.y, z + other.z }; }

	f32 sqrLength() const { return x * x + y * y + z * z; }
	f32 length() const { return sqrt(sqrLength()); }

	Vector3 normalised()
	{
		f32 l = length();
		return { x / l, y / l, z / l };
	}

	void lerp(const Vector3& dest, f32 t)
	{
		x = LERP(x, dest.x, t);
		y = LERP(y, dest.y, t);
		z = LERP(z, dest.z, t);
	}

	f32 x, y, z;
};

inline Vector3 lerp(const Vector3& a, const Vector3& b, f32 t) { return { LERP(a.x, b.x, t), LERP(a.y, b.y, t), LERP(a.z, b.z, t) }; }

struct Vector2 {
	Vector2(f32 pX, f32 pY)
	    : x(pX)
	    , y(pY)
	{
	}

	Vector2()
	    : x(0)
	    , y(0)
	{
	}

	Vector2(f32 v)
	    : x(v)
	    , y(v)
	{
	}

	f32 operator[](int index)
	{
		switch (index) {
		case 1:
			return x;
		case 2:
			return y;
		default:
			return 0;
		}
	}

	Vector2 operator-(const Vector2& other) { return { x - other.x, y - other.y }; }
	Vector2 operator+(const Vector2& other) { return { x + other.x, y + other.y }; }

	f32 sqrLength() const { return x * x + y * y; }
	f32 length() const { return sqrt(sqrLength()); }

	Vector2 normalised()
	{
		f32 l = length();
		return { x / l, y / l };
	}

	void lerp(const Vector2& dest, f32 t)
	{
		x = LERP(x, dest.x, t);
		y = LERP(y, dest.y, t);
	}

	f32 x, y;
};

struct Transform {
	Vector3 m_position;
	Vector3 m_rotation;
	Vector3 m_scale;

	void resetTransform()
	{
		m_position = { 0 };
		m_rotation = { 0 };

		m_scale.x = 1.0f;
		m_scale.y = 1.0f;
		m_scale.z = 1.0f;
	}

	void useTransform()
	{
		GRRLIB_ObjectView(m_position.x, m_position.y, m_position.z, m_rotation.x, m_rotation.y, m_rotation.z, m_scale.x, m_scale.y,
		                  m_scale.z);
	}
};
} // namespace r2lib

#endif