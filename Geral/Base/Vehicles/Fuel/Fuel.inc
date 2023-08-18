#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

new GarageLocation[MAX_PLAYERS];

forward FuelTimer(vehicleid);

public FuelTimer(vehicleid) {
    DATA_VEHICLE[vehicleid][DATA_FUEL] -= 1.4;
    return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (PRESSED(KEY_SPRINT))
	{
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 509 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 481 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 510){

        } else if(IsPlayerInAnyVehicle(playerid)) {
            if( GetPlayerState(playerid) == PLAYER_STATE_DRIVER ) {
                if(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][DATA_FUEL] <= 0.0) {

                } else {
                    if(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][VEHICLE_ON] == 1) {
                        DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][TIME_FUEL] = SetTimerEx("FuelTimer", 1000, true, "d", GetPVarInt(playerid, "vehicleIdUser"));
                    }
                }
            }
        }
	} else if (RELEASED(KEY_SPRINT)) {
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 509 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 481 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 510){

        } else if(IsPlayerInAnyVehicle(playerid)) {
            if( GetPlayerState(playerid) == PLAYER_STATE_DRIVER ) {
                if(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][DATA_FUEL] <= 0.0) {

                } else {
                    if(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][VEHICLE_ON] == 0) {
                        
                    } else {
                        KillTimer(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][TIME_FUEL]);
                    }
                }
            }
        }
    } 
    else if(newkeys == KEY_YES) {
        V_Status(playerid);
    }
	return 1;
}