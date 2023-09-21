#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>
 
#define PF::%0(%1) 		forward %0(%1);\
							public %0(%1)
 
#define COLOR_GRAD2             0xBFC0C2AA
#define COLOR_GRAD1             0xB4B5B7AA
#define COLOR_AVISO				0x4F4F4FAA
#define COLOR_GRAD5             0xF0F0F0AA
#define COLOR_LIGHTGREEN		0x2DFF2DAA
 
enum iInv
{
    DropItem,
    DropItemUni,
    DropItemID,
    Pickup,
    Virtual,
    Interior,
    Text3D:LabelItem,
    Slot,
    Unidades
};
 
new PlayerInventario[MAX_PLAYERS][33][iInv];
new DropItemSlot[MAX_OBJECTS][iInv];
new PlayerText:DrawInv[MAX_PLAYERS][40];
new InventarioAberto[MAX_PLAYERS];
new QuantidadeSelector[MAX_PLAYERS];

static stock PlayerName(playerid)
{
	new Name[MAX_PLAYER_NAME];
	GetPlayerName(playerid, Name, sizeof Name);
	return Name;
}
 
hook OnPlayerConnect(playerid)
{
	InventarioAberto[playerid] = 0;
	TextDrawInv(playerid);
	return 1;
}
 
hook OnPlayerDisconnect(playerid, reason)
{
	InventarioAberto[playerid] = 0;
	SalvarInventario(playerid);
	return 1;
}

stock QuantidadeSelect(playerid) {
	ShowPlayerDialog(playerid, 1912, DIALOG_STYLE_INPUT, "QUANTIDADE SELETOR", "1 para cima", "Confirmar", "Sair");
	return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
	new str[64], text[64];
	for(new i = 1; i < 33; ++i)
	{
		if(playertextid == DrawInv[playerid][i])
		{
			if(PlayerInventario[playerid][i][Slot] == -1)
			{
				text = " ";
			}
			else
			{
				format(str, sizeof(str), "%s - %s unidades", ItemNomeInv(PlayerInventario[playerid][i][Slot]), ConvertMoney(PlayerInventario[playerid][i][Unidades]));
				text = str;
			}
			
			PlayerTextDrawSetString(playerid, DrawInv[playerid][38], text);
			PlayerTextDrawShow(playerid, DrawInv[playerid][38]);
			SetPVarInt(playerid, #VarSlotInv, i);
		}
	}
	if(playertextid == DrawInv[playerid][39])
    {
        QuantidadeSelect(playerid);
    }
	if(playertextid == DrawInv[playerid][36]) return FuncaoItens(playerid, GetPVarInt(playerid, #VarSlotInv), QuantidadeSelector[playerid]);
	if(playertextid == DrawInv[playerid][35]) return callcmd::inventario(playerid);
	if(playertextid == DrawInv[playerid][37]) return DroparItem(playerid, GetPVarInt(playerid, #VarSlotInv), QuantidadeSelector[playerid]);
	return 1;
}
 
hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if(clickedid == Text:INVALID_TEXT_DRAW)
	{
		for(new i = 0; i < 40; ++i)
		{
			PlayerTextDrawHide(playerid, DrawInv[playerid][i]);
		}
		InventarioAberto[playerid] = 0;
		return 1;
	}
	return 0;
}

CMD:garmas(playerid) {
	new weapon = GetPlayerWeapon(playerid);
	new ammo = GetPlayerAmmo(playerid);
	if(weapon != 0) {
		GanharItem(playerid, GetIDArma(weapon), 1);
		if(ammo == 1) {

		} else {
			GanharItem(playerid, 322, ammo);
		}
		RemovePlayerWeapon(playerid, weapon);
		weapon = 0;
		ammo = 0;
		Notificar(playerid, "INVENTARIO", "Sua arma foi guardada com sucesso!");
	}
	return 1;
}

CMD:pegaritem(playerid)
{
    new Float:x, Float:y, Float:z;
    for(new i = 0; i < sizeof(DropItemSlot); i++)
    {
        GetDynamicObjectPos(DropItemSlot[i][DropItem], x,y,z);
        if(DropItemSlot[i][DropItem] != 0)
        {
            if(IsPlayerInRangeOfPoint(playerid, 1.5, x,y,z+1) && GetPlayerVirtualWorld(playerid) == DropItemSlot[i][Virtual] && GetPlayerInterior(playerid) == DropItemSlot[i][Interior])
            {
                if(!CheckInventario(playerid, DropItemSlot[i][DropItemID])) return SendClientMessage(playerid, -1, "Sua Mochila está cheia.");
                GanharItem(playerid, DropItemSlot[i][DropItemID], DropItemSlot[i][DropItemUni]);
				DestroyDynamicObject(DropItemSlot[i][DropItem]);
				DestroyDynamic3DTextLabel(DropItemSlot[i][LabelItem]);
				DropItemSlot[i][DropItem] = 0;
				DropItemSlot[i][DropItemID] = -1;
				DropItemSlot[i][DropItemUni] = 0;
				DropItemSlot[i][Interior] = 0;
				DropItemSlot[i][Virtual] = 0;
				new animlib[24], animname[24];
				format(animlib, sizeof(animlib), "BOMBER");
				format(animname, sizeof(animname), "BOM_Plant");
				ApplyAnimation(playerid, animlib, animname, 4.1, 0, 0, 0, 0, 0, 1);
                return 1;
            }
        }
    }
    return 1;
}
 
CMD:inventario(playerid)
{
	new str[64];
	CriarInventario(playerid);
	if(InventarioAberto[playerid])
	{
		for(new i = 0; i < 40; ++i)
		{
			PlayerTextDrawHide(playerid, DrawInv[playerid][i]);
		}
		InventarioAberto[playerid] = 0;
		CancelSelectTextDraw(playerid);
		return 1;
	}
	else
	{
		format(str, sizeof(str), "Inventario: %s", PlayerName(playerid));
		PlayerTextDrawSetString(playerid, DrawInv[playerid][34], str);
		new emptyString[1];

		PlayerTextDrawSetString(playerid, DrawInv[playerid][38], emptyString);
		for(new i = 1; i < 33; ++i)
		{
			PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][i], PlayerInventario[playerid][i][Slot]);
			if(PlayerInventario[playerid][i][Slot] == -1)
			{
				PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][i], 0.000000, 0.000000, 0.000000, 999);
			}
			else
			{
				PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][i], 0.000000, 0.000000, 0.000000, 1);
			}
		}
		for(new i = 0; i < 40; ++i)
		{
			PlayerTextDrawShow(playerid, DrawInv[playerid][i]);
		}
		SelectTextDraw(playerid, 0xC4C4C4AA);
		InventarioAberto[playerid] = 1;
	}
	return 1;
}
 
