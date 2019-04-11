#include "HoudiniModule.h"
#include "engine/core/memory/MemAllocDef.h"
#include "HoudiniDigitalAsset.h"

namespace Echo
{
    HoudiniModule::HoudiniModule()
    {
    }
    
    void HoudiniModule::registerTypes()
    {
        REGISTER_MODULE(HoudiniDigitalAsset)
    }
    
    void HoudiniModule::update(float elapsedTime)
    {
        
    }
}
