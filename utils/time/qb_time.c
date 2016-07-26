#include "qb_time.h"

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/

/* Data types----------------------------------------------------------------*/

/* Variables-----------------------------------------------------------------*/

/* Constants-----------------------------------------------------------------*/

/* Internal functions declarations-------------------------------------------*/

/* Functions definitions-----------------------------------------------------*/

bool qb_time_is_leap_year(uint32_t const year)
{
    bool const is_not_divisible_by_4 = (0 != (year % 4));
    bool const is_divisible_by_100 = (0 == year % 100);
    bool const is_not_divisible_by_400 = (0 != (year % 400));

    if (is_not_divisible_by_4)
    {
        return false;
    }

    if (is_divisible_by_100 && is_not_divisible_by_400)
    {
        return false;
    }

    return true;
}

uint32_t qb_time_get_total_number_of_leap_years(uint32_t const year)
{
    uint16_t const divisible_by_4_filter = 4;
    uint16_t const divisible_by_100_filter = 100;
    uint16_t const divisible_by_400_filter = 400;

    uint16_t const number_of_years_divisible_by_4 = year / divisible_by_4_filter;
    uint16_t const number_of_years_divisible_by_100 = year / divisible_by_100_filter;
    uint16_t const number_of_years_divisible_by_400 = year / divisible_by_400_filter;

    return number_of_years_divisible_by_4
            - number_of_years_divisible_by_100
            + number_of_years_divisible_by_400;
}
