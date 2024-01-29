#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

enum Morte {
    Float:PosMX,
    Float:PosMY,
    Float:PosMZ,
    Morreu
}

new PlayerText:MorteTD[MAX_PLAYERS][4];
new morteText[MAX_PLAYERS];
new morteConfigs[MAX_PLAYERS][Morte];
new mortoUpdate[MAX_PLAYERS];
new mortoTimer[MAX_PLAYERS];
new mortoTempo[MAX_PLAYERS];
new mortoAnim[MAX_PLAYERS];

forward Morto(playerid);

hook OnPlayerConnect(playerid) {

    MorteTD[playerid][0] = CreatePlayerTextDraw(playerid, 337.058746, 379.583374, "Voce_desmaiou,_restam");
    PlayerTextDrawLetterSize(playerid, MorteTD[playerid][0], 0.170823, 1.080832);
    PlayerTextDrawAlignment(playerid, MorteTD[playerid][0], 3);
    PlayerTextDrawColor(playerid, MorteTD[playerid][0], -2139062017);
    PlayerTextDrawSetShadow(playerid, MorteTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, MorteTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, MorteTD[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, MorteTD[playerid][0], 1);

    MorteTD[playerid][1] = CreatePlayerTextDraw(playerid, 340.658966, 379.583374, "300");
    PlayerTextDrawLetterSize(playerid, MorteTD[playerid][1], 0.170823, 1.080832);
    PlayerTextDrawAlignment(playerid, MorteTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, MorteTD[playerid][1], 16711935);
    PlayerTextDrawSetShadow(playerid, MorteTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, MorteTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, MorteTD[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, MorteTD[playerid][1], 1);

    MorteTD[playerid][2] = CreatePlayerTextDraw(playerid, 357.559997, 379.583374, "SEGUNDOS.");
    PlayerTextDrawLetterSize(playerid, MorteTD[playerid][2], 0.170823, 1.080832);
    PlayerTextDrawAlignment(playerid, MorteTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, MorteTD[playerid][2], -2139062017);
    PlayerTextDrawSetShadow(playerid, MorteTD[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, MorteTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, MorteTD[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, MorteTD[playerid][2], 1);

    MorteTD[playerid][3] = CreatePlayerTextDraw(playerid, 307.456939, 394.284271, "/DESISTIR");
    PlayerTextDrawLetterSize(playerid, MorteTD[playerid][3], 0.170823, 1.080832);
    PlayerTextDrawAlignment(playerid, MorteTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, MorteTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, MorteTD[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, MorteTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, MorteTD[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, MorteTD[playerid][3], 1);
    return 1;
}


hook OnPlayerDisconnect(playerid) {
    morteConfigs[playerid][Morreu] = 0;
    if(mortoUpdate[playerid] == 1) {
        new Query[128];
        mysql_format(ConexaoSQL, Query, sizeof(Query), "DELETE FROM inventario WHERE hex = %d", hexUser[playerid][hex]);
        mysql_query(ConexaoSQL, Query);
    }
    return 1;
}

public Morto(playerid) {
    if(mortoTempo[playerid] > 1) {
        if(mortoAnim[playerid] == 0) {
            mortoTempo[playerid]--;
            ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 0, 1, 1, 1, -1, 1);
            PlayerTextDrawSetStringf(playerid, MorteTD[playerid][1], "%d", mortoTempo[playerid]);       
       }
    } else {
        for(new i = 0; i < 3; i++) {
            PlayerTextDrawHide(playerid, MorteTD[playerid][i]);
        }
        PlayerTextDrawShow(playerid, MorteTD[playerid][3]);
        KillTimer(mortoTimer[playerid]);
        mortoTempo[playerid] = 0;
        morteConfigs[playerid][Morreu] = 0;
    }
    return 1;
}

public OnPlayerDeath(playerid, killerid, reason) {
    morteConfigs[playerid][Morreu] = 1;
    SpawnPlayer(playerid);
    SetSpawnInfo(playerid, NO_TEAM, getsUser[playerid][Skin], morteConfigs[playerid][PosMX], morteConfigs[playerid][PosMY], morteConfigs[playerid][PosMZ], 0.0, 0, 0, 0, 0, 0, 0); 
    ResetPlayerMoney(playerid);
    ResetPlayerWeapons(playerid);
    return 1;
}

hook OnPlayerUpdate(playerid) {
    if(mortoUpdate[playerid] == 0){
        GetPlayerPos(playerid, morteConfigs[playerid][PosMX], morteConfigs[playerid][PosMY], morteConfigs[playerid][PosMZ]);
        if(morteConfigs[playerid][Morreu] == 1) {
            mortoUpdate[playerid] = 1;
            mortoTempo[playerid] = 120;
            mortoTimer[playerid] = SetTimerEx("Morto", 1000, true, "i", playerid);
            if(morteText[playerid] == 0) {
                PlayerTextDrawShow(playerid, MorteTD[playerid][0]);
                PlayerTextDrawShow(playerid, MorteTD[playerid][1]);
                PlayerTextDrawShow(playerid, MorteTD[playerid][2]);
            }
        }
    }
    return 1;
}

stock V_Morto(playerid) {
    if(morteConfigs[playerid][Morreu] == 1) return 1;
    return 0;
}

CMD:desistir(playerid) {
    if(V_Morto(playerid) == 1) return 1;
    if(mortoTempo[playerid] == 0) {
        PlayerTextDrawShow(playerid, MorteTD[playerid][3]);
        KillTimer(mortoTimer[playerid]);
        mortoUpdate[playerid] = 0;
        mortoTempo[playerid] = 0;
        new Query[128];
        mysql_format(ConexaoSQL, Query, sizeof(Query), "DELETE FROM inventario WHERE hex = %d", hexUser[playerid][hex]);
        mysql_query(ConexaoSQL, Query);
        ResetPlayerMoney(playerid);
        ResetPlayerWeapons(playerid);
    }
    return 1;
}