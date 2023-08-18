#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

new IsRote[MAX_PLAYERS];

stock BUY_Rotas(playerid, const nameRote[]) {
    if(nameRote == "tinta") {   
        if(IsRote[playerid] == 0) {
            SetPlayerCheckpoint(playerid, Float:GetPVarFloat(playerid, "tx"), Float:GetPVarFloat(playerid, "ty"), Float:GetPVarFloat(playerid, "tz"), 1.0);
            Notificar(playerid, "info", "EMPREGOS", "Siga o checkpoint.", 5000);
            IsRote[playerid] = 1;
        }
    } else if(nameRote == "toxic") {
        if(IsRote[playerid] == 0) {
            SetPlayerCheckpoint(playerid, Float:GetPVarFloat(playerid, "tox"), Float:GetPVarFloat(playerid, "toy"), Float:GetPVarFloat(playerid, "toz"), 1.0);
            Notificar(playerid, "info", "EMPREGOS", "Siga o checkpoint.", 5000);
            IsRote[playerid] = 1;
        }
    }
    return 1;
}

stock D_C(playerid) {
    ShowPlayerDialog(playerid, 2, DIALOG_STYLE_LIST, "CAMINHONEIRO", "Caminhão\nRotas", "Confirmar", "Fechar");
    return 1;
}