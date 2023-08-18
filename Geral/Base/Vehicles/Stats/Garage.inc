#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

#define CEF_HUD5 (5)

new EnterVehicle[MAX_PLAYERS];

new hexPlayer[MAX_PLAYERS];

new rCar1[MAX_PLAYERS];
new rCar2[MAX_PLAYERS];
new rCar3[MAX_PLAYERS];
new rCar4[MAX_PLAYERS];
new rCar5[MAX_PLAYERS];
new rCar6[MAX_PLAYERS];
new rCar7[MAX_PLAYERS];
new rCar8[MAX_PLAYERS];

new carName[MAX_PLAYERS][128][7];
new carId[MAX_PLAYERS][7];
new carList[MAX_PLAYERS][128][7];
new Float:carLataria[MAX_PLAYERS][7];
new Float:carGasolina[MAX_PLAYERS][7];
new VehiclePlayer1[MAX_PLAYERS];
new VehiclePlayer2[MAX_PLAYERS];
new VehiclePlayer3[MAX_PLAYERS];
new VehiclePlayer4[MAX_PLAYERS];
new VehiclePlayer5[MAX_PLAYERS];
new VehiclePlayer6[MAX_PLAYERS];
new VehiclePlayer7[MAX_PLAYERS];
new VehiclePlayer8[MAX_PLAYERS];

// CARS

new carUsed[MAX_PLAYERS][128][7];
new caridselector[MAX_PLAYERS][7];
new carlist[MAX_PLAYERS][128][7];
new Float:carlata[MAX_PLAYERS][7];
new Float:cargasol[MAX_PLAYERS][7];

//

forward CAR_Submit(playerid);
forward CAR_PlayerList(playerid);
forward CAR_PlayerStats(playerid);

hook OnPlayerConnect(playerid) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `server_accounts` WHERE `nome`='%e'", GetPlayerNameEx(playerid));
    mysql_tquery(ConexaoSQL, Query, "CAR_PlayerStats", "i", playerid);
    return 1;
}

public CAR_PlayerStats(playerid) {
    new Query[128];
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "hex", hexPlayer[playerid]);
        
        SetPVarInt(playerid, "hexGarage", hexPlayer[playerid]);

        mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `car_list` WHERE `hex`='%d'", hexPlayer[playerid]);
        mysql_tquery(ConexaoSQL, Query, "CAR_PlayerList", "i", playerid);
    }
    return 1;
}

