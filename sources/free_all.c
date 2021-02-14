/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** free_all.c
*/

#include "../include/include.h"

int free_all(global_t *g)
{
    sfRenderWindow_destroy(g->window);
    sfSprite_destroy(g->alex.sprite);
    sfSprite_destroy(g->map.sprite);
    sfTexture_destroy(g->alex.texture);
    sfTexture_destroy(g->map.texture);
    for(int i = AMER_ND; i <= OCEA; i += 1) {
        sfTexture_destroy(g->bloc[i].texture);
        sfSprite_destroy(g->bloc[i].sprite);
        sfMusic_destroy(g->music[i].music);
    }
    free(g->bloc);
    free(g->music);
    free(g);
    return 0;
}