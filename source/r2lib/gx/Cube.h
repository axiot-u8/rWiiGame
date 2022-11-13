#ifndef _R2LIB_GX_CUBE_H
#define _R2LIB_GX_CUBE_H

#include "grrlib.h"
#include "r2lib/Math.h"

namespace r2lib {
namespace gx {
class Cube : public r2lib::Transform {
public:
	Cube(GRRLIB_texImg* texture, GRRLIB_texImg* frontTex = nullptr)
	    : m_texture(texture)
	    , m_frontTex(frontTex)
	{
		resetTransform();
	}

	Cube(const u8* texture)
	    : m_texture(GRRLIB_LoadTexture(texture))
	{
		resetTransform();
	}

	~Cube() { GRRLIB_FreeTexture(m_texture); }

	void render()
	{
		useTransform();

		GRRLIB_SetTexture(m_texture, true);
		GX_Begin(GX_QUADS, GX_VTXFMT0, 20);
		GX_Position3f32(-1.0f, 1.0f, 1.0f); // Top Left of the quad (top)
		GX_Normal3f32(-1.0f, 1.0f, 1.0f);
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 0.0f);
		GX_Position3f32(1.0f, 1.0f, 1.0f); // Top Right of the quad (top)
		GX_Normal3f32(1.0f, 1.0f, 1.0f);   // Top Right of the quad (top)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 1.0f);
		GX_Position3f32(1.0f, 1.0f, -1.0f); // Bottom Right of the quad (top)
		GX_Normal3f32(1.0f, 1.0f, -1.0f);   // Bottom Right of the quad (top)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 1.0f);
		GX_Position3f32(-1.0f, 1.0f, -1.0f); // Bottom Left of the quad (top)
		GX_Normal3f32(-1.0f, 1.0f, -1.0f);   // Bottom Left of the quad (top)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 0.0f);

		GX_Position3f32(-1.0f, -1.0f, 1.0f); // Top Left of the quad (bottom)
		GX_Normal3f32(-1.0f, -1.0f, 1.0f);   // Top Left of the quad (bottom)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 0.0f);
		GX_Position3f32(1.0f, -1.0f, 1.0f); // Top Right of the quad (bottom)
		GX_Normal3f32(1.0f, -1.0f, 1.0f);   // Top Right of the quad (bottom)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 1.0f);
		GX_Position3f32(1.0f, -1.0f, -1.0f); // Bottom Right of the quad (bottom)
		GX_Normal3f32(1.0f, -1.0f, -1.0f);   // Bottom Right of the quad (bottom)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 1.0f);
		GX_Position3f32(-1.0f, -1.0f, -1.0f); // Bottom Left of the quad (bottom)
		GX_Normal3f32(-1.0f, -1.0f, -1.0f);   // Bottom Left of the quad (bottom)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 0.0f);

		GX_Position3f32(-1.0f, 1.0f, -1.0f); // Top Left of the quad (back)
		GX_Normal3f32(-1.0f, 1.0f, -1.0f);   // Top Left of the quad (back)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 0.0f);
		GX_Position3f32(-1.0f, -1.0f, -1.0f); // Top Right of the quad (back)
		GX_Normal3f32(-1.0f, -1.0f, -1.0f);   // Top Right of the quad (back)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 1.0f);
		GX_Position3f32(1.0f, -1.0f, -1.0f); // Bottom Right of the quad (back)
		GX_Normal3f32(1.0f, -1.0f, -1.0f);   // Bottom Right of the quad (back)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 1.0f);
		GX_Position3f32(1.0f, 1.0f, -1.0f); // Bottom Left of the quad (back)
		GX_Normal3f32(1.0f, 1.0f, -1.0f);   // Bottom Left of the quad (back)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 0.0f);

		GX_Position3f32(-1.0f, 1.0f, 1.0f); // Top Left of the quad (left)
		GX_Normal3f32(-1.0f, 1.0f, 1.0f);   // Top Left of the quad (left)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 0.0f);
		GX_Position3f32(-1.0f, 1.0f, -1.0f); // Top Right of the quad (back)
		GX_Normal3f32(-1.0f, 1.0f, -1.0f);   // Top Right of the quad (back)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 1.0f);
		GX_Position3f32(-1.0f, -1.0f, -1.0f); // Bottom Right of the quad (back)
		GX_Normal3f32(-1.0f, -1.0f, -1.0f);   // Bottom Right of the quad (back)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 1.0f);
		GX_Position3f32(-1.0f, -1.0f, 1.0f); // Bottom Left of the quad (back)
		GX_Normal3f32(-1.0f, -1.0f, 1.0f);   // Bottom Left of the quad (back)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 0.0f);

		GX_Position3f32(1.0f, 1.0f, 1.0f); // Top Left of the quad (right)
		GX_Normal3f32(1.0f, 1.0f, 1.0f);   // Top Left of the quad (right)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 0.0f);
		GX_Position3f32(1.0f, 1.0f, -1.0f); // Top Right of the quad (right)
		GX_Normal3f32(1.0f, 1.0f, -1.0f);   // Top Right of the quad (right)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 1.0f);
		GX_Position3f32(1.0f, -1.0f, -1.0f); // Bottom Right of the quad (right)
		GX_Normal3f32(1.0f, -1.0f, -1.0f);   // Bottom Right of the quad (right)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 1.0f);
		GX_Position3f32(1.0f, -1.0f, 1.0f); // Bottom Left of the quad (right)
		GX_Normal3f32(1.0f, -1.0f, 1.0f);   // Bottom Left of the quad (right)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 0.0f);
		GX_End();

		if (m_frontTex) {
			GRRLIB_SetTexture(m_frontTex, true);
		}

		// FRONT FACE
		GX_Begin(GX_QUADS, GX_VTXFMT0, 4);
		GX_Position3f32(-1.0f, 1.0f, 1.0f); // Top Left of the quad (front)
		GX_Normal3f32(-1.0f, 1.0f, 1.0f);   // Top Left of the quad (front)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 0.0f);
		GX_Position3f32(-1.0f, -1.0f, 1.0f); // Top Right of the quad (front)
		GX_Normal3f32(-1.0f, -1.0f, 1.0f);   // Top Right of the quad (front)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(1.0f, 1.0f);
		GX_Position3f32(1.0f, -1.0f, 1.0f); // Bottom Right of the quad (front)
		GX_Normal3f32(1.0f, -1.0f, 1.0f);   // Bottom Right of the quad (front)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 1.0f);
		GX_Position3f32(1.0f, 1.0f, 1.0f); // Bottom Left of the quad (front)
		GX_Normal3f32(1.0f, 1.0f, 1.0f);   // Bottom Left of the quad (front)
		GX_Color1u32(0xFFFFFFFF);
		GX_TexCoord2f32(0.0f, 0.0f);
		GX_End();
	}

private:
	GRRLIB_texImg* m_texture;
	GRRLIB_texImg* m_frontTex;
};
} // namespace gx
} // namespace r2lib

#endif