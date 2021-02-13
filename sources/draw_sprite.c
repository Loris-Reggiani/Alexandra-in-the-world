/*
** EPITECH PROJECT, 2020
** Alexandra-in-the-world
** File description:
** draw_sprite.c
*/

#include "../include/include.h"

int draw_sprite(global_t *g)
{
    sfRenderWindow_drawSprite(g->window, g->map.sprite, NULL);
    sfRenderWindow_drawSprite(g->window, g->alex.sprite, NULL);
    for (int i = AMER_ND; i <= OCEA; i += 1)
        sfRenderWindow_drawSprite(g->window, g->bloc[i].sprite, NULL);
    return 0;
}