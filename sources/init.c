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
    g->alex.pos.x = 900;
    g->alex.pos.y = 950;
    sfSprite_setScale(g->alex.sprite, g->alex.scale);
    sfSprite_setPosition(g->alex.sprite, g->alex.pos);
    sfSprite_setOrigin(g->alex.sprite, origin);
    return 0;
}

int continent_sprite(global_t *g)
{
    g->bloc[AMER_ND].texture = sfTexture_createFromFile("image/amerique_du_nord.png", NULL);
    g->bloc[AMER_SD].texture = sfTexture_createFromFile("image/amerique_du_sud.png", NULL);
    g->bloc[EURO].texture = sfTexture_createFromFile("image/europe.png", NULL);
    g->bloc[AFR].texture = sfTexture_createFromFile("image/afrique.png", NULL);
    g->bloc[ASIE].texture = sfTexture_createFromFile("image/asie.png", NULL);
    g->bloc[OCEA].texture = sfTexture_createFromFile("image/oceanie.png", NULL);
    for (int i = AMER_ND; i <= OCEA; i += 1) {
        g->bloc[i].sprite = sfSprite_create();
        g->bloc[i].scale.x = 1;
        g->bloc[i].scale.y = 1;
        g->bloc[i].pos.x = -1000;
        g->bloc[i].pos.y = -1000;
        sfSprite_setTexture(g->bloc[i].sprite, g->bloc[i].texture, TRUE);
        sfSprite_setScale(g->bloc[i].sprite, g->bloc[i].scale);
        sfSprite_setPosition(g->bloc[i].sprite, g->bloc[i].pos);
        g->bloc[i].quiz = 0;
    }
    return 0;
}

int continent_music(global_t *g)
{
    g->music[AMER_ND].music = sfMusic_createFromFile("music/NA.OGG");
    g->music[AMER_SD].music = sfMusic_createFromFile("music/NS.OGG");
    g->music[EURO].music = sfMusic_createFromFile("music/EU.OGG");
    g->music[AFR].music = sfMusic_createFromFile("music/AFR.OGG");
    g->music[ASIE].music = sfMusic_createFromFile("music/AS.OGG");
    g->music[OCEA].music = sfMusic_createFromFile("music/OC.OGG");
    

    sfMusic_setPlayingOffset(g->music[AMER_ND].music, sfSeconds(3.5));
    sfMusic_setPlayingOffset(g->music[AMER_SD].music, sfSeconds(3.5));
    sfMusic_setPlayingOffset(g->music[EURO].music, sfSeconds(7));
    sfMusic_setPlayingOffset(g->music[AFR].music, sfSeconds(23));
    sfMusic_setPlayingOffset(g->music[ASIE].music, sfSeconds(17));

    for (int i = AMER_ND; i <= OCEA; i += 1) {
        sfMusic_setLoop(g->music[i].music, TRUE);
        g->music[i].volume = 50;
        sfMusic_setVolume(g->music[i].music, g->music[i].volume);
    }
    return 0;
}

int init(global_t *g)
{
    g->clic_pos.x = 900;
    g->clic_pos.y = 950;
    g->window = create_Window();
    sfRenderWindow_setFramerateLimit(g->window, 60);
    g->bloc = malloc(sizeof(objet_t) * 6);
    g->music = malloc(sizeof(objet_t) * 6);
    map_sprite(g);
    alex_sprite(g);
    continent_sprite(g);
    continent_music(g);
    return 0;
}