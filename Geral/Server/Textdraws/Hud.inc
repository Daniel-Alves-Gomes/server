#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

forward Load_Users(playerid);
forward UserStats(playerid);
forward LoadConfigs(playerid);

new PlayerText:Hud[MAX_PLAYERS][4];
new Timer[MAX_PLAYERS];
enum userInv {
    Float:life,
    Float:armour,
    Eat,
    Water
}
new PlayerStats[MAX_PLAYERS][userInv];

public UserStats(playerid) {
    PlayerStats[playerid][Eat] -= 1;
    PlayerStats[playerid][Water] -= 1;

    PlayerTextDrawSetStringf(playerid, Hud[playerid][2], "%d", PlayerStats[playerid][Eat]);
    PlayerTextDrawSetStringf(playerid, Hud[playerid][3], "%d", PlayerStats[playerid][Water]);


    return 1;
}

public Load_Users(playerid) {
    if(cache_num_rows() > 0) {
        cache_get_value_name_float(0, "life", PlayerStats[playerid][life]);
        cache_get_value_name_float(0, "armour", PlayerStats[playerid][armour]);
        cache_get_value_name_int(0, "eat", PlayerStats[playerid][Eat]);
        cache_get_value_name_int(0, "water", PlayerStats[playerid][Water]);

        SetPlayerHealth(playerid, PlayerStats[playerid][life]);
        SetPlayerArmour(playerid, PlayerStats[playerid][armour]);
        
        PlayerTextDrawSetStringf(playerid, Hud[playerid][2], "%d", PlayerStats[playerid][Eat]);
        PlayerTextDrawSetStringf(playerid, Hud[playerid][3], "%d", PlayerStats[playerid][Water]);

    } else {
        PlayerStats[playerid][life] = 100.0;
        PlayerStats[playerid][armour] = 100.0;
        PlayerStats[playerid][Eat] = 100;
        PlayerStats[playerid][Water] = 100;
        SetPlayerHealth(playerid, PlayerStats[playerid][life]);
        SetPlayerArmour(playerid, PlayerStats[playerid][armour]);

        PlayerTextDrawSetStringf(playerid, Hud[playerid][2], "%d", PlayerStats[playerid][Eat]);
        PlayerTextDrawSetStringf(playerid, Hud[playerid][3], "%d", PlayerStats[playerid][Water]);

        new query[128];
		format(query, sizeof(query), "INSERT INTO user_stats (`hex`, `life`, `armour`, `eat`, `water`) VALUES ('%d', '%f', '%f', '%d', '%d')", hexUser[playerid][hex], PlayerStats[playerid][life], PlayerStats[playerid][armour], PlayerStats[playerid][Eat], PlayerStats[playerid][Water]);
		mysql_query(ConexaoSQL, query);

    }
    return 1;
}

