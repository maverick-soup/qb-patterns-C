#include "qb_object_foo.h"

#include "../utils/logger/qb_logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Copyright (C)-------------------------------------------------------------*/

/* Includes------------------------------------------------------------------*/

/* Preprocessor constants----------------------------------------------------*/

/* Data types----------------------------------------------------------------*/

struct
{
    int size;
} qb_object_impl_s;

/* Variables-----------------------------------------------------------------*/

/* Constants-----------------------------------------------------------------*/

/* Internal functions declarations-------------------------------------------*/

static void int_method(qb_object_ptr self);
static qb_object_impl_ptr int_qb_object_impl_create(void);
static void int_qb_object_impl_destroy(qb_object_impl_ptr *implementation);

/* Functions definitions-----------------------------------------------------*/

qb_object_ptr qb_object_foo_create(void)
{
    struct qb_object *temp = (struct qb_object *) malloc(sizeof *temp);
    if (NULL == temp)
    {
        QB_LOG("NULL pointer");
        return temp;
    }

    temp->method = int_method;
    temp->object = int_qb_object_impl_create();
    return temp;
}

static void int_method(qb_object_ptr self)
{
    if (NULL == self->object)
    {
        QB_LOG("NULL pointer");
        return;
    }
}

static qb_object_impl_ptr int_qb_object_impl_create(void)
{
    QB_LOG("object FOO implementation constructor");
    return NULL;
}

void qb_object_foo_destroy(qb_object_ptr *object)
{
    if (NULL == object)
    {
        QB_LOG("prevents from NULL as argument");
        return;
    }

    if (NULL == *object)
    {
        QB_LOG("prevetns from pointing to NULL");
	return;
    }

    int_qb_object_impl_destroy((qb_object_impl_ptr *)&(*object)->object);
    memset((void *)(*object), 0, sizeof **object);
    free((void *)(*object));
    *object = NULL;
}

static void int_qb_object_impl_destroy(qb_object_impl_ptr *implementation)
{
    (void)implementation;
    QB_LOG("object FOO implementation destructor");
}
