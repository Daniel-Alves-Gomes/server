#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

enum org {
    Organizacao[128],
    Cargo
}

new infoOrg[MAX_PLAYERS][org];

forward GET_StatusOrg(playerid);
forward GET_Orgs(playerid);

public GET_Orgs(playerid)
{
    if(cache_num_rows() > 0) {
        cache_get_value_name(0, "org", infoOrg[playerid][Organizacao]);
        cache_get_value_name_int(0, "cargo", infoOrg[playerid][Cargo]);
    } 
    return 1;
}

public GET_StatusOrg(playerid) {
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "hex", hexUser[playerid][hex]);
        new Query[128];
        mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `orgs_user` WHERE `hex`='%i'", hexUser[playerid][hex]);
        mysql_tquery(ConexaoSQL, Query, "GET_Orgs", "i", playerid);
    } else {
        Kick(playerid);
    }
    return 1;
}

hook OnPlayerConnect(playerid) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `server_accounts` WHERE `nome`='%e'", GetPlayerNameEx(playerid));
    mysql_tquery(ConexaoSQL, Query, "GET_StatusOrg", "i", playerid);
    return 1;
}