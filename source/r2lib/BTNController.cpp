#include <wiiuse/wpad.h>

#include "r2lib/BTNController.h"

namespace r2lib {
void BTNController::update(f32 stickAccelRate)
{
	WPAD_ScanPads();
	m_btnDown = WPAD_ButtonsDown(m_controllerIdx);
	m_btnHeld = WPAD_ButtonsHeld(m_controllerIdx);
	m_btnUp   = WPAD_ButtonsUp(m_controllerIdx);

	if (isButtonHeld(WPAD_BUTTON_LEFT)) {
		m_stickDir.x = MAX(m_stickDir.x - stickAccelRate, -1);
	} else if (isButtonHeld(WPAD_BUTTON_RIGHT)) {
		m_stickDir.x = MIN(m_stickDir.x + stickAccelRate, 1);
	} else {
		m_stickDir.x = 0;
	}

	if (isButtonHeld(WPAD_BUTTON_UP)) {
		m_stickDir.y = MIN(m_stickDir.y + stickAccelRate, 1);
	} else if (isButtonHeld(WPAD_BUTTON_DOWN)) {
		m_stickDir.y = MAX(m_stickDir.y - stickAccelRate, -1);
	} else {
		m_stickDir.y = 0;
	}
}
} // namespace r2lib