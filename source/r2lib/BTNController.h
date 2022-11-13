#ifndef _R2LIB_BTNCONTROLLER_H
#define _R2LIB_BTNCONTROLLER_H

#include <gctypes.h>
#include <wiiuse/wpad.h>
#include "r2lib/Math.h"

namespace r2lib {
struct BTNController {
public:
	BTNController(const u8 channel)
	    : m_controllerIdx(channel)
	{
		m_btnDown = 0;
		m_btnHeld = 0;
		m_btnUp   = 0;
	}

	~BTNController() { }

	void update(f32 stickAccelRate);

	u32 isButtonDown(u32 btn) { return m_btnDown & btn; }
	u32 isButtonHeld(u32 btn) { return m_btnHeld & btn; }
	u32 isButtonUp(u32 btn) { return m_btnUp & btn; }

	const u32& getButtonsDown() { return m_btnDown; }
	const u32& getButtonsHeld() { return m_btnHeld; }
	const u32& getButtonsUp() { return m_btnUp; }

	const Vector2& getStickDir() const { return m_stickDir; }
	const Vector2& getStickDir() { return m_stickDir; }

private:
	u8 m_controllerIdx;
	u32 m_btnDown;
	u32 m_btnHeld;
	u32 m_btnUp;

	Vector2 m_stickDir;
};

} // namespace r2lib

#endif