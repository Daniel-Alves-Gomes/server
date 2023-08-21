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
        case 16: str = "Revólver";
        case 17: str = "Faca";
        case 18: str = "Metanfetamina";
        case 19: str = "Cocaína";
        case 20: str = "Colete";
        case 21: str = "Pistola";
        case 22: str = "Rifle";
        case 23: str = "Laptop";
        case 24: str = "Tablet";
        case 25: str = "Maconha";
        case 26: str = "Heroína";
        case 27: str = "Pizza";
        case 28: str = "Sorvete";
        case 29: str = "Cachorro-Quente";
        case 30: str = "Sanduíche";
        case 31: str = "Cerveja";
        case 32: str = "Vinho";
        case 33: str = "Whisky";
        case 34: str = "Barra de Chocolate";
        case 35: str = "Bala de Menta";
        case 36: str = "Peixe Grelhado";
        case 37: str = "Arroz";
        case 38: str = "Banana";
        case 39: str = "Maçã";
        case 40: str = "Kit Médico";
        case 41: str = "Kit Reparos";
        case 42: str = "Extintor";
        case 43: str = "Adaga";
        case 44: str = "Metralhadora";
        case 45: str = "LSD";
        case 46: str = "MDMA";
        case 47: str = "Lata de Spray";
        case 48: str = "Gás Lacrimogêneo";
        case 49: str = "Granada";
        case 50: str = "Saco de Dinheiro";
        case 51: str = "Chaves do Carro";
        case 52: str = "Óculos Escuros";
        case 53: str = "Chapéu";
        case 54: str = "Relógio";
        case 55: str = "Livro";
        case 56: str = "Bolsa";
        case 57: str = "Laptop Roubado";
        case 58: str = "Bilhete de Trem";
        case 59: str = "Mapa da Cidade";
        case 60: str = "Cigarro";
        case 61: str = "Isqueiro";
        case 62: str = "Câmera";
        case 63: str = "Binóculos";
        case 64: str = "Escova de Dentes";
        case 65: str = "Perfume";
        case 66: str = "Cinto";
        case 67: str = "Pulseira";
        case 68: str = "Anel";
        case 69: str = "Mochila";
        case 100: str = "";
    }

    return str;
}

stock ITEM_PesoGET(id) {
    new weight = 0;
    switch(id) {
        case 1: weight = 1; // Suco De Laranja
        case 3: weight = 1; // Suco De Morango
        case 4: weight = 1; // Suco De Maça
        case 5: weight = 1; // Suco De Abacaxi
        case 6: weight = 1; // Cookie
        case 7: weight = 1; // Hamburguer
        case 8: weight = 1; // Cookie De Natal
        case 9: weight = 1; // X-Salada
        case 10: weight = 1; // Taco
        case 11: weight = 1; // Biscoito Lua
        case 12: weight = 1; // Bolacha Chease
        case 13: weight = 2; // Celular
        case 14: weight = 2; // Celular IOX
        case 15: weight = 2; // Rádio
        case 16: weight = 3; // Revólver
        case 17: weight = 2; // Faca
        case 18: weight = 1; // Metanfetamina
        case 19: weight = 1; // Cocaína
        case 20: weight = 10; // Colete
        case 21: weight = 3; // Pistola
        case 22: weight = 6; // Rifle
        case 23: weight = 5; // Laptop
        case 24: weight = 3; // Tablet
        case 25: weight = 1; // Maconha
        case 26: weight = 1; // Heroína
        case 27: weight = 1; // Pizza
        case 28: weight = 1; // Sorvete
        case 29: weight = 1; // Cachorro-Quente
        case 30: weight = 1; // Sanduíche
        case 31: weight = 1; // Cerveja
        case 32: weight = 1; // Vinho
        case 33: weight = 1; // Whisky
        case 34: weight = 1; // Barra de Chocolate
        case 35: weight = 1; // Bala de Menta
        case 36: weight = 1; // Peixe Grelhado
        case 37: weight = 1; // Arroz
        case 38: weight = 1; // Banana
        case 39: weight = 1; // Maçã
        case 40: weight = 2; // Kit Médico
        case 41: weight = 2; // Kit Reparos
        case 42: weight = 2; // Extintor
        case 43: weight = 2; // Adaga
        case 44: weight = 6; // Metralhadora
        case 45: weight = 1; // LSD
        case 46: weight = 1; // MDMA
        case 47: weight = 1; // Lata de Spray
        case 48: weight = 2; // Gás Lacrimogêneo
        case 49: weight = 2; // Granada
        case 50: weight = 1; // Saco de Dinheiro
        case 51: weight = 1; // Chaves do Carro
        case 52: weight = 1; // Óculos Escuros
        case 53: weight = 1; // Chapéu
        case 54: weight = 1; // Relógio
        case 55: weight = 1; // Livro
        case 56: weight = 1; // Bolsa
        case 57: weight = 3; // Laptop Roubado
        case 58: weight = 1; // Bilhete de Trem
        case 59: weight = 1; // Mapa da Cidade
        case 60: weight = 1; // Cigarro
        case 61: weight = 1; // Isqueiro
        case 62: weight = 1; // Câmera
        case 63: weight = 2; // Binóculos
        case 64: weight = 1; // Escova de Dentes
        case 65: weight = 1; // Perfume
        case 66: weight = 1; // Cinto
        case 67: weight = 1; // Pulseira
        case 68: weight = 1; // Anel
        case 69: weight = 1; // Mochila
        case 100: weight = 1; // Item Desconhecido
    }

    return weight;
}
