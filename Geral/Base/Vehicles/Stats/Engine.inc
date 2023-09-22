#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

forward FuelTimer(vehicleid);

public FuelTimer(vehicleid) {
    DATA_VEHICLE[vehicleid][DATA_FUEL] -= 1;
    return 1;
}

stock V_Status(playerid) {
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
        new mot, lu, alar, por, cap, porma, ob;
        new carro = GetPlayerVehicleID(playerid);
        GetVehicleParamsEx(carro, mot, lu, alar, por, cap, porma, ob);
        if(GetVehicleModel(carro) == 509 || GetVehicleModel(carro) == 481 || GetVehicleModel(carro) == 510){

        } else {
            if(DATA_VEHICLE[carro][DATA_FUEL] <= 0.0) {
                
            } else {
                if(DATA_VEHICLE[carro][VEHICLE_ON] == 0) {
                    DATA_VEHICLE[carro][VEHICLE_ON] = 1;
                    SetVehicleParamsEx(carro, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, alar, por, cap, porma, ob);
                } else if(DATA_VEHICLE[carro][VEHICLE_ON] == 1) {
                    DATA_VEHICLE[carro][VEHICLE_ON] = 0;
                    SetVehicleParamsEx(carro, VEHICLE_PARAMS_OFF, VEHICLE_PARAMS_OFF, alar, por, cap, porma, ob);
                    KillTimer(DATA_VEHICLE[carro][TIME_FUEL]);
                }
            }
        }
    }
    return 1;
}

stock V_Gaso(vehicleid) {
    new type = GetVehicleModel(vehicleid);
    if(type == 509 || type == 481 || type == 510){
        
    } else {
        DATA_VEHICLE[vehicleid][TIME_FUEL] = SetTimerEx("FuelTimer", 60000, true, "i", vehicleid);
    }
    return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid) {
    KillTimer(DATA_VEHICLE[vehicleid][TIME_FUEL]);
    return 1;
}