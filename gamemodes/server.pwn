#include <a_samp>
#include <a_mysql>
#include <fmt>
#include <Pawn.CMD>
#include <cef>
#include <sscanf2>
#include <streamer>
#include <fuelvehicle>
#include <playervehicle>
#include <playerverification>
#include <YSI-Includes\YSI_Coding\y_hooks>
#include "../Geral/Server/Database_Central.inc"
#include "../Geral/Server/Config/Formats/Format.inc"
#include "../Geral/Base/Groups/Group.inc"
#include "../Geral/Base/Notify/Notify.inc"
#include "../Geral/Base/Empregos/Empregos.inc"
#include "../Geral/Base/Vehicles/Vehicle.inc"
#include "../Geral/Base/Vehicles/Fuel/Fuel.inc"
#include "../Geral/Base/Vehicles/Stats/Engine.inc"
#include "../Geral/Base/Vehicles/Stats/Cinto.inc"
#include "../Geral/Base/Vehicles/Stats/Garage.inc"
#include "../Geral/Base/Inventory/InventoryClass.inc"
#include "../Geral/Base/Inventory/Hooks/ItemHooks.inc"
#include "../Geral/Base/Organizacoes/Organizacao.inc"
#include "../Geral/Base/Organizacoes/Gangues/Workbench/Bancada.inc"

#define CEF_HUD (1)
#define SCMf SendClientMessagef

enum Player_Data
{
	Float:fome,
	Float:sede
}
new pInfo[MAX_PLAYERS][Player_Data];
new TimerHUD[MAX_PLAYERS];
new TimerFomeSede[MAX_PLAYERS];

main()
{
}


