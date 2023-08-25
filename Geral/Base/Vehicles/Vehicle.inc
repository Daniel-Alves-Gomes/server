#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

CMD:car(playerid, params[])
{
    new car;
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(V_User(playerid, "Staff") == 1) {
        if(sscanf(params,"i", car)) {
            Notificar(playerid, "erro", "ADMIN", "Carro invalido", 5000);
        }
        if(car < 400 || car >611) {
            Notificar(playerid, "erro", "ADMIN", "Carro invalido", 5000);
        }
        V_Create(playerid, car);
    }
    return 1;
}