public CAR_PlayerList(playerid){
    if(cache_num_rows() > 0) {
        printf("%d", cache_num_rows());
        for(new i = 0; i < cache_num_rows(); i++) 
        { 
            printf("3 - %i", i);
            cache_get_value_name(i, "car", carUsed[playerid][i]);
            cache_get_value_name_int(i, "carid", caridselector[playerid][i]);
            cache_get_value_name(i, "carlist", carlist[playerid][i]);
            cache_get_value_name_float(i, "car_lataria", carlata[playerid][i]);
            cache_get_value_name_float(i, "car_gasolina", cargasol[playerid][i]);
            carName[playerid][i] = carUsed[playerid][i];
            carId[playerid][i] = caridselector[playerid][i];
            carList[playerid][i] = carlist[playerid][i];
            carLataria[playerid][i] = carlata[playerid][i];
            carGasolina[playerid][i] = cargasol[playerid][i];
        }

    }
    return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger) {
    if(vehicleid == VehiclePlayer1[playerid]) {
        EnterVehicle[playerid] = 1;
    } else if(vehicleid == VehiclePlayer2[playerid]) {
        EnterVehicle[playerid] = 2;
    } else if(vehicleid == VehiclePlayer3[playerid]) {
        EnterVehicle[playerid] = 3;
    } else if(vehicleid == VehiclePlayer4[playerid]) {
        EnterVehicle[playerid] = 4;
    } else if(vehicleid == VehiclePlayer5[playerid]) {
        EnterVehicle[playerid] = 5;
    } else if(vehicleid == VehiclePlayer6[playerid]) {
        EnterVehicle[playerid] = 6;
    } else if(vehicleid == VehiclePlayer7[playerid]) {
        EnterVehicle[playerid] = 7;
    } else if(vehicleid == VehiclePlayer8[playerid]) {
        EnterVehicle[playerid] = 8;
    }
    return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid) {
    if(vehicleid == VehiclePlayer1[playerid]) {
        EnterVehicle[playerid] = 0;
    } else if(vehicleid == VehiclePlayer2[playerid]) {
        EnterVehicle[playerid] = 0;
    } else if(vehicleid == VehiclePlayer3[playerid]) {
        EnterVehicle[playerid] = 0;
    } else if(vehicleid == VehiclePlayer4[playerid]) {
        EnterVehicle[playerid] = 0;
    } else if(vehicleid == VehiclePlayer5[playerid]) {
        EnterVehicle[playerid] = 0;
    } else if(vehicleid == VehiclePlayer6[playerid]) {
        EnterVehicle[playerid] = 0;
    } else if(vehicleid == VehiclePlayer7[playerid]) {
        EnterVehicle[playerid] = 0;
    } else if(vehicleid == VehiclePlayer8[playerid]) {
        EnterVehicle[playerid] = 0;
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if(newkeys == KEY_YES)
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.0, 2320.8792, 1444.7968, 42.8203))
        {
            SetPlayerVirtualWorld(playerid, 1);
            GarageLocation[playerid] = 1;
            if(carId[playerid][0] > 0) {
                if(rCar1[playerid] == 0) {
                    VehiclePlayer1[playerid] = CreateVehicle(carId[playerid][0], 2328.0398,1434.5360,42.8203,174.2471, 1, 1, -0, 0);
                    DATA_VEHICLE[VehiclePlayer1[playerid]][DATA_FUEL] = carGasolina[playerid][0];
                    DATA_VEHICLE[VehiclePlayer1[playerid]][VEHICLE_ON] = 1;
                    DATA_VEHICLE[VehiclePlayer1[playerid]][Cinto_A] = 1;
                    SetVehicleHealth(VehiclePlayer1[playerid], carLataria[playerid][0]);
                }
            }
            if(carId[playerid][1] > 0) {
                if(rCar2[playerid] == 0) {
                    VehiclePlayer2[playerid] = CreateVehicle(carId[playerid][1], 2325.2346,1435.1975,42.8203,174.2471, 1, 1, -0, 0);
                    DATA_VEHICLE[VehiclePlayer2[playerid]][DATA_FUEL] = carGasolina[playerid][1];
                    DATA_VEHICLE[VehiclePlayer2[playerid]][VEHICLE_ON] = 1;
                    DATA_VEHICLE[VehiclePlayer2[playerid]][Cinto_A] = 1;
                    SetVehicleHealth(VehiclePlayer2[playerid], carLataria[playerid][1]);
                }
            }
            if(carId[playerid][2] > 0) {
                if(rCar3[playerid] == 0) {
                    VehiclePlayer3[playerid] = CreateVehicle(carId[playerid][1], 2321.4602,1433.9543,42.8203, 1, 1, -0, 0);
                    DATA_VEHICLE[VehiclePlayer3[playerid]][DATA_FUEL] = carGasolina[playerid][2];
                    DATA_VEHICLE[VehiclePlayer3[playerid]][VEHICLE_ON] = 1;
                    DATA_VEHICLE[VehiclePlayer3[playerid]][Cinto_A] = 1;
                    SetVehicleHealth(VehiclePlayer3[playerid], carLataria[playerid][2]);
                }
            }
        }
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    if(dialogid == 5) {
        if(response) {
            switch(listitem) 
            {
                case 0: 
                {
                    if(GarageLocation[playerid] == 0) {
                        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
                            if(EnterVehicle[playerid] == 1) {
                                if(rCar1[playerid] == 1) {
                                    DestroyVehicle(VehiclePlayer1[playerid]);
                                    rCar1[playerid] = 0;
                                }
                            } else if(EnterVehicle[playerid] == 2) {
                                if(rCar2[playerid] == 1) {
                                    DestroyVehicle(VehiclePlayer2[playerid]);
                                    rCar2[playerid] = 0;
                                }
                            } else if(EnterVehicle[playerid] == 3) {
                                if(rCar3[playerid] == 1) {
                                    DestroyVehicle(VehiclePlayer3[playerid]);
                                    rCar3[playerid] = 0;
                                }
                            } else if(EnterVehicle[playerid] == 4) {
                                if(rCar4[playerid] == 1) {
                                    DestroyVehicle(VehiclePlayer4[playerid]);
                                    rCar4[playerid] = 0;
                                }
                            } else if(EnterVehicle[playerid] == 5) {
                                if(rCar5[playerid] == 1) {
                                    DestroyVehicle(VehiclePlayer5[playerid]);
                                    rCar5[playerid] = 0;
                                }
                            } else if(EnterVehicle[playerid] == 6) {
                                if(rCar6[playerid] == 1) {
                                    DestroyVehicle(VehiclePlayer6[playerid]);
                                    rCar6[playerid] = 0;
                                }
                            } else if(EnterVehicle[playerid] == 7) {
                                if(rCar7[playerid] == 1) {
                                    DestroyVehicle(VehiclePlayer7[playerid]);
                                    rCar7[playerid] = 0;
                                }
                            } else if(EnterVehicle[playerid] == 8) {
                                if(rCar8[playerid] == 1) {
                                    DestroyVehicle(VehiclePlayer8[playerid]);
                                    rCar8[playerid] = 0;
                                }
                            }
                        }
                    }
                }
                case 1:
                {
                    if(GarageLocation[playerid] == 1) {
                        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
                            if(EnterVehicle[playerid] == 1) {
                                if(rCar1[playerid] == 0) {
                                    SetPlayerVirtualWorld(playerid, 0);
                                    DestroyVehicle(VehiclePlayer2[playerid]);
                                    DestroyVehicle(VehiclePlayer1[playerid]);
                                    DestroyVehicle(VehiclePlayer1[playerid]);
                                    VehiclePlayer1[playerid] = CreateVehicle(carId[playerid][0], 2328.0398,1434.5360,42.8203,174.2471, 1, 0, -0, 0);
                                    rCar1[playerid] = 1;
                                    PutPlayerInVehicle(playerid, VehiclePlayer1[playerid], 0);
                                    GarageLocation[playerid] = 0;
                                }
                            } else if(EnterVehicle[playerid] == 2) {
                                if(rCar2[playerid] == 0) {
                                    SetPlayerVirtualWorld(playerid, 0);
                                    DestroyVehicle(VehiclePlayer1[playerid]);
                                    DestroyVehicle(VehiclePlayer2[playerid]);
                                    DestroyVehicle(VehiclePlayer3[playerid]);
                                    VehiclePlayer2[playerid] = CreateVehicle(carId[playerid][1], 2325.2346,1435.1975,42.8203,174.2471, 1, 0, -0, 0);
                                    rCar2[playerid] = 1;
                                    PutPlayerInVehicle(playerid, VehiclePlayer2[playerid], 0);
                                    GarageLocation[playerid] = 0;
                                }
                            } else if(EnterVehicle[playerid] == 3) {
                                if(rCar3[playerid] == 0) {
                                    SetPlayerVirtualWorld(playerid, 0);
                                    DestroyVehicle(VehiclePlayer1[playerid]);
                                    DestroyVehicle(VehiclePlayer2[playerid]);
                                    DestroyVehicle(VehiclePlayer3[playerid]);
                                    VehiclePlayer3[playerid] = CreateVehicle(carId[playerid][2], 2321.4602,1433.9543,42.8203, 1, 0, -0, 0);
                                    rCar3[playerid] = 1;
                                    PutPlayerInVehicle(playerid, VehiclePlayer3[playerid], 0);
                                    GarageLocation[playerid] = 0;
                                }
                            }
                        } else {
                            SetPlayerVirtualWorld(playerid, 0);
                            SetPlayerPos(playerid, 2320.8792, 1444.7968, 42.8203);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

CMD:garagem(playerid) {
    if(IsPlayerInRangeOfPoint(playerid, 1.0, 2320.8792, 1444.7968, 42.8203)) {
        ShowPlayerDialog(playerid, 5, DIALOG_STYLE_LIST, "GARAGEM", "Entrar\nSair", "Confirmar", "Fechar");
    }
    return 1;
}