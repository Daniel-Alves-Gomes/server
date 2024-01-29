#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>
#include "../Geral/Base/Groups/Hooks/Hook.inc"

forward GET_PlayerStats(playerid);
forward GET_PlayerPunish(playerid);

enum Gets {
    ip_Code[120],
    cargo[120],
    plataform[120],
    hex[120],
    mtvBan[128] 
}

new pGet[MAX_PLAYERS][Gets];

hook OnPlayerConnect(playerid) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `server_accounts` WHERE `nome`='%e'", GetPlayerNameEx(playerid));
    mysql_tquery(ConexaoSQL, Query, "GET_PlayerStats", "i", playerid);
    return 1;
}

public GET_PlayerStats(playerid) {
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "hex", pGet[playerid][hex]);
        cache_get_value_name(0, "ip_code", pGet[playerid][ip_Code]);
        cache_get_value_name(0, "admin", pGet[playerid][cargo]);
        cache_get_value_name(0, "plataform", pGet[playerid][plataform]);
        
        hexUser[playerid][hex] = pGet[playerid][hex];
        SetPVarString(playerid, "ip_Code", pGet[playerid][ip_Code]);
        SetPVarString(playerid, "plataform", pGet[playerid][plataform]);
        SetPVarString(playerid, "admin", pGet[playerid][cargo]);
    } else {
        Kick(playerid);
    }
    return 1;
}