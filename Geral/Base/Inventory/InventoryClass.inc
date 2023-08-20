#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

#define DIALOG_INVENTORY 565

forward Inventory_Open(playerid);

new ItemUser[MAX_PLAYERS][40];
new Quant[MAX_PLAYERS][40];
new Peso[MAX_PLAYERS][2];
new PesoT[MAX_PLAYERS];
new PesoF[MAX_PLAYERS];

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    if(dialogid == DIALOG_INVENTORY) {
        if(!response) {
            PesoT[playerid] = 0;
        } else if(response) {
            switch(listitem) {
                
        }
    }
    return 0;
}

stock INVENTORY_Dialog(playerid) {
    new Dialog[1000];
    new StrCat[1000];

    if(ItemUser[playerid][0] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][0]), Quant[playerid][0]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][0]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][1] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][1]), Quant[playerid][1]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][1]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][2] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][2]), Quant[playerid][2]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][2]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][3] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][3]), Quant[playerid][3]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][3]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][4] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][4]), Quant[playerid][4]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][4]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][5] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][5]), Quant[playerid][5]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][5]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][6] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][6]), Quant[playerid][6]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][6]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][7] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][7]), Quant[playerid][7]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][7]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][8] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][8]), Quant[playerid][8]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][8]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][9] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][9]), Quant[playerid][9]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][9]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][10] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][10]), Quant[playerid][10]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][10]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][11] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][11]), Quant[playerid][11]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][11]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][12] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][12]), Quant[playerid][12]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][12]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][13] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][13]), Quant[playerid][13]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][13]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][14] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][14]), Quant[playerid][14]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][14]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][15] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][15]), Quant[playerid][15]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][15]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][16] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][16]), Quant[playerid][16]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][16]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][17] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][17]), Quant[playerid][17]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][17]);
    }
    if(ItemUser[playerid][18] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][18]), Quant[playerid][18]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][18]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][19] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][19]), Quant[playerid][19]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][19]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][20] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][20]), Quant[playerid][20]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][20]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][21] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][21]), Quant[playerid][21]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][21]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][22] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][22]), Quant[playerid][22]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][22]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][23] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][23]), Quant[playerid][23]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][23]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][24] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][24]), Quant[playerid][24]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][24]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][25] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][25]), Quant[playerid][25]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][25]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][26] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][26]), Quant[playerid][26]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][26]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][27] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][27]), Quant[playerid][27]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][27]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][28] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][28]), Quant[playerid][28]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][28]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][29] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][29]), Quant[playerid][29]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][29]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][30] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][30]), Quant[playerid][30]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][30]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][31] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][31]), Quant[playerid][31]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][31]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][32] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][32]), Quant[playerid][32]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][32]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][33] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][33]), Quant[playerid][33]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][33]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][34] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][34]), Quant[playerid][34]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][34]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][35] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][35]), Quant[playerid][35]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][35]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][36] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][36]), Quant[playerid][36]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][36]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][37] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][37]), Quant[playerid][37]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][37]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][38] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][38]), Quant[playerid][38]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][38]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }
    if(ItemUser[playerid][39] > 0) 
    {
        format(StrCat, sizeof(StrCat), "%s\t%i x\n", ITEM_NameGET(ItemUser[playerid][39]), Quant[playerid][39]);
        strcat(Dialog, StrCat);
        PesoT[playerid] += ITEM_PesoGET(ItemUser[playerid][39]);
    } else {
        format(StrCat, sizeof(StrCat), "Nada\n");
        strcat(Dialog, StrCat);
    }

    PesoF[playerid] = PesoT[playerid];

    new StrCaptain[250];

    format(StrCaptain, sizeof(StrCaptain), "%i/%i ITEM \t QUANT", PesoT[playerid], Peso[playerid][1]);

    ShowPlayerDialog(playerid, DIALOG_INVENTORY, DIALOG_STYLE_LIST, StrCaptain, Dialog, "Usar", "Sair");
    return 1;
}


