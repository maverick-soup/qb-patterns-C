#ifndef QB_LOGGER_H
#define QB_LOGGER_H

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"{
#endif

/* Forward declarations------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/
 
/* Macros--------------------------------------------------------------------*/

#define QB_LOG(...) do{qb_logger_log(__FILE__, __LINE__, __VA_ARGS__);}while(0)

/* Data types----------------------------------------------------------------*/

/* Exported variables--------------------------------------------------------*/

/* Exported functions--------------------------------------------------------*/

void qb_logger_log(char const *const file, int const line, ...);

#ifdef __cplusplus
}
#endif

#endif /* QB_LOGGER_H */

