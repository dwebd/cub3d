#include "../inc/cub3d.h"

char *skip_digits(char *line)
{
    while (ft_isdigit(*line))
        line++;
    return line;
}

char *skip_comma(char *line)
{
    if (*line == ',')
        return line + 1;
    return NULL;
}

char *set_color_value(char *line, int *value)
{
    int i;

    if (!ft_isdigit(*line))
    {
        printf("[set_color_value] Error: Expected digit\n");
        return NULL;
    }

    *value = ft_atoi(line);
    i = *value;
    printf("value :%d", i);
    if (*value < 0 || *value > 255)
    {
        printf("[set_color_value] Error: Value should be in [0,255]\n");
        return NULL;
    }

    line = skip_digits(line);
    line = skip_tab_spaces(line);
    if (*line == ',' && *(line + 1) != '\0')
        return skip_tab_spaces(line + 1); // пропускаем запятую и пробелы
    return line;
}
