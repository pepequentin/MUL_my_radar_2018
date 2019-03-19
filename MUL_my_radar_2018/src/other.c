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

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}

void option(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_radar map.txt\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" FpsStart = 10\n");
    my_putstr(" press Upkey = fps + 1\n");
    my_putstr(" press Downkey = fps - 1\n");
}

char *cleanstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = '\0';
    return (str);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}