CMD:daritem(playerid, const params[])
{
	new id, item, quantia;
	new strNotf[350];
	if(V_User(playerid, "Staff"))
	{
		if(sscanf(params, "iii", id, item, quantia)) return SendClientMessage(playerid, COLOR_GRAD2, "Use: /daritem [ID] [ITEM ID] [UNIDADES].");
		if(!IsPlayerConnected(id)) return SendClientMessage(playerid, COLOR_GRAD1, "Jogador não conectado.");
		if(!IsValidItemInv(item)) return SendClientMessage(playerid, COLOR_GRAD1, "Item Indefinido no servidor.");
		if(quantia < 1) return SendClientMessage(playerid, COLOR_GRAD1, "A quantia deve ser no mínimo 1.");
		if(!CheckInventario(id, item)) return SendClientMessage(playerid, COLOR_GRAD1, "O inventario desse jogador está cheio.");
		GanharItem(id, item, quantia);
		format(strNotf, sizeof(strNotf), "Você deu %d unidades de %s para %s", quantia, ItemNomeInv(item), PlayerName(id));
		Notificar(playerid, "HEY!", strNotf);
	} else {
		Notificar(playerid,  "ERRO! ERRO!", "Voce nao e administrador");
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, const inputtext[100]) {
	if(dialogid == 1912) {
		if(response) {
			if(eNumero(inputtext)) {
				new number = strval(inputtext);
				new str[128];
				format(str, sizeof(str), "%i", number);
				PlayerTextDrawSetString(playerid, DrawInv[playerid][39], str);
				QuantidadeSelector[playerid] = number;
				return 1;
			} else {
				return 1;
			}
		}
	}
	return 0;
}

GanharItem(playerid, itemid, quantia)
{
	for(new i = 1; i < 33; ++i)
	{
		if(PlayerInventario[playerid][i][Slot] == itemid)
		{
			PlayerInventario[playerid][i][Slot] = itemid;
			PlayerInventario[playerid][i][Unidades]+= quantia;
			SalvarInventario(playerid);
			return 1;
		}
		else if(PlayerInventario[playerid][i][Slot] == -1)
		{
			PlayerInventario[playerid][i][Slot] = itemid;
			PlayerInventario[playerid][i][Unidades] = quantia;
			SalvarInventario(playerid);
			return 1;
		}
	}
	return 1;
}
 
PF::CriarInventario(playerid)
{
    new query[512];
    format(query, sizeof(query), "SELECT * FROM inventario WHERE player_id = %d", hexUser[playerid][hex]);
    mysql_tquery(ConexaoSQL, query, "CreateInventoryCallback", "d", playerid);
    return 1;
}

PF::CreateInventoryCallback(playerid)
{
    if (cache_num_rows() > 0)
    {
        LoadInv(playerid);
    }
    else
    {
        new query[128];
		format(query, sizeof(query), "INSERT INTO inventario (`player_id`) VALUES ('%d')", hexUser[playerid][hex]);
		mysql_query(ConexaoSQL, query);
		for(new i = 1; i < 33; i++) {
			mysql_format(ConexaoSQL, query, sizeof(query), "UPDATE `inventario` SET \
                `slot%i`='-1' \
                WHERE `player_id`='%i'", i, hexUser[playerid][hex]);
            mysql_query(ConexaoSQL, query);
		}
		for(new i = 1; i < 33; i++) {
			mysql_format(ConexaoSQL, query, sizeof(query), "UPDATE `inventario` SET \
                `slot%i_unidade`='-1' \
                WHERE `player_id`='%i'", i, hexUser[playerid][hex]);
            mysql_query(ConexaoSQL, query);
		}
        printf("Criou inventário no banco de dados!");
    }

    return 1;
}

PF::LoadInv(playerid)
{
    new query[512];
    format(query, sizeof(query), "SELECT * FROM inventario WHERE player_id = %d", hexUser[playerid][hex]);
    mysql_tquery(ConexaoSQL, query, "LoadPlayerInventoryCallback", "d", playerid);
    return 1;
}

PF::LoadPlayerInventoryCallback(playerid)
{
    if (cache_num_rows() > 0)
    {
        
        for (new i = 1; i <= 33; i++)
		{
			new str1[128];
			format(str1, sizeof(str1), "slot%d", i);
			new str2[128];
			format(str2, sizeof(str2), "slot%d_unidade", i); 
			cache_get_value_name_int(0, str1, PlayerInventario[playerid][i][Slot]);
			cache_get_value_name_int(0, str2, PlayerInventario[playerid][i][Unidades]);
		}
        
        SendClientMessage(playerid, -1, "Seu inventário foi carregado do banco de dados.");
    }
    else
    {
        SendClientMessage(playerid, -1, "Seu inventário não foi encontrado no banco de dados.");
    }
    return 1;
}

PF::SalvarInventario(playerid)
{
    new query[512];
    for(new i = 1; i < 33; i++) {
		mysql_format(ConexaoSQL, query, sizeof(query), "UPDATE `inventario` SET \
            `slot%i`='%i' \
            WHERE `player_id`='%i'", i, PlayerInventario[playerid][i][Slot], hexUser[playerid][hex]);
        mysql_query(ConexaoSQL, query);
	}
	for(new i = 1; i < 33; i++) {
		mysql_format(ConexaoSQL, query, sizeof(query), "UPDATE `inventario` SET \
            `slot%i_unidade`='%i' \
            WHERE `player_id`='%i'", i, PlayerInventario[playerid][i][Unidades], hexUser[playerid][hex]);
        mysql_query(ConexaoSQL, query);
	}

    return 1;
}

CheckInventario(playerid, itemid)
{
	for(new i = 1; i < 33; ++i)
	{
		if(PlayerInventario[playerid][i][Slot] == itemid || PlayerInventario[playerid][i][Unidades] == -1) return 1;
	}
	return 0;
}

CheckItem(playerid, itemid, quantia) {
	for(new i = 1; i < 33; ++i)
	{
		if(PlayerInventario[playerid][i][Slot] == itemid || PlayerInventario[playerid][i][Unidades] >= quantia) return 1;
	}
	return 0;
}
 
ItemNomeInv(itemid) // AQUI VOCÊ PODE ADICIONAR OS ID DOS ITENS E SETAR SEU NOME (OBS: TOME CUIDADO AO OPTAR O USO DE LOOPS)
{
	new name[25];
	format(name, 25, "(null)");
    if(itemid >= 330 && itemid < 372) format(name, 25, NomeArmas(GetArmaInv(itemid))); // se for armas
	else
	switch(itemid)
	{
		case 1279: name = "Polvora";
		case 630: name = "Planta Maconha";
		case 1575: name = "Pasta Base";
		case 19873: name = "Papel";
		case 354: name = "Cano";
		case 1145: name = "Chapa de Metal";
		case 322: name = "Capsula";
		case 2061: name = "Municao";
		case 11746: name = "Chave";
		case 3044: name = "Baseado";                                                                                                                                                                                                                                                         
		case 19039: name = "Relogio de Ouro";
		case 19040: name = "Relogio de Prata";
		case 19042: name = "Relogio Dourado";
		case 19044: name = "Relogio Rosa";
		case 19045: name = "Relogio Vermelho";
		case 19046: name = "Relogio Verde";
		case 19047: name = "Relogio Roxo";
		case 11747: name = "Baseado";
		case 18865: name = "Celular";
		case 18866: name = "Celular Azul";
		case 18867: name = "Celular Laranja";
		case 18868: name = "Celular Preto";
		case 18869: name = "Celular Rosa";
		case 18870: name = "Celular Vermelho";
		case 18871: name = "Celular Verde";
		case 18872: name = "Celular Azul";
		case 18873: name = "Celular Amarelo";
		case 18874: name = "Celular Branco";
		case 19513: name = "Celular Branco";
		case 18875: name = "GPS";
		case 19874: name = "Barra de Ouro";
		case 19138: name = "Oculos Preto";
		case 19139: name = "Oculos Vermelho";
		case 19140: name = "Oculos Azul";
		case 19022: name = "Oculos Prata";
		case 19023: name = "Oculos Azul";
		case 19024: name = "Oculos Roxo";
		case 19025: name = "Oculos Rosa";
		case 19026: name = "Oculos Vermelho";
		case 19027: name = "Oculos Laranja";
		case 19028: name = "Oculos Amarelo";
		case 19029: name = "Oculos Verde";
		case 19030: name = "Oculos";
		case 19031: name = "Oculos";
		case 19032: name = "Oculos";
		case 19033: name = "Oculos Preto";
		case 19034: name = "Oculos";
		case 19035: name = "Oculos Azul";
		case 2992: name = "Aurea de Anjo";
		case 3065: name = "Bola de Basquete";
		case 11712: name = "Cruz";
		case 18953: name = "Toca Preta";
		case 18954: name = "Toca Verde";
		case 19554: name = "Gorro";
		case 18974: name = "Mascara Zorro";
		case 2114: name = "Bola de Basquete";
		case 18894: name = "Bandana";
		case 18903: name = "Bandana";
		case 18898: name = "Bandana";
		case 18899: name = "Bandana";
		case 18891: name = "Bandana";
		case 18909: name = "Bandana";
		case 18908: name = "Bandana";
		case 18907: name = "Bandana";
		case 18906: name = "Bandana";
		case 18905: name = "Bandana";
		case 18904: name = "Bandana";
		case 18901: name = "Bandana";
		case 18902: name = "Bandana";
		case 18892: name = "Bandana";
		case 18900: name = "Bandana";
		case 18897: name = "Bandana";
		case 18896: name = "Bandana";
		case 18895: name = "Bandana";
		case 18893: name = "Bandana";
		case 18810: name = "Bandana";
		case 18947: name = "Chapeu";
		case 18948: name = "Chapeu";
		case 18949: name = "Chapeu";
		case 18950: name = "Chapeu";
		case 18951: name = "Chapeu";
		case 19488: name = "Chapeu";
		case 18921: name = "Boina";
		case 18922: name = "Boina";
		case 18923: name = "Boina";
		case 18924: name = "Boina";
		case 18925: name = "Boina";
		case 18939: name = "Bone";
		case 18940: name = "Bone";
		case 18941: name = "Bone";
		case 18942: name = "Bone";
		case 18943: name = "Bone";
		case 18646: name = "Sirene";
		case 1314: name = "2 Players";
		case 19578: name = "Banana";
		case 18636: name = "Bone COP";
		case 19942: name = "Radio";
		case 19141: name = "Capacete S.W.A.T";
		case 19558: name = "Bone Pizzaiolo";
		case 19801: name = "Mascara de Assalto";
		case 19330: name = "Chapeu de Bombeiro";
		case 1210: name = "Maleta";
		case 19528: name = "Chapeu de Mago";
		case 19134: name = "Seta Verde";
		case 19904: name = "Colete de Operario";
		case 19515: name = "Colete";
		case 19142: name = "Colete COP";
		case 19315: name = "Cervo";
		case 19527: name = "Caldeirao";
		case 19317: name = "Guitarra Eletrica";
		case 18688: name = "Efeito Fogo";
		case 18702: name = "Efeito Nitro";
		case 18728: name = "Efeito Sinalizador";
		case 19605: name = "Marker Vermelho";
		case 19606: name = "Marker Verde";
		case 19607: name = "Marker Azul";
		case 19823: name = "Whiskey";
		case 19820: name = "Conhaque";
		case 11722: name = "Ketchup";
		case 11723: name = "Mostarda";
		case 19570: name = "Leite";
		case 19824: name = "Champanhe";
		case 1486: name = "Cerveja";
		case 19822: name = "Vinho";
		case 1668: name = "Agua";
		case 2958: name = "Cerveja";
		case 19577: name = "Tomate";
		case 1485: name = "Baseado";
		case 19574: name = "Laranja";
		case 19575: name = "Maca";
		case 19576: name = "Maca Verde";
		case 2703: name = "Hamburger";
		case 2880: name = "Hamburger";
		case 19883: name = "Fatia de Pao";
		case 19896: name = "Maco de Cigarro";
		case 19897: name = "Maco de Cigarro";
		case 1546: name = "Refrigerante";
		case 2768: name = "Hamburger";
		case 1550: name = "Dinheiro Sujo";
		case 1212: name = "Dinheiro";
		case 2601: name = "Refrigerante";
		case 19835: name = "Cafe";
		case 2881: name = "Fatia de Pizza";
		case 2702: name = "Fatia de Pizza";
		case 2769: name = "Taco";
		case 2709: name = "Remedio";
		case 19579: name = "Pao";
		case 19630: name = "Peixe";
		case 19094: name = "Hamburger";
		case 1582: name = "Pizza Media";
		case 19580: name = "Pizza Grande";
		case 19602: name = "Mina Terrestre";
		case 11738: name = "Remedio Grande";
		case 1654: name = "Dinamite";
		case 11736: name = "MedKit";
		case 1650: name = "Galao de Gasolina";
		case 1252: name = "C4";
		case 19893: name = "Notebook";
		case 19921: name = "Caixa de Ferramentas";
		case 2226: name = "Radio";
		case 19054: name = "Caixa Pequena";
		case 19056: name = "Caixa Grande";
		case 19055: name = "Caixa Media";
		case 19057: name = "Caixa Ouro";
		case 19058: name = "Caixa VIP";
		case 333: name = "Taco de Golfe";
		case 334: name = "Cacetete";
		case 335: name = "Faca";
		case 336: name = "Taco de Baseball";
		case 337: name = "Pa";
		case 338: name = "Taco de Sinuca";
		case 339: name = "Katana";
		case 341: name = "Motoserra";
		case 321: name = "Dildo Roxo";
		case 323: name = "Vibrador";
		case 324: name = "Vibrador de Prata";
		case 325: name = "Flores";
		case 326: name = "Cano";
		case 342: name = "Granada";
		case 343: name = "Gas Lacrimogenio";
		case 344: name = "Coquetel Molotov";
		case 346: name = "Pistola 9mm";
		case 347: name = "Silenciadora 9mm";
		case 348: name = "Desert Eagle";
		case 349: name = "Shotgun";
		case 350: name = "Sawnoff";
		case 351: name = "Combat Shotgun";
		case 352: name = "Uzi";
		case 353: name = "MP5";
		case 355: name = "Sig-Sauer";
		case 356: name = "M4A1";
		case 372: name = "Tec-9";
		case 357: name = "Country Rifle";
		case 358: name = "Sniper Rifle";
		case 359: name = "RPG";
		case 360: name = "HS Rocket";
		case 361: name = "Lanca-Chamas";
		case 362: name = "Minigun";
		case 363: name = "Satchel Charge";
		case 364: name = "Detonador";
		case 365: name = "Lata de Spray";
		case 366: name = "Extintor";
		case 367: name = "Camera";
		case 368: name = "Oculos Noturno";
		case 369: name = "Osculo Termal";
		case 371: name = "Parachute";
		default: name = "(null)";
	}
    return name;
}

static NomeArmas(armaid)
{
    new name[35];
    switch(armaid)
    {
        case 1: name = "Soco Ingles";
        case 2: name = "Taco de Golfe";
        case 3: name = "Cacetete";
        case 4: name = "Faca";
        case 5: name = "Taco de Baseball";
        case 6: name = "Pa";
        case 7: name = "Taco de Sinuca";
        case 8: name = "Katana";
        case 9: name = "Motoserra";
        case 12: name = "Vibrador";
        case 13: name = "Vibrador de Prata";
        case 14: name = "Flores";
        case 15: name = "Cano";
        case 16: name = "Granada";
        case 17: name = "Gas Lacrimogenio";
        case 18: name = "Coquetel Molotov";
        case 22: name = "Pistola 9mm";
        case 23: name = "Silenciadora 9mm";
        case 24: name = "Desert Eagle";
        case 25: name = "Shotgun";
        case 26: name = "Sawnoff ";
        case 27: name = "Combat Shotgun";
        case 28: name = "Uzi";
        case 29: name = "MP5";
        case 30: name = "Sig-Sauer";
        case 31: name = "M4A1";
        case 32: name = "Tec-9";
        case 33: name = "Country Rifle";
        case 34: name = "Sniper Rifle";
        case 35: name = "RPG";
        case 36: name = "HS Rocket";
        case 37: name = "Lanca-chamas";
        case 38: name = "Minigun";
        case 39: name = "Satchel Charge";
        case 40: name = "Detonador";
        case 41: name = "Lata de Spray";
        case 42: name = "Extintor";
        case 43: name = "Camera";
        case 44: name = "Oculos Noturno";
        case 45: name = "Osculo Termal";
        case 46: name = "Parachute";
        default: name = "Nenhuma";
    }
    return name;
}
 
DroparItem(playerid, modelid, quantidade)
{
    if(IsPlayerConnected(playerid))
    {
    	if(quantidade >= 1) {
			if(PlayerInventario[playerid][modelid][Unidades] >= quantidade) 
			{
				new str[128], Float:x, Float:y, Float:z;
				if(PlayerInventario[playerid][modelid][Slot] != -1)
				{
					GetPlayerPos(playerid, x,y,z);
					for(new i = 0; i < MAX_OBJECTS; i++)
					{
						if(DropItemSlot[i][DropItem] == 0)
						{
							DropItemSlot[i][DropItem] = CreateDynamicObject(PlayerInventario[playerid][modelid][Slot], x,y,z-1, 0, 0, 0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
							DropItemSlot[i][DropItemUni] = quantidade;
							DropItemSlot[i][DropItemID] = PlayerInventario[playerid][modelid][Slot];
							DropItemSlot[i][Virtual] = GetPlayerVirtualWorld(playerid);
							DropItemSlot[i][Interior] = GetPlayerInterior(playerid);
							format(str, sizeof(str), "Item: %s\nUnidades: %s", ItemNomeInv(PlayerInventario[playerid][modelid][Slot]), ConvertMoney(PlayerInventario[playerid][modelid][Unidades]));
							DropItemSlot[i][LabelItem] = CreateDynamic3DTextLabel(str, COLOR_GRAD5, x,y,z-1, 5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
							PlayerInventario[playerid][modelid][Unidades] -= quantidade;
							AtualizarInventario(playerid, modelid);
							new animlib[24], animname[24];
							format(animlib, sizeof(animlib), "BOMBER");
							format(animname, sizeof(animname), "BOM_Plant");
							ApplyAnimation(playerid, animlib, animname, 4.1, 0, 0, 0, 0, 0, 1);
							return 1;
						}
					}
				}
			}
		}
	}
    return 0;
}
RemoveItens(playerid, itemid, quantia) {
	for(new i = 1; i < 33; i++) {
		if(PlayerInventario[playerid][i][Slot] == itemid || PlayerInventario[playerid][i][Unidades] >= quantia) {
			PlayerInventario[playerid][i][Unidades] -= quantia;
			AtualizarInventario(playerid, i);
			return 1;
		}
	}
	return 0;
}
AtualizarInventario(playerid, i)
{
    new str[64];
    if(PlayerInventario[playerid][i][Unidades] < 1)
    {
        PlayerInventario[playerid][i][Unidades] = 0;
        PlayerInventario[playerid][i][Slot] = -1;
    }
    if(PlayerInventario[playerid][i][Slot] == -1)
	{
		new emptyString[1];
		PlayerTextDrawSetString(playerid, DrawInv[playerid][38], emptyString);
		PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][i], 0.000000, 0.000000, 0.000000, 999);
	}
	else
	{
		format(str, sizeof(str), "%s - %s unidades", ItemNomeInv(PlayerInventario[playerid][i][Slot]), ConvertMoney(PlayerInventario[playerid][i][Unidades]));
		PlayerTextDrawSetString(playerid, DrawInv[playerid][38], str);
		PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][i], 0.000000, 0.000000, 0.000000, 1);
	}
	PlayerTextDrawShow(playerid, DrawInv[playerid][38]);
	PlayerTextDrawShow(playerid, DrawInv[playerid][i]);
	SalvarInventario(playerid);
    return 1;
}
 
