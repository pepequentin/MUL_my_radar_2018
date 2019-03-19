/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdio.h>
#include "../include/struct.h"
#include "../include/my.h"

void whoplane(me_t *me, int n, my_plane_t **plane)
{
    if (me->compteur == 0 && me->who == 1)
        plane[me->yo]->x_plane = n;
    if (me->compteur == 1 && me->who == 1)
        plane[me->yo]->y_plane = n;
    if (me->compteur == 2 && me->who == 1)
        plane[me->yo]->x_dest_plane = n;
    if (me->compteur == 3 && me->who == 1)
        plane[me->yo]->y_dest_plane = n;
    if (me->compteur == 4 && me->who == 1)
        plane[me->yo]->vitesse_plane = n;
    if (me->compteur == 5 && me->who == 1)
        plane[me->yo]->temp_plane = n * 10;
}

int my_getnbr(char *str, me_t *me, my_plane_t **plane)
{
    int i = 0;
    int n = 0;

    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0') {
        if ((str[i] < '0' || str[i] > '9'))
            return (0);
        n = n + str[i] - 48;
        n = n * 10;
        i++;
    }
    n /= 10;
    if (str[0] == '-') {
        whoplane(me, -n, plane);
        me->compteur++;
    }
    else {
        whoplane(me, n, plane);
        me->compteur++;
    }
}

void str_to_word_array(char *str, me_t *me, my_plane_t **plane)
{
    char *pos = malloc(my_strlen(str));
    int i = 0;

    for (int j = 0; str[i] != '\0'; i++, j++) {
        if (str[i] == ' ' || str[i + 1] == '\0') {
            my_getnbr(pos, me, plane);
            cleanstr(pos);
            j = -1;
        }
        else
            pos[j] = str[i];
    }
}

void sep(char *str, me_t *me, my_plane_t **plane, my_tower_t **tower)
{
    char *arr = malloc(my_strlen(str));
    int i = 3;
    me->compteur = 0;

    if (str[0] == 'A') {
        me->who = 1;
        plane[0]->nbr_of_plane++;
    }
    else {
        me->who = 0;
        plane[0]->nbr_of_tower++;
    }
    for (int j = 0; str[i] != '\0'; i++, j++) {
        if (str[i] == ' ' && str[i + 1] == ' ')
            j--;
        else
            arr[j] = str[i];
    }
    str_to_word_array(arr, me, plane);
}
