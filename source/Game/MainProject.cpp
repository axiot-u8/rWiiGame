#include <stdarg.h>

#include "MainProject.h"
#include "r2lib/Colour.h"

#include "floor_png.h"
#include "debug_font_ttf.h"

using namespace r2lib;

namespace Game {
namespace config {
// Speeds (% per frame)
constexpr f32 kCamInterpSpeed = (15.0f / 100.0f); // 15% per frame
} // namespace config

MainProject* mainProj;

MainProject::MainProject()
    : m_camera(true, true, 0.01f, 1500.0f, 55)
    , m_debugFont(GRRLIB_LoadTTF(debug_font_ttf, debug_font_ttf_size))
    , m_timer(0.0f)
    , m_floorPlane(floor_png)
{
	SYS_SetResetCallback([](u32, void*) { mainProj->stop(); });
	SYS_SetPowerCallback([]() { mainProj->stop(); });
}

MainProject::~MainProject() { GRRLIB_FreeTTF(m_debugFont); }

void MainProject::run_setup()
{
	GRRLIB_SetAntiAliasing(true);
	GRRLIB_SetBlend(GRRLIB_BLEND_ALPHA);

	m_floorPlane.m_rotation.x = 90;
	m_floorPlane.m_scale      = { 5, 5, 1 };

	m_camera.m_position     = { 0, 2, -5 };
	m_camera.m_lookPosition = { 0, 0, 5 };

	m_player.setup();
}

void MainProject::run_input() { m_player.run_input(); }

void MainProject::run_gfx()
{
	m_camera.apply();

	GRRLIB_SetLightAmbient(0x333333FF);
	GRRLIB_SetLightDiff(0, { 0.0f, 0.0f, 0.0f }, 50.0f, 1, white);
	GRRLIB_SetLightDiff(1, { sin(m_timer * 2) * 10, 10.0f, cos(m_timer * 2) * 10 }, 20.0f, 1,
	                    getColour(((int)(m_timer * 10)) % 256, 0xFF, 0xFF));

	m_floorPlane.render();

	m_player.run_gfx();
	m_camera.m_lookPosition = lerp(m_camera.m_lookPosition, m_player.getPosition(), config::kCamInterpSpeed);

	m_timer += getTickRate();
}

void MainProject::run_UI()
{
	GRRLIB_2dMode();
	m_player.run_UI();
}

void MainProject::debugPrint(u32 x, u32 y, u32 size, u32 colour, const char* fmt, ...)
{
	char txt[0x200];

	va_list argList;
	va_start(argList, fmt);
	vsprintf(txt, fmt, argList);
	va_end(argList);

	GRRLIB_PrintfTTF(x, y, m_debugFont, txt, size, colour);
}

} // namespace Game