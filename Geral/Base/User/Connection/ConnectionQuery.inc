#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

SET_IpUser(playerid) {
    static IpUser[MAX_PLAYERS][18];
    static Query[128];
    GetPlayerIp(playerid, IpUser[playerid], sizeof(IpUser[playerid]));
    if(IsAndroidPlayer(playerid)) {
        mysql_format(ConexaoSQL, query, sizeof(query), "UPDATE `server_accounts` SET \
            `ip_code`='%s' \
            `platform`='Android' \
            WHERE `nome`='%s'", IpUser[playerid], GetPlayerNameEx(playerid));
    } else if(IsPcPlayer(playerid)) {
        mysql_format(ConexaoSQL, query, sizeof(query), "UPDATE `server_accounts` SET \
            `ip_code`='%s' \
            `platform`='Pc' \
            WHERE `nome`='%s'", IpUser[playerid], GetPlayerNameEx(playerid));
        }
    mysql_query(ConexaoSQL, Query);
    return 1;
}

SET_Others(playerid) {
    static Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "");
    return 1;
}