#pragma once
#include <Application.h>

class SimulatorApplication : public Application
{
public:
	SimulatorApplication() = default;
protected:
	bool IsLeftMouseButtonHeldDown = false;
	void SDLEventLoop() override;
	
};

