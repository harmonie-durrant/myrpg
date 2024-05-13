/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** init_sound
*/

#include <stdlib.h>
#include "my.h"
#include "components/sound.h"

c_sound_t* create_sound(const char* sound_file, float volume)
{
    c_sound_t* new_sound = NULL;

    new_sound = (c_sound_t*)malloc(sizeof(c_sound_t));
    if (!new_sound) {
        return NULL;
    }
    if ((new_sound->buffer = create_buffer_ff(sound_file)) == NULL) {
        my_fprintf(2, "Error sound file charging : %s\n", sound_file);
        free(new_sound);
        return NULL;
    }
    new_sound->volume = volume;
    new_sound->sound = sfSound_create();
    if (!new_sound->sound) {
        sfSoundBuffer_destroy(new_sound->buffer);
        free(new_sound);
        return NULL;
    }
    sfSound_setBuffer(new_sound->sound, new_sound->buffer);
    return new_sound;
}

component_t *create_sound_comp(const char* sound_file, float volume)
{
    c_sound_t *sound = NULL;
    component_t *sound_comp = NULL;

    if ((sound = create_sound(sound_file, volume)) == NULL) {
        return NULL;
    }
    if ((sound_comp = create_component(C_SOUND, sound)) == NULL) {
        destroy_sound(sound);
        return NULL;
    }
    sound_comp->destroy = &destroy_sound;
    sound_comp->print = &print_sound;
    return sound_comp;
}

void destroy_sound(void *sound)
{
    c_sound_t* sound_comp = (c_sound_t*)sound;

    if (sound_comp) {
        if (sound_comp->sound) {
            sfSound_destroy(sound_comp->sound);
        }
        if (sound_comp->buffer) {
            sfSoundBuffer_destroy(sound_comp->buffer);
        }
        free(sound_comp);
    }
}
