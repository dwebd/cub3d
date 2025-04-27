#include "../inc/cub3d.h"

bool valid_file(char *input)
{
    int fd;

    fd = open(input, O_RDONLY);
    if(fd < 3)
    {
        close(fd);
        return(false);
    }
    close(fd);
    return(true);
}
bool check_file_format(char *input)
{
    size_t len;
    len = ft_strlen(input);

    if(len >= 4 
        && (input[len - 1] == 'b' 
        && input[len - 2] == 'u' 
        && input[len - 3] == 'c'
        && input[len - 4] == '.'))
        return(true);
    return(false);
}

