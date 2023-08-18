#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>
#include "../Geral/Base/Empregos/Jobs/Caminhoneiro/SubHook/FinishJob.inc"

#define MAX_ROTAS 25

enum rotasCaminhoneiro {
    Float:tintax,
    Float:tintay,
    Float:tintaz,
    Float:toxicx,
    Float:toxicy,
    Float:toxicz
}

new rotasCaminhao[MAX_PLAYERS][rotasCaminhoneiro];

forward GET_Rotas(playerid);
forward SET_Rotas(playerid);

public GET_Rotas(playerid) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `coords_caminhoneiro` WHERE `cds`='3'");
    mysql_tquery(ConexaoSQL, Query, "SET_Rotas", "i", playerid);
    return 1;
}

public SET_Rotas(playerid) {
    cache_get_value_name_float(0, "tintax", rotasCaminhao[playerid][tintax]);
    cache_get_value_name_float(0, "tintay", rotasCaminhao[playerid][tintay]);
    cache_get_value_name_float(0, "tintaz", rotasCaminhao[playerid][tintaz]);
    cache_get_value_name_float(0, "toxicx", rotasCaminhao[playerid][toxicx]);
    cache_get_value_name_float(0, "toxicy", rotasCaminhao[playerid][toxicy]);
    cache_get_value_name_float(0, "toxicz", rotasCaminhao[playerid][toxicz]);

    SetPVarFloat(playerid, "tx", rotasCaminhao[playerid][tintax]);
    SetPVarFloat(playerid, "ty", rotasCaminhao[playerid][tintay]);
    SetPVarFloat(playerid, "tz", rotasCaminhao[playerid][tintaz]);
    SetPVarFloat(playerid, "tox", rotasCaminhao[playerid][toxicx]);
    SetPVarFloat(playerid, "toy", rotasCaminhao[playerid][toxicy]);
    SetPVarFloat(playerid, "toz", rotasCaminhao[playerid][toxicz]);
    return 1;
}