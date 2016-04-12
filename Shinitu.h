//=============================
// Shinitu Header
#pragma once

//=============================
#include <iostream>
#include <Windows.h>
#include "Vmt.h"
#include "hooks.h"
#include "ValveSDK.h"
#include "AutoHop.h"
#include "Triggerbot.h"
#include "math.h"
#include "render.h"
#include "AutoStrafe.h"
//=============================


//=============================
VMTManager * hookedCreateMove;
VMTManager * hookedPanel;
//=============================


//=============================
ValveSDK::BaseClientDll * Base_Client;
ValveSDK::ClientMode ** Client_Mode;
ValveSDK::ClientEntityList * Client_Entity;
ValveSDK::EngineClient * Engine_Client;
ValveSDK::BaseEntity * Base_Entity;
CRender * Render;
//=============================


//=============================
extern ValveSDK::BaseClientDll * Base_Client;
extern ValveSDK::ClientMode ** Client_Mode;
extern ValveSDK::ClientEntityList * Client_Entity;
extern ValveSDK::EngineClient * Engine_Client;
extern ValveSDK::BaseEntity * Base_Entity;
extern CRender * Render;
extern VMTManager * hookedCreateMove;
extern VMTManager * hookedPanel;
//=============================


//=============================
Hooks::CreateMove oCreateMove;
Hooks::PaintTraverse oPaintTraverse;
//=============================


//=============================
cAutoHop * pAutoHop;
cTrigger * pTrigger;
cAutoStrafe * pAutoStrafe;
//=============================
