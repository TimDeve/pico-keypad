#include "bsp/board.h"
#include "tusb.h"

#include "usb_descriptors.h"

bool ready_for_animation(int interval_ms);
void led_blinking_task(void);
void hid_task(void);
void press_key(int);
