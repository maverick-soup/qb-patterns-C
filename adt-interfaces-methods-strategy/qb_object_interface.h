#ifndef QB_OBJECT_INTERFACE_H
#define QB_OBJECT_INTERFACE_H

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/
#include <stdint.h>

#ifdef __cplusplus
extern "C"{
#endif

/* Forward declarations------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/
 
/* Macros--------------------------------------------------------------------*/
 
/* Data types----------------------------------------------------------------*/

typedef struct qb_object_impl_s* qb_object_impl_ptr;
typedef struct qb_object const * qb_object_ptr;

struct qb_object
{
    void (*method)(qb_object_ptr self);
    void (*destroy)(qb_object_ptr *self);
    qb_object_impl_ptr impl;
};

/* Exported variables--------------------------------------------------------*/

/* Exported functions--------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* QB_OBJECT_INTERFACE_H */

