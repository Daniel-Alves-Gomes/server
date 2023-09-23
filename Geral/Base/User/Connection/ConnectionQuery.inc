#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>
#include "../Geral/Base/User/Connection/Selector.inc"

enum gets {
    Whitelist,
    Ip[15 + 1],
    Float:xS,
    Float:yS, 
    Float:zS,
    Skin,
    Tipo
}

new getsUser[MAX_PLAYERS][gets];


forward LOAD_Mysql(playerid);

public LOAD_Mysql(playerid) {
    if(cache_num_rows() > 0) {
        cache_get_value_name(0, "ip_code", getsUser[playerid][Ip]);
        cache_get_value_name(0, "tipo", getsUser[playerid][Tipo]);
        cache_get_value_name_int(0, "whitelist", getsUser[playerid][Whitelist]);
        cache_get_value_name_int(0, "skin", getsUser[playerid][Skin]);
        cache_get_value_name_float(0, "x", getsUser[playerid][xS]);
        cache_get_value_name_float(0, "y", getsUser[playerid][yS]);
        cache_get_value_name_float(0, "z", getsUser[playerid][zS]);

        WL_Query(playerid);

    } else {
        SET_Others(playerid);
    }
    return 1;
}

stock SET_IpUser(playerid) {
    static Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "UPDATE `server_accounts` SET \
        `ip_code`='%s' \
        WHERE `nome`='%s'", YSI_gPlayerIP[playerid], GetPlayerNameEx(playerid));
    mysql_query(ConexaoSQL, Query);
    Kick(playerid);
    return 1;
}

stock SET_Others(playerid) {
    static Query[128];
    format(Query, sizeof(Query), "INSERT INTO server_accounts (`nome`, `whitelist`, `x`, `y`, `z`) VALUES ('%s', 0, 1958.33, 1343.12, 15.36)", GetPlayerNameEx(playerid));
	mysql_query(ConexaoSQL, Query);
    SET_IpUser(playerid);
    return 1;
}

stock WL_Query(playerid) {
    if(strcmp(getsUser[playerid][Ip], YSI_gPlayerIP[playerid]) == 0) {
        if(getsUser[playerid][Whitelist] == 1) {
            if(getsUser[playerid][Skin] == 0) {
                OpenSelector(playerid);
            } else {
                SpawnPlayer(playerid);
                SetSpawnInfo(playerid, NO_TEAM, getsUser[playerid][Skin], getsUser[playerid][xS], getsUser[playerid][yS], getsUser[playerid][zS], 0, 0, 0, 0, 0, 0, 0);
                TogglePlayerSpectating(playerid, false);
            }
        } else {
            Kick(playerid);
        }
    } else {
        Kick(playerid);
    }
    return 1;
}

hook OnPlayerConnect(playerid) {
    TogglePlayerSpectating(playerid, true);
    static Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `server_accounts` WHERE `nome`='%e'", GetPlayerNameEx(playerid));
    mysql_tquery(ConexaoSQL, Query, "LOAD_Mysql", "i", playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
    new Float:Pos[MAX_PLAYERS][3];
    new Query[128];
    GetPlayerPos(playerid, Pos[playerid][0], Pos[playerid][1], Pos[playerid][2]);
    mysql_format(ConexaoSQL, Query, sizeof(Query), "UPDATE `server_accounts` SET \
        `x`='%f', \
        `y`='%f', \
        `z`='%f' \
        WHERE `nome`='%s'", Pos[playerid][0], Pos[playerid][1], Pos[playerid][2], GetPlayerNameEx(playerid));
    mysql_query(ConexaoSQL, Query);
    return 1;
}