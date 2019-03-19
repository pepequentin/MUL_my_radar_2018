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

void tower_check(my_plane_t **plane, int i, my_tower_t **tower, int j)
{
    int temp = 0;

    for (int o = 0; o != tower[0]->nbr_of_tower; o++) {
        if (tower[o]->x_tower - tower[o]->rayon < plane[i]->x_plane &&
            tower[o]->x_tower + tower[o]->rayon > plane[i]->x_plane &&
            tower[o]->y_tower - tower[o]->rayon < plane[i]->y_plane &&
            tower[o]->y_tower + tower[o]->rayon > plane[i]->y_plane)
            temp++;
    }
    if (temp == 0) {
        plane[i]->here = 1;
        plane[j]->here = 1;
    }
}

void bet(sfRenderWindow *w, my_plane_t **plane, int i, my_tower_t **t)
{
    for (int j = 0; j < plane[0]->nbr_of_plane; j++) {
        if (j == i)
            j++;
        else if (plane[j]->x_plane - 10 < plane[i]->x_plane &&
                plane[i]->x_plane < plane[j]->x_plane + 10 &&
                plane[j]->y_plane - 10 < plane[i]->y_plane &&
                plane[i]->y_plane < plane[j]->y_plane + 10)
            tower_check(plane, i, t, j);
        else
        {
        }
    }
}