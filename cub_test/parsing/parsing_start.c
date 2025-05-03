#include "../inc/cub3d.h"

bool valid_content(char **file_content, t_main_data *main_data)
{
    int index;
    int j;
    size_t i;
    i = 0;
    j = 0;


    if (!file_content || !main_data)
        return (false);
    if(!init_main_data(main_data)) 
        return(false);
    while(file_content && i < 6)
    {
        if(is_empty_line(file_content[j]))
        {
            j++;
            continue;
        }
        index = get_index(file_content[j]);
        if(index >= 0 && index <= 3)
        {
            printf("index : %d\n", index);
            if(!validate_textures(file_content[j], main_data))
                return(false);
            i++;
        }
        else if(index == 4 || index == 5)
        {
            if(!validate_colors(file_content[i], main_data))
                return(false);
            i++;
        }
        if (i == 6)
            break;
        j++;
    }
    i = 0;
    while (i < 4)
    {
        if (main_data->textures[i++].path == NULL)
        {
            printf("[validate_textures] Error: Missing texture at index %lu\n", i - 1);
            return (false);
        }
    } 
    // if (i == 4)
    printf("[validate_textures] All textures validated successfully!\n");

    return (true);
}
