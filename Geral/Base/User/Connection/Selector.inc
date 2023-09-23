#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

#define TIPO (25556)

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    static Query[128];
    if(dialogid == TIPO){
        if(response) {
                mysql_format(ConexaoSQL, Query, sizeof(Query), "UPDATE `server_accounts` SET \
                    `skin`='154' \
                    `tipo`='M' \
                    WHERE `nome`='%s'", GetPlayerNameEx(playerid));
                mysql_query(ConexaoSQL, Query);
                SpawnPlayer(playerid);
                SetSpawnInfo(playerid, 0, 154, 1958.33, 1343.12, 15.36, 0, 0, 0, 0, 0, 0, 0);
        } else {
                mysql_format(ConexaoSQL, Query, sizeof(Query), "UPDATE `server_accounts` SET \
                    `skin`='190' \
                    `tipo`='F' \
                    WHERE `nome`='%s'", GetPlayerNameEx(playerid));
                mysql_query(ConexaoSQL, Query);
                SetSpawnInfo(playerid, 0, 190, 1958.33, 1343.12, 15.36, 0, 0, 0, 0, 0, 0, 0);
        }
    }
    return 1;
}

stock OpenSelector(playerid) {
    ShowPlayerDialog(playerid, TIPO, DIALOG_STYLE_MSGBOX, "SELECIONE SEU SEXO", "Clique nos botões", "Masculino", "Feminino");
    return 1;
}