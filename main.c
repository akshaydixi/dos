#include "monitor.h"

int main(struct multiboot *mboot_ptr)
{

  monitor_clear();
  monitor_write("Hello, World!\r\n");
  monitor_write("This is a test\r");
monitor_write_hex(255);

   return 0;
}
