#ifndef _GAME_PLAYER_H
#define _GAME_PLAYER_H

#include "r2lib/BTNController.h"
#include "r2lib/gx/Primitives.h"

namespace Game {
namespace gx = r2lib::gx;
class Player {
public:
	Player();
	~Player() { }

	void setup();
	void run_gfx();
	void run_input();
	void run_UI();

	inline const r2lib::Vector3& getPosition() { return m_mesh.m_position; }

private:
	r2lib::BTNController m_controller;
	r2lib::Vector3 m_velocity;
	f32 m_faceDirection;

	// TODO: swap this out with a mesh
	gx::Cube m_mesh;
};

} // namespace Game

#endif