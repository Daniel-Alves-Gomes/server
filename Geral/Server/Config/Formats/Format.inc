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

stock eNumero(const input[])
{
    new i = 0;
    while (input[i])
    {
        if (!('0' <= input[i] && input[i] <= '9'))
        {
            return false;
        }
        i++;
    }
    return true;
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



stock Float:Power(Float:base, exponent) {
    new Float:result = 1.0;
    for (new i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

stock Float:fabs(Float:value) {
    return (value >= 0.0) ? value : -value;
}

stock Float:NewtonSqrt(Float:value) {
    if (value <= 0.0) return 0.0;

    new Float:x0 = value;
    new Float:x1 = (x0 + value / x0) / 2.0;

    while (Float:fabs(x1 - x0) >= 0.0001) {
        x0 = x1;
        x1 = (x0 + value / x0) / 2.0;
    }

    return x1;
}

stock Float:GetDistance(Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2) {
    return NewtonSqrt(Power(x2 - x1, 2) + Power(y2 - y1, 2) + Power(z2 - z1, 2));
}