FuncaoItens(playerid, modelid, quantidade)//  AQUI VOCÊ PODE DEFINIR AS FUNÇÕES DE CADA ITEM. SEGUE AS FUNÇÕES PRONTAS ABAIXO
{
	new Float:life5;
	switch(PlayerInventario[playerid][modelid][Slot])
	{
		case 19515:
		{
			PlayerInventario[playerid][modelid][Unidades]--;
			StatsControl(playerid, 1, 100.0, 0);
			AtualizarInventario(playerid, modelid);
		}
		case 331..371://
        {
            GivePlayerWeapon(playerid, GetArmaInv(PlayerInventario[playerid][modelid][Slot]), PlayerInventario[playerid][modelid][Unidades]);
            PlayerInventario[playerid][modelid][Unidades] = 0;
            AtualizarInventario(playerid, modelid);
            return 1;
        }
        case 19823, 19820, 1486, 19824, 19822, 2958://Bebidas Alcoolicas
        {
        	PlayerInventario[playerid][modelid][Unidades]--;
        	StatsControl(playerid, 3, 0.0, 15);
        	if(life5 > 100){SetPlayerHealth(playerid, 100);}
        	new animlib[24], animname[24];
			format(animlib, sizeof(animlib), "VENDING");
			format(animname, sizeof(animname), "VEND_Drink_P");
			ApplyAnimation(playerid, animlib, animname, 4.1, 0, 0, 0, 0, 0, 1);
            AtualizarInventario(playerid, modelid);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_BEER);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_WINE);
            return 1;
        }
        case 11722, 11723://Mostarda & Ketchup
        {
        	PlayerInventario[playerid][modelid][Unidades]--;
        	StatsControl(playerid, 4, 0.0, 30);
        	if(life5 > 100){SetPlayerHealth(playerid, 100);}
        	new animlib[24], animname[24];
			format(animlib, sizeof(animlib), "FOOD");
			format(animname, sizeof(animname), "EAT_Burger");
            AtualizarInventario(playerid, modelid);
            return 1;
        }
        case 19570, 1668, 1546, 2601://Leite & Agua & Refrigerante
        {
        	StatsControl(playerid, 3, 0.0, 50);
        	if(life5 > 100){SetPlayerHealth(playerid, 100);}
        	PlayerInventario[playerid][modelid][Unidades]--;
        	new animlib[24], animname[24];
			format(animlib, sizeof(animlib), "VENDING");
			format(animname, sizeof(animname), "VEND_Drink_P");
            AtualizarInventario(playerid, modelid);
            return 1;
        }
        case 1485, 19896, 19897://Baseado & Maco de Cigarro
        {
        	PlayerInventario[playerid][modelid][Unidades]--;
        	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);
			new animlib[24], animname[24];
			format(animlib, sizeof(animlib), "SMOKING");
			format(animname, sizeof(animname), "M_smk_drag");
        	AtualizarInventario(playerid, modelid);
            return 1;
        }
        case 19574, 19575, 19576://Frutas
        {
        	PlayerInventario[playerid][modelid][Unidades]--;
        	StatsControl(playerid, 4, 0.0, 50);
        	if(life5 > 100){SetPlayerHealth(playerid, 100);}
        	new animlib[24], animname[24];
			format(animlib, sizeof(animlib), "FOOD");
			format(animname, sizeof(animname), "EAT_Burger");
            AtualizarInventario(playerid, modelid);
            return 1;
        }
        case 2703, 2880, 2768, 19094, 2769, 19579, 19630://Hamburgers & Peixes & Taco & Pão
        {
        	PlayerInventario[playerid][modelid][Unidades]--;
        	StatsControl(playerid, 4, 0.0, 50);
     		if(life5 > 100){SetPlayerHealth(playerid, 100);}   
        	new animlib[24], animname[24];
			format(animlib, sizeof(animlib), "FOOD");
			format(animname, sizeof(animname), "EAT_Burger");
            AtualizarInventario(playerid, modelid);
            return 1;
        }
        case 2881, 2702, 1582, 19580://Pizzas
        {
        	PlayerInventario[playerid][modelid][Unidades]--;
        	StatsControl(playerid, 4, 0.0, 50);
        	if(life5 > 100){SetPlayerHealth(playerid, 100);}
        	new animlib[24], animname[24];
			format(animlib, sizeof(animlib), "FOOD");
			format(animname, sizeof(animname), "EAT_Burger");
            AtualizarInventario(playerid, modelid);
            return 1;
        }
        case 2709://Remedio
        {
        	StatsControl(playerid, 2, 25.0, 0);
        	if(life5 > 100){SetPlayerHealth(playerid, 100);}
        	PlayerInventario[playerid][modelid][Unidades]--;
        	AtualizarInventario(playerid, modelid);
            return 1;
        }
        case 11738://Remedio Grande
        {
        	StatsControl(playerid, 2, 50.0, 0);
        	if(life5 > 100){SetPlayerHealth(playerid, 100);}
        	PlayerInventario[playerid][modelid][Unidades]--;
        	AtualizarInventario(playerid, modelid);
            return 1;
        }
        case 1212:
        {
        	GivePlayerMoney(playerid, PlayerInventario[playerid][modelid][Unidades]);
        	PlayerInventario[playerid][modelid][Unidades] = 0;
        	AtualizarInventario(playerid, modelid);
        	return 1;
		}
		case 322:
		{
			if(quantidade > 0) {
				new weapon = GetPlayerWeapon(playerid);
				if(PlayerInventario[playerid][modelid][Unidades] >= quantidade)
				{
					if(weapon != 0) {
						GivePlayerWeapon(playerid, weapon, quantidade);
						PlayerInventario[playerid][modelid][Unidades] -= quantidade;
						AtualizarInventario(playerid, modelid);
					} else {
						Notificar(playerid, "INVENTARIO", "Voce nao possui uma arma em sua mao para poder usar as municoes.");
					}
				}
			}
			return 1;
		}
	}
	return 0;
}

