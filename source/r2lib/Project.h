#ifndef _R2LIB_PROJECT_H
#define _R2LIB_PROJECT_H

#include <grrlib.h>
#include <wiiuse/wpad.h>

namespace r2lib {
class Project {
public:
	Project();
	virtual ~Project();

	virtual void run();

	// Before the main active loop
	virtual void run_setup() = 0;

	// During the main active loop
	virtual void run_input() = 0;
	virtual void run_gfx()   = 0;
	virtual void run_UI()    = 0;

protected:
	bool m_isActive;
};
} // namespace r2lib

#endif