#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

#define MAX_BENCHS (1000)
#define DIALOG_DROGAS1 (45)

#define DIALOG_ARMAS (58)
#define DIALOG_MUNI (56)
#define DIALOG_DROGAS (510)

enum coordsBenchs{ 
    Float:x,
    Float:y,
    Float:z,
    Perm[250],
    Type[250]
}

new workBench[MAX_BENCHS][coordsBenchs];
new workBenchsLoaded;

forward SET_Workbenchs();

hook OnGameModeInit() {
    new Query[500];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `workbenchs_orgs`");
    mysql_tquery(ConexaoSQL, Query, "SET_Workbenchs");
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
    if(dialogid == DIALOG_ARMAS) {
        if(response) {
            switch(listitem) {
                case 0:
                {
                    if(CheckItem(playerid, 354, 1)) {
                        if(CheckItem(playerid, 1145, 15)) {
                            RemoveItens(playerid, 354, 1);
                            RemoveItens(playerid, 1145, 15);
                            GanharItem(playerid, 356, 1);
                        }
                    }
                }
                case 1:
                {
                    if(CheckItem(playerid, 354, 1)) {
                        if(CheckItem(playerid, 1145, 10)) {
                            RemoveItens(playerid, 354, 1);
                            RemoveItens(playerid, 1145, 10);
                            GanharItem(playerid, 355, 1);
                        }
                    }
                }
                case 2:
                {
                    if(CheckItem(playerid, 354, 1)) {
                        if(CheckItem(playerid, 1145, 5)) {
                            RemoveItens(playerid, 354, 1);
                            RemoveItens(playerid, 1145, 5);
                            GanharItem(playerid, 348, 1);
                        }
                    }
                }
                case 3:
                {
                    if(CheckItem(playerid, 354, 1)) {
                        if(CheckItem(playerid, 1145, 4)) {
                            RemoveItens(playerid, 354, 1);
                            RemoveItens(playerid, 1145, 4);
                            GanharItem(playerid, 347, 1);
                        }
                    }
                }
            }
        }
    } else if(dialogid == DIALOG_MUNI) {
        if(response) {
            switch(listitem) {
                case 0:
                {
                    if(CheckItem(playerid, 322, 10)) {
                        if(CheckItem(playerid, 1279, 10)) {
                            RemoveItens(playerid, 322, 10);
                            RemoveItens(playerid, 1279, 10);
                            GanharItem(playerid, 2061, 10);
                        }
                    }
                }
                case 1:
                {
                    if(CheckItem(playerid, 322, 50)) {
                        if(CheckItem(playerid, 1279, 50)) {
                            RemoveItens(playerid, 322, 50);
                            RemoveItens(playerid, 1279, 50);
                            GanharItem(playerid, 2061, 50);
                        }
                    }
                }
                case 2:
                {
                    if(CheckItem(playerid, 322, 1)) {
                        if(CheckItem(playerid, 1279, 1)) {
                            RemoveItens(playerid, 322, 1);
                            RemoveItens(playerid, 1279, 1);
                            GanharItem(playerid, 2061, 1);
                        }
                    }
                }
            }
        }
    } else if(dialogid == DIALOG_DROGAS) {
        if(response) {
            switch(listitem) {
                case 0:
                {
                    if(CheckItem(playerid, 19873, 1)) {
                        if(CheckItem(playerid, 1575, 1)) {
                            RemoveItens(playerid, 19873, 1);
                            RemoveItens(playerid, 1575, 1);
                            GanharItem(playerid, 3044, 1);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

public SET_Workbenchs(){
    if(cache_num_rows() > 0) {
        for(new i = 0; i < cache_num_rows(); i++) {
            cache_get_value_name_float(i, "x", workBench[i][x]);
            cache_get_value_name_float(i, "y", workBench[i][y]);
            cache_get_value_name_float(i, "z", workBench[i][z]);
            cache_get_value_name(i, "permission", workBench[i][Perm]);
            cache_get_value_name(i, "type", workBench[i][Type]);
            CreateObject(18092, workBench[i][x], workBench[i][y], workBench[i][z], 0, 0, 0, 300);
            workBenchsLoaded += 1;
        }
    }
    return 1;
}

stock WORK_Prox(playerid) {
    new typeInteger;
    for(new i = 0; i < workBenchsLoaded; i++) {
        if(IsPlayerInRangeOfPoint(playerid, 1.5, workBench[i][x], workBench[i][y], workBench[i][z])) {
            if(infoOrg[playerid][Organizacao] == workBench[i][Perm]) {
                if(strcmp(workBench[i][Type], "Armas") == 0) {
                typeInteger = 1;
                }
                if(strcmp(workBench[i][Type], "Drogas") == 0) {
                    typeInteger = 2;
                }
                if(strcmp(workBench[i][Type], "Muni") == 0) {
                    typeInteger = 3;
                }
                if(strcmp(workBench[i][Type], "Utils") == 0) {
                    typeInteger = 4;
                }
                switch(typeInteger) {
                    case 1: 
                    {
                        ShowPlayerDialog(playerid, DIALOG_ARMAS, DIALOG_STYLE_LIST, "PRODUCAO DE ARMAS", "M4A1 \t 1 CANO 15 CHAPAS \nSIG-SAUER \t 1 CANO 10 CHAPAS \nDESERT EAGLE \t 1 CANO 5 CHAPAS \nHK \t 1 CANO 4 CHAPAS", "CRIAR", "CANCELAR");
                    }
                    case 3: 
                    {
                        ShowPlayerDialog(playerid, DIALOG_MUNI, DIALOG_STYLE_LIST, "PRODUCAO DE MUNI.", "Muni. \t10 CAPSULA \t10 POLVORA \t10 UNI.\nMuni. \t10 CAPSULA \t10 POLVORA \t50 UNI.\nMuni. \t1 CAPSULA \t1 POLVORA \t1 UNI.", "CRIAR", "CANCELAR");
                    }
                    case 2: 
                    {
                        ShowPlayerDialog(playerid, DIALOG_DROGAS, DIALOG_STYLE_LIST, "PRODUCAO DE DROGAS.", "Baseado \t1 PASTA BASE \t1 PAPEL", "CRIAR", "CANCELAR");
                    }
                }
            }
        }
    }
    return 1;
}

stock CreateWorkBench(const permission[], const type[], Float:xO, Float:yO, Float:zO) {
    CreateObject(18092, xO, yO, zO-0.5, 0, 0, 0, 300);
    new Query[500];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "INSERT INTO `workbenchs_orgs` (`x`, `y`, `z`, `permission`, `type`) VALUES ('%f', '%f', '%f', '%s', '%s')", xO, yO, zO-0.5, permission, type);
    mysql_query(ConexaoSQL, Query); 

    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `workbenchs_orgs`");
    mysql_tquery(ConexaoSQL, Query, "SET_Workbenchs");
    return 1;
}

CMD:criarbancada(playerid, params[]) {
    new PERMISSION[250], TYPE[250];
    if(V_User(playerid, "Staff")) {
        if(sscanf(params, "s[250]s[250]", PERMISSION, TYPE)) {
            Notificar(playerid,"WORKBENCH", "Nao foram especificados os parametros corretos.");
        } else {
            new Float:POSU[3];
            GetPlayerPos(playerid, POSU[0], POSU[1], POSU[2]);
            CreateWorkBench(PERMISSION, TYPE, POSU[0], POSU[1], POSU[2]);
        }
    }
    return 1;
}

CMD:bancada(playerid) {
    WORK_Prox(playerid);
    return 1;
}