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

struct qb_object
{
    void (*method)(struct qb_object *const self);
    qb_object_impl_ptr object;
};

/* Exported variables--------------------------------------------------------*/

/* Exported functions--------------------------------------------------------*/

struct qb_object qb_object_create(void);
void qb_object_destroy(struct qb_object *object);

#ifdef __cplusplus
}
#endif

#endif /* QB_OBJECT_H */

