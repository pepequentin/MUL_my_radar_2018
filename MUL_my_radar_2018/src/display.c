/*
** EPITECH PROJECT, 2018
** display
** File description:
** display
*/

#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "../include/framebuffer.h"
#include <math.h>
#include "../include/my.h"
#include "../include/struct.h"

void mytower(sfRenderWindow *w, int i, my_tower_t **tower)
{
    sfTexture *map_tt = sfTexture_createFromFile("./asset/tower.png", NULL);
    sfSprite *map_s = sfSprite_create();
    sfVector2f centre = {tower[i]->x_tower, tower[i]->y_tower};
    sfSprite_setPosition(map_s, centre);
    sfSprite_setTexture(map_s, map_tt, sfTrue);
    sfRenderWindow_drawSprite(w, map_s, NULL);
    sfTexture_destroy(map_tt);
    sfSprite_destroy(map_s);
}

void plane_display(sfRenderWindow *w, my_plane_t **plane, int i)
{
    sfTexture *map_tt = sfTexture_createFromFile("./asset/plane.png", NULL);
    sfSprite *map_s = sfSprite_create();
    map_pos(plane, i);
    sfVector2f centre = {plane[i]->x_plane, plane[i]->y_plane};
    sfSprite_setPosition(map_s, centre);
    sfSprite_setTexture(map_s, map_tt, sfTrue);
    sfRenderWindow_drawSprite(w, map_s, NULL);
    sfTexture_destroy(map_tt);
    sfSprite_destroy(map_s);
}

void map_display(sfRenderWindow *w)
{
    sfTexture *map_tt = sfTexture_createFromFile("./asset/map.png", NULL);
    sfSprite *map_s = sfSprite_create();
    sfVector2f centre = {0, 0};
    sfSprite_setPosition(map_s, centre);
    sfSprite_setTexture(map_s, map_tt, sfTrue);
    sfRenderWindow_drawSprite(w, map_s, NULL);
    sfTexture_destroy(map_tt);
    sfSprite_destroy(map_s);
}
