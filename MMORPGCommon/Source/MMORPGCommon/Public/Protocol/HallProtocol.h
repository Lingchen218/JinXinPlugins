#pragma once

#include "SimpleProtocolsDefinition.h"

//定义协议的宏
DEFINITION_SIMPLE_PROTOCOLS(CharacterAppearanceRequests, 4)//角色信息请求
DEFINITION_SIMPLE_PROTOCOLS(CharacterAppearanceResponses, 5)//角色信息回调
DEFINITION_SIMPLE_PROTOCOLS(CheckCharacterNameRequests, 6)//检查角色名字请求
DEFINITION_SIMPLE_PROTOCOLS(CheckCharacterNameResponses, 7)//检查角色名字回调
DEFINITION_SIMPLE_PROTOCOLS(CreateCharacterRequests, 8)//创建角色请求
DEFINITION_SIMPLE_PROTOCOLS(CreateCharacterResponses, 9)//创建角色回调
DEFINITION_SIMPLE_PROTOCOLS(DeleteCharacterRequests, 20)//删除角色请求
DEFINITION_SIMPLE_PROTOCOLS(DeleteCharacterResponses, 21)//删除角色回调