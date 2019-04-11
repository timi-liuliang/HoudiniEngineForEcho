#pragma once

#include "engine/core/scene/node.h"

namespace Echo
{
    class HoudiniDigitalAsset : public Node
    {
        ECHO_CLASS(HoudiniDigitalAsset, Node)
        
    public:
        HoudiniDigitalAsset();
        virtual ~HoudiniDigitalAsset();
    };
}

