#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../utils/list/qb_list.h"

typedef void (*qb_timeout_notification_cb)(void);

typedef void (*qb_battery_notification_cb)(int const level);
typedef struct
{
    int const level;
} battery_notification_data;

typedef void (*qb_kbd_notification_cb)(int const button);
typedef struct
{
    int const button;
} kbd_notification_data;

typedef void (*qb_update_notification_cb)(uint8_t const *const data, size_t const len);
typedef struct
{
    uint8_t const *const data;
    size_t const len;
} update_notification_data;

typedef union
{
    qb_timeout_notification_cb timeout;
    qb_battery_notification_cb battery;
    qb_kbd_notification_cb kbd;
    qb_update_notification_cb update;
} qb_notification;

typedef struct
{
    qb_notification instance;
} qb_observer_wrapper;

typedef qb_observer_wrapper* qb_observer_wrapper_ptr;

typedef void (iterator_strategy)(qb_list_elem_ptr elem);
typedef union
{
    battery_notification_data battery;
    kbd_notification_data kbd;
    update_notification_data update;
} notification_data;

static qb_list_ptr g_timeout_observers;
static qb_list_ptr g_battery_observers;
static qb_list_ptr g_kbd_observers;

static void int_check_timeout(void);
static void int_check_battery(void);
static void int_check_kbd(void);
static void int_notify_kbd_observers(int const button);

static void int_iterate(qb_list_ptr observers,
			iterator_strategy const notification_strategy);

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    g_timeout_observers = qb_list_create();
    g_battery_observers = qb_list_create();
    g_kbd_observers = qb_list_create();

    while (true)
    {
        int_check_timeout();
	int_check_battery();
	int_check_kbd();
    }

    return 0;
}

static void int_check_timeout(void)
{

}

static void int_check_battery(void)
{

}

static void int_check_kbd(void)
{
    int_notify_kbd_observers(0);

}

static void int_notify_kbd_observers(int const button)
{
    (void)button;
    int_iterate(g_kbd_observers, NULL);
}

static void int_iterate(qb_list_ptr observers,
			iterator_strategy const notification_strategy)
{
    (void)observers;
    (void)notification_strategy;
}

