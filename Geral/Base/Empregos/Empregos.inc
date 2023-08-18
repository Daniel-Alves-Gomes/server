#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>
#include "../Geral/Base/Empregos/Jobs/Caminhoneiro/Hook.inc"

enum jobs {
    Job[64]
}

new emprego[MAX_PLAYERS][jobs];
new VehicleJob[MAX_PLAYERS];

forward E_Stats(playerid);

hook OnPlayerConnect(playerid) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `job_users` WHERE `hex`='%d'", hexUser[playerid][hex]);
    mysql_tquery(ConexaoSQL, Query, "E_Stats", "i", playerid);
    return 1;
}

public E_Stats(playerid) {
    if(cache_num_rows() > 0) {
        cache_get_value_name(0, "job", emprego[playerid][Job]);
        SetPVarString(playerid, "emprego", emprego[playerid][Job]);
    }
    return 1;
}

stock E_User(playerid) {
    new cargoUser[128];
    new returnConst;
    new Desempregado[128] = "Desempregado";
    GetPVarString(playerid, "emprego", cargoUser, sizeof(cargoUser));
    if(strcmp(cargoUser, Desempregado) == 0) 
    {
    } else {
        if(strcmp(cargoUser, cargo) == 0) {
        returnConst = 1;
        } else {
        returnConst = 0;
        }
    }
    return returnConst;
}

stock E_Desempregar(playerid) {
    new Query[128];
    mysql_format
    SetPVarString(playerid, "emprego", "Desempregado");
    Notificar(playerid, "info", "EMPREGOS", "Voce esta desempregado.", 5000);
    return 1;
}

stock E_Empregar(playerid, const empregoConst[]) {
    new cargoUser[128];
    new Desempregado[128] = "Desempregado";
    GetPVarString(playerid, "emprego", cargoUser, sizeof(cargoUser));
    if(strcmp(cargoUser, Desempregado) == 0) {
        SetPVarString(playerid, "emprego", empregoConst);
        Notificar(playerid, "info", "EMPREGOS", "Siga o GPS.", 5000);
        TABLE_SetEConst(hexUser[playerid][hex], "job_users", empregoConst);
    }
    return 1;
}

stock D_Empregos(playerid) {
    ShowPlayerDialog(playerid, 1, DIALOG_STYLE_LIST, "EMPREGOS", "Caminhoneiro", "Confirmar", "Fechar");
}

stock E_CarJob(Float:x, Float:y, Float:z, carid) {
    VehicleJob[playerid] = CreateVehicle(carid, Float:x, Float:y, Float:z, 0, 1, 1, 1,-1);
    PutPlayerInVehicle(playerid, VehicleJob[playerid], 0);
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    if(dialogid == 1) {
        if(response) {
            switch(listitem)
            {
                case 0: 
                {
                    E_Empregar(playerid, "Caminhoneiro");
                }
            }
        }
    }
    if(dialogid == 2) {
        if(response) {
        switch(listitem)
        {
            case 0: 
            {
                 ShowPlayerDialog(playerid, 3, DIALOG_STYLE_LIST, "CAMINHONEIRO", "WALTON\t1000$", "Confirmar", "Fechar");
            }
            case 1: 
            {
                ShowPlayerDialog(playerid, 4, DIALOG_STYLE_LIST, "CAMINHONEIRO", "Tinta\t1000$ - 5000$\nToxic\t2500", "Confirmar", "Fechar");
            }
        }
        }
    }
    return 0;
}

CMD:Empregos(playerid) {
    D_Empregos(playerid);
    return 1;
}