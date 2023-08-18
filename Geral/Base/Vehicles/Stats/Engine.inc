#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

stock V_Status(playerid) {
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
        new mot, lu, alar, por, cap, porma, ob;
        new carro = GetPlayerVehicleID(playerid);
        GetVehicleParamsEx(carro, mot, lu, alar, por, cap, porma, ob);
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 509 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 481 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 510){

        } else {
            if(DATA_VEHICLE[carro][DATA_FUEL] <= 0.0) {
                
            } else {
                if(DATA_VEHICLE[carro][VEHICLE_ON] == 0) {
                    DATA_VEHICLE[carro][VEHICLE_ON] = 1;
                    SetVehicleParamsEx(carro, VEHICLE_PARAMS_ON, VEHICLE_PARAMS_ON, alar, por, cap, porma, ob);
                } else if(DATA_VEHICLE[carro][VEHICLE_ON] == 1) {
                    DATA_VEHICLE[carro][VEHICLE_ON] = 0;
                    SetVehicleParamsEx(carro, VEHICLE_PARAMS_OFF, VEHICLE_PARAMS_OFF, alar, por, cap, porma, ob);
                }
            }
        }
    }
    return 1;
}