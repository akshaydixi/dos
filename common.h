#ifndef COMMON_H
#define COMMON_H

typedef unsigned int u32int;
typedef int s32int;
typedef unsigned short u16int;
typedef short s16int;
typedef unsigned char u8int;
typedef char s8int;

void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);
void* memset(void* s,u8int c,u32int n);
void* memset_16bit(void* s,u16int c,u32int n);
void* memset_32bit(void* s,u32int c,u32int n);
void* memcpy(void* dest, void* src, u32int n);
#endif  //COMMON_H
