#include "qb_logger.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/

/* Data types----------------------------------------------------------------*/

/* Variables-----------------------------------------------------------------*/

/* Constants-----------------------------------------------------------------*/

/* Internal functions declarations-------------------------------------------*/

/* Functions definitions-----------------------------------------------------*/

void qb_logger_log(char const *const file, int const line, ...)
{
    enum{MAX_LOG_BUFFER_LEN = 1024};
    char buffer[MAX_LOG_BUFFER_LEN + 1] = {0};

    char const* format = NULL;
    va_list extra_params;
    
    va_start(extra_params, line);
    format = va_arg(extra_params, char const*);
    vsnprintf(buffer, sizeof buffer, format, extra_params);
    printf("%s (%s:%d)\n", buffer, file, line);
    va_end(extra_params);
}

