#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

stock V_User(playerid, const cargo[]) {
    new cargoUser[128];
    new returnConst;
    GetPVarString(playerid, "admin", cargoUser, sizeof(cargoUser));
    if(strcmp(cargoUser, cargo) == 0) {
        returnConst = 1;
    } else {
        returnConst = 0;
    }
    return returnConst;
}

stock G_User(playerid, const cargo[], const cargo2[]) {
    new cargoUser[128];
    new returnConst;
    GetPVarString(playerid, cargo2, cargoUser, sizeof(cargoUser));
    if(strcmp(cargoUser, cargo) == 0) {
        returnConst = 1;
    } else {
        returnConst = 0;
    }
    return returnConst;
}