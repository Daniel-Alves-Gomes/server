#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

public OnVehicleDamageStatusUpdate(vehicleid, playerid) {
    new Float:Life;
    GetVehicleHealth(vehicleid, Life);
    new Float:VIDA;
    GetPlayerHealth(playerid, VIDA);
    if(VEHICLE_PLAYER[playerid][Cinto_A] == 1) {
        SetPlayerHealth(playerid, VIDA-(Life/100*0.5));
    } else if(VEHICLE_PLAYER[playerid][Cinto_B] == 1) {
        SetPlayerHealth(playerid, VIDA-(Life/100*1.0));
    } else if(VEHICLE_PLAYER[playerid][Cinto_C] == 1) {
        SetPlayerHealth(playerid, VIDA-(Life/100*1.5));
    } else if(VEHICLE_PLAYER[playerid][Cinto_D] == 1) {
        SetPlayerHealth(playerid, VIDA-(Life/100*1.8));
    }
    return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid) {
    new Float:VIDA;
    GetPlayerHealth(playerid, VIDA);
    if(VEHICLE_PLAYER[playerid][Cinto_A] == 1) {
        Notificar(playerid, "erro", "CARRO", "Voce se machucou ao tentar sair do carro com o cinto", 5000);
        SetPlayerHealth(playerid, VIDA-20);
    } else if(VEHICLE_PLAYER[playerid][Cinto_B] == 1) {
        Notificar(playerid, "erro", "CARRO", "Voce se machucou ao tentar sair do carro com o cinto", 5000);
        SetPlayerHealth(playerid, VIDA-30);
    } else if(VEHICLE_PLAYER[playerid][Cinto_C] == 1) {
        Notificar(playerid, "erro", "CARRO", "Voce se machucou ao tentar sair do carro com o cinto", 5000);
        SetPlayerHealth(playerid, VIDA-40);
    } else if(VEHICLE_PLAYER[playerid][Cinto_D] == 1) {
        Notificar(playerid, "erro", "CARRO", "Voce se machucou ao tentar sair do carro com o cinto", 5000);
        SetPlayerHealth(playerid, VIDA-50);
    }
    return 1;
}

CMD:c(playerid) {
    new carro = GetPlayerVehicleID(playerid);
    if(DATA_VEHICLE[carro][Cinto_A] == 1) {
        if(VEHICLE_PLAYER[playerid][Cinto_A] == 1) {
            VEHICLE_PLAYER[playerid][Cinto_A] = 0;
            Notificar(playerid, "sucesso", "CINTO", "Cinto retirado.", 2000);
        } else if(VEHICLE_PLAYER[playerid][Cinto_A] == 0) {
            VEHICLE_PLAYER[playerid][Cinto_A] = 1;
            Notificar(playerid, "sucesso", "CINTO", "Cinto colocado.", 2000);
        }
    } else if(DATA_VEHICLE[carro][Cinto_B] == 1) {
        if(VEHICLE_PLAYER[playerid][Cinto_B] == 1) {
            VEHICLE_PLAYER[playerid][Cinto_B] = 0;
            Notificar(playerid, "sucesso", "CINTO", "Cinto retirado.", 2000);
        } else if(VEHICLE_PLAYER[playerid][Cinto_B] == 0) {
            VEHICLE_PLAYER[playerid][Cinto_B] = 1;
            Notificar(playerid, "sucesso", "CINTO", "Cinto colocado.", 2000);
        }
    } else if(DATA_VEHICLE[carro][Cinto_C] == 1) {
        if(VEHICLE_PLAYER[playerid][Cinto_C] == 1) {
            VEHICLE_PLAYER[playerid][Cinto_C] = 0;
            Notificar(playerid, "sucesso", "CINTO", "Cinto retirado.", 2000);
        } else if(VEHICLE_PLAYER[playerid][Cinto_C] == 0) {
            VEHICLE_PLAYER[playerid][Cinto_C] = 1;
            Notificar(playerid, "sucesso", "CINTO", "Cinto colocado.", 2000);
        }
    } else if(DATA_VEHICLE[carro][Cinto_D] == 1) {
        if(VEHICLE_PLAYER[playerid][Cinto_D] == 1) {
            VEHICLE_PLAYER[playerid][Cinto_D] = 0;
            Notificar(playerid, "sucesso", "CINTO", "Cinto retirado.", 2000);
        } else if(VEHICLE_PLAYER[playerid][Cinto_D] == 0) {
            VEHICLE_PLAYER[playerid][Cinto_D] = 1;
            Notificar(playerid, "sucesso", "CINTO", "Cinto colocado.", 2000);
        }
    } else {
        Notificar(playerid, "sucesso", "CINTO", "Seu carro nao possui cinto.", 2000);
    }
    return 1;
}