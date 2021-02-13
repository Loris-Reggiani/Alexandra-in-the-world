/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** init.c
*/

#include "../include/include.h"

sfRenderWindow *create_Window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};

    window = sfRenderWindow_create(video_mode,
    "Alexandra_in_the_world", sfDefaultStyle, NULL);
    return window;
}

int map_sprite(global_t *g)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile("image/Map.jpg", NULL);
    g->map.sprite = sfSprite_create();
    sfSprite_setTexture(g->map.sprite, texture, TRUE);
    g->map.scale.x = 0.387;
    g->map.scale.y = 0.38;
    sfSprite_setScale(g->map.sprite, g->map.scale);
    return 0;
}

int alex_sprite(global_t *g)
{
    sfTexture *texture;

    texture = sfTexture_createFromFile("image/Alexandra.png", NULL);
    g->alex.sprite = sfSprite_create();
    sfSprite_setTexture(g->alex.sprite, texture, TRUE);
    g->alex.scale.x = 1;
    g->alex.scale.y = 1;
    g->alex.pos.x = 1;
    g->alex.pos.y = 1;
    sfSprite_setScale(g->alex.sprite, g->map.scale);
    return 0;
}

int init(global_t *g)
{
    g->window = create_Window();
    sfRenderWindow_setFramerateLimit(g->window, 144);
    map_sprite(g);
    g->bloc = malloc(sizeof(objet_t) * 7);
    alex_sprite(g);
    return 0;
}