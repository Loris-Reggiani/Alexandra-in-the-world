/*
** EPITECH PROJECT, 2020
** Jam
** File description:
** window.cpp
*/

#include "../include/include.h"

int main(void)
{
    global_t *g = malloc(sizeof(global_t));

    init(g);
    while (sfRenderWindow_isOpen(g->window)) {
        while (sfRenderWindow_pollEvent(g->window, &g->event))
            check_event(g);
        //changes(g);
        //draw_image(g, g->window);
        sfRenderWindow_drawSprite(g->window, g->map.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->alex.sprite, NULL);
        sfRenderWindow_display(g->window);
        sfRenderWindow_clear(g->window, sfWhite);
    }
    free_all(g);
    return 0;
}