static GetIDArma(i)
{
    switch(i)
    {
		case 331: return 1;
        case 333: return 2;
        case 334: return 3;
        case 335: return 4;
        case 336: return 5;
        case 337: return 6;
        case 338: return 7;
        case 339: return 8;
        case 341: return 9;
        case 321: return 10;
        case 322: return 11;
        case 323: return 12;
        case 324: return 13;
        case 325: return 14;
        case 326: return 15;
        case 342: return 16;
        case 343: return 17;
        case 344: return 18;
        case 346: return 22;
        case 347: return 23;
        case 348: return 24;
        case 349: return 25;
        case 350: return 26;
        case 351: return 27;
        case 352: return 28;
        case 353: return 29;
        case 355: return 30;
        case 356: return 31;
        case 372: return 32;
        case 357: return 33;
        case 358: return 34;
        case 359: return 35;
        case 360: return 36;
        case 361: return 37;
        case 362: return 38;
        case 363: return 39;
        case 364: return 40;
        case 365: return 41;
        case 366: return 42;
        case 367: return 43;
        case 368: return 44;
        case 369: return 45;
        case 371: return 46;
    }
    return 1;
}

static GetArmaInv(i)
{
    switch(i)
    {
        case 331: return 1;
        case 333: return 2;
        case 334: return 3;
        case 335: return 4;
        case 336: return 5;
        case 337: return 6;
        case 338: return 7;
        case 339: return 8;
        case 341: return 9;
        case 321: return 10;
        case 322: return 11;
        case 323: return 12;
        case 324: return 13;
        case 325: return 14;
        case 326: return 15;
        case 342: return 16;
        case 343: return 17;
        case 344: return 18;
        case 346: return 22;
        case 347: return 23;
        case 348: return 24;
        case 349: return 25;
        case 350: return 26;
        case 351: return 27;
        case 352: return 28;
        case 353: return 29;
        case 355: return 30;
        case 356: return 31;
        case 372: return 32;
        case 357: return 33;
        case 358: return 34;
        case 359: return 35;
        case 360: return 36;
        case 361: return 37;
        case 362: return 38;
        case 363: return 39;
        case 364: return 40;
        case 365: return 41;
        case 366: return 42;
        case 367: return 43;
        case 368: return 44;
        case 369: return 45;
        case 371: return 46;
    }
    return 1;
}
 
