#include "qb_object.h"

#include <stdio.h>

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

static void int_method(struct qb_object *const self);

/* Functions definitions-----------------------------------------------------*/

struct qb_object qb_object_create(void)
{
    struct qb_object temp = {0};

    temp.method = int_method;

    return temp;
}

static void int_method(struct qb_object *const self)
{
    if (NULL == self->object)
    {
        printf("NULL pointer\n");
        return;
    }
}

void qb_object_destroy(struct qb_object *object)
{
    (void)object;
}

