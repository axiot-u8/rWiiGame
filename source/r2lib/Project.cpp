#include <stdlib.h>

#include "r2lib/Project.h"

namespace r2lib {
Project::Project()
{
	GRRLIB_Init();
	WPAD_Init();

	srand(time(NULL));

	m_isActive = true;
}

Project::~Project() { GRRLIB_Exit(); }

void Project::run()
{
	run_setup();
	while (m_isActive) {
		run_input();
		run_gfx();
		run_UI();

		GRRLIB_Render();
	}
}
} // namespace r2lib