#include "../inc/cub3d.h"
static bool store_map(char **map_lines, int j, t_main_data *main_data)
{
    int index;
    index = 0;
    if(!main_data->map_height || main_data->map_height < 3)
        return(false);
    main_data->maplines = malloc(sizeof(char *) * (main_data->map_height + 1));
    if(!main_data->maplines)
        return(false);
    while(index < main_data->map_height)
    {
        main_data->maplines[index] = malloc(sizeof(char) * (main_data->map_width + 1));
        if(!main_data->maplines[index])
            return(false);
    }
    
}

 static bool get_map_size(char **map_lines, int j, t_main_data *main_data)
{
    size_t height;
    size_t max_width;

    height = 0;
    max_width = 0;
    while(map_lines[j])
    {
        printf("hello from get_map_size loop, j here = %s\n", map_lines[j]);
        if(!map_lines[j] || is_empty_line(map_lines[j]))
        {
            printf("empty line in the map\n");
            return(false);
        }
        height++;
        if(ft_strlen(map_lines[j]) > max_width)
            max_width = ft_strlen(map_lines[j]);
        j++;   
    }
    main_data->map_height = height;
    main_data->map_width = max_width;
    printf("map_height: %zu\n", main_data->map_height);
    printf("map_width: %zu\n", main_data->map_width);
    printf("j last: %s\n", map_lines[j]);
    
    return (true);
}

bool validate_map(char **map_lines, int j, t_main_data *main_data)
{
    (void)main_data;

    printf("j после того как попала в функцию validate_map: %s\n", map_lines[j]);
    while(is_empty_line(map_lines[j]))
        j++;
    printf("j после loop пропуска пустых строк: %s", map_lines[j]);
    
    if(!get_map_size(map_lines, j, main_data))
        return(false);
    if(!store_map(map_lines, j, main_data))
        return(false);
    return(true);
   
}