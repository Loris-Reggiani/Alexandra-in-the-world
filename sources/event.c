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
    if (g->event.type == sfEvtMouseButtonPressed)
        g->clic_pos = sfMouse_getPositionRenderWindow(g->window);
    return 0;
}

int quizz(global_t *g)
{
    sfVector2i vec;
    if (g->bloc[AMER_ND].pos.x != -1000 && g->bloc[AMER_ND].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 1126 && vec.y > 1014 && vec.x < 1442 &&  vec.y < 1048)
                g->bloc[AMER_ND].quiz = 1;
            if (vec.x > 854  && vec.y > 1018 && vec.x < 1116 &&  vec.y < 1052)
                g->exit = 2;
            if (vec.x > 1442 && vec.y > 1014 && vec.x < 1724 &&  vec.y < 1047)
                g->exit = 2;
        }
    }
    if (g->bloc[AMER_SD].pos.x != -1000 && g->bloc[AMER_SD].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 1489 && vec.y > 992 && vec.x < 1723 &&  vec.y < 1027)
                g->bloc[AMER_SD].quiz = 1;
            if (vec.x > 850 && vec.y > 988 && vec.x < 1490 &&  vec.y < 1026)
                g->exit = 2;
        }
    }
    if (g->bloc[AFR].pos.x != -1000 && g->bloc[AFR].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 52 && vec.y > 973 && vec.x < 332 &&  vec.y < 1033)
                g->bloc[AFR].quiz = 1;
            if (vec.x > 358 && vec.y > 978 && vec.x < 925 &&  vec.y < 1028)
                g->exit = 2;
        }
    }
    if (g->bloc[EURO].pos.x != -1000 && g->bloc[EURO].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 90 && vec.y > 976 && vec.x < 276 &&  vec.y < 1041)
                g->bloc[EURO].quiz = 1;
            if (vec.x > 276 && vec.y > 975 && vec.x < 667 &&  vec.y < 1051)
                g->exit = 2;
        }
    }
    if (g->bloc[ASIE].pos.x != -1000 && g->bloc[ASIE].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 699 && vec.y > 987 && vec.x < 1069 && vec.y < 1036)
                g->bloc[ASIE].quiz = 1;
            if (vec.x > 1068 && vec.y > 983 && vec.x < 1572 && vec.y < 1032)
                g->exit = 2;
        }
    }
    if (g->bloc[OCEA].pos.x != -1000 && g->bloc[OCEA].pos.y != -1000) {
        if (g->event.type == sfEvtMouseButtonPressed) {
            vec = sfMouse_getPositionRenderWindow(g->window);
            if (vec.x > 1023 && vec.y > 994 && vec.x < 1263 && vec.y < 1040)
                g->bloc[OCEA].quiz = 1;
            if (vec.x > 701 && vec.y > 1003 && vec.x < 1017 && vec.y < 1043)
                g->exit = 2;
            if (vec.x > 1264 && vec.y > 995 && vec.x < 1572 && vec.y < 1043)
                g->exit = 2;
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