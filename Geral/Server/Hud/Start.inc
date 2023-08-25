#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

enum Player_Data
{
	Float:fome,
	Float:sede
}
new pInfo[MAX_PLAYERS][Player_Data];
new TimerHUD[MAX_PLAYERS];
new TimerFomeSede[MAX_PLAYERS];

#define CEF_HUD (1)
#define SCMf SendClientMessagef

forward OnCefInitialize(player_id, success);
public OnCefInitialize(player_id, success)
{
	if(success == 1) {
	}
	return;
}

public OnPlayerDisconnect(playerid, reason)
{
    cef_destroy_browser(playerid, CEF_HUD);
	KillTimer(TimerHUD[playerid]);
	KillTimer(TimerFomeSede[playerid]);
	return 1;
}

public OnPlayerSpawn(playerid)
{
	
	cef_create_browser(playerid, CEF_HUD, "https://danielteste1321.000webhostapp.com/index.html", false, false);
	/*
		cef_create_browser(player_id, browser_id, const url[], bool:hidden, bool:focused);
		hidden - Para esconder o navegador / focused - ativar o cursor do mouse
	*/
	TimerHUD[playerid] = SetTimerEx("UpdateHUD", 1000, true, "d", playerid); // 1 Segundo para atualizar o hud!
	TimerFomeSede[playerid] = SetTimerEx("UpdateFomeSede", 1000, true, "d", playerid); // 5 Segundos para atualizar a fome e sede! 
	return 1;
}

public OnPlayerUpdate(playerid) {
	new carro = GetPlayerVehicleID(playerid);
	new mot, lu, alar, por, cap, porma, ob;
	GetVehicleParamsEx(carro, mot, lu, alar, por, cap, porma, ob);
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
		SetPVarInt(playerid, "isInVehicle", 1);
		SetPVarInt(playerid, "vehicleIdUser", carro);
	} else {
		SetPVarInt(playerid, "isInVehicle", 0);
		SetPVarInt(playerid, "vehicleIdUser", 0);
	}
	if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 509 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 481 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 510){
		
	} else {
		if(DATA_VEHICLE[carro][VEHICLE_ON] == 1) {
			if(DATA_VEHICLE[carro][DATA_FUEL] <= 0.0)
			{
				DATA_VEHICLE[carro][VEHICLE_ON] = 0;
                SetVehicleParamsEx(carro, VEHICLE_PARAMS_OFF, VEHICLE_PARAMS_OFF, alar, por, cap, porma, ob);
				KillTimer(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][TIME_FUEL]);
			}
		}
	}
	return 1;
}

forward UpdateFomeSede(playerid);
public UpdateFomeSede(playerid)
{
	if(pInfo[playerid][fome] == 0.0 || pInfo[playerid][sede] == 0.0) {

	} else {
		pInfo[playerid][fome] -= 1.0;
		pInfo[playerid][sede] -= 1.0;
	}
	return 1;
}

forward UpdateHUD(playerid);
public UpdateHUD(playerid)
{
	new Float:vida, Float:colete;
	GetPlayerHealth(playerid, vida);
	GetPlayerArmour(playerid, colete);
	
	cef_emit_event(playerid, "Player:status", CEFFLOAT(vida), CEFFLOAT(colete), CEFFLOAT(pInfo[playerid][fome]), CEFFLOAT(pInfo[playerid][sede]), CEFINT(VelocidadeDoVeiculo(GetPVarInt(playerid, "vehicleIdUser"))), CEFINT(GetPVarInt(playerid, "isInVehicle")), CEFFLOAT(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][DATA_FUEL], CEFINT(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][VEHICLE_ON])));
	//SCMf(playerid, -1, "VEHICLE-VELOCITY - %d , VEHICLE-STATUS - %d, VEHICLE-FUEL - %f", VelocidadeDoVeiculo(GetPVarInt(playerid, "vehicleIdUser")), GetPVarInt(playerid, "isInVehicle"), DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][DATA_FUEL]);
	return 1;
}