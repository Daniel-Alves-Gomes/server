#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>


Notificar(playerid, const type[100], const title[100], const message[350], time)
{
    new format[450];
    format(format, sizeof(format), "[%s] %s", );
    SendClientMessage(playerid, -1, );
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