/*
** EPITECH PROJECT, 2018
** struct
** File description:
** struct
*/

#pragma once

typedef struct my_tower_s {
    int x_tower;
    int y_tower;

    int rayon;

    int nbr_of_plane;
    int nbr_of_tower;
} my_tower_t;

typedef struct my_plane_s {
    int frame;
    int nbr_line;
    int x_temp;
    int y_temp;

    int here;
    int plane;
    int x_plane;
    int y_plane;

    int x_dest_plane;
    int y_dest_plane;
    int vitesse_plane;
    int temp_plane;

    int x_tower;
    int y_tower;
    int coef;

    int x_dest_tower;
    int y_dest_tower;
    int vitesse_tower;
    int temp_tower;

    int nbr_of_plane;
    int nbr_of_tower;
} my_plane_t;

typedef struct me_s {
    int temp;
    int compteur;
    int who;
    int nbr_A;
    int nbr_T;
    int yo;
    int ya;
} me_t;