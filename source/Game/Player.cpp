#include "Game/Player.h"
#include "Game/MainProject.h"

#include "r2lib/Math.h"

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Texture includes
#include "player_body_png.h"
#include "player_face_png.h"
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

using namespace r2lib;

namespace Game {
namespace config {
// Speeds (% per frame)
constexpr f32 kPlayerMoveSpeed = (2.5f / 100.0f);  // X units per frame
constexpr f32 kPlayerRotSpeed  = (12.5f / 100.0f); // X% per frame
} // namespace config

Player::Player()
    : m_controller(WPAD_CHAN_0)
    , m_mesh(GRRLIB_LoadTexture(player_body_png), GRRLIB_LoadTexture(player_face_png))
{
}

void Player::setup() { m_mesh.m_scale = { 0.25f, 0.25f, 0.25f }; }

void Player::run_input()
{
	m_controller.update(0.8f);

	const Vector2& stickDir = m_controller.getStickDir();
	Vector3 moveVel(-stickDir.x * config::kPlayerMoveSpeed, m_velocity.y, stickDir.y * config::kPlayerMoveSpeed);

	m_mesh.m_position = m_velocity + getPosition() + moveVel;
}

void Player::run_gfx()
{
	const Vector2& stickDir = m_controller.getStickDir();
	if (stickDir.x != 0.0f || stickDir.y != 0.0f) {
		const f32 startY = m_mesh.m_rotation.y;

		// Get the smallest difference between the wanted angle and the current angle (- 90 for the front face)
		const f32 targetY = (startY + math::deltaAngle(startY, RadToDeg(atan2f(stickDir.y, stickDir.x)))) - 90;

		// Then smoothly move towards that target angle
		m_faceDirection = LERP(startY, targetY, config::kPlayerRotSpeed);

		// BUGFIX: Wrap angle to min (-360) max (360)
		if (m_faceDirection > 360) {
			m_faceDirection -= 360;
		} else if (m_faceDirection < -360) {
			m_faceDirection += 360;
		}

		m_mesh.m_rotation.y = m_faceDirection;
	}

	m_mesh.render();
}

void Player::run_UI()
{
	const Vector2& stickDir = m_controller.getStickDir();
	mainProj->debugPrint(32, 16, 12, 0xFFFFFFFF, "sdir %f %f fdir %f", stickDir.x, stickDir.y, m_faceDirection);
	mainProj->debugPrint(32, 28, 12, 0xFFFFFFFF, "svel %f %f", m_velocity.x, m_velocity.z);
}
} // namespace Game