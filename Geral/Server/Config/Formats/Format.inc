#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

#define RELEASED(%0) \
	(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))
#define PRESSED(%0) \
	(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

stock SQL_Errno(Error) {
    new errno[59];
    if(Error == 1049) {
        format(errno, sizeof(errno), "DTBS does not exist");
    }
    return errno;
}

stock GetPlayerNameEx(playerid)
{
    static pname[MAX_PLAYER_NAME];
    GetPlayerName(playerid, pname, MAX_PLAYER_NAME);
    return pname;
}

stock TABLE_SetEConst(hexu, const tabletSet[], const tableValue[]) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "INSERT INTO %s (`hex`, `job`) VALUES ('%d', '%s')", tabletSet, hexu, tableValue);
    mysql_query(ConexaoSQL, Query);
    printf("S");
    return 1;
}

stock TABLE_SetConst(hexu, const tabletSet[], const ValueOne[], const ValueTwo[], const tableValue[], const tableValue2[]) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "INSERT INTO %s (`hex`, `%s`, `%s`) VALUES ('%d', '%s', '%s')", tabletSet, ValueOne, ValueTwo, hexu, tableValue, tableValue2);
    mysql_query(ConexaoSQL, Query);
    printf("S");
    return 1;
}

stock TABLE_SetIConst(hexu, const tabletSet[], const ValueOne[], const ValueTwo[], tableValue, tableValue2) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "INSERT INTO %s (`hex`, `%s`, `%s`) VALUES ('%d', '%d', '%d')", tabletSet, ValueOne, ValueTwo, hexu, tableValue, tableValue2);
    mysql_query(ConexaoSQL, Query);
    printf("S");
    return 1;
}

stock TABLE_SetFConst(hexu, const tabletSet[], const ValueOne[], const ValueTwo[], Float:tableValue[], Float:tableValue2) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "INSERT INTO %s (`hex`, `%s`, `%s`) VALUES ('%d', '%f', '%f')", tabletSet, ValueOne, ValueTwo, hexu, tableValue, tableValue2);
    mysql_query(ConexaoSQL, Query);
    printf("S");
    return 1;
}

stock ITEM_NameGET(id) {
    new str[250];
    switch(id) {
        case 50: str = "Coca-Cola";
        case 1: str = "Suco De Laranja";
        case 3: str = "Suco De Morango";
        case 4: str = "Suco De Maça";
        case 5: str = "Suco De Abacaxi";
        case 6: str = "Cookie";
        case 7: str = "Hamburguer";
        case 8: str = "Cookie De Natal";
        case 9: str = "X-Salada";
        case 10: str = "Taco";
        case 11: str = "Biscoito Lua";
        case 12: str = "Bolacha Chease";
        case 13: str = "Celular";
        case 14: str = "Celular IOX";
        case 15: str = "Rádio";
        case 20: str = "Colete";
        case 100: str = "";
    }

    return str;
}

stock ITEM_PesoGET(id) {
    new str;
    switch(id) {
        case 50: str = 1;
        case 1: str = 1;
        case 3: str = 1;
        case 4: str = 1;
        case 5: str = 1;
        case 6: str = 1;
        case 7: str = 1;
        case 8: str = 1;
        case 9: str = 1;
        case 10: str = 1;
        case 11: str = 1;
        case 12: str = 1;
        case 13: str = 2;
        case 14: str = 2;
        case 15: str = 2;
        case 20: str = 10;
    }

    return str;
}