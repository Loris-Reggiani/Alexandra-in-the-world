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

int check_event_volume(global_t *g)
{
    if (sfKeyboard_isKeyPressed(sfKeyAdd))
        if (g->music->volume < 100){
            g->music->volume += 2;
        }
    if (sfKeyboard_isKeyPressed(sfKeySubtract))
        if (g->music->volume > 0) {
            g->music->volume -= 2;
        }
    return 0;
}

int check_event(global_t *g)
{
    check_event_close(g);
    //check_event_volume(g);
    return 0;
}