/*
** EPITECH PROJECT, 2020
** Jam
** File description:
** include.hpp
*/

#ifndef H_W
#define H_W

// include

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>

#include <stddef.h>
#include <stdlib.h>

#include <unistd.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <time.h>

//define 

#define TRUE 0
#define FALSE 1

// structure

typedef enum 
{
    AMER_ND, AMER_SD, EUROPE, AFR, ASIE, OCEANIE
}continents;

typedef struct
{
    sfMusic *music;
    float volume;
}music_t;

typedef struct
{
    sfIntRect IntRect;
    int offset;
    int offset_;
    int max;
    int max_;
}my_rect;

typedef struct
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    my_rect rect;
}objet_t;

typedef struct
{
    sfRenderWindow *window;
    sfEvent event;
    sfKeyEvent key;

    music_t *music;
    objet_t map;
    objet_t alex;
    objet_t *bloc;

    sfVector2i clic_pos;
}global_t;

// fonction

int init(global_t *map);

int check_event(global_t *g);
int check_event_mouse(global_t *g);

int free_all(global_t *g);

#endif