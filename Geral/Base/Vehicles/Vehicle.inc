#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

new Vehicle[MAX_PLAYERS];

CMD:car(playerid, params[])
{
    new car;
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(V_User(playerid, "Staff") == 1) {
        if(sscanf(params,"i", car)) return SendClientMessage(playerid,0xff0000ff,"USAGE: /car < 400 - 611>");
        if(car < 400 || car >611) return SendClientMessage(playerid, 0xff0000ff, "ERROR: Veiculo não existente.");
        Vehicle[playerid] = CreateVehicle(car, x + 3.0, y + 3.0, z + 3.0, 0, 1, 1, -1, -1);
        DATA_VEHICLE[Vehicle[playerid]][DATA_FUEL] = 100.0;
        DATA_VEHICLE[Vehicle[playerid]][VEHICLE_ON] = 1;
        DATA_VEHICLE[Vehicle[playerid]][Cinto_A] = 1;
    }
    return 1;
}