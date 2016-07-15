#ifndef QB_OBJECT_H
#define QB_OBJECT_H

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/
 
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
    qb_object_impl_ptr object;
};

/* Exported variables--------------------------------------------------------*/

/* Exported functions--------------------------------------------------------*/

qb_object_ptr qb_object_create(void);
void qb_object_destroy(qb_object_ptr *object);

#ifdef __cplusplus
}
#endif

#endif /* QB_OBJECT_H */

