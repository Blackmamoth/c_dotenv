#ifndef DOTENV_H
#define DOTENV_H

#define MAX_LINE_LENGTH 1024
#define MAX_VARIABLE_LENGTH 31
#define MAX_VALUE_LENGTH 1024
#define EQUAL_SIGN "="

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void load_env(const char *file_path);

#endif