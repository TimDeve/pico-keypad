#include <pico/stdlib.h>
#include <time.h>

int clock_gettime(clockid_t clk_id, struct timespec *tp) {
  return to_ms_since_boot(get_absolute_time());
}
