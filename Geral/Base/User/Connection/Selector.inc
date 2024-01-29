#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

#define TIPO (25556)

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    new QueryUser[128];
    if(dialogid == TIPO){
        if(response) {
            switch(listitem) {
                case 0:
                {
                    mysql_format(ConexaoSQL, QueryUser, sizeof(QueryUser), "UPDATE `server_accounts` SET \
                        `skin`='154', \
                        `tipo`='M' \
                        WHERE `hex`='%d'", hexUser[playerid][hex]);
                    mysql_query(ConexaoSQL, QueryUser);
                    SpawnPlayer(playerid);
                    SetSpawnInfo(playerid, 0, 154, 1958.33, 1343.12, 15.36, 0, 0, 0, 0, 0, 0, 0);
                    TogglePlayerSpectating(playerid, false);
                }
                case 1:
                {
                    mysql_format(ConexaoSQL, QueryUser, sizeof(QueryUser), "UPDATE `server_accounts` SET \
                        `skin`='154', \
                        `tipo`='F' \
                        WHERE `hex`='%d'", hexUser[playerid][hex]);
                    mysql_query(ConexaoSQL, QueryUser);
                    SpawnPlayer(playerid);
                    SetSpawnInfo(playerid, 0, 154, 1958.33, 1343.12, 15.36, 0, 0, 0, 0, 0, 0, 0);
                    TogglePlayerSpectating(playerid, false);
                }
            }
        } else {
            Kick(playerid);
        }
    }
    return 1;
}

stock OpenSelector(playerid) {
    ShowPlayerDialog(playerid, TIPO, DIALOG_STYLE_LIST, "SELECIONE SEU SEXO", "Masculino\nFeminino", "Confirmar", "Sair");
    return 1;
}