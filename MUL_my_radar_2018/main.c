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
#include "./include/framebuffer.h"
#include <math.h>
#include "./include/my.h"
#include "./include/struct.h"
#include <stdio.h>

void timelife(my_plane_t **plane, int i)
{
    if (plane[i]->temp_plane != 0)
        plane[i]->temp_plane -= 1;
    else
        plane[i]->here = 1;
}

int step2(int argc, char **argv, my_plane_t **plane, me_t *me)
{
    plane[0]->frame = 10;
    if (argc != 2)
        return (84);
    else if ((argc == 2 && argv[1][0] == '-' && argv[1][1] == \
            'h' || argv[1][2] == 'z')) {
        option();
        return (84);
    }
    else
        return (0);
}

void check(char *line, me_t *me, my_plane_t **plane, my_tower_t **tower)
{
    if (line[0] == 'A') {
        sep(line, me, plane, tower);
        me->yo++;
    }
    else {
        newchar(line, me, tower);
        me->ya++;
    }
}

int secondgetline(int ac, char **av, me_t *me, my_plane_t **plane)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen(av[1], "r");
    if (fp == NULL)
        return (0);
    my_tower_t **tower = malloc(sizeof(my_tower_t *) * me->nbr_T + 1);
    for (int i = 0; i < me->nbr_A; i++)
        tower[i] = malloc(sizeof(my_tower_t) * 4);
    while ((read = getline(&line, &len, fp)) != -1)
        check(line, me, plane, tower);
    if (line)
        free(line);
    if (step2(ac, av, plane, me) == 84)
        return (84);
    my_window(plane, me, tower);
    return (0);
}
