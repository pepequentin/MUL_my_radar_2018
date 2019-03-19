/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** all the functions
*/

#include <stdarg.h>
#include "struct.h"

void option(void);
int my_window(my_plane_t **plane, me_t *me, my_tower_t **tower);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char *str);
char *cleanstr(char *str);
int step2(int argc, char **argv, my_plane_t **plane, me_t *me);
void *malloc(size_t size);
void map_display(sfRenderWindow *w);
void plane_display(sfRenderWindow *w, my_plane_t **plane, int i);
void alltower(sfRenderWindow *w, my_plane_t **plane);
void mytower(sfRenderWindow *w, int i, my_tower_t **tower);
void map_pos(my_plane_t **plane, int i);
void sep(char *str, me_t *me, my_plane_t **plane, my_tower_t **tower);
int secondgetline(int ac, char **av, me_t *me, my_plane_t **plane);
void free(void *ptr);
void bet(sfRenderWindow *w, my_plane_t **plane, int i, my_tower_t **t);
void newchar(char *str, me_t *me, my_tower_t **tower);
void timelife(my_plane_t **plane, int i);