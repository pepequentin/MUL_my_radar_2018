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

void map_pos(my_plane_t **plane, int i)
{
    if (plane[i]->x_plane > 1920)
        plane[i]->x_plane = 0;
    if (plane[i]->x_plane < 0)
        plane[i]->x_plane = 1920;
    if (plane[i]->y_plane > 1080)
        plane[i]->y_plane = 0;
    if (plane[i]->y_plane < 0)
        plane[i]->y_plane = 1080;
}