/*
** EPITECH PROJECT, 2020
** Jam
** File description:
** window.cpp
*/

#include "../include/include.h"


int changes(global_t *g)
{
    g->alex.pos.x += (g->alex.pos.x < g->clic_pos.x) ? 3: 0;
    g->alex.pos.y += (g->alex.pos.y < g->clic_pos.y) ? 3: 0;
    g->alex.pos.x -= (g->alex.pos.x > g->clic_pos.x) ? 3: 0;
    g->alex.pos.y -= (g->alex.pos.y > g->clic_pos.y) ? 3: 0;
    sfSprite_setPosition(g->alex.sprite, g->alex.pos);
    return 0;
}

int main(void)
{
    global_t *g = malloc(sizeof(global_t));

    init(g);
    while (sfRenderWindow_isOpen(g->window)) {
        while (sfRenderWindow_pollEvent(g->window, &g->event)) {
            check_event(g);
        }
        changes(g);
        sfRenderWindow_drawSprite(g->window, g->map.sprite, NULL);
        sfRenderWindow_drawSprite(g->window, g->alex.sprite, NULL);

        for (int i = AMER_ND; i <= OCEANIE; i += 1)
            sfRenderWindow_drawSprite(g->window, g->bloc[i].sprite, NULL);
        sfRenderWindow_display(g->window);
        sfRenderWindow_clear(g->window, sfWhite);
    }
    free_all(g);
    return 0;
}