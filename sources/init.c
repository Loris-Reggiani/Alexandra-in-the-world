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
    g->alex.texture = sfTexture_createFromFile("image/Alexandra.png", NULL);
    sfVector2f origin = {193, 255};
    g->alex.sprite = sfSprite_create();
    sfSprite_setTexture(g->alex.sprite, g->alex.texture, TRUE);
    g->alex.scale.x = 0.20;
    g->alex.scale.y = 0.20;
    g->alex.pos.x = 950;
    g->alex.pos.y = 200;
    sfSprite_setScale(g->alex.sprite, g->alex.scale);
    sfSprite_setPosition(g->alex.sprite, g->alex.pos);
    sfSprite_setOrigin(g->alex.sprite, origin);
    return 0;
}

int continent_sprite(global_t *g)
{
    for (int i = AMER_ND; i <= OCEANIE; i += 1) {
        g->bloc[i].texture = sfTexture_createFromFile("image/babouche.png", NULL);
        g->bloc[i].sprite = sfSprite_create();
        g->bloc[i].scale.x = 0.25;
        g->bloc[i].scale.y = 0.25;
        g->bloc[i].pos.x = -400;
        g->bloc[i].pos.y = -400;
        sfSprite_setTexture(g->bloc[i].sprite, g->bloc[i].texture, TRUE);
        sfSprite_setScale(g->bloc[i].sprite, g->bloc[i].scale);
        sfSprite_setPosition(g->bloc[i].sprite, g->bloc[i].pos);
    }
    return 0;
}

int init(global_t *g)
{
    g->clic_pos.x = 950;
    g->clic_pos.y = 200;
    g->window = create_Window();
    sfRenderWindow_setFramerateLimit(g->window, 60);
    g->bloc = malloc(sizeof(objet_t) * 7);
    g->bloc = malloc(sizeof(objet_t) * 7);
    map_sprite(g);
    alex_sprite(g);
    continent_sprite(g);
    return 0;
}