#include "monitor.h"

int main(struct multiboot *mboot_ptr)
{

  monitor_clear();
  memset_16bit(0xB8000,0x0F41,2000);
  //int i;
  //for(i = 0;i<50;i++)monitor_put('A');
  monitor_write("Hello, World!\r\n");
  monitor_write("This is a test\r");
  monitor_write_hex(255);
  monitor_write("\r");
  monitor_write_dec(255);
   
  return 0;
}
