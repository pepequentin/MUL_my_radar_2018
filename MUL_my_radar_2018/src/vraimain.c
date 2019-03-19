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
#include <math.h>
#include "../include/my.h"
#include "../include/struct.h"
#include <stdio.h>

void know(me_t *me, int ac, char **av)
{
    my_plane_t **plane = malloc(sizeof(my_plane_t *) * me->nbr_A + 1);
    for (int i = 0; i < me->nbr_A; i++)
        plane[i] = malloc(sizeof(my_plane_t) * 4);
    secondgetline(ac, av, me, plane);
}

int error(char *str, me_t *me, ssize_t read)
{
    int j = 0;

    if (read == 0)
        return (0);
    for (int i = 1; str[i] != '\0'; i++)
            if ((str[i] >= 'a' && str[i] <= 'z') || \
                (str[i] >= 'A' && str[i] <= 'Z'))
                return (0);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            j++;
    if (str[0] == 'A' && j == 10) {
        me->nbr_A++;
        return (1);
    }
    else if (str[0] == 'T' && j == 5) {
        me->nbr_T++;
        return (1);
    }
    else
        return (0);
}

int checkoss(int ac, char **av)
{
    if (ac != 2)
        return (0);
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == \
        'h' || av[1][2] == 'z') {
        option();
        return (0);
    }
    else
        return (1);
}

void init(me_t *me)
{
    me->nbr_A = 0;
    me->nbr_T = 0;
}

int test(char *line, size_t len, FILE *fp, ssize_t read)
{
    if (read = getline(&line, &len, fp) == 0)
        return (0);
}

int main(int ac, char **av)
{
    if (checkoss(ac, av) == 0)
        return (84);
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    me_t *me = malloc(sizeof(me_t));
    init(me);
    fp = fopen(av[1], "r");
    if (fp == NULL || ac != 2)
        return (0);
    while ((read = getline(&line, &len, fp)) != -1)
        if (error(line, me, read) == 0) {
            write(2, "map error\n", 11);
            return (0);
        }
    if (line)
        free(line);
    know(me, ac, av);
}
/*A  234 253  26 6  66  66
A  377 777  777 777  1  1
T  266 666  100*/