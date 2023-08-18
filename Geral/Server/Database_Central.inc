#include <a_samp>
#include <a_mysql>
#include <YSI-Includes\YSI_Coding\y_hooks>

#define HOST "localhost"
#define USER "root"
#define DTBS "ambarsamp"
#define PASS ""

new MySQL:ConexaoSQL;

hook OnGameModeInit() {
     
    ConexaoSQL = mysql_connect(HOST,USER,PASS,DTBS);


    new tick[128];
    format(tick, sizeof(tick), "[Ambar]: A conexão com a database ['%s'] não foi conectada pelo seguinte erro ['%s'].", DTBS, SQL_Errno(mysql_errno(ConexaoSQL)));
    if(mysql_errno(ConexaoSQL) != 0) {
        printf(tick);
        SendRconCommand("exit");
    } else {
        printf("[Ambar]: A conexão com a database ['%s'] foi concluida!", DTBS);
    }
    return true;
}