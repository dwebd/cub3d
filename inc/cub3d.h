#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include "parsing.h"

//validation
bool check_file_format(char *input);
bool valid_file(char *input);
bool is_empty_line(char *str);
bool parse_content(char *input, char ***file_content); 
void clean(char **content);
void clean_2darray(char **content);
void exit_program(char *message, void *data);
bool valid_content(char **file_content, t_main_data *main_data);
bool init_main_data(t_main_data *main_data);
void free_split(char **split);
bool validate_textures(char *file_content, t_main_data *main_data);
int get_index(const char *str);
char *skip_tab_spaces(char *line);
char *skip_digits(char *line);
char *skip_comma(char *line);
char *skip_empty_lines(int fd);
char *set_color_value(char *line, int *value, bool is_coma);
bool validate_colors(char *file_content, t_main_data *main_data);
bool validate_map(char **map_lines, int j, t_main_data *main_data);