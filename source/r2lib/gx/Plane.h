#ifndef _R2LIB_GX_PLANE_H
#define _R2LIB_GX_PLANE_H

#include "grrlib.h"
#include "r2lib/Math.h"

namespace r2lib {
namespace gx {
class Plane : public r2lib::Transform {
public:
	Plane(GRRLIB_texImg* texture)
	    : m_texture(texture)
	{
		resetTransform();
	}

	Plane(const u8* texture)
	    : m_texture(GRRLIB_LoadTexture(texture))
	{
		resetTransform();
	}

	~Plane() { GRRLIB_FreeTexture(m_texture); }

	void render()
	{
		useTransform();

		GRRLIB_SetTexture(m_texture, true);
		GX_Begin(GX_QUADS, GX_VTXFMT0, 4);
		GX_Position3f32(-1.0f, 1.0f, 1.0f);
		GX_Normal3f32(-1.0f, 1.0f, 1.0);
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 0.0f);

		GX_Position3f32(1.0f, 1.0f, 1.0f);
		GX_Normal3f32(1.0f, 1.0f, 1.0f);
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 0.0f);

		GX_Position3f32(1.0f, -1.0f, 1.0f);
		GX_Normal3f32(1.0, 1.0, -1.0);
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 1.0f);

		GX_Position3f32(-1.0f, -1.0f, 1.0f);
		GX_Normal3f32(-1.0, 1.0, -1.0);
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 1.0f);
		GX_End();
	}

private:
	GRRLIB_texImg* m_texture;
};
} // namespace gx
} // namespace r2lib

#endif