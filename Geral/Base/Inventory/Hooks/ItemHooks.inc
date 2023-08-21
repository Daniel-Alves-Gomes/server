#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

#define MAX_ITEMS_ON_GROUND 10000

new ItemS[MAX_PLAYERS][40];
new QS[MAX_PLAYERS][40];
new DroppedItems[MAX_ITEMS_ON_GROUND][4];

forward Inventory_Load(playerid);

public Inventory_Load(playerid) {
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "id1", ItemS[playerid][0]);
        cache_get_value_name_int(0, "id2", ItemS[playerid][1]);
        cache_get_value_name_int(0, "id3", ItemS[playerid][2]);
        cache_get_value_name_int(0, "id4", ItemS[playerid][3]);
        cache_get_value_name_int(0, "id5", ItemS[playerid][4]);
        cache_get_value_name_int(0, "id6", ItemS[playerid][5]);
        cache_get_value_name_int(0, "id7", ItemS[playerid][6]);
        cache_get_value_name_int(0, "id8", ItemS[playerid][7]);
        cache_get_value_name_int(0, "id9", ItemS[playerid][8]);
        cache_get_value_name_int(0, "id10", ItemS[playerid][9]);
        cache_get_value_name_int(0, "id11", ItemS[playerid][10]);
        cache_get_value_name_int(0, "id12", ItemS[playerid][11]);
        cache_get_value_name_int(0, "id13", ItemS[playerid][12]);
        cache_get_value_name_int(0, "id14", ItemS[playerid][13]);
        cache_get_value_name_int(0, "id15", ItemS[playerid][14]);
        cache_get_value_name_int(0, "id16", ItemS[playerid][15]);
        cache_get_value_name_int(0, "id17", ItemS[playerid][16]);
        cache_get_value_name_int(0, "id18", ItemS[playerid][17]);
        cache_get_value_name_int(0, "id19", ItemS[playerid][18]);
        cache_get_value_name_int(0, "id20", ItemS[playerid][19]);
        cache_get_value_name_int(0, "id21", ItemS[playerid][20]);
        cache_get_value_name_int(0, "id22", ItemS[playerid][21]);
        cache_get_value_name_int(0, "id23", ItemS[playerid][22]);
        cache_get_value_name_int(0, "id24", ItemS[playerid][23]);
        cache_get_value_name_int(0, "id25", ItemS[playerid][24]);
        cache_get_value_name_int(0, "id26", ItemS[playerid][25]);
        cache_get_value_name_int(0, "id27", ItemS[playerid][26]);
        cache_get_value_name_int(0, "id28", ItemS[playerid][27]);
        cache_get_value_name_int(0, "id29", ItemS[playerid][28]);
        cache_get_value_name_int(0, "id30", ItemS[playerid][29]);
        cache_get_value_name_int(0, "id31", ItemS[playerid][30]);
        cache_get_value_name_int(0, "id32", ItemS[playerid][31]);
        cache_get_value_name_int(0, "id33", ItemS[playerid][32]);
        cache_get_value_name_int(0, "id34", ItemS[playerid][33]);
        cache_get_value_name_int(0, "id35", ItemS[playerid][34]);
        cache_get_value_name_int(0, "id36", ItemS[playerid][35]);
        cache_get_value_name_int(0, "id37", ItemS[playerid][36]);
        cache_get_value_name_int(0, "id38", ItemS[playerid][37]);
        cache_get_value_name_int(0, "id39", ItemS[playerid][38]);
        cache_get_value_name_int(0, "id40", ItemS[playerid][39]);

        cache_get_value_name_int(0, "peso1", QS[playerid][0]);
        cache_get_value_name_int(0, "peso2", QS[playerid][1]);
        cache_get_value_name_int(0, "peso3", QS[playerid][2]);
        cache_get_value_name_int(0, "peso4", QS[playerid][3]);
        cache_get_value_name_int(0, "peso5", QS[playerid][4]);
        cache_get_value_name_int(0, "peso6", QS[playerid][5]);
        cache_get_value_name_int(0, "peso7", QS[playerid][6]);
        cache_get_value_name_int(0, "peso8", QS[playerid][7]);
        cache_get_value_name_int(0, "peso9", QS[playerid][8]);
        cache_get_value_name_int(0, "peso10", QS[playerid][9]);
        cache_get_value_name_int(0, "peso11", QS[playerid][10]);
        cache_get_value_name_int(0, "peso12", QS[playerid][11]);
        cache_get_value_name_int(0, "peso13", QS[playerid][12]);
        cache_get_value_name_int(0, "peso14", QS[playerid][13]);
        cache_get_value_name_int(0, "peso15", QS[playerid][14]);
        cache_get_value_name_int(0, "peso16", QS[playerid][15]);
        cache_get_value_name_int(0, "peso17", QS[playerid][16]);
        cache_get_value_name_int(0, "peso18", QS[playerid][17]);
        cache_get_value_name_int(0, "peso19", QS[playerid][18]);
        cache_get_value_name_int(0, "peso20", QS[playerid][19]);
        cache_get_value_name_int(0, "peso21", QS[playerid][20]);
        cache_get_value_name_int(0, "peso22", QS[playerid][21]);
        cache_get_value_name_int(0, "peso23", QS[playerid][22]);
        cache_get_value_name_int(0, "peso24", QS[playerid][23]);
        cache_get_value_name_int(0, "peso25", QS[playerid][24]);
        cache_get_value_name_int(0, "peso26", QS[playerid][25]);
        cache_get_value_name_int(0, "peso27", QS[playerid][26]);
        cache_get_value_name_int(0, "peso28", QS[playerid][27]);
        cache_get_value_name_int(0, "peso29", QS[playerid][28]);
        cache_get_value_name_int(0, "peso30", QS[playerid][29]);
        cache_get_value_name_int(0, "peso31", QS[playerid][30]);
        cache_get_value_name_int(0, "peso32", QS[playerid][31]);
        cache_get_value_name_int(0, "peso33", QS[playerid][32]);
        cache_get_value_name_int(0, "peso34", QS[playerid][33]);
        cache_get_value_name_int(0, "peso35", QS[playerid][34]);
        cache_get_value_name_int(0, "peso36", QS[playerid][35]);
        cache_get_value_name_int(0, "peso37", QS[playerid][36]);
        cache_get_value_name_int(0, "peso38", QS[playerid][37]);
        cache_get_value_name_int(0, "peso39", QS[playerid][38]);
        cache_get_value_name_int(0, "peso40", QS[playerid][39]);

    }
    return 1;
}

