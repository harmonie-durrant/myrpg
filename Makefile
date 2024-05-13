##
## EPITECH PROJECT, 2022
## my_rpg
## File description:
## makefile
##

NAME	=	my_rpg

## Flags

CFLAGS	=	-W -Wall -Wextra -pedantic -I./include/

CRITERION_FLAGS	=	-lcriterion -lgcov --coverage

CSFML_FLAGS  =   -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LDFLAGS	=	-L./lib/ -lmy -lm

## Main

MAIN	=	src/main.c

TMAIN	=	tests/test_main.c

## Sources

# Main sources

SRC	=	my_rpg.c\
		banks.c\
		bank_utils.c\
		input_handler.c\
		box_bank.c\
		game/loop.c\
		game/init_splash.c\
		scene/handle_scene.c\
		scene/init_scene.c\
		utils/debug_tools.c\
		utils/array_tools.c\
		utils/str_tools.c\
		utils/vector_parsing.c\
		utils/parser_utils.c\
		utils/number_parsing.c\
		utils/get_line_data.c\
		window/init_window.c\
		window/destroy_window.c\
		window/resize_window.c\
		map/parse_map.c\
		map/parse_layers.c\
		map/handle_layer_parsing.c\
		utils/vector_interpolation.c\
		utils/math_tools.c\


# ECS files

SRC	+=	ecs/entity/init_entity.c\
		ecs/entity/handle_entity.c\
		ecs/entity/update_entity.c\
		ecs/entity/print_entity.c\
		ecs/entity_group/init_group.c\
		ecs/entity_group/handle_group.c\
		ecs/entity_group/print_group.c\
		ecs/scene_parser/scene_parser.c\
		ecs/scene_parser/parser_components_utils.c\
		ecs/scene_parser/parser_components.c\
		ecs/scene_parser/parser_entities_utils.c\
		ecs/scene_parser/parser_group_utils.c\
		ecs/component/init_component.c\
		ecs/component/destroy_component.c\
		ecs/component/handle_component.c\
		ecs/component/print_component.c\
		ecs/component/transform/init_transform.c\
		ecs/component/transform/handle_transform.c\
		ecs/component/transform/parse_transform.c\
		ecs/component/stats/init_stats.c\
		ecs/component/stats/handle_stats.c\
		ecs/component/stats/print_stats.c\
		ecs/component/stats/parse_stats.c\
		ecs/component/sprite/init_sprite.c\
		ecs/component/sprite/handle_sprite.c\
		ecs/component/sprite/parse_sprite.c\
		ecs/component/sprite/draw_sprite.c\
		ecs/component/sprite/info_sprite.c\
		ecs/component/animator/handle_animator.c\
		ecs/component/animator/init_animator.c\
		ecs/component/animator/parse_animator.c\
		ecs/component/sound/init_sound.c\
		ecs/component/sound/handle_sound.c\
		ecs/component/sound/parse_sound.c\
		ecs/component/tile/init_tile.c\
		ecs/component/tile/handle_tile.c\
		ecs/component/tile/print_tile.c\
		ecs/component/tile/parse_tilemap.c\
		ecs/component/inventory/parse_inventoty.c\
		ecs/component/inventory/print_inventory.c\
		ecs/component/inventory/init_inventory.c\
		ecs/component/inventory/handle_inventory.c\
		ecs/component/magic/init_magic.c\
		ecs/component/magic/handle_magic.c\
		ecs/component/magic/parse_magic.c\
		ecs/component/ui_button/handle_ui_button.c\
		ecs/component/ui_button/init_ui_button.c\
		ecs/component/ui_button/parse_ui_button.c\
		ecs/component/controller/init_controller.c\
		ecs/component/controller/handle_controller.c\
		ecs/component/controller/parse_controller.c\
		ecs/component/controller/update_controller.c\
		ecs/component/cam_controller/handle_cam_controller.c\
		ecs/component/cam_controller/init_cam_controller.c\
		ecs/component/cam_controller/parse_cam_controller.c\
		ecs/component/dialogue/handle_dialogue.c\
		ecs/component/dialogue/init_dialogue.c\
		ecs/component/dialogue/parse_dialogue.c\
		ecs/system/dialogue/dialogue_range_check.c\
		ecs/system/dialogue/handle_dialogue.c\
		ecs/system/callback/callback_events.c\
		ecs/component/is_active/handle_is_active.c\
		ecs/component/is_active/init_is_active.c\
		ecs/component/is_active/parse_is_active.c\
		ecs/component/tag/handle_tag.c\
		ecs/component/tag/init_tag.c\
		ecs/component/tag/parse_tag.c\
		ecs/component/tag/find_tag.c\
		ecs/component/collider/init_collider.c\
		ecs/component/collider/handle_collider.c\
		ecs/component/collider/parse_collider.c\
		ecs/component/collider/print_collider.c\
		ecs/component/collider/handle_collision.c\
		ecs/component/collision_map/handle_collision_map.c\
		ecs/component/collision_map/init_collision_map.c\
		ecs/component/collision_map/parse_collision_map_file.c\
		ecs/component/collision_map/parse_collision_map.c\
		ecs/component/mob_controller/init_mob_controller.c\
		ecs/component/mob_controller/handle_mob_controller.c\
		ecs/component/mob_controller/parse_mob_controller.c\
		ecs/component/mob_controller/update_mob_controller.c\
		ecs/component/mob_controller/compute_mob_controller.c\
		ecs/component/hitbox/init_hitbox.c\
		ecs/component/hitbox/handle_hitbox.c\
		ecs/component/hitbox/parse_hitbox.c\
		ecs/component/hitbox/update_hitbox.c\

