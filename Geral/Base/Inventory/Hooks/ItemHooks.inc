#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>
#include "../Geral/Base/Inventory/Hooks/DropHooks.inc"

new ItemS[MAX_PLAYERS][40];
new QS[MAX_PLAYERS][40];

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

stock AddItem(playerid, slot, id, quantidade) {
    new i = 0;
    while(i < 39) [
        if(ItemS[playerid][i] == 0) {
            mysql_format(ConexaoSQL, Query, sizeof(Query), "UPDATE `inventory_sessions` SET \
            `id%i`='%i', \
            `peso%i`='%i' \
            WHERE `hex`='%i'", slot, id, slot, quantidade, hexUser[playerid][hex]);
            mysql_query(ConexaoSQL, Query);
            id = 0;
            i = 0;
            break;
        }
    ]
    return 1;
}

stock RemoveItem(playerid, slot, quantidade) {
    new Query[259];
    if(slot == 0) {
        if(GetPVarInt(playerid, "removeSlot") > 0) {
            mysql_format(ConexaoSQL, Query, sizeof(Query), "UPDATE `inventory_sessions` SET \
            `id%i`='0', \
            `peso%i`='%i' \
            WHERE `hex`='%i'", GetPVarInt(playerid, "removeSlot"), GetPVarInt(playerid, "removeSlot"), quantidade, hexUser[playerid][hex]);
            mysql_query(ConexaoSQL, Query);
            SetPVarInt(playerid, "removeSlot", 0);
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
    if(ItemS[playerid][0] == id) {
        if(QS[playerid][0] == quant) {
            SetPVarInt(playerid, "removeSlot", 1);
            return 1;
        }
    } else if(ItemS[playerid][1] == id) {
        if(QS[playerid][1] == quant) {
            SetPVarInt(playerid, "removeSlot", 2);
            return 1;
        }
    } else if(ItemS[playerid][2] == id) {
        if(QS[playerid][2] == quant) {
            SetPVarInt(playerid, "removeSlot", 3);
            return 1;
        }
    } else if(ItemS[playerid][3] == id) {
        if(QS[playerid][3] == quant) {
            SetPVarInt(playerid, "removeSlot", 4);
            return 1;
        }
    } else if(ItemS[playerid][4] == id) {
        if(QS[playerid][4] == quant) {
            SetPVarInt(playerid, "removeSlot", 5);
            return 1;
        }
    } else if(ItemS[playerid][5] == id) {
        if(QS[playerid][5] == quant) {
            SetPVarInt(playerid, "removeSlot", 6);
            return 1;
        }
    } else if(ItemS[playerid][6] == id) {
        if(QS[playerid][6] == quant) {
            SetPVarInt(playerid, "removeSlot", 7);
            return 1;
        }
    } else if(ItemS[playerid][7] == id) {
        if(QS[playerid][7] == quant) {
            SetPVarInt(playerid, "removeSlot", 8);
            return 1;
        }
    } else if(ItemS[playerid][8] == id) {
        if(QS[playerid][8] == quant) {
            SetPVarInt(playerid, "removeSlot", 9);
            return 1;
        }
    } else if(ItemS[playerid][9] == id) {
        if(QS[playerid][9] == quant) {
            SetPVarInt(playerid, "removeSlot", 10);
            return 1;
        }
    } else if(ItemS[playerid][10] == id) {
        if(QS[playerid][10] == quant) {
            SetPVarInt(playerid, "removeSlot", 11);
            return 1;
        }
    } else if(ItemS[playerid][11] == id) {
        if(QS[playerid][11] == quant) {
            SetPVarInt(playerid, "removeSlot", 12);
            return 1;
        }
    } else if(ItemS[playerid][12] == id) {
        if(QS[playerid][12] == quant) {
            SetPVarInt(playerid, "removeSlot", 13);
            return 1;
        }
    } else if(ItemS[playerid][13] == id) {
        if(QS[playerid][13] == quant) {
            SetPVarInt(playerid, "removeSlot", 14);
            return 1;
        }
    } else if(ItemS[playerid][14] == id) {
        if(QS[playerid][14] == quant) {
            SetPVarInt(playerid, "removeSlot", 15);
            return 1;
        }
    } else if(ItemS[playerid][15] == id) {
        if(QS[playerid][15] == quant) {
            SetPVarInt(playerid, "removeSlot", 16);
            return 1;
        }
    } else if(ItemS[playerid][16] == id) {
        if(QS[playerid][16] == quant) {
            SetPVarInt(playerid, "removeSlot", 17);
            return 1;
        }
    } else if(ItemS[playerid][17] == id) {
        if(QS[playerid][17] == quant) {
            SetPVarInt(playerid, "removeSlot", 18);
            return 1;
        }
    } else if(ItemS[playerid][18] == id) {
        if(QS[playerid][18] == quant) {
            SetPVarInt(playerid, "removeSlot", 19);
            return 1;
        }
    } else if(ItemS[playerid][19] == id) {
        if(QS[playerid][19] == quant) {
            SetPVarInt(playerid, "removeSlot", 20);
            return 1;
        }
    } else if(ItemS[playerid][20] == id) {
        if(QS[playerid][20] == quant) {
            SetPVarInt(playerid, "removeSlot", 21);
            return 1;
        }
    } else if(ItemS[playerid][21] == id) {
        if(QS[playerid][21] == quant) {
            SetPVarInt(playerid, "removeSlot", 22);
            return 1;
        }
    } else if(ItemS[playerid][22] == id) {
        if(QS[playerid][22] == quant) {
            SetPVarInt(playerid, "removeSlot", 23);
            return 1;
        }
    } else if(ItemS[playerid][23] == id) {
        if(QS[playerid][23] == quant) {
            SetPVarInt(playerid, "removeSlot", 24);
            return 1;
        }
    } else if(ItemS[playerid][24] == id) {
        if(QS[playerid][24] == quant) {
            SetPVarInt(playerid, "removeSlot", 25);
            return 1;
        }
    } else if(ItemS[playerid][25] == id) {
        if(QS[playerid][25] == quant) {
            SetPVarInt(playerid, "removeSlot", 26);
            return 1;
        }
    } else if(ItemS[playerid][26] == id) {
        if(QS[playerid][26] == quant) {
            SetPVarInt(playerid, "removeSlot", 27);
            return 1;
        }
    } else if(ItemS[playerid][27] == id) {
        if(QS[playerid][27] == quant) {
            SetPVarInt(playerid, "removeSlot", 28);
            return 1;
        }
    } else if(ItemS[playerid][28] == id) {
        if(QS[playerid][28] == quant) {
            SetPVarInt(playerid, "removeSlot", 29);
            return 1;
        }
    } else if(ItemS[playerid][29] == id) {
        if(QS[playerid][29] == quant) {
            SetPVarInt(playerid, "removeSlot", 30);
            return 1;
        }
    } else if(ItemS[playerid][30] == id) {
        if(QS[playerid][30] == quant) {
            SetPVarInt(playerid, "removeSlot", 31);
            return 1;
        }
    } else if(ItemS[playerid][31] == id) {
        if(QS[playerid][31] == quant) {
            SetPVarInt(playerid, "removeSlot", 32);
            return 1;
        }
    } else if(ItemS[playerid][32] == id) {
        if(QS[playerid][32] == quant) {
            SetPVarInt(playerid, "removeSlot", 33);
            return 1;
        }
    } else if(ItemS[playerid][33] == id) {
        if(QS[playerid][33] == quant) {
            SetPVarInt(playerid, "removeSlot", 34);
            return 1;
        }
    } else if(ItemS[playerid][34] == id) {
        if(QS[playerid][34] == quant) {
            SetPVarInt(playerid, "removeSlot", 35);
            return 1;
        }
    } else if(ItemS[playerid][35] == id) {
        if(QS[playerid][35] == quant) {
            SetPVarInt(playerid, "removeSlot", 36);
            return 1;
        }
    } else if(ItemS[playerid][36] == id) {
        if(QS[playerid][36] == quant) {
            SetPVarInt(playerid, "removeSlot", 37);
            return 1;
        }
    } else if(ItemS[playerid][37] == id) {
        if(QS[playerid][37] == quant) {
            SetPVarInt(playerid, "removeSlot", 38);
            return 1;
        }
    } else if(ItemS[playerid][38] == id) {
        if(QS[playerid][38] == quant) {
            SetPVarInt(playerid, "removeSlot", 39);
            return 1;
        }
    } else if(ItemS[playerid][39] == id) {
        if(QS[playerid][39] == quant) {
            SetPVarInt(playerid, "removeSlot", 40);
            return 1;
        }
    }
    return 0;
}