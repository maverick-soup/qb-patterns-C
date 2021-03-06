#include "qb_object_bar.h"

#include "../utils/logger/qb_logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/

/* Data types----------------------------------------------------------------*/

struct qb_object_impl_s
{
    int size;
    char temp;
    char *name;
};

/* Variables-----------------------------------------------------------------*/

/* Constants-----------------------------------------------------------------*/

/* Internal functions declarations-------------------------------------------*/

static void int_method(qb_object_ptr self);
static qb_object_impl_ptr int_qb_object_impl_create(void);
static void int_qb_object_impl_destroy(qb_object_impl_ptr *implementation);

/* Functions definitions-----------------------------------------------------*/

qb_object_ptr qb_object_bar_create(void)
{
    struct qb_object *temp = (struct qb_object *) malloc(sizeof *temp);
    if (NULL == temp)
    {
        QB_LOG("NULL pointer");
        return temp;
    }

    *temp = (struct qb_object){0};
    temp->method = int_method;
    temp->destroy = qb_object_bar_destroy;
    temp->impl = int_qb_object_impl_create();
    return temp;
}

static void int_method(qb_object_ptr self)
{
    if (NULL == self)
    {
        QB_LOG("NULL pointer");
        return;
    }

    if (NULL == self->impl)
    {
        QB_LOG("NULL pointer");
        return;
    }

    self->impl->temp = 60;
    QB_LOG("Method value temp %c", self->impl->temp);
}

static qb_object_impl_ptr int_qb_object_impl_create(void)
{
    qb_object_impl_ptr temp = (qb_object_impl_ptr) malloc(sizeof *temp);
    if (NULL == temp)
    {
        QB_LOG("NULL pointer");
        return temp;
    }

    *temp = (struct qb_object_impl_s){0};
    return temp;
}

void qb_object_bar_destroy(qb_object_ptr *object)
{
    struct qb_object **mutable = (struct qb_object **)object;
    if (NULL == mutable)
    {
        QB_LOG("prevents from NULL as argument");
        return;
    }

    if (NULL == *mutable)
    {
        QB_LOG("prevetns from pointing to NULL");
	return;
    }

    int_qb_object_impl_destroy((qb_object_impl_ptr *)&(*mutable)->impl);
    **mutable = (struct qb_object){0};
    free((void *)(*mutable));
    *mutable = NULL;
}

static void int_qb_object_impl_destroy(qb_object_impl_ptr *implementation)
{
    if (NULL == implementation)
    {
        QB_LOG("prevents from NULL as argument");
        return;
    }

    if (NULL == *implementation)
    {
        QB_LOG("prevents from pointing to NULL");
	return;
    }

    **implementation = (struct qb_object_impl_s){0};
    free((void *)(*implementation));
    *implementation = NULL;
}