# unit_tests sources

TEST_SRC	=	tests/unit_tests/ecs_component.c\
				tests/unit_tests/ecs_entity.c\
				tests/unit_tests/map.c\
				tests/unit_tests/rpg.c\
				tests/unit_tests/scene.c\
				tests/unit_tests/window.c\

SRC :=	$(addprefix src/, $(SRC))

## Objects

MAIN_OBJ	=	$(MAIN:.c=.o)

TMAIN_OBJ	=	$(TMAIN:.c=.o)

TEST_OBJ	=	$(TEST_SRC:.c=.o)

OBJ	=	$(SRC:.c=.o)

## Rules

$(NAME): $(MAIN_OBJ) $(OBJ) lib/libmy.a
	gcc -o $(NAME) $(MAIN_OBJ) $(OBJ) $(LDFLAGS) $(CSFML_FLAGS)
	echo -e "\033[1;31m {MY_RPG} \033[0;32m Compiled Successfully\033[0m"

all:	$(NAME)

lib/libmy.a:
	make -C lib/

clean:
	rm -f $(OBJ)
	rm -f $(MAIN_OBJ)
	make clean -C lib/

tclean:
	find -name "*.gc*" -type f -delete
	rm -rf unit_tests
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.gcov

fclean:	clean
	make tclean
	make fclean -C lib/
	rm -f debug_$(NAME)
	rm -f $(NAME)

re:	fclean all

unit_tests: LDFLAGS += $(CRITERION_FLAGS)
unit_tests: lib/libmy.a $(TEST_OBJ) $(OBJ)
	gcc -o unit_tests $(TEST_OBJ) $(OBJ) $(CFLAGS) $(LDFLAGS) $(CSFML_FLAGS)

tests_run:	unit_tests
	./unit_tests

test_re:	tclean	unit_tests	tests_run

test_main:	$(TMAIN_OBJ) $(OBJ) lib/libmy.a
	gcc -o $(NAME) $(TMAIN_OBJ) $(OBJ) $(LDFLAGS) $(CSFML_FLAGS)
	echo -e "\033[1;31m {MY_RPG} \033[0;35m Compiled with Test_Main\033[0m"

lib/libdebug.a:
	make debug -C lib/

debug: CFLAGS += -g
debug: LDFLAGS := $(subst -lmy,-ldebug,$(LDFLAGS))
debug:	lib/libdebug.a $(OBJ) $(MAIN_OBJ)
	gcc -o debug_$(NAME) $(MAIN_OBJ) $(OBJ) $(LDFLAGS) $(CSFML_FLAGS)

debug_re:	fclean	debug

.PHONY: all clean fclean re debug
