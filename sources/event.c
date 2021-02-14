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

int quizz(global_t *g)
{
    sfVector2i vec;
    if (g->bloc[AMER_ND].pos.x != -1000 && g->bloc[AMER_ND].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 50 && vec.y > 50 && vec.x < 685 &&  vec.y < 452)
                g->bloc[AMER_ND].quiz = 1;
        }
    }
    if (g->bloc[AMER_SD].pos.x != -1000 && g->bloc[AMER_SD].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 513 && vec.y > 483 && vec.x < 800 &&  vec.y < 866)
                g->bloc[AMER_SD].quiz = 1;
        }
    }
    if (g->bloc[AFR].pos.x != -1000 && g->bloc[AFR].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 855 && vec.y > 351 && vec.x < 1292 &&  vec.y < 727)
                g->bloc[AFR].quiz = 1;
        }
    }
    if (g->bloc[EURO].pos.x != -1000 && g->bloc[EURO].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 832 && vec.y > 123 && vec.x < 1241 &&  vec.y < 333)
                g->bloc[EURO].quiz = 1;
        }
    }
    if (g->bloc[ASIE].pos.x != -1000 && g->bloc[ASIE].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 1251 && vec.y > 91 && vec.x < 1904 && vec.y < 500)
                g->bloc[ASIE].quiz = 1;
        }
    }
    if (g->bloc[OCEA].pos.x != -1000 && g->bloc[OCEA].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 1507 && vec.y > 558 && vec.x < 1909 && vec.y < 798)
                g->bloc[OCEA].quiz = 1;
        }
    }
    return 0;
}

int check_event(global_t *g)
{
    check_event_close(g);
    check_event_mouse(g);
    quizz(g);
    return 0;
}