IsValidItemInv(itemid) //AQUI VOCÊ DEVE DEFINIR OS ID'S DOS ITENS PARA SER VALIDO AO SETAR, CASO CONTRARIO RETORNARA COMO ERRO
{
	if(GetArmaInv(itemid)) return 1;
	switch(itemid)
	{
		case 1550, 1279, 2061, 19873, 1575, 630, 322, 19823, 19820, 11722, 11723, 19570, 19824, 1486, 19822, 1668, 2958, 19625, 11746,
		3044, 19039, 19040, 19042, 19044, 19045, 19046, 19047, 11747, 18865, 18866, 18867,
		18868, 18869, 18870, 18871, 18872, 18873, 18874, 19513, 18875, 19874, 19138, 19139,
		19140, 19022, 19023, 19024, 19025, 19026, 19027, 19028, 19029, 19030, 19031, 19032,
		19033, 19034, 19035, 2992, 3065, 11712, 18953, 18954, 19554, 18974, 2114,
		18894, 18903, 18898, 18899, 18891, 18909, 18908, 18907, 18906, 18905, 18904, 18901,
		18902, 18892, 18900, 18897, 18896, 18895, 18893, 18810, 18947, 18948, 18949, 18950,
		18951, 19488, 18921, 18922, 18923, 18924, 18925, 18939, 18940, 18941, 18942, 18943,
		1314, 19578, 18636, 19942, 18646, 19141, 19558, 19801, 19330, 1210, 19528,
		19134, 19904, 19515, 19142, 19315, 19527, 19317, 18688, 18702, 18728, 19605, 19606,
		19607, 19577, 1485, 19574, 19575, 19576, 2703, 2880, 19883, 19896, 19897, 1546, 2768, 1212,
		2601, 19835, 2881, 2702, 2769, 2709, 19579, 19630, 19094, 1582, 19580, 19602, 11738,
		1654, 11736, 1650, 1252, 19893, 19921, 2226, 19054, 19056, 19055, 19057,354,1145,19058: return 1;
	}
	return 0;
}
 
