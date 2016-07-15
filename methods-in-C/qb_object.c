#include "qb_object.h"

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

static void int_method(struct qb_object *const self);

/* Functions definitions-----------------------------------------------------*/

qb_object_ptr qb_object_create(void)
{
    qb_object_ptr temp = (qb_object_ptr) malloc(sizeof *temp);
    if (NULL == temp)
    {
        printf("NULL pointer");
        return temp;
    }

    temp->method = int_method;

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

void qb_object_destroy(qb_object_ptr *object)
{
    memset(*object, 0, sizeof **object);
    free(*object);
    *object = NULL;
}

