#pragma once

#include "CoreMinimal.h"
#include "SimpleProtocolsDefinition.h"
//普通的定义协议，不丢包，速度慢
DEFINITION_SIMPLE_PROTOCOLS(HelloRequests, 0)
DEFINITION_SIMPLE_PROTOCOLS(HelloResponses, 1)
//强制发送的协议，速度快，易丢包
DEFINITION_SIMPLE_PROTOCOLS_FORCE(HelloForceRequests, 2)
DEFINITION_SIMPLE_PROTOCOLS_FORCE(HelloForceResponses, 3)