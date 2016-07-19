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

void qb_logger_log(char const *const file, int const line, char const *const format, ...)
{
    enum{MAX_LOG_BUFFER_LEN = 1024};
    char buffer[MAX_LOG_BUFFER_LEN + 1] = {0};

    va_list extra_params = NULL;
    
    va_start(extra_params, format);
    vsnprintf(buffer, sizeof buffer, format, extra_params);
    va_end(extra_params);

    printf("%s (%s:%d)\n", buffer, file, line);
}
