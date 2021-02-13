/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** event.c
*/

#include "../include/include.h"

int check_event_close(global_t *g)
{
    if (g->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(g->window);
    return 0;
}

int check_event_mouse(global_t *g)
{
    if (g->event.type == sfEvtMouseButtonPressed) {
        g->clic_pos = sfMouse_getPositionRenderWindow(g->window);
        printf("%i, %i\n", g->clic_pos.x, g->clic_pos.y);
    }
    return 0;
}

int check_event(global_t *g)
{
    check_event_close(g);
    check_event_mouse(g);
    return 0;
}