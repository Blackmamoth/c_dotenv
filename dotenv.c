#include "dotenv.h"

void remove_quotes(char str[], size_t length)
{
    size_t j = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] != '"' && str[i] != '\'')
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

void load_env(const char *file_path)
{
    FILE *env;
    char line[MAX_LINE_LENGTH];
    char variable[MAX_VARIABLE_LENGTH];
    char value[MAX_VALUE_LENGTH];
    char quote = ' ';
    int assigment_index = 0;
    int line_length = 0;
    int i = 0;
    if ((env = fopen(file_path, "r")) != NULL)
    {
        while (fgets(line, MAX_LINE_LENGTH, env))
        {
            value[0] = '\0';
            assigment_index = 0;
            line_length = 0;
            i = 0;
            line[strcspn(line, "\n")] = '\0';
            line_length = strlen(line);
            assigment_index = strcspn(line, EQUAL_SIGN);
            if (line[assigment_index - 1] == ' ')
                assigment_index--;
            strncpy(variable, line, assigment_index);
            variable[assigment_index] = '\0';
            if (line[assigment_index] == ' ')
                assigment_index++;
            assigment_index++;
            while (line[assigment_index] == ' ')
                assigment_index++;
            if (line[assigment_index] == '"' || line[assigment_index] == '\'')
                quote = line[assigment_index];
            while (line[assigment_index] != '\0')
            {
                value[i] = line[assigment_index];
                i++;
                assigment_index++;
            }
            value[i] = '\0';
            if (quote != ' ')
            {
                remove_quotes(value, strlen(value));
            }
                }
    }
    else
    {
        fprintf(stderr, "File [%s] does not exist.\n", file_path);
        return;
    }
}
