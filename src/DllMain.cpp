#include "DllMain.h"
#include <engine/core/main/module.h>

bool loadHoudiniEnginePlugin(Echo::Engine* engine)
{
	// replace instances
	engine->initializeDll();

	// register modules
    Echo::registerModules();

	return true;
}

bool unloadHoudiniEnginePlugin()
{
	return false;
}
