#ifndef QB_TIME_H
#define QB_TIME_H

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif

/* Forward declarations------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/
 
/* Macros--------------------------------------------------------------------*/
 
/* Data types----------------------------------------------------------------*/
 
/* Exported variables--------------------------------------------------------*/

/* Exported functions--------------------------------------------------------*/

bool qb_time_is_leap_year(uint32_t const year);
uint32_t qb_time_get_total_number_of_leap_years(uint32_t const year);

#ifdef __cplusplus
}
#endif

#endif /* QB_TIME_H */

