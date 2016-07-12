#include <qb_obejct.h>

static void int_fake_method(qb_object *self);

int main(int argc, char *argv[])
{
    qb_object test = {0};
    qb_object object = qb_object_create();

    test.method = listener.method;
    listener.method = int_fake_method;
    listener.method(&test);

    qb_object_destroy(&object);
}

static void int_fake_method(qb_object *object)
{
    printf("Fake method");
    self->method(self);
}