stock AddItem(playerid, id, quantidade) {
    new i;
    for (i = 0; i < sizeof(ItemS[playerid]); i++) {
        if (ItemS[playerid][i] == 0) {
            mysql_format(ConexaoSQL, Query, sizeof(Query), "UPDATE `inventory_sessions` SET \
                `id%i`='%i', \
                `peso%i`='%i' \
                WHERE `hex`='%i'", ItemS[playerid][i], id, ItemS[playerid][i], quantidade, hexUser[playerid][hex]);
            mysql_query(ConexaoSQL, Query);
            ItemS[playerid][i] = id;
            QS[playerid][i] = quantidade;
            break;
        }
    }
    return 1;
}

stock RemoveItem(playerid, slot, quantidade) {
    new Query[259];
    if(slot == 0) {
        if(GetPVarInt(playerid, "removeSlot") > 0) {
            if(QS[playerid][slot] => 1) {
                mysql_format(ConexaoSQL, Query, sizeof(Query), "UPDATE `inventory_sessions` SET \
                `peso%i`='%i' \
                WHERE `hex`='%i'", GetPVarInt(playerid, "removeSlot"), quantidade, hexUser[playerid][hex]);
                mysql_query(ConexaoSQL, Query);
                SetPVarInt(playerid, "removeSlot", 0);
            } else {
                mysql_format(ConexaoSQL, Query, sizeof(Query), "UPDATE `inventory_sessions` SET \
                `id%i`='0' \
                `peso%i`='%i' \
                WHERE `hex`='%i'", GetPVarInt(playerid, "removeSlot"), GetPVarInt(playerid, "removeSlot"), quantidade, hexUser[playerid][hex]);
                mysql_query(ConexaoSQL, Query);
                SetPVarInt(playerid, "removeSlot", 0);
            }
        }
    } else {
        mysql_format(ConexaoSQL, Query, sizeof(Query), "UPDATE `inventory_sessions` SET \
        `id%i`='0', \
        `peso%i`='%i' \
        WHERE `hex`='%i'", slot, slot, quantidade, hexUser[playerid][hex]);
        mysql_query(ConexaoSQL, Query);
        SetPVarInt(playerid, "removeSlot", 0);
    }
    return 1;
}

stock ItemVerify(playerid, id, quant) {
    for (new i = 0; i < sizeof(ItemS[playerid]); i++) {
        if (ItemS[playerid][i] == id && QS[playerid][i] == quant) {
            SetPVarInt(playerid, "removeSlot", i + 1); // Índices de slots começam em 1
            return 1;
        }
    }
    return 0;
}

stock DropItem(playerid, slot, quantidade){
    if (ItemS[playerid][slot] != 0) {
        
        new Float:x, Float:y, Float:z;
        GetPlayerPos(playerid, x, y, z);
        x += 1.0;

        new objectid = CreateObject(1247, x, y, z, 0.0, 0.0, 0.0);

        new itemIndex = -1;
        for (new i = 0; i < sizeof(DroppedItems); i++) {
            if (DroppedItems[i][0] == 0) {
                DroppedItems[i][0] = ItemS[playerid][slot];
                DroppedItems[i][3] = QS[playerid][slot];
                GetPlayerPos(playerid, DroppedItems[i][1], DroppedItems[i][2], 0.0);
                itemIndex = i;
                break;
            }
        }

        if (itemIndex >= 0) {
            RemoveItem(playerid, slot, quantidade);
        }

    }

    return 1;
}

stock PickUpItem(playerid, itemIndex) {
    if (DroppedItems[itemIndex][0] != 0) {
        new playerX, playerY, playerZ;
        GetPlayerPos(playerid, playerX, playerY, playerZ);

        new itemX = DroppedItems[itemIndex][1];
        new itemY = DroppedItems[itemIndex][2];

        new distance = Float:VectorDistance(playerX, playerY, playerZ, itemX, itemY, 0.0);

        if (distance <= 2.0) {
            AddItem(playerid, id, quantidade);
            
            DroppedItems[itemIndex][0] = 0;
            DroppedItems[itemIndex][1] = 0.0;
            DroppedItems[itemIndex][2] = 0.0;
        }
    }

    return 1;
}