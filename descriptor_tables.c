#include "common.h"
#include "descriptor_tables.h"

extern void gdt_flush(u32int);
extern void idt_flush(u32int);
static void int init_gdt();
static void gdt_set_gate(s32int,u32int,u32int,u8int,u8int);

gdt_entry_t gdt_entries[5];
gdt_ptr_t gdt_ptr;
idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;

void init_descriptor_tables(){
  init_gdt();
}

static void init_gdt()
{
  gdt_ptr.limit = (sizeof(gdt_entry t) * 5) - 1;
  gdt_ptr.base = (u32int)&gdt_entries;

  gdt_set_gate(0,0,0,0,0);
  gdt_set_gate(1,0,0xFFFFFFFF,0x9A,0xCF);
  gdt_set_gate(2,0,0xFFFFFFFF,0x92,0xCF);
  gdt_set_gate(3,0,0xFFFFFFFF,0xFA,0xCF);
  gdt_set_gate(4,0,0xFFFFFFFF,0xF2,0xCF);

  gdt_flush((u32int)&gdt_ptr);
}


static void gdt_set_gate(s32int num,u32int base, u32int limit,u8int access, u8int gran)
{
  gdt_entries[num].base_low = (base & 0xFFFF);
  gdt_entries[num].base_middle = (base >> 16) & 0xFF;
  gdt_entries[num].base_high = (base >> 24) & 0xFF;
  gdt_entries[num].limit_low = (limit & 0xFFFF);
  gdt_entries[num].granularity |= gran & 0xF0;
  gdt_entries[num].access = access;
}
