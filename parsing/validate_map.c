#include "../inc/cub3d.h"
// bool store_map(char **map_lines, int j, t_main_data main_data)
// {
    
// }

 static bool get_map_size(char **map_lines, int j, t_main_data *main_data)
{
    size_t height;
    size_t max_width;

    height = 0;
    max_width = 0;
    while(map_lines[j])
    {
        if(!map_lines[j] || !skip_tab_spaces(map_lines[j]))
            return(false);
        height++;
        if(ft_strlen(map_lines[j]) > max_width)
            max_width = ft_strlen(map_lines[j]);
        j++;   
    }
    main_data->map_height = height;
    main_data->map_width = max_width;
    printf("map_height: %zu\n", main_data->map_height);
    printf("map_width: %zu\n", main_data->map_width);
    
    return (true);
}

bool validate_map(char **map_lines, int j, t_main_data *main_data)
{
    (void)main_data;
    
    if(!get_map_size(map_lines, j, main_data))
        return(false);
    // if(!store_map(map_lines, j, main_data))
    //     return(false);
    return(true);
   
}