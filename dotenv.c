#include "dotenv.h"

void get_env_variable_name(char variable_name[], char line[])
{
    int i = 0;
    char variable[MAX_VARIABLE_LENGTH + 1];
    while (line[i] != ' ' && line[i] != '\0')
    {
        variable[i] = line[i];
        i++;
    }
    variable[i] = '\0';
    strcpy(variable_name, variable);
}

void get_env_value(char value[], char line[])
{
    char END_OF_LINE = ' ';
    int i = strcspn(line, EQUAL_SIGN), j = 0;
    char _value[MAX_VALUE_LENGTH + 1];
    i++;
    while (line[i] != '\0' && line[i] == ' ')
        i++;
    if (line[i] == '\'' || line[i] == '"')
    {
        END_OF_LINE = line[i];
        i++;
    }
    while (line[i] != '\0' && line[i] != END_OF_LINE)
    {
        _value[j] = line[i];
        i++;
        j++;
    }
    _value[j] = '\0';
    strcpy(value, _value);
}

void load_env(const char *file_path)
{
    FILE *env;
    char line[MAX_LINE_LENGTH];
    char variable[MAX_VARIABLE_LENGTH];
    char value[MAX_VALUE_LENGTH];
    if ((env = fopen(file_path, "r")) != NULL)
    {
        while (fgets(line, MAX_LINE_LENGTH, env))
        {
            value[0] = '\0';
            line[strcspn(line, "\n")] = '\0';
            get_env_variable_name(variable, line);
            get_env_value(value, line);
            setenv(variable, value, -1);
        }
        fclose(env);
    }
    else
    {
        fprintf(stderr, "File [%s] does not exist or could not be opened.\n", file_path);
        return;
    }
}
