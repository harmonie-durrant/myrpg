/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** parse_layers
*/

#include <stdio.h>
#include "map_parser.h"

int parse_interior_feature_layer(c_tile_map_t *tilemap, char *str)
{
    sprite_char_t sprite_chars[] = {
        {'B', BARIL, {2, 2}},       {'b', BARIL_WATER, {2, 2}},
        {'p', BARIL_APPLE, {2, 2}}, {'w', WHEAT_F, {2, 3}},
        {'W', WHEAT, {2, 2}},       {'1', DIRT_A, {1, 1}},
        {'2', DIRT_B, {1, 1}},      {'3', DIRT_C, {1, 1}},
        {'C', SEED_A, {1, 1}},      {'s', SEED_B, {1, 1}},
        {'c', SEED_C, {1, 1}},      {'r', SEED_D, {1, 1}},
        {'S', SEED_E, {1, 1}},      {'*', SEED_F, {1, 1}},
        {'f', SEED_G, {1, 1}},      {'F', SEED_H, {1, 1}},
        {'P', SEED_I, {1, 1}},      {'L', LARGE_BED, {2, 2}},
        {'T', TABLE, {3, 2}},       {'E', SETUP, {2, 3}},
        {'G', WINDOW, {1, 1}},      {'x', LAMP, {1, 1}},
        {'n', NIGHTSTAND, {1, 2}},  {'a', FRAME_A, {1, 1}},
        {'l', FRAME_B, {1, 1}},     {'A', APPLE_BASKET, {1, 1}},
        {'R', CARPET, {2, 2}},      {'I', LIBRARY_C, {2, 2}},
        {'V', TV, {1, 2}},          {'O', SOFA, {1, 3}},
        {'t', TOILLET, {1, 2}},
    };

    return parse_tiles(tilemap, str, sprite_chars);
}

int parse_interior_layer(c_tile_map_t *tilemap, char *str)
{
    sprite_char_t sprite_chars[] = {
        {'F', FLOOR, {1, 1}},           {'l', SKIRT_LEFT, {1, 1}},
        {'r', SKIRT_RIGHT, {1, 1}},     {'L', CORNER_LEFT, {1, 1}},
        {'R', CORNER_RIGHT, {1, 1}},    {'[', WALL_LEFT, {1, 1}},
        {']', WALL_RIGHT, {1, 1}},      {'/', WALL_TOP_LEFT, {1, 1}},
        {'-', WALL_TOP_CENTER, {1, 1}}, {'\\', WALL_TOP_RIGHT, {1, 1}},
        {'(', SK_C_DOWN_LEFT, {1, 1}},  {')', SK_C_DOWN_RIGHT, {1, 1}},
        {'+', C_D_DOWN_LEFT, {1, 1}},   {'*', C_D_DOWN_RIGHT, {1, 1}},
        {'_', WALL_FLAT, {1, 1}},       {'=', T_WALL_CENTER, {1, 1}},
        {'?', T_WALL_RIGHT, {1, 1}},    {'!', T_WALL_LEFT, {1, 1}},
    };

    return parse_tiles(tilemap, str, sprite_chars);
}

