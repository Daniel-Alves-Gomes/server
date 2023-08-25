#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

#define CEF_HUD3 (3)
#define SCMf SendClientMessagef

hook OnGameModeInit() {
    cef_subscribe("send:action:notificar", "Notificar");
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    SetPlayerPos(playerid, 1958.3783, 1343.1572, 15.3746);

    cef_create_browser(playerid, CEF_HUD3, "https://geradordesenhasdaniel.000webhostapp.com/index.html", false, false);
    return 1;
}

Notificar(playerid, const type[100], const title[100], const message[350], time)
{
    cef_emit_event(playerid, "send:action:notificar", CEFSTR(type), CEFSTR(title), CEFSTR(message), CEFINT(time));
}

/*cmd:teste(playerid)
{
    Notificar(playerid, "geral", "Titulo", "Mensagem aqui", 2000);
    Notificar(playerid, "info", "Titulo", "Mensagem aqui", 2000);
    Notificar(playerid, "sucesso", "Titulo", "Mensagem aqui", 2000);
    Notificar(playerid, "erro", "Titulo", "Mensagem aqui", 2000);
    Notificar(playerid, "aviso", "Titulo", "Mensagem aqui", 2000);
    Notificar(playerid, "sms", "Titulo", "Mensagem aqui", 2000);
    return 1;
}*/