public OnGameModeInit()
{
	new tmpobjid;
	tmpobjid = CreateDynamicObject(19379, 1000.000000, 1000.000000, 1000.000000, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1010.459716, 1000.000000, 1000.000000, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1020.939636, 1000.000000, 1000.000000, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 999.630554, 1007.069213, 1004.787658, 0.000000, 25.900003, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10806, "airfence_sfse", "ws_leccyfncetop", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 999.630554, 1007.087158, 1004.778869, 0.000000, 25.900003, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18065, "ab_sfammumain", "shelf_glas", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1009.250793, 1007.069213, 1004.787658, 0.000007, 25.900003, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10806, "airfence_sfse", "ws_leccyfncetop", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1009.250793, 1007.087158, 1004.778869, 0.000007, 25.900003, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18065, "ab_sfammumain", "shelf_glas", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1018.870483, 1007.069213, 1004.787658, 0.000014, 25.900003, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10806, "airfence_sfse", "ws_leccyfncetop", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1018.870483, 1007.087158, 1004.778869, 0.000014, 25.900003, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18065, "ab_sfammumain", "shelf_glas", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(18762, 1004.610351, 1006.145874, 1002.174499, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.601623, 1008.413757, 1006.664489, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1017.331054, 1006.145874, 1002.174499, -26.799991, -0.099991, 0.000003, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1017.322326, 1008.413757, 1006.664489, -26.799991, -0.099991, 0.000003, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 994.791687, 1006.145874, 1002.174499, -26.799989, -0.099982, 0.000007, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 994.782958, 1008.413757, 1006.664489, -26.799989, -0.099982, 0.000007, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 998.999755, 1009.839050, 993.955871, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1008.969299, 1009.839050, 993.955871, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1018.729064, 1009.839050, 993.955871, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1000.000000, 990.389282, 1000.000000, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1010.459716, 990.389282, 1000.000000, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1020.939636, 990.389282, 1000.000000, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1000.000000, 980.779602, 1000.000000, 0.000000, 90.000030, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1010.459716, 980.779602, 1000.000000, 0.000000, 90.000030, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1020.939636, 980.779602, 1000.000000, 0.000000, 90.000030, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1031.370117, 980.779602, 1000.000000, 0.000000, 90.000038, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1041.829833, 980.779602, 1000.000000, 0.000000, 90.000038, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1052.309814, 980.779602, 1000.000000, 0.000000, 90.000038, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1031.370117, 990.399658, 1000.000000, 0.000000, 90.000045, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1041.829833, 990.399658, 1000.000000, 0.000000, 90.000045, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1052.309814, 990.399658, 1000.000000, 0.000000, 90.000045, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1031.370117, 999.979309, 1000.000000, 0.000000, 90.000053, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1041.829833, 999.979309, 1000.000000, 0.000000, 90.000053, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1052.309814, 999.979309, 1000.000000, 0.000000, 90.000053, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1028.509277, 1007.069213, 1004.787658, 0.000007, 25.900003, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10806, "airfence_sfse", "ws_leccyfncetop", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1028.509277, 1007.087158, 1004.778869, 0.000007, 25.900003, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18065, "ab_sfammumain", "shelf_glas", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1038.129394, 1007.069213, 1004.787658, 0.000014, 25.900003, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10806, "airfence_sfse", "ws_leccyfncetop", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1038.129394, 1007.087158, 1004.778869, 0.000014, 25.900003, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18065, "ab_sfammumain", "shelf_glas", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1047.749145, 1007.069213, 1004.787658, 0.000022, 25.900003, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10806, "airfence_sfse", "ws_leccyfncetop", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1047.749145, 1007.087158, 1004.778869, 0.000022, 25.900003, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 18065, "ab_sfammumain", "shelf_glas", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(18762, 1030.093261, 1006.145874, 1002.174499, -26.799989, -0.099982, 0.000006, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1030.084472, 1008.413757, 1006.664489, -26.799989, -0.099982, 0.000006, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1042.825805, 1006.145874, 1002.174499, -26.799987, -0.099973, 0.000009, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1042.817016, 1008.413757, 1006.664489, -26.799987, -0.099973, 0.000009, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 999.688171, 1004.711608, 1009.176635, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1010.157226, 1004.711608, 1009.176635, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1020.646850, 1004.711608, 1009.176635, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1031.146728, 1004.711608, 1009.176635, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1041.636474, 1004.711608, 1009.176635, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1052.135131, 1004.711608, 1009.176635, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1042.825805, 996.506286, 1002.174499, -26.799985, -0.099965, 0.000014, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1042.817016, 998.774169, 1006.664489, -26.799985, -0.099965, 0.000014, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 999.688171, 995.072021, 1009.176635, 0.000000, 90.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1010.157226, 995.072021, 1009.176635, 0.000000, 90.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1020.646850, 995.072021, 1009.176635, 0.000000, 90.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1031.146728, 995.072021, 1009.176635, 0.000000, 90.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1041.636474, 995.072021, 1009.176635, 0.000000, 90.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1052.135131, 995.072021, 1009.176635, 0.000000, 90.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1030.093261, 996.534851, 1002.174499, -26.799987, -0.099973, 0.000009, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1030.084472, 998.802734, 1006.664489, -26.799987, -0.099973, 0.000009, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1017.303100, 996.534851, 1002.174499, -26.799985, -0.099965, 0.000014, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1017.294311, 998.802734, 1006.664489, -26.799985, -0.099965, 0.000014, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.861328, 996.534851, 1002.174499, -26.799982, -0.099956, 0.000018, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.852539, 998.802734, 1006.664489, -26.799982, -0.099956, 0.000018, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 999.688171, 985.482910, 1009.176635, 0.000000, 90.000015, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1010.157226, 985.482910, 1009.176635, 0.000000, 90.000015, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1020.646850, 985.482910, 1009.176635, 0.000000, 90.000015, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1031.146728, 985.482910, 1009.176635, 0.000000, 90.000015, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1041.636474, 985.482910, 1009.176635, 0.000000, 90.000015, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1052.135131, 985.482910, 1009.176635, 0.000000, 90.000015, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19379, 1000.000000, 971.179748, 1000.000000, 0.000000, 90.000045, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1010.459716, 971.179748, 1000.000000, 0.000000, 90.000045, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1020.939636, 971.179748, 1000.000000, 0.000000, 90.000045, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1031.370117, 971.179748, 1000.000000, 0.000000, 90.000053, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1041.829833, 971.179748, 1000.000000, 0.000000, 90.000053, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(19379, 1052.309814, 971.179748, 1000.000000, 0.000000, 90.000053, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "ws_metalpanel1", 0x90FFFFFF);
	tmpobjid = CreateDynamicObject(18762, 1004.860351, 997.139038, 1008.785888, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.860351, 992.159362, 1008.785888, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.860351, 987.199829, 1008.785888, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1017.271179, 997.139038, 1008.785888, 0.000007, 90.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1017.271179, 992.159362, 1008.785888, 0.000007, 90.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1017.271179, 987.199829, 1008.785888, 0.000007, 90.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1030.101928, 997.139038, 1008.785888, 0.000014, 90.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1030.101928, 992.159362, 1008.785888, 0.000014, 90.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1030.101928, 987.199829, 1008.785888, 0.000014, 90.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1042.792236, 997.139038, 1008.785888, 0.000022, 90.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1042.792236, 992.159362, 1008.785888, 0.000022, 90.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1042.792236, 987.199829, 1008.785888, 0.000022, 90.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 999.648620, 966.361022, 1005.306152, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1009.258483, 966.361022, 1005.306152, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1018.928588, 966.361022, 1005.306152, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1028.577392, 966.361022, 1005.306152, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1038.237304, 966.361022, 1005.306152, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1047.876220, 966.361022, 1005.306152, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1057.476074, 966.361022, 1005.306152, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 999.688171, 975.833618, 1009.176635, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1010.157226, 975.833618, 1009.176635, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1020.646850, 975.833618, 1009.176635, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1031.146728, 975.833618, 1009.176635, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1041.636474, 975.833618, 1009.176635, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1052.135131, 975.833618, 1009.176635, 0.000000, 90.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1042.792236, 987.489746, 1008.785888, 0.000029, 90.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1042.792236, 982.510070, 1008.785888, 0.000029, 90.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1042.792236, 977.550537, 1008.785888, 0.000029, 90.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 999.688171, 966.303649, 1009.176635, 0.000000, 90.000030, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1010.157226, 966.303649, 1009.176635, 0.000000, 90.000030, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1020.646850, 966.303649, 1009.176635, 0.000000, 90.000030, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1031.146728, 966.303649, 1009.176635, 0.000000, 90.000030, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1041.636474, 966.303649, 1009.176635, 0.000000, 90.000030, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1052.135131, 966.303649, 1009.176635, 0.000000, 90.000030, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10041, "archybuild10", "rooftop_gz3", 0x00000000);
	tmpobjid = CreateDynamicObject(2445, 1031.619140, 993.846313, 1000.015930, 0.000014, 0.000007, 89.999923, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(2445, 1031.619140, 992.866577, 1000.015930, 0.000014, 0.000007, 89.999923, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(2445, 1031.619140, 990.145874, 1000.015930, 0.000014, 0.000014, 89.999923, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(2445, 1031.619140, 989.166137, 1000.015930, 0.000014, 0.000014, 89.999923, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(2445, 1031.619140, 986.455322, 1000.015930, 0.000014, 0.000022, 89.999923, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(2445, 1031.619140, 985.475585, 1000.015930, 0.000014, 0.000022, 89.999923, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(2445, 1031.619140, 982.924560, 1000.015930, 0.000014, 0.000029, 89.999923, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(2445, 1031.619140, 981.944824, 1000.015930, 0.000014, 0.000029, 89.999923, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(2445, 1031.619140, 978.924072, 1000.015930, 0.000014, 0.000037, 89.999923, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(2445, 1031.619140, 977.944335, 1000.015930, 0.000014, 0.000037, 89.999923, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1027.751831, 994.333679, 1000.606384, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1027.751831, 992.393615, 1000.606384, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1027.751831, 990.574157, 1000.606384, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1027.751831, 988.634094, 1000.606384, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1027.751831, 986.853149, 1000.606384, 0.000014, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1027.751831, 984.913085, 1000.606384, 0.000014, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1027.751831, 983.262878, 1000.606384, 0.000022, 0.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1027.751831, 981.322814, 1000.606384, 0.000022, 0.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1027.751831, 979.392944, 1000.606384, 0.000029, 0.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1027.751831, 977.452880, 1000.606384, 0.000029, 0.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1025.811157, 994.333679, 1000.606384, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1025.811157, 992.393615, 1000.606384, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1025.811157, 990.574157, 1000.606384, 0.000014, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1025.811157, 988.634094, 1000.606384, 0.000014, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1025.811157, 986.853149, 1000.606384, 0.000022, 0.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1025.811157, 984.913085, 1000.606384, 0.000022, 0.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1025.811157, 983.262878, 1000.606384, 0.000029, 0.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1025.811157, 981.322814, 1000.606384, 0.000029, 0.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1025.811157, 979.392944, 1000.606384, 0.000037, 0.000000, 89.999885, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1025.811157, 977.452880, 1000.606384, 0.000037, 0.000000, 89.999885, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1023.870849, 994.333679, 1000.606384, 0.000014, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1023.870849, 992.393615, 1000.606384, 0.000014, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1023.870849, 990.574157, 1000.606384, 0.000022, 0.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1023.870849, 988.634094, 1000.606384, 0.000022, 0.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1023.870849, 986.853149, 1000.606384, 0.000029, 0.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1023.870849, 984.913085, 1000.606384, 0.000029, 0.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1023.870849, 983.262878, 1000.606384, 0.000037, 0.000000, 89.999885, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1023.870849, 981.322814, 1000.606384, 0.000037, 0.000000, 89.999885, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1023.870849, 979.392944, 1000.606384, 0.000045, 0.000000, 89.999862, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(2773, 1023.870849, 977.452880, 1000.606384, 0.000045, 0.000000, 89.999862, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 19058, "xmasboxes", "silk7-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(1897, 1031.441650, 991.466369, 1000.165893, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(1897, 1031.441650, 987.826171, 1000.165893, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(1897, 1031.441650, 984.056091, 1000.165893, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(1897, 1031.441650, 980.496093, 1000.165893, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1036.765625, 988.744201, 1002.495910, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1036.765625, 982.443725, 1002.495910, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1036.765625, 994.014221, 1002.495910, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1036.765625, 976.713500, 1002.495910, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1036.926391, 980.469970, 1001.835937, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1036.926391, 978.569946, 1001.835937, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1036.926391, 992.870483, 1001.835937, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1036.926391, 989.870483, 1001.835937, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1034.957641, 988.945678, 1006.393127, -0.300000, -54.299991, -5.199998, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1035.427612, 994.114196, 1006.366149, -0.300000, -54.299991, -5.199998, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1034.381713, 982.622314, 1006.426452, -0.300000, -54.299991, -5.199998, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1034.736206, 976.907287, 1006.520019, -0.300000, -54.299991, -5.199998, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1039.000488, 982.283508, 1006.394958, -0.299991, -54.299991, 174.799880, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1038.483520, 976.597412, 1006.365112, -0.299991, -54.299991, 174.799880, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1038.861816, 988.571899, 1006.435974, -0.299991, -54.299991, 174.799880, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1038.960327, 993.774597, 1006.366943, -0.299991, -54.299991, 174.799880, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1033.500732, 992.051513, 1007.066345, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1033.500732, 992.051513, 1006.026367, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1033.500732, 987.071655, 1007.066345, 0.000007, 90.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1033.500732, 987.071655, 1006.026367, 0.000007, 90.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1033.500732, 982.171569, 1007.066345, 0.000014, 90.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1033.500732, 982.171569, 1006.026367, 0.000014, 90.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1033.500732, 977.351318, 1007.066345, 0.000022, 90.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1033.500732, 977.351318, 1006.026367, 0.000022, 90.000000, 89.999931, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1039.641479, 977.351318, 1007.066345, 0.000029, 90.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1039.641479, 977.351318, 1006.026367, 0.000029, 90.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1039.641479, 982.211303, 1007.066345, 0.000037, 90.000000, 89.999885, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1039.641479, 982.211303, 1006.026367, 0.000037, 90.000000, 89.999885, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1039.641479, 987.161132, 1007.066345, 0.000045, 90.000000, 89.999862, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1039.641479, 987.161132, 1006.026367, 0.000045, 90.000000, 89.999862, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1039.641479, 992.001159, 1007.066345, 0.000052, 90.000000, 89.999839, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1039.641479, 992.001159, 1006.026367, 0.000052, 90.000000, 89.999839, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "sl_vicbrikwall01", 0x00000000);
	tmpobjid = CreateDynamicObject(19786, 1033.099975, 985.597106, 1006.716430, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 2772, "airp_prop", "CJ_AIRP_S_1", 0x00000000);
	tmpobjid = CreateDynamicObject(19786, 1033.099975, 991.687316, 1006.716430, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 2772, "airp_prop", "CJ_AIRP_S_1", 0x00000000);
	tmpobjid = CreateDynamicObject(19786, 1033.099975, 979.346923, 1006.716430, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 2772, "airp_prop", "CJ_AIRP_S_1", 0x00000000);
	tmpobjid = CreateDynamicObject(7313, 1033.338745, 984.668273, 1004.516113, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF} BOARDING", 110, "Arial", 60, 1, 0x00000000, 0x00000001, 1);
	tmpobjid = CreateDynamicObject(19128, 1036.828125, 991.320983, 1001.366210, 90.000000, 90.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 2430, "cj_burg_sign", "CJ_BS_MENU3", 0x00000000);
	tmpobjid = CreateDynamicObject(19128, 1036.828125, 979.521179, 1001.366210, 90.000000, 90.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 1733, "cj_commercial", "CJ_SPRUNK_FRONT", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 999.819946, 966.565002, 1005.275634, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 1009.449401, 966.565002, 1005.285888, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 1008.524414, 966.665161, 1005.336303, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF} S E L F", 120, "Calibri", 100, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 1005.254577, 966.665161, 1005.336303, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF} C H E C K", 120, "Calibri", 100, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 1003.185119, 966.665161, 1005.636230, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF} -", 50, "Calibri", 100, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 1001.765136, 966.665161, 1005.376403, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF} I N", 120, "Calibri", 100, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(18765, 1028.708374, 1009.839050, 993.955871, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1038.658935, 1009.839050, 993.955871, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1048.568725, 1009.839050, 993.955871, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1058.528808, 1009.839050, 993.955871, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 998.999755, 1019.788696, 993.955871, 0.000000, 0.000014, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1008.969299, 1019.788696, 993.955871, 0.000000, 0.000014, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1018.729064, 1019.788696, 993.955871, 0.000000, 0.000014, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1052.705444, 1006.261901, 1001.776000, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1057.555419, 1006.261901, 1001.776000, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1028.708374, 1019.788696, 993.955871, 0.000000, 0.000014, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1038.658935, 1019.788696, 993.955871, 0.000000, 0.000014, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1048.568725, 1019.788696, 993.955871, 0.000000, 0.000014, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1058.528808, 1019.788696, 993.955871, 0.000000, 0.000014, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 998.999755, 1029.607910, 993.955871, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1008.969299, 1029.607910, 993.955871, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1018.729064, 1029.607910, 993.955871, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1057.555419, 1009.431823, 1001.776000, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1052.694946, 1009.431823, 1001.776000, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1028.708374, 1029.607910, 993.955871, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1038.658935, 1029.607910, 993.955871, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1048.568725, 1029.607910, 993.955871, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(18765, 1058.528808, 1029.607910, 993.955871, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 11013, "crackdrive_sfse", "ws_asphalt2", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1054.474731, 1006.161499, 999.986389, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1057.953857, 1006.161499, 999.986389, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1057.953857, 1009.351684, 999.986389, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1054.464233, 1009.351684, 999.986389, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1055.165527, 1010.951599, 1001.776000, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16293, "a51_undergrnd", "Was_scrpyd_door_in_hngr", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1055.925292, 1011.001708, 1001.776000, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1054.194946, 1011.001708, 1001.776000, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1054.464233, 1009.351684, 1003.586791, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1054.464233, 1006.171936, 1003.586791, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1057.914306, 1006.171936, 1003.586791, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1057.914306, 1009.361511, 1003.586791, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1057.476074, 971.200500, 1005.306152, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1057.476074, 980.839599, 1005.306152, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1057.476074, 990.489440, 1005.306152, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 1057.476074, 1000.179199, 1005.306152, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1055.741455, 1004.708435, 1005.435729, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1054.191284, 1004.698425, 1005.435729, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1052.692382, 1006.248352, 1005.435729, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1055.741455, 1004.708435, 1008.965698, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1054.191284, 1004.698425, 1008.965698, 0.000007, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1052.692382, 1006.248352, 1008.965698, 0.000000, -0.000007, 179.999954, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1057.973999, 1008.933288, 997.608154, 0.000000, -31.200006, 3.399999, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "metpat64", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1053.107910, 1008.684326, 997.679199, 0.000000, -31.200006, 183.399993, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16640, "a51", "metpat64", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 994.761047, 971.218322, 1001.856018, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10763, "airport1_sfse", "airportwind03", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 994.761047, 980.838073, 1001.856018, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10763, "airport1_sfse", "ws_airportdoors1", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 994.761047, 990.407653, 1001.856018, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10763, "airport1_sfse", "airportwind03", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 994.761047, 999.996948, 1001.856018, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10763, "airport1_sfse", "airportwind03", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 994.728637, 971.110900, 1005.306152, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 994.728637, 980.690795, 1005.306152, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 994.728637, 990.310485, 1005.306152, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 994.728637, 999.880310, 1005.306152, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 994.728637, 1004.590148, 1005.306152, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(19378, 999.288635, 1004.580139, 1005.306152, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10755, "airportrminl_sfse", "ws_airportwall2", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.610351, 1005.458618, 1002.522033, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.601989, 1007.649780, 1006.860168, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.601989, 1006.783813, 1007.297119, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.610168, 1004.583862, 1002.940856, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.618774, 1002.365905, 998.549255, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.601562, 1006.039489, 1007.751220, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.610229, 1003.785583, 1003.287902, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.618347, 1001.693603, 999.146301, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.618347, 1003.255432, 998.357604, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.602111, 1005.083374, 1007.876098, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.610351, 1002.946411, 1003.645080, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18762, 1004.618286, 1000.854431, 999.503295, -26.799993, -0.100000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	tmpobjid = CreateDynamicObject(18764, 1009.124816, 984.064453, 998.085449, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19360, 1009.084899, 984.084167, 1000.555847, 0.000000, 90.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19058, "xmasboxes", "silk5-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(18763, 1010.194335, 984.428100, 1003.532470, 48.799991, -49.400005, 88.200012, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 19058, "xmasboxes", "silk6-128x128", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 994.917968, 973.401062, 1005.615783, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{000080} j", 50, "Webdings", 100, 0, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19482, 994.917968, 978.951049, 1005.615783, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF} W E L C O M E", 120, "Calibri", 100, 0, 0x00000000, 0x00000080, 1);
	tmpobjid = CreateDynamicObject(19482, 994.917968, 984.530883, 1005.615783, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF} T    O", 120, "Calibri", 100, 0, 0x00000000, 0x00000080, 1);
	tmpobjid = CreateDynamicObject(19482, 994.917968, 990.100402, 1005.615783, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF} A I R P O R T", 120, "Calibri", 100, 0, 0x00000000, 0x00000080, 1);
	tmpobjid = CreateDynamicObject(968, 994.797058, 976.208923, 1007.086059, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(968, 994.797058, 976.208923, 1004.245788, 0.000000, 90.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(968, 994.797058, 992.969909, 1004.245788, 0.000000, 90.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(968, 994.797058, 992.969909, 1007.135803, 0.000000, 90.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 16093, "a51_ext", "ws_whitewall2_top", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "black64", 0x00000000);
	tmpobjid = CreateDynamicObject(19482, 1052.608520, 966.721252, 1005.355834, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFFFFF} E X I T ------   >", 120, "Calibri", 100, 1, 0x00000000, 0x0000FF00, 1);
	tmpobjid = CreateDynamicObject(19482, 1005.108398, 1005.551330, 1007.625732, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	SetDynamicObjectMaterialText(tmpobjid, 0, "{FFD700}      2", 120, "Segoe Keycaps", 100, 1, 0x00000000, 0x00000000, 1);
	tmpobjid = CreateDynamicObject(19446, 1019.009460, 966.565002, 1005.285888, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 1028.608886, 966.565002, 1005.285888, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 1038.168212, 966.565002, 1005.285888, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 1047.717773, 966.565002, 1005.285888, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 1057.237915, 966.565002, 1005.285888, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 1057.237915, 971.454589, 1005.285888, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 1057.237915, 981.084472, 1005.285888, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 1057.237915, 990.724365, 1005.285888, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	tmpobjid = CreateDynamicObject(19446, 1057.237915, 1000.264221, 1005.285888, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 14789, "ab_sfgymmain", "gym_floor6", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObject(2942, 1000.710754, 966.873657, 1000.736083, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2942, 1003.500976, 966.873657, 1000.736083, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2942, 1006.140747, 966.873657, 1000.736083, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2942, 1008.570861, 966.873657, 1000.736083, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2942, 1011.410949, 966.873657, 1000.736083, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2942, 998.050781, 966.873657, 1000.736083, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1681, 1046.363647, 1015.042907, 998.615661, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1681, 1018.682739, 1015.042907, 998.615661, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1009.540222, 971.511291, 1008.995910, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1023.460449, 971.511291, 1008.995910, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1035.941406, 971.511291, 1008.995910, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1047.391235, 971.511291, 1008.995910, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1049.231567, 983.501525, 1008.995910, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1049.231567, 995.391601, 1008.995910, 0.000000, 0.000000, 360.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1039.182128, 976.043762, 1000.575866, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1043.361572, 976.043762, 1000.575866, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1047.521118, 976.043762, 1000.575866, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1035.060180, 976.043762, 1000.575866, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1030.930786, 976.043762, 1000.575866, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1026.770751, 976.043762, 1000.575866, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1022.600891, 976.043762, 1000.575866, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1009.039794, 983.631896, 1008.995910, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1021.460205, 983.631896, 1008.995910, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1034.430541, 983.631896, 1008.995910, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1034.430541, 1002.942077, 1008.995910, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1022.899841, 1002.942077, 1008.995910, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(18075, 1010.209838, 1002.942077, 1008.995910, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(638, 1011.812744, 982.865295, 1000.635864, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(638, 1011.812744, 985.465270, 1000.635864, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(638, 1006.252746, 982.865295, 1000.635864, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(638, 1006.252746, 985.465270, 1000.635864, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(638, 1010.252563, 986.625549, 1000.635864, 0.000007, 0.000015, 89.999946, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(638, 1007.652587, 986.625549, 1000.635864, 0.000007, 0.000015, 89.999946, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(638, 1010.252563, 981.395812, 1000.635864, 0.000015, 0.000015, 89.999923, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(638, 1007.652587, 981.395812, 1000.635864, 0.000015, 0.000015, 89.999923, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1020.582824, 999.519653, 1000.675781, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1020.582824, 1000.669494, 1000.675781, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1022.112731, 999.519653, 1000.675781, 0.000000, 0.000007, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1022.112731, 1000.669494, 1000.675781, 0.000000, -0.000007, 179.999954, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1023.572814, 999.519653, 1000.675781, 0.000000, 0.000015, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1023.572814, 1000.669494, 1000.675781, 0.000000, -0.000015, 179.999908, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1030.703369, 999.519653, 1000.675781, 0.000000, 0.000022, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1030.703369, 1000.669494, 1000.675781, 0.000000, -0.000022, 179.999862, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1032.254028, 999.519653, 1000.675781, 0.000000, 0.000030, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1032.254028, 1000.669494, 1000.675781, 0.000000, -0.000030, 179.999816, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1033.764038, 999.519653, 1000.675781, 0.000000, 0.000038, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1033.764038, 1000.669494, 1000.675781, 0.000000, -0.000038, 179.999771, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1038.894409, 999.519653, 1000.675781, 0.000000, 0.000045, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1038.894409, 1000.669494, 1000.675781, 0.000000, -0.000045, 179.999725, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1040.344604, 999.519653, 1000.675781, 0.000000, 0.000053, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1040.344604, 1000.669494, 1000.675781, 0.000000, -0.000053, 179.999679, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1041.803833, 999.519653, 1000.675781, 0.000000, 0.000061, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(2748, 1041.803833, 1000.669494, 1000.675781, 0.000000, -0.000061, 179.999633, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1049.561401, 978.093872, 1000.575866, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1049.561401, 982.213867, 1000.575866, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1049.561401, 986.393859, 1000.575866, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1049.561401, 990.553649, 1000.575866, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1049.561401, 994.723632, 1000.575866, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(970, 1049.561401, 998.863952, 1000.575866, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1775, 999.226501, 1003.813354, 1001.235534, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1775, 1002.236389, 1003.813354, 1001.235534, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 
	tmpobjid = CreateDynamicObject(1775, 996.756408, 1003.813354, 1001.235534, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00); 

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

forward OnCefInitialize(player_id, success);
public OnCefInitialize(player_id, success)
{
	if(success == 1) {
	}
	return;
}

public OnPlayerConnect(playerid)
{
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    cef_destroy_browser(playerid, CEF_HUD);
	KillTimer(TimerHUD[playerid]);
	KillTimer(TimerFomeSede[playerid]);
	return 1;
}

public OnPlayerSpawn(playerid)
{
	
	cef_create_browser(playerid, CEF_HUD, "https://danielteste1321.000webhostapp.com/index.html", false, false);
	/*
		cef_create_browser(player_id, browser_id, const url[], bool:hidden, bool:focused);
		hidden - Para esconder o navegador / focused - ativar o cursor do mouse
	*/
	TimerHUD[playerid] = SetTimerEx("UpdateHUD", 1000, true, "d", playerid); // 1 Segundo para atualizar o hud!
	TimerFomeSede[playerid] = SetTimerEx("UpdateFomeSede", 1000, true, "d", playerid); // 5 Segundos para atualizar a fome e sede! 
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid) {
	SetPVarInt(playerid, "isInVehicle", 0);
	SetPVarInt(playerid, "vehicleIdUser", 0);
	return 1;
}

public OnPlayerUpdate(playerid) {
	new carro = GetPlayerVehicleID(playerid);
	new mot, lu, alar, por, cap, porma, ob;
	GetVehicleParamsEx(carro, mot, lu, alar, por, cap, porma, ob);
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
		SetPVarInt(playerid, "isInVehicle", 1);
		SetPVarInt(playerid, "vehicleIdUser", carro);
	}
	if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 509 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 481 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 510){
		
	} else {
		if(DATA_VEHICLE[carro][VEHICLE_ON] == 1) {
			if(DATA_VEHICLE[carro][DATA_FUEL] <= 0.0)
			{
				DATA_VEHICLE[carro][VEHICLE_ON] = 0;
                SetVehicleParamsEx(carro, VEHICLE_PARAMS_OFF, VEHICLE_PARAMS_OFF, alar, por, cap, porma, ob);
				KillTimer(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][TIME_FUEL]);
			}
		}
	}
	return 1;
}

forward UpdateFomeSede(playerid);
public UpdateFomeSede(playerid)
{
	if(pInfo[playerid][fome] == 0.0 || pInfo[playerid][sede] == 0.0) {

	} else {
		pInfo[playerid][fome] -= 1.0;
		pInfo[playerid][sede] -= 1.0;
	}
	return 1;
}

forward UpdateHUD(playerid);
public UpdateHUD(playerid)
{
	new Float:vida, Float:colete;
	GetPlayerHealth(playerid, vida);
	GetPlayerArmour(playerid, colete);
	
	cef_emit_event(playerid, "Player:status", CEFFLOAT(vida), CEFFLOAT(colete), CEFFLOAT(pInfo[playerid][fome]), CEFFLOAT(pInfo[playerid][sede]), CEFINT(VelocidadeDoVeiculo(GetPVarInt(playerid, "vehicleIdUser"))), CEFINT(GetPVarInt(playerid, "isInVehicle")), CEFFLOAT(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][DATA_FUEL], CEFINT(DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][VEHICLE_ON])));
	//SCMf(playerid, -1, "VEHICLE-VELOCITY - %d , VEHICLE-STATUS - %d, VEHICLE-FUEL - %f", VelocidadeDoVeiculo(GetPVarInt(playerid, "vehicleIdUser")), GetPVarInt(playerid, "isInVehicle"), DATA_VEHICLE[GetPVarInt(playerid, "vehicleIdUser")][DATA_FUEL]);
	return 1;
}

//CMD:check_plugin(playerid) return SCMf(playerid, -1, "Plugin status: - %s", cef_player_has_plugin(playerid) ? ("{ffc600}Sucess") : ("{ff0000}Not sucess"));
stock VelocidadeDoVeiculo(vehicleid) {
	new Float:xPos[3];
	GetVehicleVelocity(vehicleid, xPos[0], xPos[1], xPos[2]);
	return floatround(floatsqroot(xPos[0] * xPos[0] + xPos[1] * xPos[1] + xPos[2] * xPos[2]) * 170.00);
}

stock S_PlayerType(playerid, const type[], bool:typeSet, Float:quantidade) {
	if(strcmp(type, "Sede") == 0) {
		if(typeSet == true) {
			pInfo[playerid][sede] += quantidade;
		} else {
			pInfo[playerid][sede] -= quantidade;
		}
	} else if(strcmp(type, "Colete") == 0) {
		if(typeSet == true) {
			SetPlayerArmour(playerid, quantidade);
		}
	}
	return 1;
}

stock S_Fome(playerid, Float:quantidade) {
	pInfo[playerid][fome] += quantidade;
	return 1;
}

CMD:tpcoords(playerid, const params[]) {
	new Float:cds[3];
	if(sscanf(params, "fff", cds[0], cds[1], cds[2])) SendClientMessage(playerid, 0xFF0000AA, "Usage: \"/tpcoords <x> <y> <z>\"");
	else 
	{
		SetPlayerPos(playerid, cds[0], cds[1], cds[2]);
	}
	return 1;
}