#pragma once

#include "SimpleProtocolsDefinition.h"

//定义协议的宏
DEFINITION_SIMPLE_PROTOCOLS(GateStatusRequests, 2)//网关状态请求协议
DEFINITION_SIMPLE_PROTOCOLS(GateStatusResponses, 3)//网关状态回调协议
DEFINITION_SIMPLE_PROTOCOLS(PlayerRegistInfoRequests, 12)//玩家注册信息请求协议
DEFINITION_SIMPLE_PROTOCOLS(PlayerRegistInfoResponses, 13)//玩家注册信息回调协议