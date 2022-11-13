#ifndef _MAINPROJECT_H
#define _MAINPROJECT_H

#include "r2lib/Project.h"
#include "r2lib/Camera.h"

#include "Game/Player.h"

namespace Game {
class MainProject : public r2lib::Project {
public:
	MainProject();
	virtual ~MainProject();

	virtual void run_setup();

	virtual void run_input();
	virtual void run_gfx();
	virtual void run_UI();

	void debugPrint(u32 x, u32 y, u32 size, u32 colour, const char* fmt, ...);

	void stop() { m_isActive = false; }

	inline f32 getTickRate() { return 0.01f; }

private:
	r2lib::Camera m_camera;
	GRRLIB_ttfFont* m_debugFont;

	r2lib::gx::Plane m_floorPlane;
	Game::Player m_player;

	f32 m_timer;
};

extern MainProject* mainProj;
} // namespace Game

#endif