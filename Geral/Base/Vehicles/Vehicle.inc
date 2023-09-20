#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

CMD:car(playerid, params[])
{
    new car;
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(V_User(playerid, "Staff") == 1) {
        if(sscanf(params,"i", car)) {
            Notificar(playerid, "ADMIN", "Carro invalido");
        }else if(car < 400 || car >611) {
            Notificar(playerid, "ADMIN", "Adicione um id válido.");
        } else {
            V_Create(playerid, car);
        }
    }
    return 1;
}