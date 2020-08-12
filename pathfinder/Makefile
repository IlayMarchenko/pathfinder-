NAME = pathfinder
INC = pathfinder.h
INCI = inc/pathfinder.h
SRC = main.c\
      mx_add_all_from_array.c\
      mx_append_city_to_arr.c\
      mx_atoi.c\
      mx_back_path.c\
      mx_count_character.c\
      mx_del_all_numbers_and_com.c\
      mx_del_dub.c\
      mx_del_not_alphabet.c\
      mx_error_1.c\
      mx_error_2.c\
      mx_error_3.c\
      mx_error_4.c\
      mx_error_5.c\
      mx_error_6.c\
      mx_error_7.c\
      mx_error_8.c\
      mx_error_check.c\
      mx_find_all_paths.c\
      mx_floydWarshall.c\
      mx_get_distance.c\
      mx_numbers_only.c\
      mx_read_one_line.c\
      mx_ret_trip_output.c\
      mx_struct_init.c\
      mx_the_biggest_name.c
SRCS = $(addprefix src/, main.c\
      mx_add_all_from_array.c\
      mx_append_city_to_arr.c\
      mx_atoi.c\
      mx_back_path.c\
      mx_count_character.c\
      mx_del_all_numbers_and_com.c\
      mx_del_dub.c\
      mx_del_not_alphabet.c\
      mx_error_1.c\
      mx_error_2.c\
      mx_error_3.c\
      mx_error_4.c\
      mx_error_5.c\
      mx_error_6.c\
      mx_error_7.c\
      mx_error_8.c\
      mx_error_check.c\
      mx_find_all_paths.c\
      mx_floydWarshall.c\
      mx_get_distance.c\
      mx_numbers_only.c\
      mx_read_one_line.c\
      mx_ret_trip_output.c\
      mx_struct_init.c\
      mx_the_biggest_name.c)
OBJ = main.o\
      mx_add_all_from_array.o\
      mx_append_city_to_arr.o\
      mx_atoi.o\
      mx_back_path.o\
      mx_count_character.o\
      mx_del_all_numbers_and_com.o\
      mx_del_dub.o\
      mx_del_not_alphabet.o\
      mx_error_1.o\
      mx_error_2.o\
      mx_error_3.o\
      mx_error_4.o\
      mx_error_5.o\
      mx_error_6.o\
      mx_error_7.o\
      mx_error_8.o\
      mx_error_check.o\
      mx_find_all_paths.o\
      mx_floydWarshall.o\
      mx_get_distance.o\
      mx_numbers_only.o\
      mx_read_one_line.o\
      mx_ret_trip_output.o\
      mx_struct_init.o\
      mx_the_biggest_name.o
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
all: install clean
install:
	@make -C libmx
	@cp $(SRCS) .
	@cp $(INCI) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@mkdir -p obj
	@clang $(CFLAGS) libmx/libmx.a $(OBJ) -o $(NAME)
	@mv $(OBJ) ./obj
uninstall:
	@make uninstall -C libmx
	@rm -rf $(NAME)
clean:
	@make clean -C libmx
	@rm -rf $(INC)
	@rm -rf $(SRC)
	@rm -rf $(OBJ)
	@rm -rf ./obj
reinstall: uninstall all
