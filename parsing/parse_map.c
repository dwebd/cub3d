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
        ft_strlcpy(main_data->maplines[index], map_lines[j], main_data->map_width + 1);
        while((int)ft_strlen(main_data->maplines[index]) < main_data->map_width)
        {
            dprintf(2, "current line:   %d and len is:  %d\n", index, (int)ft_strlen(main_data->maplines[index]));
           ft_strlcat(main_data->maplines[index], " ", main_data->map_width + 1);
        }
        index++;
        j++;
    }
    index = 0;
while (index < main_data->map_height)
{
    printf(" map: $%s$\n", main_data->maplines[index]);
    index++;
}
    return(true);
}

 static bool get_map_size(char **map_lines, int j, t_main_data *main_data)
{
    size_t height;
    size_t max_width;

    height = 0;
    max_width = 0;
    while(map_lines[j])
    {
        printf("hello from get_map_size loop, j here = $%s$\n", map_lines[j]);
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
    printf("\n\nmap_height: %d\n", main_data->map_height);
    printf("map_width: %d\n", main_data->map_width);
    printf("j last: %s\n", map_lines[j]);
    
    return (true);
}

bool parse_map(char **map_lines, int j, t_main_data *main_data)
{
    (void)main_data;

    printf("initial j:  %d\n\n\n", j);
    printf("j после того как попала в функцию validate_map: %s", map_lines[j]);
    while(is_empty_line(map_lines[j]))
        j++;
    printf("j после loop пропуска пустых строк: %s", map_lines[j]);
    
    printf("post j:  %d\n", j);
    if(!get_map_size(map_lines, j, main_data))
        return(false);
    if(!store_map(map_lines, j, main_data))
        return(false);
    // find player
    if(!validate_map(map_lines, j, main_data))
        return(false);
    return (true);
}