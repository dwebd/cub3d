#include "../inc/cub3d.h"

int main(int ac, char **av)
{
    t_main_data main_data;
    char **file_content;

    file_content = NULL;
    if(ac == 2)
    {
        if(!check_file_format(av[1]))
            exit_program("Error: wrong format file: .cub\n", NULL);
        if(!valid_file(av[1]))
            exit_program("Error: file   can not be opened\n", NULL);
        if(!parse_content(av[1], &file_content))
            exit_program("Error: invalid content\n", NULL);
        /* file_content contains*/
        // int i = 0;
        // while(file_content[i])
        // {
        //     printf("File_content contains: %s", file_content[i]);
        //     i++;
        // }
        if(!valid_content(file_content, &main_data))
            exit_program("Error: invalid content\n", NULL);
    }
    clean(file_content);
    return(1);
}