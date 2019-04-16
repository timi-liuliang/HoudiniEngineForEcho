#pragma once

#ifdef WIN32
    #define ECHO_PLUGIN_EXPORT __declspec(dllexport)
#else
    #define ECHO_PLUGIN_EXPORT __attribute__((visibility("default")))
#endif

#include <engine/core/main/Engine.h>

extern "C"
{
	// load houdini plugin
	bool ECHO_PLUGIN_EXPORT loadHoudiniEnginePlugin(Echo::Engine* engine);

	// unload houdini plugin
	bool ECHO_PLUGIN_EXPORT unloadHoudiniEnginePlugin();
}
