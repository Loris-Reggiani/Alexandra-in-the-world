/*
** EPITECH PROJECT, 2020
** Jam
** File description:
** window.cpp
*/

#include "../include/include.h"

int alex_move(global_t *g)
{
    g->alex.pos.x += (g->alex.pos.x < g->clic_pos.x) ? 3: 0;
    g->alex.pos.y += (g->alex.pos.y < g->clic_pos.y) ? 3: 0;
    g->alex.pos.x -= (g->alex.pos.x > g->clic_pos.x) ? 3: 0;
    g->alex.pos.y -= (g->alex.pos.y > g->clic_pos.y) ? 3: 0;
    sfSprite_setPosition(g->alex.sprite, g->alex.pos);
    return 0;
}

int contibox(global_t *g)
{
    if (g->bloc[AMER_ND].quiz == 0 && g->alex.pos.x > 50 && g->alex.pos.y > 50 && g->alex.pos.x < 685 && g->alex.pos.y < 452) {
        g->bloc[AMER_ND].pos.x = 850;
        g->bloc[AMER_ND].pos.y = 500;
    } else {
        g->bloc[AMER_ND].pos.x = -1000;
        g->bloc[AMER_ND].pos.y = -1000;
    }
    if (g->bloc[AMER_SD].quiz == 0 && g->alex.pos.x > 513 && g->alex.pos.y > 483 && g->alex.pos.x < 800 && g->alex.pos.y < 866) {
        g->bloc[AMER_SD].pos.x = 850;
        g->bloc[AMER_SD].pos.y = 550;
    } else {
        g->bloc[AMER_SD].pos.x = -1000;
        g->bloc[AMER_SD].pos.y = -1000;
    }
    if (g->bloc[AFR].quiz == 0 && g->alex.pos.x > 855 && g->alex.pos.y > 351 && g->alex.pos.x < 1250 && g->alex.pos.y < 727) {
        g->bloc[AFR].pos.x = 50;
        g->bloc[AFR].pos.y = 500;
    } else {
        g->bloc[AFR].pos.x = -1000;
        g->bloc[AFR].pos.y = -1000;
    }
    if (g->bloc[EURO].quiz == 0 && g->alex.pos.x > 832 && g->alex.pos.y > 123 && g->alex.pos.x < 1241 && g->alex.pos.y < 333) {
        g->bloc[EURO].pos.x = 50;
        g->bloc[EURO].pos.y = 450;
    } else {
        g->bloc[EURO].pos.x = -1000;
        g->bloc[EURO].pos.y = -1000;
    }
    if (g->bloc[ASIE].quiz == 0 && g->alex.pos.x > 1251 && g->alex.pos.y > 91 && g->alex.pos.x < 1904 && g->alex.pos.y < 500) {
        g->bloc[ASIE].pos.x = 700;
        g->bloc[ASIE].pos.y = 400;
    } else {
        g->bloc[ASIE].pos.x = -1000;
        g->bloc[ASIE].pos.y = -1000;
    }
    if (g->bloc[OCEA].quiz == 0 && g->alex.pos.x > 1507 && g->alex.pos.y > 558 && g->alex.pos.x < 1909 && g->alex.pos.y < 798) {
        g->bloc[OCEA].pos.x = 700;
        g->bloc[OCEA].pos.y = 450;
    } else {
        g->bloc[OCEA].pos.x = -1000;
        g->bloc[OCEA].pos.y = -1000;
    }
    for (int i = AMER_ND; i <= OCEA; i += 1) {
        sfSprite_setPosition(g->bloc[i].sprite, g->bloc[i].pos);
        if (g->bloc[i].pos.x != -1000 && g->bloc[i].pos.y != -1000) {
            if (g->music[i].m == 0) {
                g->music[i].m = 1;
                sfMusic_play(g->music[i].music);
            }
        } else {
            g->music[i].m = 0;
            sfMusic_pause(g->music[i].music);
        }
    }
    return 0;
}

int changes(global_t *g)
{
    for (int i = AMER_ND; i <= OCEA; i += 1) {
        if (i < OCEA && g->music[i].m == 1)
            break;
        if (i == OCEA && g->music[i].m == 0)
            alex_move(g);
    }
    contibox(g);
    return 0;
}

int main(void)
{
    global_t *g = malloc(sizeof(global_t));
    g->exit = 0;

    init(g);
    sfRenderWindow_setMouseCursorVisible(g->window, FALSE);
    while (sfRenderWindow_isOpen(g->window)) {
        while (sfRenderWindow_pollEvent(g->window, &g->event)) {
            check_event(g);
        }
        changes(g);
        draw_sprite(g);
        sfRenderWindow_display(g->window);
        sfRenderWindow_clear(g->window, sfWhite);
        for(int i = AMER_ND; i <= OCEA; i += 1) {
            if (g->bloc[i].quiz == 0)
                break;
            if (i == OCEA &&  g->bloc[i].quiz == 1)
                g->exit = 1;
        }
        if (g->exit == 1) {
            printf("\n\n\n\n\n\n\n\n");
            printf("█   █  █████  █   █    █   █ █████ █   █\n");
            printf("██ ██  █   █  █   █    █   █   █   ██  █\n");
            printf(" ███   █   █  █   █    █ █ █   █   █ █ █\n");
            printf("  █    █   █  █   █    █ █ █   █   █  ██\n");
            printf("  █    █████  █████     █ █  █████ █   █\n");
            printf("\n");
            break;
        }
        if (g->exit == 2) {
            printf("\n\n\n\n\n\n\n\n");
            printf("█   █  █████  █   █    █      █████  █████ █████\n");
            printf("██ ██  █   █  █   █    █      █   █  █     █    \n");
            printf(" ███   █   █  █   █    █      █   █  █████ ████ \n");
            printf("  █    █   █  █   █    █      █   █      █ █    \n");
            printf("  █    █████  █████    ██████ █████  █████ █████\n");
            printf("\n");
            break;
        }
    }
    free_all(g);
    return 0;
}