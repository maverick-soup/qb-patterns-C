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

static void int_method(qb_object *const self);

/* Functions definitions-----------------------------------------------------*/

qb_object qb_object_create(void)
{
    qb_object temp = {0};

    temp.method = int_method;

    return temp;
}

static void int_method(qb_object *const self)
{
    if (is_null(self->object))
    {

    }
}

void qb_object_destroy(qb_object *object)
{

}

