#include "common.h"

void outb(u16int port, u8int value)
{
  asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port)
{
  u8int ret;
  asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
  return ret;
}

u16int inw(u16int port)
{
  u16int ret;
  asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
  return ret;
}

void * memset(void * s, u8int c, u32int n)
{
  u32int i;
  u8int * ptr = s;

  for ( i = 0; i < n; i++, ptr++)
  {
    *ptr = c;
  }
  return s;
}

void * memset_16bit(void * s, u16int c, u32int n)
{
  u32int i;
  u16int * ptr = s;

  for ( i = 0; i < n; i++, ptr++)
  {
    *ptr = c;
  }
  return s;
}

void * memset_32bit(void * s, u32int c, u32int n)
{
  u32int i;
  u32int * ptr = s;

  for ( i = 0; i < n; i++, ptr++)
  {
    *ptr = c;
  }
  return s;
}

void * memcpy(void * dest, void * src, u32int n)
{
  u8int * d = (u8int*)dest;
  u8int * s = (u8int*)src;
  while(n--)
  {
    *d++ = *s++;
  }
  return dest;
}

