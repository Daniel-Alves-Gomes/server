#include <a_samp>
#include <a_mysql>
#include <YSI-Includes\YSI_Coding\y_hooks>

#define HOST "localhost"
#define USER "root"
#define DTBS "database"
#define PASS ""

new MySQL:ConexaoSQL;

hook OnGameModeInit() {
    ConexaoSQL = mysql_connect(HOST,USER,PASS,DTBS);
    new tick[128];
    format(tick, sizeof(tick), "[alpha]: A conexão com a database ['%s'] não foi conectada pelo seguinte erro ['%i'].", DTBS, mysql_errno(ConexaoSQL));
    if(mysql_errno(ConexaoSQL) != 0) {
        printf(tick);
    } else {
        printf("[alpha]: A conexão com a database ['%s'] foi concluida!", DTBS);
    }
    return true;
}