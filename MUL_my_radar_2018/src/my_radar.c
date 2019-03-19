/*
** EPITECH PROJECT, 2018
** allscreensaver
** File description:
** screen
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "../include/framebuffer.h"
#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>

void dead(my_plane_t **plane, int i)
{
    if (plane[i]->y_dest_plane < plane[i]->y_plane)
        plane[i]->y_plane -= 1;
    else if (plane[i]->y_dest_plane > plane[i]->y_plane)
        plane[i]->y_plane += 1;
    else {
    }
}

void move(my_plane_t **plane, int i, me_t *me)
{
    float x;
    float y;

    if (me->temp == 0) {
        plane[i]->x_temp = plane[i]->x_plane;
        plane[i]->y_temp = plane[i]->y_plane;
    }
    x = plane[i]->y_dest_plane - plane[i]->y_temp;
    y = plane[i]->x_dest_plane - plane[i]->x_temp;
    if (plane[i]->x_dest_plane < plane[i]->x_plane) {
        plane[i]->x_plane -= 1;
        dead(plane, i);
    }
    else if (plane[i]->x_dest_plane > plane[i]->x_plane) {
        plane[i]->x_plane += 1;
        dead(plane, i);
    }
    else
        timelife(plane, i);
}

void alldisplay(sfRenderWindow *w, my_plane_t **p, me_t *me, my_tower_t **tower)
{
    map_display(w);
    int dead = 0;
    for (int i = 0; i != me->nbr_A; i++)
        if (p[i]->here != 1)
            plane_display(w, p, i);
    for (int i = 0; i != me->nbr_A; i++)
        bet(w, p, i, tower);
    for (int i = 0; i != me->nbr_A; i++)
        if (p[i]->here != 1)
            move(p, i, me);
    tower[0]->nbr_of_tower = me->nbr_T;
    for (int i = 0; i != me->nbr_T; i++)
        mytower(w, i, tower);
    for (int i = 0; i != me->nbr_A; i++)
        if (p[i]->here == 0)
            dead++;
    if (dead == 0) {
        write(2, "all planes are destroyed\n", 26);
        sfRenderWindow_close(w);
    }
    me->temp++;
}

void framelimite(sfRenderWindow *w, my_plane_t **plane, sfEvent event)
{

    while (sfRenderWindow_pollEvent(w, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
            plane[0]->frame++;
            sfRenderWindow_setFramerateLimit(w, plane[0]->frame);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
            plane[0]->frame--;
            sfRenderWindow_setFramerateLimit(w, plane[0]->frame);
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w);
    }
}

int my_window(my_plane_t **plane, me_t *me, my_tower_t **tower)
{
    sfEvent event;
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, "toi", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, plane[0]->frame);
    me->temp = 0;
    while (sfRenderWindow_isOpen(window)) {
        alldisplay(window, plane, me, tower);
        framelimite(window, plane, event);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (EXIT_SUCCESS);
}