ConvertMoney(number)
{
    new real,mil,milhao,milhaor,bilhao,bilhaor,string[100];
    if(number > 999999999)
    {
        bilhao = number / 1000000000;
        bilhaor = number % 1000000000;
        milhao =  bilhaor / 1000000;
        milhaor = bilhaor % 1000000;
        mil = milhaor / 1000;
        real = milhaor % 1000;
    }
    else if(number > 999999)
    {
        milhao = number / 1000000;
        milhaor = number % 1000000;
        mil = milhaor / 1000;
        real = milhaor % 1000;
    }
    else if(number > 999)
    {
        mil = number / 1000;
        real = number % 1000;
    }
    if(number > 999999999)
    {
        format(string, 100, "%d.%03d.%03d.%03d", bilhao, milhao, mil, real);
    }
    else if(number > 999999)
    {
        format(string, 100, "%d.%03d.%03d", milhao, mil, real);
    }
    else if(number > 999)
    {
        format(string, 100, "%d.%03d", mil, real);
    }
    else
    {
        format(string, 100, "%d", number);
    }
    return string;
}
 
PF::TextDrawInv(playerid)
{

	new emptyString[1];

	DrawInv[playerid][0] = CreatePlayerTextDraw(playerid, 373.000000, 179.000000, "box");
	PlayerTextDrawLetterSize(playerid, DrawInv[playerid][0], 0.000000, 14.687500);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][0], 592.389404, 0.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][0], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][0], -1);
	PlayerTextDrawUseBox(playerid, DrawInv[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, DrawInv[playerid][0], 150);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][0], 255);
	PlayerTextDrawFont(playerid, DrawInv[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][0], 1);
 
	DrawInv[playerid][1] = CreatePlayerTextDraw(playerid, 372.000000, 179.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][1], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][1], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][1], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][1], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][1], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][1], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][1], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][1], 0.000000, 0.000000, 0.000000, 99.000000);
 
	DrawInv[playerid][2] = CreatePlayerTextDraw(playerid, 400.000000, 179.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][2], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][2], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][2], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][2], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][2], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][2], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][2], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][2], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][3] = CreatePlayerTextDraw(playerid, 428.000000, 179.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][3], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][3], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][3], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][3], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][3], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][3], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][3], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][3], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][3], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][4] = CreatePlayerTextDraw(playerid, 456.000000, 179.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][4], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][4], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][4], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][4], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][4], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][4], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][4], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][4], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][4], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][5] = CreatePlayerTextDraw(playerid, 484.000000, 179.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][5], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][5], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][5], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][5], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][5], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][5], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][5], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][5], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][6] = CreatePlayerTextDraw(playerid, 512.000000, 179.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][6], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][6], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][6], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][6], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][6], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][6], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][6], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][6], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][7] = CreatePlayerTextDraw(playerid, 540.000000, 179.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][7], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][7], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][7], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][7], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][7], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][7], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][7], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][7], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][8] = CreatePlayerTextDraw(playerid, 568.000000, 179.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][8], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][8], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][8], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][8], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][8], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][8], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][8], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][8], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][9] = CreatePlayerTextDraw(playerid, 372.000000, 207.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][9], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][9], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][9], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][9], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][9], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][9], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][9], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][9], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][10] = CreatePlayerTextDraw(playerid, 400.000000, 207.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][10], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][10], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][10], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][10], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][10], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][10], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][10], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][10], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][10], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][10], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][11] = CreatePlayerTextDraw(playerid, 428.000000, 207.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][11], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][11], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][11], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][11], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][11], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][11], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][11], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][11], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][11], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][11], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][12] = CreatePlayerTextDraw(playerid, 456.000000, 207.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][12], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][12], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][12], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][12], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][12], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][12], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][12], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][12], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][12], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][12], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][13] = CreatePlayerTextDraw(playerid, 484.000000, 207.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][13], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][13], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][13], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][13], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][13], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][13], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][13], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][13], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][13], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][13], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][14] = CreatePlayerTextDraw(playerid, 512.000000, 207.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][14], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][14], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][14], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][14], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][14], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][14], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][14], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][14], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][14], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][14], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][15] = CreatePlayerTextDraw(playerid, 540.000000, 207.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][15], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][15], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][15], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][15], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][15], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][15], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][15], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][15], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][15], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][15], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][16] = CreatePlayerTextDraw(playerid, 568.000000, 207.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][16], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][16], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][16], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][16], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][16], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][16], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][16], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][16], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][16], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][16], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][17] = CreatePlayerTextDraw(playerid, 372.000000, 235.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][17], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][17], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][17], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][17], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][17], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][17], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][17], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][17], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][17], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][17], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][18] = CreatePlayerTextDraw(playerid, 400.000000, 235.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][18], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][18], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][18], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][18], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][18], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][18], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][18], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][18], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][18], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][18], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][19] = CreatePlayerTextDraw(playerid, 428.000000, 235.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][19], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][19], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][19], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][19], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][19], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][19], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][19], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][19], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][19], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][19], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][20] = CreatePlayerTextDraw(playerid, 456.000000, 235.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][20], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][20], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][20], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][20], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][20], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][20], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][20], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][20], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][20], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][20], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][21] = CreatePlayerTextDraw(playerid, 484.000000, 235.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][21], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][21], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][21], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][21], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][21], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][21], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][21], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][21], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][21], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][21], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][22] = CreatePlayerTextDraw(playerid, 512.000000, 235.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][22], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][22], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][22], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][22], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][22], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][22], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][22], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][22], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][22], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][22], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][23] = CreatePlayerTextDraw(playerid, 540.000000, 235.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][23], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][23], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][23], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][23], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][23], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][23], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][23], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][23], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][23], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][23], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][24] = CreatePlayerTextDraw(playerid, 568.000000, 235.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][24], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][24], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][24], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][24], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][24], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][24], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][24], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][24], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][24], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][24], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][25] = CreatePlayerTextDraw(playerid, 372.000000, 263.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][25], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][25], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][25], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][25], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][25], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][25], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][25], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][25], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][25], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][25], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][26] = CreatePlayerTextDraw(playerid, 400.000000, 263.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][26], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][26], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][26], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][26], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][26], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][26], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][26], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][26], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][26], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][26], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][27] = CreatePlayerTextDraw(playerid, 428.000000, 263.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][27], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][27], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][27], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][27], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][27], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][27], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][27], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][27], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][27], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][28] = CreatePlayerTextDraw(playerid, 456.000000, 263.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][28], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][28], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][28], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][28], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][28], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][28], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][28], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][28], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][28], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][28], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][29] = CreatePlayerTextDraw(playerid, 484.000000, 263.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][29], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][29], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][29], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][29], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][29], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][29], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][29], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][29], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][29], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][29], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][30] = CreatePlayerTextDraw(playerid, 512.000000, 263.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][30], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][30], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][30], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][30], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][30], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][30], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][30], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][30], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][30], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][30], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][31] = CreatePlayerTextDraw(playerid, 540.000000, 263.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][31], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][31], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][31], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][31], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][31], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][31], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][31], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][31], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][31], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][31], 0.000000, 0.000000, 0.000000, 1.000000);
 
	DrawInv[playerid][32] = CreatePlayerTextDraw(playerid, 568.000000, 263.000000, emptyString);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][32], 25.000000, 25.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][32], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][32], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][32], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][32], 170);
	PlayerTextDrawFont(playerid, DrawInv[playerid][32], 5);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][32], 0);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][32], true);
	PlayerTextDrawSetPreviewModel(playerid, DrawInv[playerid][32], 0);
	PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][32], 0.000000, 0.000000, 0.000000, 1.000000);
 
	for(new i = 1; i < 33; ++i)
	{
		PlayerTextDrawSetPreviewRot(playerid, DrawInv[playerid][i], 0.000000, 0.000000, 0.000000, 999);
	}
 
	DrawInv[playerid][33] = CreatePlayerTextDraw(playerid, 373.000000, 161.000000, "box");
	PlayerTextDrawLetterSize(playerid, DrawInv[playerid][33], 0.000000, 1.466506);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][33], 592.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][33], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][33], -1);
	PlayerTextDrawUseBox(playerid, DrawInv[playerid][33], 1);
	PlayerTextDrawBoxColor(playerid, DrawInv[playerid][33], 255);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][33], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][33], 255);
	PlayerTextDrawFont(playerid, DrawInv[playerid][33], 1);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][33], 1);
 
	DrawInv[playerid][34] = CreatePlayerTextDraw(playerid, 372.000000, 162.000000, "INVENTARIO:_MAX_PLAYER_NAME");
	PlayerTextDrawLetterSize(playerid, DrawInv[playerid][34], 0.210623, 0.888332);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][34], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][34], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][34], 0);
	PlayerTextDrawSetOutline(playerid, DrawInv[playerid][34], 1);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][34], 255);
	PlayerTextDrawFont(playerid, DrawInv[playerid][34], 1);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][34], 1);
 
	DrawInv[playerid][35] = CreatePlayerTextDraw(playerid, 584.375000, 163.166656, "X");
	PlayerTextDrawLetterSize(playerid, DrawInv[playerid][35], 0.298748, 0.824165);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][35], 590, 10.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][35], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][35], -16776961);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][35], 0);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][35], 255);
	PlayerTextDrawFont(playerid, DrawInv[playerid][35], 3);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][35], 1);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][35], true);
 
	DrawInv[playerid][36] = CreatePlayerTextDraw(playerid, 374.000000, 296.000000, "Usar");
	PlayerTextDrawLetterSize(playerid, DrawInv[playerid][36], 0.200000, 1.000000);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][36], 396, 10.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][36], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][36], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][36], 0);
	PlayerTextDrawSetOutline(playerid, DrawInv[playerid][36], 1);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][36], 255);
	PlayerTextDrawFont(playerid, DrawInv[playerid][36], 2);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][36], 1);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][36], true);
 
	DrawInv[playerid][37] = CreatePlayerTextDraw(playerid, 405.000000, 296.000000, "Descartar");
	PlayerTextDrawLetterSize(playerid, DrawInv[playerid][37], 0.200000, 1.000000);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][37], 455, 10.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][37], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][37], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][37], 0);
	PlayerTextDrawSetOutline(playerid, DrawInv[playerid][37], 1);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][37], 255);
	PlayerTextDrawFont(playerid, DrawInv[playerid][37], 2);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][37], 1);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][37], true);
 
	DrawInv[playerid][38] = CreatePlayerTextDraw(playerid, 593.147094, 303.800354, "_0_unidades");
	PlayerTextDrawLetterSize(playerid, DrawInv[playerid][38], 0.200000, 0.800000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][38], 3);
	PlayerTextDrawColor(playerid, DrawInv[playerid][38], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][38], 0);
	PlayerTextDrawSetOutline(playerid, DrawInv[playerid][38], 1);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][38], 255);
	PlayerTextDrawFont(playerid, DrawInv[playerid][38], 1);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][38], 1);
 
	DrawInv[playerid][39] = CreatePlayerTextDraw(playerid, 464.601501, 296.016723, "Quantidade");
	PlayerTextDrawLetterSize(playerid, DrawInv[playerid][39], 0.200000, 1.000000);
	PlayerTextDrawTextSize(playerid, DrawInv[playerid][39], 502.000000, 10.000000);
	PlayerTextDrawAlignment(playerid, DrawInv[playerid][39], 1);
	PlayerTextDrawColor(playerid, DrawInv[playerid][39], -1);
	PlayerTextDrawSetShadow(playerid, DrawInv[playerid][39], 0);
	PlayerTextDrawSetOutline(playerid, DrawInv[playerid][39], 1);
	PlayerTextDrawBackgroundColor(playerid, DrawInv[playerid][39], 255);
	PlayerTextDrawFont(playerid, DrawInv[playerid][39], 2);
	PlayerTextDrawSetProportional(playerid, DrawInv[playerid][39], 1);
	PlayerTextDrawSetSelectable(playerid, DrawInv[playerid][39], true);
	return 1;
}