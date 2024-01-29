#include <a_samp>
#include <YSI-Includes\YSI_Coding\y_hooks>

Notificar(playerid, const title[100], const message[350])
{
    new form[450];
    format(form, sizeof(form), "[%s] %s", title, message);
    SendClientMessage(playerid, -1, form);
}