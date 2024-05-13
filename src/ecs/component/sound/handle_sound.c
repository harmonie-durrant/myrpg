/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** handle_sound
*/

#include "my.h"
#include "ecs.h"
#include "scene.h"
#include "components/sound.h"

void print_sound(void *sound)
{
    c_sound_t* sound_comp = (c_sound_t*)sound;

    if (sound_comp) {
        my_fprintf(2, "Sound component:\n");
        my_fprintf(2, "- Sound: %p\n", (void*)sound_comp->sound);
        my_fprintf(2, "- Buffer: %p\n", (void*)sound_comp->buffer);
    } else {
        my_fprintf(2, "Invalid sound component.\n");
    }
}

void play_sound(c_sound_t* sound_component)
{
    float volume = 0;

    volume = (sound_component->volume > 100) ? 100 : sound_component->volume;
    if (sound_component && sound_component->sound) {
        sfSound_setVolume(sound_component->sound, volume);
        sfSound_play(sound_component->sound);
    }
}

void stop_sound(c_sound_t* sound_component)
{
    if (sound_component && sound_component->sound) {
        sfSound_stop(sound_component->sound);
    }
}

void play_entity_sound(entity_t *entity, int isActive)
{
    c_sound_t *sound_comp = NULL;

    sound_comp = get_component(entity->component, C_SOUND);
    if (sound_comp && isActive) {
        play_sound(sound_comp);
    }
    if (sound_comp && isActive == 0) {
        stop_sound(sound_comp);
    }
}

void play_scene_sound(scene_t *scene, int isActive)
{
    entity_group_t *group = NULL;
    entity_t *entity = NULL;

    group = scene->entity_groups;
    while (group) {
        entity = group->entity;
        while (entity) {
            play_entity_sound(entity, isActive);
            entity = entity->next;
        }
        group = group->next;
    }
    return;
}
