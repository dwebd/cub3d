#include "../inc/cub3d.h"

static int get_index(const char *str)
{
    if (!ft_strncmp(str, "NO", 2))
        return NO;
    if (!ft_strncmp(str, "SO", 2))
        return SO;
    if (!ft_strncmp(str, "WE", 2))
        return WE;
    if (!ft_strncmp(str, "EA", 2))
        return EA;
    return -1;
}

static bool set_path(char **splitted, t_main_data *main_data)
{
    int index;
    index = get_index(splitted[0]);
    if(index == -1 || main_data->textures[index].path != NULL)
        return(false);
    main_data->textures[index].path = ft_strdup(splitted[1]);
    if(!main_data->textures[index].path)
        return(false);
    return(true);
}

bool validate_textures(char **file_content, t_main_data *main_data)
{
    int i;
    i = 0;
    char **splitted;
    while(file_content[i] != NULL)
    {
       
            // if (!ft_strncmp(file_content[i], "NO", 2) ||
            //     !ft_strncmp(file_content[i], "SO", 2) ||
            //     !ft_strncmp(file_content[i], "WE", 2) ||
            //     !ft_strncmp(file_content[i], "EA", 2))
            if(get_index(file_content[i]) != -1)
            {
                splitted = ft_split(file_content[i], ' ');
                if (!splitted || !splitted[0] || !splitted[1] || splitted[2] ||
                    !set_path(splitted, main_data))
                return(free_split(splitted), false);
                free_split(splitted);
            }
            i++;   
    }
        i = 0;
        while(i < 4)
            if(main_data->textures[i++].path == NULL)
                return (false);
        return(true);
}