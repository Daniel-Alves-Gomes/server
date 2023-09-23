#include <a_samp>
#include <a_mysql>
#include <playerverification>
#include <fmt>
#include <Pawn.CMD>
#include <cef>
#include <foreach>
#include <sscanf2>
#include <streamer>
#include <fuelvehicle>
#include <YSI-Includes\YSI_Coding\y_hooks>
#include <YSI-Includes\YSI_Players\y_android>
#include "../Geral/Server/Database_Central.inc"
#include "../Geral/Server/Config/Formats/Format.inc"
#include "../Geral/Base/Groups/Group.inc"
#include "../Geral/Server/Textdraws/Hud.inc"

#include "../Geral/Base/User/Connection/ConnectionQuery.inc"

//CARS

#include "../Geral/Base/Vehicles/Vehicle.inc"
#include "../Geral/Base/Vehicles/Stats/Create.inc"
#include "../Geral/Base/Vehicles/Stats/Engine.inc"
#include "../Geral/Server/Textdraws/Velo.inc"

//

#include "../Geral/Base/Notify/Notify.inc"
#include "../Geral/Base/Inventory/InventoryClass.inc"
#include "../Geral/Base/Organizacoes/Organizacao.inc"
#include "../Geral/Base/Organizacoes/Gangues/Workbench/Bancada.inc"

forward InfoUser(playerid);

main()
{
}


public OnGameModeInit() {
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraPos(playerid, 1958.3783, 1343.1572, 15.3746);
	SetPlayerCameraLookAt(playerid, 1958.3783, 1343.1572, 15.3746);
	return 1;
}

public OnPlayerConnect(playerid)
{
	new Query[128];
    mysql_format(ConexaoSQL, Query, sizeof(Query), "SELECT * FROM `server_accounts` WHERE `nome`='%e'", GetPlayerNameEx(playerid));
    mysql_tquery(ConexaoSQL, Query, "InfoUser", "i", playerid);
	return 1;
}

public InfoUser(playerid) {
    if(cache_num_rows() > 0) {
        cache_get_value_name_int(0, "hex", hexUser[playerid][hex]);
    } else {
        Kick(playerid);
    }
    return 1;
}

//CMD:check_plugin(playerid) return SCMf(playerid, -1, "Plugin status: - %s", cef_player_has_plugin(playerid) ? ("{ffc600}Sucess") : ("{ff0000}Not sucess"));
stock VelocidadeDoVeiculo(vehicleid) {
	new Float:xPos[3];
	GetVehicleVelocity(vehicleid, xPos[0], xPos[1], xPos[2]);
	return floatround(floatsqroot(xPos[0] * xPos[0] + xPos[1] * xPos[1] + xPos[2] * xPos[2]) * 170.00);
}