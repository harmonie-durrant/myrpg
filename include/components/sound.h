/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** sound
*/

#ifndef SOUND_H_
    #define SOUND_H_
    #include "window.h"
    #include "types/s_types.h"
    #include "scene.h"
    #include "ecs.h"
    #include "rpg.h"

    typedef struct c_sound_s {
        float volume;
        sfSound* sound;
        sfSoundBuffer* buffer;
    } c_sound_t;

    #define create_buffer_ff sfSoundBuffer_createFromFile

// sound
c_sound_t* create_sound(const char* sound_file, float volume);
component_t *create_sound_comp(const char* sound_file, float volume);
void destroy_sound(void *sound);

void print_sound(void *sound);
void play_sound(c_sound_t *sound);
void stop_sound(c_sound_t *sound);
void play_scene_sound(scene_t *scene, int isActive);
#endif /* !SOUND_H_ */
