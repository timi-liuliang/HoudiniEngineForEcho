#include "HoudiniModule.h"
#include "HoudiniDigitalAsset.h"

namespace Echo
{
    HoudiniModule::HoudiniModule()
    {
    }
    
    void HoudiniModule::registerTypes()
    {
		Class::registerType<HoudiniDigitalAsset>();
    }
    
    void HoudiniModule::update(float elapsedTime)
    {
        
    }
}