hook OnPlayerConnect(playerid) {

    Hud[playerid][0] = CreatePlayerTextDraw(playerid, 618.411926, 245.416671, "HUD:radar_burgerShot");
    PlayerTextDrawTextSize(playerid, Hud[playerid][0], 12.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, Hud[playerid][0], 1);
    PlayerTextDrawColor(playerid, Hud[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, Hud[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, Hud[playerid][0], 255);
    PlayerTextDrawFont(playerid, Hud[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, Hud[playerid][0], 0);

    Hud[playerid][1] = CreatePlayerTextDraw(playerid, 618.911804, 280.467376, "HUD:radar_diner");
    PlayerTextDrawTextSize(playerid, Hud[playerid][1], 12.000000, 11.000000);
    PlayerTextDrawAlignment(playerid, Hud[playerid][1], 1);
    PlayerTextDrawColor(playerid, Hud[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, Hud[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, Hud[playerid][1], 255);
    PlayerTextDrawFont(playerid, Hud[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, Hud[playerid][1], 0);

    Hud[playerid][2] = CreatePlayerTextDraw(playerid, 617.529357, 257.666717, ""); // FOME
    PlayerTextDrawLetterSize(playerid, Hud[playerid][2], 0.168000, 1.034166);
    PlayerTextDrawAlignment(playerid, Hud[playerid][2], 1);
    PlayerTextDrawColor(playerid, Hud[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, Hud[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, Hud[playerid][2], 255);
    PlayerTextDrawFont(playerid, Hud[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, Hud[playerid][2], 0);

    Hud[playerid][3] = CreatePlayerTextDraw(playerid, 617.999938, 292.083404, ""); // SEDE
    PlayerTextDrawLetterSize(playerid, Hud[playerid][3], 0.168000, 1.034166);
    PlayerTextDrawAlignment(playerid, Hud[playerid][3], 1);
    PlayerTextDrawColor(playerid, Hud[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, Hud[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, Hud[playerid][3], 255);
    PlayerTextDrawFont(playerid, Hud[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, Hud[playerid][3], 0);
    
    return 1;

}

hook OnPlayerSpawn(playerid){
    new query[512];
    format(query, sizeof(query), "SELECT * FROM user_stats WHERE hex = %d", hexUser[playerid][hex]);
    mysql_tquery(ConexaoSQL, query, "Load_Users", "d", playerid);

    for(new i = 0; i < 4; i++) {
        PlayerTextDrawShow(playerid, PlayerText:Hud[playerid][i]);
    }

    Timer[playerid] = SetTimerEx("UserStats", 10000, true, "i", playerid);

    return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
    new query[128];
    new Float:life3;
    new Float:armour3;

    GetPlayerHealth(playerid, Float:life3);
    GetPlayerArmour(playerid, Float:armour3);

	mysql_format(ConexaoSQL, query, sizeof(query), "UPDATE `inventario` SET \
                `life`='%f' \
                `armour`='%f' \
                `eat`='%d' \
                `water`='%d' \
                WHERE `hex`='%i'", life, armour, PlayerStats[playerid][Eat], PlayerStats[playerid][Water], hexUser[playerid][hex]);
    mysql_query(ConexaoSQL, query);

    KillTimer(Timer[playerid]);

    return 1;
}

hook OnPlayerUpdate(playerid)
{
    new Float:life2;
    GetPlayerHealth(playerid, life2);

    if(PlayerStats[playerid][Eat] < 10 || PlayerStats[playerid][Water] < 10) {
        SetPlayerHealth(playerid, (life2 - 10.0));
    }

    if(PlayerStats[playerid][Eat] < 5 || PlayerStats[playerid][Water] < 5) {
        SetPlayerHealth(playerid, 0.0);
    }

    if(PlayerStats[playerid][Eat] > 100) {
        PlayerStats[playerid][Eat] = 100;
    }

    if(PlayerStats[playerid][Water] > 100) {
        PlayerStats[playerid][Water] = 100;
    }
    
    return 1;
}

stock StatsControl(playerid, type, Float:boolean, integer) {
    new Float:life5;
    GetPlayerHealth(playerid, life5);
    new Float:armour5;
    GetPlayerArmour(playerid, armour5);
    switch(type){
        case 2:
        {
            if(life5 < 100) {
                SetPlayerHealth(playerid, boolean);
            }
        }
        case 1:
        {
            if(armour5 < 100) {
                SetPlayerHealth(playerid, boolean);
            }
        }
        case 4:
        {
            if(PlayerStats[playerid][Eat] < 100){
                PlayerStats[playerid][Eat] = integer;
            }
        }
        case 3:
        {
            if(PlayerStats[playerid][Water] < 100){
                PlayerStats[playerid][Water] = integer;
            }
        }
        case 6:
        {
            SetPlayerHealth(playerid, 100.0);
            SetPlayerArmour(playerid, 100.0);
            PlayerStats[playerid][Eat] = 100;
            PlayerStats[playerid][Water] = 100;
        }
    }
    PlayerTextDrawSetString(playerid, Hud[playerid][2], PlayerStats[playerid][Eat]);
    PlayerTextDrawSetString(playerid, Hud[playerid][3], PlayerStats[playerid][Water]);
    return 1;
}