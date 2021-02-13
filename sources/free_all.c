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
    free(g);
    return 0;
}