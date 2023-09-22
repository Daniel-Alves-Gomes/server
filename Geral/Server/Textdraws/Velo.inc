#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

new PlayerText:Veloc[MAX_PLAYERS][15];
new TimerConfs[MAX_PLAYERS];

forward VehicleConfigs(playerid, vehicleid);

public VehicleConfigs(playerid, vehicleid) {
    new veloVehicle = VelocidadeDoVeiculo(vehicleid);
    new sstats[128];
    for(new i = 0; i < 15; i++) {
        PlayerTextDrawShow(playerid, Veloc[playerid][i]);
    }
    if(DATA_VEHICLE[vehicleid][VEHICLE_ON] == 1) {
        format(sstats, sizeof(sstats), "ON");
        PlayerTextDrawColor(playerid, Veloc[playerid][12], -1);
        PlayerTextDrawSetString(playerid, Veloc[playerid][12], sstats);
    } else {
        format(sstats, sizeof(sstats), "OFF");
        PlayerTextDrawColor(playerid, Veloc[playerid][12], -1);
        PlayerTextDrawSetString(playerid, Veloc[playerid][12], sstats);
    }
    PlayerTextDrawSetStringf(playerid, Veloc[playerid][11], "%d", veloVehicle);
    PlayerTextDrawSetStringf(playerid, Veloc[playerid][13], "%d", DATA_VEHICLE[vehicleid][DATA_FUEL]);
    return 1;
}

hook OnPlayerConnect(playerid) {

    Veloc[playerid][0] = CreatePlayerTextDraw(playerid, 529.059020, 363.833312, "box");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][0], 0.000000, 5.482345);
    PlayerTextDrawTextSize(playerid, Veloc[playerid][0], 626.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][0], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, Veloc[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, Veloc[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][0], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][0], 1);

    Veloc[playerid][1] = CreatePlayerTextDraw(playerid, 520.999938, 354.500091, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Veloc[playerid][1], 19.000000, 21.000000);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][1], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][1], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][1], 0);

    Veloc[playerid][2] = CreatePlayerTextDraw(playerid, 520.999938, 403.500244, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Veloc[playerid][2], 19.000000, 21.000000);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][2], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][2], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][2], 0);

    Veloc[playerid][3] = CreatePlayerTextDraw(playerid, 616.999755, 353.916656, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Veloc[playerid][3], 19.000000, 21.000000);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][3], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][3], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][3], 0);

    Veloc[playerid][4] = CreatePlayerTextDraw(playerid, 617.000122, 404.083404, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, Veloc[playerid][4], 19.000000, 21.000000);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][4], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][4], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][4], 0);

    Veloc[playerid][5] = CreatePlayerTextDraw(playerid, 531.411987, 359.749969, "box");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][5], 0.000000, 0.211763);
    PlayerTextDrawTextSize(playerid, Veloc[playerid][5], 628.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][5], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][5], -1);
    PlayerTextDrawUseBox(playerid, Veloc[playerid][5], 1);
    PlayerTextDrawBoxColor(playerid, Veloc[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][5], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, Veloc[playerid][5], true);

    Veloc[playerid][6] = CreatePlayerTextDraw(playerid, 531.882629, 418.083435, "box");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][6], 0.000000, 0.070589);
    PlayerTextDrawTextSize(playerid, Veloc[playerid][6], 631.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][6], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][6], -1);
    PlayerTextDrawUseBox(playerid, Veloc[playerid][6], 1);
    PlayerTextDrawBoxColor(playerid, Veloc[playerid][6], 255);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][6], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][6], 1);
    PlayerTextDrawSetSelectable(playerid, Veloc[playerid][6], true);

    Veloc[playerid][7] = CreatePlayerTextDraw(playerid, 525.765197, 369.083435, "box");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][7], 0.000000, 4.588239);
    PlayerTextDrawTextSize(playerid, Veloc[playerid][7], 626.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][7], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][7], -1);
    PlayerTextDrawUseBox(playerid, Veloc[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, Veloc[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][7], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, Veloc[playerid][7], true);

    Veloc[playerid][8] = CreatePlayerTextDraw(playerid, 527.647705, 368.500152, "box");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][8], 0.000000, 4.588239);
    PlayerTextDrawTextSize(playerid, Veloc[playerid][8], 631.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][8], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][8], -1);
    PlayerTextDrawUseBox(playerid, Veloc[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, Veloc[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][8], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, Veloc[playerid][8], true);

    Veloc[playerid][9] = CreatePlayerTextDraw(playerid, 573.294128, 390.666595, "KM/H");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][9], 0.122823, 0.783333);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][9], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][9], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][9], 1);

    Veloc[playerid][10] = CreatePlayerTextDraw(playerid, 529.529235, 397.666687, "MOTOR~n~");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][10], 0.146823, 0.905833);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][10], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][10], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][10], 1);

    Veloc[playerid][11] = CreatePlayerTextDraw(playerid, 570.470581, 380.166748, "100");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][11], 0.261647, 1.092499);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][11], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][11], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][11], 1);

    Veloc[playerid][12] = CreatePlayerTextDraw(playerid, 531.882385, 407.583312, "ON");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][12], 0.206117, 0.917500);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][12], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][12], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][12], 1);

    Veloc[playerid][13] = CreatePlayerTextDraw(playerid, 603.411743, 397.083282, "60");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][13], 0.283294, 1.121666);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][13], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][13], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][13], 1);

    Veloc[playerid][14] = CreatePlayerTextDraw(playerid, 617.529357, 397.083312, "L");
    PlayerTextDrawLetterSize(playerid, Veloc[playerid][14], 0.287529, 1.168333);
    PlayerTextDrawAlignment(playerid, Veloc[playerid][14], 1);
    PlayerTextDrawColor(playerid, Veloc[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, Veloc[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, Veloc[playerid][14], 255);
    PlayerTextDrawFont(playerid, Veloc[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, Veloc[playerid][14], 1);

    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if(newkeys == KEY_YES) {
        V_Status(playerid);
    }
	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
        V_Gaso(vehicleid);
    }
    return 1;
}

hook OnPlayerUpdate(playerid) {
    new vehicleId[MAX_PLAYERS];
    vehicleId[playerid] = GetPlayerVehicleID(playerid);
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
        AbrirVelo(playerid, vehicleId[playerid]);
    } else if(GetPlayerState(playerid) == PLAYER_STATE_PASSENGER) {
        AbrirVelo(playerid, vehicleId[playerid]);
    }
    return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid) {
    FecharVelo(playerid);
    return 1;
}

