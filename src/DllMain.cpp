#include "DllMain.h"
#include <engine/core/main/module.h>

bool loadHoudiniEnginePlugin()
{
    Echo::registerModules();

	return true;
}

bool unloadHoudiniEnginePlugin()
{
	return false;
}
