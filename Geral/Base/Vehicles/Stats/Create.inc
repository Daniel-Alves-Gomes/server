#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

new Vehicle[MAX_PLAYERS];

stock V_Create(playerid, carid) {
    new car = carid;
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    Vehicle[playerid] = CreateVehicle(car, x + 3.0, y + 3.0, z + 3.0, 0, 1, 1, -1, -1);
    DATA_VEHICLE[Vehicle[playerid]][DATA_FUEL] = 60;
    DATA_VEHICLE[Vehicle[playerid]][VEHICLE_ON] = 1;
    DATA_VEHICLE[Vehicle[playerid]][Cinto_A] = 1;
    return 1;
}