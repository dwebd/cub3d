#include "../inc/cub3d.h"
void free_split(char **split)
{
    int i = 0;
    if (!split)
        return;
    while (split[i])
        free(split[i++]);
    free(split);
}
void exit_program(char *message, void *data)
{
    (void)data;
    if(message)
        printf("%s", message);
    return ;
}

void  clean_2darray(char **content)
{
    int i;
    i = 0;
    while (content[i] != NULL)
    {
        free(content[i]);
        i++;
    }
free(content);
}

void clean(char **content)
{
    if(!content)
        return;
    else
        clean_2darray(content);
    return;
}
bool is_empty_line(char *str)
{
    int i;
    int n_symb;

    i = 0;
    n_symb = 0;
    while (str[i] != '\0')
    {
        if(str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
            n_symb++;
        i++;
    }
    if(n_symb == 0)
        return(true);
    return(false);
    
}