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
#include "../include/framebuffer.h"
#include <math.h>
#include "../include/my.h"
#include "../include/struct.h"

void whotower(me_t *me, int n, my_tower_t **tower)
{
    if (me->compteur == 0)
        tower[me->ya]->x_tower = n;
    if (me->compteur == 1)
        tower[me->ya]->y_tower = n;
    if (me->compteur == 2)
        tower[me->ya]->rayon = n;
}

int my_getnbre(char *str, me_t *me, my_tower_t **tower)
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
        whotower(me, -n, tower);
        me->compteur++;
    }
    else {
        whotower(me, n, tower);
        me->compteur++;
    }
}

void str_to_word(char *str, me_t *me, my_tower_t **tower)
{
    char *pos = malloc(my_strlen(str));
    int i = 0;

    for (int j = 0; str[i] != '\0'; i++, j++) {
        if (str[i] == ' ' || str[i + 1] == '\0') {
            my_getnbre(pos, me, tower);
            cleanstr(pos);
            j = -1;
        }
        else
            pos[j] = str[i];
    }
}

void newchar(char *str, me_t *me, my_tower_t **tower)
{
    char *arr = malloc(my_strlen(str));
    int i = 3;
    me->compteur = 0;

    for (int j = 0; str[i] != '\0'; i++, j++) {
        if (str[i] == ' ' && str[i + 1] == ' ')
            j--;
        else
            arr[j] = str[i];
    }
    str_to_word(arr, me, tower);
}