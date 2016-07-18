#ifndef QB_OBJECT_BAR_H
#define QB_OBJECT_BAR_H

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/

#include "qb_object_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/* Forward declarations------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/
 
/* Macros--------------------------------------------------------------------*/
 
/* Data types----------------------------------------------------------------*/
 
/* Exported variables--------------------------------------------------------*/

/* Exported functions--------------------------------------------------------*/

qb_object_ptr qb_object_bar_create(void);
void qb_object_bar_destroy(qb_object_ptr *object);

#ifdef __cplusplus
}
#endif

#endif /* QB_OBJECT_BAR_H */

