#ifndef _R2LIB_CAMERA_H
#define _R2LIB_CAMERA_H

#include "r2lib/Math.h"
#include <grrlib.h>

namespace r2lib {
class Camera {
public:
	inline Camera(bool useTex = false, bool useNrm = true, f32 closePlane = 0.01f, f32 farPlane = 1500.0f, f32 fov = 55.0f)
	{
		apply(useTex, useNrm, closePlane, farPlane, fov);
	}
	~Camera() { }

	inline void apply(bool useTex, bool useNrm, f32 closePlane = 0.01f, f32 farPlane = 1500.0f, f32 fov = 55.0f)
	{
		m_useTex         = useTex;
		m_useNrm         = useNrm;
		m_closeClipPlane = closePlane;
		m_farClipPlane   = farPlane;
		m_fov            = fov;

		apply();
	}

	inline void apply()
	{
		GRRLIB_Camera3dSettings(m_position.x, m_position.y, m_position.z, 0, 1, 0, m_lookPosition.x, m_lookPosition.y, m_lookPosition.z);
		GRRLIB_3dMode(m_closeClipPlane, m_farClipPlane, m_fov, m_useTex, m_useNrm);
	}

	inline void setLookPosition(Vector3 destination) { m_lookPosition = destination; }
	inline const Vector3& getLookPosition() { return m_lookPosition; }

	inline void setFOV(f32 newFov)
	{
		if (newFov < 180 && newFov > 0) {
			m_fov = newFov;
		}
	}
	inline const f32 getFOV() const { return m_fov; }

public:
	Vector3 m_position;
	Vector3 m_lookPosition;

	f32 m_fov;

	f32 m_closeClipPlane;
	f32 m_farClipPlane;

	bool m_useTex;
	bool m_useNrm;
};
} // namespace r2lib

#endif