int parse_feature_layer(c_tile_map_t *tilemap, char *str)
{
    sprite_char_t sprite_chars[] = {
        {'H', HOUSE, {6, 6}},       {'B', BARIL, {2, 2}},
        {'K', KENNEL, {3, 3}},      {'b', BARIL_WATER, {2, 2}},
        {'d', DOOR_C, {2, 2}},      {'n', BARIL_FLOWER, {2, 2}},
        {'D', DOOR_O, {2, 2}},      {'p', BARIL_APPLE, {2, 2}},
        {'@', WELL, {2, 3}},        {'>', F_UP_LEFT, {1, 1}},
        {'T', TREE_A, {3, 4}},      {'<', F_UP_RIGHT, {1, 1}},
        {'t', TREE_B, {3, 4}},      {']', F_DOOR_F_RIGHT, {1, 1}},
        {'s', TREE_C, {2, 1}},      {'[', F_DOOR_F_LEFT, {1, 1}},
        {'w', WHEAT_F, {2, 3}},     {'|', F_MID_LEFT, {1, 1}},
        {'W', WHEAT, {2, 2}},       {'!', F_MID_RIGHT, {1, 1}},
        {'f', W_FLOWER, {1, 1}},    {'=', F_DOWN_LEFT, {1, 1}},
        {'F', R_FLOWER, {1, 1}},    {'+', F_DOWN_RIGHT, {1, 1}},
        {'S', S_FLOWER, {1, 2}},    {'-', F_DOWN_MID, {1, 1}},
        {'X', F_DBL_DOOR, {2, 1}},  {'x', F_SGL_DOOR, {1, 1}},
        {'R', G_ROCK, {3, 3}},      {'o', SIGN, {1, 1}},
    };

    return parse_tiles(tilemap, str, sprite_chars);
}

int parse_feature_farm(c_tile_map_t *tilemap, char *str)
{
    sprite_char_t sprite_chars[] = {
        {'$', BARN, {6, 6}},         {'&', LEAF_SECOND, {1, 1}},
        {'N', PUMPKIN, {1, 1}},      {'*', LEAF_THIRD, {1, 1}},
        {'m', POTATO, {1, 1}},       {'j', WAY_H_LEFT, {1, 1}},
        {'M', CORN, {1, 2}},         {'J', WAY_H_MID, {1, 1}},
        {'y', WAY_UP_LEFT, {1, 1}},  {'k', WAY_H_RIGHT, {1, 1}},
        {'Y', WAY_UP_MID, {1, 1}},   {':', WAY_V_MID, {1, 1}},
        {'u', WAY_UP_RIGHT, {1, 1}}, {';', WAY_V_DOWN, {1, 1}},
        {'U', WAY_MID_LEFT, {1, 1}}, {'a', F_PUMPKIN, {1, 1}},
        {'i', WAY_MID_MID, {1, 1}},  {'A', S_PUMPKIN, {1, 1}},
        {'I', WAY_MID_RIGHT, {1, 1}},{'q', T_PUMPKIN, {1, 1}},
        {'O', WAY_DOWN_LEFT, {1, 1}},
        {'c', WAY_DOWN_MID, {1, 1}},
        {'C', WAY_DOWN_RIGHT, {1, 1}},
        {'%', LEAF_FIRST, {1, 1}},
    };
    return parse_tiles(tilemap, str, sprite_chars);
}

int parse_ground_layer(c_tile_map_t *tilemap, char *str)
{
    sprite_char_t sprite_chars[] = {
        {'#', G_MID, {1, 1}},       {'M', P_MID, {1, 1}},
        {'-', G_UP, {1, 1}},        {'w', P_UP, {1, 1}},
        {'=', G_DOWN, {1, 1}},      {'s', P_DOWN, {1, 1}},
        {'[', G_LEFT, {1, 1}},      {'a', P_LEFT, {1, 1}},
        {']', G_RIGHT, {1, 1}},     {'d', P_RIGHT, {1, 1}},
        {'(', G_UP_LEFT, {1, 1}},   {'q', P_UP_LEFT, {1, 1}},
        {')', G_UP_RIGHT, {1, 1}},  {'e', P_UP_RIGHT, {1, 1}},
        {'{', G_DOWN_LEFT, {1, 1}}, {'z', P_DOWN_LEFT, {1, 1}},
        {'}', G_DOWN_RIGHT, {1, 1}},{'$', BRIDGE_LEFT, {1, 1}},
        {'.', GC_UP_LEFT, {1, 1}},  {'N', WATER_LILY, {1, 1}},
        {',', GC_UP_RIGHT, {1, 1}},
        {'!', GC_DOWN_LEFT, {1, 1}},
        {'?', GC_DOWN_RIGHT, {1, 1}},
    };

    return parse_tiles(tilemap, str, sprite_chars);
}
