#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>
#include "../Geral/Base/Groups/Hooks/Hook.inc"

#define CEF_HUD2 (2)
#define SCMf SendClientMessagef

forward GET_PlayerStats(playerid);
forward GET_PlayerPunish(playerid);
forward V_Ban(playerid);
forward SET_PunishBan(player_id, const arguments[]);
forward SET_PunishKick(player_id, id);

new TimerADMIN[MAX_PLAYERS];

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
    cef_subscribe("pwd:tryBan", "SET_PunishBan");
    cef_subscribe("pwd:tryKick", "SET_PunishKick");
    return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
    cef_destroy_browser(playerid, CEF_HUD2);
	return 1;
}

hook OnPlayerSpawn(playerid) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `punish_list` WHERE `hex`='%d'", hexUser[playerid][hex]);
    mysql_tquery(ConexaoSQL, Query, "GET_PlayerPunish", "i", playerid);
    return 1;    
}

public GET_PlayerPunish(playerid) {
    new Query[128];
    if(cache_num_rows() > 0) {
        new cache_temp;
        cache_get_value_name_int(0, "tempo", cache_temp);

        if(cache_temp < gettime()) {
            Kick(playerid);
        } else {
            mysql_format(ConexaoSQL, Query, sizeof(Query), "DELETE FROM `punish_list` WHERE `hex`='%d'", hexUser[playerid][hex]);
            mysql_query(ConexaoSQL, Query);
        }

    }
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

public SET_PunishKick(player_id, id) {
    new fSend[150];
    new hexId';
    sscanf(arguments, "d", hexId);
    if(IsPlayerConnected(hexId)) {
        format(fSend, sizeof(fSend), "O jogador com id %i (SESSAO) kickado.", hexId);
        Notificar(player_id, "sucesso", "KICK", fSend, 5000);
        cef_focus_browser(player_id, CEF_HUD2, false);
        Kick(hexId);
    }
    return 1;
}

public SET_PunishBan(player_id, const arguments[]) {
    new Query[128];
    new motivoBan[128], idBan, tempoBan;
    sscanf(arguments, "p<,>s[128]dd", motivoBan, idBan, tempoBan);
    SetPVarInt(player_id, "hexPunish", idBan);
    new timeDays;
    timeDays = tempoBan*86400;
    SetPVarInt(player_id, "tempoBan", timeDays);
    pGet[player_id][mtvBan] = motivoBan;
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `server_accounts` WHERE `hex`='%i'", idBan);
    mysql_tquery(ConexaoSQL, Query, "V_Ban", "i", player_id);
}

public V_Ban(playerid) {
    new fSend[150];
    new Query[350];
    if(cache_num_rows() > 0) {
        mysql_format(ConexaoSQL, Query, sizeof(Query), "INSERT INTO `punish_list` (`admin`, `hex`, `motivo`, `tempo`) VALUES ('%s', '%d', '%s', '%d')", GetPlayerNameEx(playerid), GetPVarInt(playerid, "hexPunish"), pGet[playerid][mtvBan], GetPVarInt(playerid, "tempoBan"));
        mysql_query(ConexaoSQL, Query);
        cef_destroy_browser(playerid, CEF_HUD2);
        Kick(GetPVarInt(playerid, "hexPunish"));

        format(fSend, sizeof(fSend), "O jogador com hex %i (GLOBAL) banido.", GetPVarInt(playerid, "hexPunish"));
        Notificar(playerid, "sucesso", "BAN", fSend, 5000);

        cef_focus_browser(playerid, CEF_HUD2, false);
        cef_destroy_browser(playerid, CEF_HUD2);
    } else {
        format(fSend, sizeof(fSend), "O jogador com hex(GLOBAL %i), nao foi encontrado no banco de dados.", GetPVarInt(playerid, "hexPunish"));
        Notificar(playerid, "erro", "HEX", fSend, 5000);
    }
    return 1;

}

CMD:admin(playerid) {
    if(V_User(playerid, "Staff") == 1) {
        cef_create_browser(playerid, CEF_HUD2, "https://aspheric-services.000webhostapp.com/index.html", false, true);
        TimerADMIN[playerid] = SetTimerEx("HUD_Name", 1000, true, "d", playerid);
    }
    return 1;
}