public Inventory_Open(playerid) {
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "inventory_peso", Peso[playerid][0]);
        cache_get_value_name_int(0, "inventory_peso_max", Peso[playerid][1]);
        cache_get_value_name_int(0, "id1", ItemUser[playerid][0]);
        cache_get_value_name_int(0, "id2", ItemUser[playerid][1]);
        cache_get_value_name_int(0, "id3", ItemUser[playerid][2]);
        cache_get_value_name_int(0, "id4", ItemUser[playerid][3]);
        cache_get_value_name_int(0, "id5", ItemUser[playerid][4]);
        cache_get_value_name_int(0, "id6", ItemUser[playerid][5]);
        cache_get_value_name_int(0, "id7", ItemUser[playerid][6]);
        cache_get_value_name_int(0, "id8", ItemUser[playerid][7]);
        cache_get_value_name_int(0, "id9", ItemUser[playerid][8]);
        cache_get_value_name_int(0, "id10", ItemUser[playerid][9]);
        cache_get_value_name_int(0, "id11", ItemUser[playerid][10]);
        cache_get_value_name_int(0, "id12", ItemUser[playerid][11]);
        cache_get_value_name_int(0, "id13", ItemUser[playerid][12]);
        cache_get_value_name_int(0, "id14", ItemUser[playerid][13]);
        cache_get_value_name_int(0, "id15", ItemUser[playerid][14]);
        cache_get_value_name_int(0, "id16", ItemUser[playerid][15]);
        cache_get_value_name_int(0, "id17", ItemUser[playerid][16]);
        cache_get_value_name_int(0, "id18", ItemUser[playerid][17]);
        cache_get_value_name_int(0, "id19", ItemUser[playerid][18]);
        cache_get_value_name_int(0, "id20", ItemUser[playerid][19]);
        cache_get_value_name_int(0, "id21", ItemUser[playerid][20]);
        cache_get_value_name_int(0, "id22", ItemUser[playerid][21]);
        cache_get_value_name_int(0, "id23", ItemUser[playerid][22]);
        cache_get_value_name_int(0, "id24", ItemUser[playerid][23]);
        cache_get_value_name_int(0, "id25", ItemUser[playerid][24]);
        cache_get_value_name_int(0, "id26", ItemUser[playerid][25]);
        cache_get_value_name_int(0, "id27", ItemUser[playerid][26]);
        cache_get_value_name_int(0, "id28", ItemUser[playerid][27]);
        cache_get_value_name_int(0, "id29", ItemUser[playerid][28]);
        cache_get_value_name_int(0, "id30", ItemUser[playerid][29]);
        cache_get_value_name_int(0, "id31", ItemUser[playerid][30]);
        cache_get_value_name_int(0, "id32", ItemUser[playerid][31]);
        cache_get_value_name_int(0, "id33", ItemUser[playerid][32]);
        cache_get_value_name_int(0, "id34", ItemUser[playerid][33]);
        cache_get_value_name_int(0, "id35", ItemUser[playerid][34]);
        cache_get_value_name_int(0, "id36", ItemUser[playerid][35]);
        cache_get_value_name_int(0, "id37", ItemUser[playerid][36]);
        cache_get_value_name_int(0, "id38", ItemUser[playerid][37]);
        cache_get_value_name_int(0, "id39", ItemUser[playerid][38]);
        cache_get_value_name_int(0, "id40", ItemUser[playerid][39]);

        cache_get_value_name_int(0, "peso1", Quant[playerid][0]);
        cache_get_value_name_int(0, "peso2", Quant[playerid][1]);
        cache_get_value_name_int(0, "peso3", Quant[playerid][2]);
        cache_get_value_name_int(0, "peso4", Quant[playerid][3]);
        cache_get_value_name_int(0, "peso5", Quant[playerid][4]);
        cache_get_value_name_int(0, "peso6", Quant[playerid][5]);
        cache_get_value_name_int(0, "peso7", Quant[playerid][6]);
        cache_get_value_name_int(0, "peso8", Quant[playerid][7]);
        cache_get_value_name_int(0, "peso9", Quant[playerid][8]);
        cache_get_value_name_int(0, "peso10", Quant[playerid][9]);
        cache_get_value_name_int(0, "peso11", Quant[playerid][10]);
        cache_get_value_name_int(0, "peso12", Quant[playerid][11]);
        cache_get_value_name_int(0, "peso13", Quant[playerid][12]);
        cache_get_value_name_int(0, "peso14", Quant[playerid][13]);
        cache_get_value_name_int(0, "peso15", Quant[playerid][14]);
        cache_get_value_name_int(0, "peso16", Quant[playerid][15]);
        cache_get_value_name_int(0, "peso17", Quant[playerid][16]);
        cache_get_value_name_int(0, "peso18", Quant[playerid][17]);
        cache_get_value_name_int(0, "peso19", Quant[playerid][18]);
        cache_get_value_name_int(0, "peso20", Quant[playerid][19]);
        cache_get_value_name_int(0, "peso21", Quant[playerid][20]);
        cache_get_value_name_int(0, "peso22", Quant[playerid][21]);
        cache_get_value_name_int(0, "peso23", Quant[playerid][22]);
        cache_get_value_name_int(0, "peso24", Quant[playerid][23]);
        cache_get_value_name_int(0, "peso25", Quant[playerid][24]);
        cache_get_value_name_int(0, "peso26", Quant[playerid][25]);
        cache_get_value_name_int(0, "peso27", Quant[playerid][26]);
        cache_get_value_name_int(0, "peso28", Quant[playerid][27]);
        cache_get_value_name_int(0, "peso29", Quant[playerid][28]);
        cache_get_value_name_int(0, "peso30", Quant[playerid][29]);
        cache_get_value_name_int(0, "peso31", Quant[playerid][30]);
        cache_get_value_name_int(0, "peso32", Quant[playerid][31]);
        cache_get_value_name_int(0, "peso33", Quant[playerid][32]);
        cache_get_value_name_int(0, "peso34", Quant[playerid][33]);
        cache_get_value_name_int(0, "peso35", Quant[playerid][34]);
        cache_get_value_name_int(0, "peso36", Quant[playerid][35]);
        cache_get_value_name_int(0, "peso37", Quant[playerid][36]);
        cache_get_value_name_int(0, "peso38", Quant[playerid][37]);
        cache_get_value_name_int(0, "peso39", Quant[playerid][38]);
        cache_get_value_name_int(0, "peso40", Quant[playerid][39]);

        INVENTORY_Dialog(playerid);

    } else {
        TABLE_SetIConst(hexUser[playerid][hex], "inventory_sessions", "inventory_peso", "inventory_peso_max", 0, 100);
    }
    return 1;
}

CMD:inventory(playerid) {
    new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `inventory_sessions` WHERE `hex`='%i'", hexUser[playerid][hex]);
    mysql_tquery(ConexaoSQL, Query, "Inventory_Open", "i", playerid);
    return 1;
}