AbrirVelo(playerid, vehicleid) {
    new veloVehicle = VelocidadeDoVeiculo(vehicleid);
    new sstats[128];
    for(new i = 0; i < 15; i++) {
        PlayerTextDrawShow(playerid, Veloc[playerid][i]);
    }
    if(DATA_VEHICLE[vehicleid][VEHICLE_ON] == 1) {
        format(sstats, sizeof(sstats), "ON");
        PlayerTextDrawColor(playerid, Veloc[playerid][12], -1);
        PlayerTextDrawSetString(playerid, Veloc[playerid][12], sstats);
    } else {
        format(sstats, sizeof(sstats), "OFF");
        PlayerTextDrawColor(playerid, Veloc[playerid][12], -1);
        PlayerTextDrawSetString(playerid, Veloc[playerid][12], sstats);
    }
    PlayerTextDrawSetStringf(playerid, Veloc[playerid][11], "%d", veloVehicle);
    PlayerTextDrawSetStringf(playerid, Veloc[playerid][13], "%d", DATA_VEHICLE[vehicleid][DATA_FUEL]);
    TimerConfs[playerid] = SetTimerEx("VehicleConfigs", 10000, true, "ii", playerid, vehicleid);
    return 1;
}


FecharVelo(playerid) {
    for(new i = 0; i < 15; i++) {
        PlayerTextDrawHide(playerid, Veloc[playerid][i]);
    }
    KillTimer(TimerConfs[playerid]);
    return 1;
}