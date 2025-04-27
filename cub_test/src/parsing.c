#include "../inc/cub3d.h"

static bool lines_counter(char *input, int *nbr_lines, int *empty_lines)
{
    int fd;
    fd = open(input, O_RDONLY);
    char *line;
    
    *empty_lines = 0;
    *nbr_lines = 0;
    while((line = get_next_line(fd)) != NULL)
    {
        (*nbr_lines)++;
        if(is_empty_line(line))
        (*empty_lines)++;
        free(line);
        line = NULL;
    }
    close(fd);
    if(*nbr_lines - *empty_lines < 7)
    {
        // printf("less then 7 lines\n");
        return(false);
    }
    return(true);

}
bool parse_content(char *input, char ***file_content)
{
    int nbr_lines;
    int fd;
    char *line;
    int empty_lines;
    int i;
    
    i = 0;
    line = NULL;
    if((lines_counter(input, &nbr_lines, &empty_lines)) == false)
        return(false);
    fd = open(input, O_RDONLY);
    if(fd < 0)
        return(false);
        *file_content = malloc(sizeof(char *) * (nbr_lines + 1));
    if (!(*file_content)[i])
        return(false);
    while((line = get_next_line(fd)) != NULL)
    {
        (*file_content)[i] = ft_strdup(line);
        if(!(*file_content)[0])
        {
            return(clean_2darray(*file_content), false);
        }
        i++;
        free(line);
    }
    (*file_content)[i] = NULL;
    close(fd);
    return(true);
}