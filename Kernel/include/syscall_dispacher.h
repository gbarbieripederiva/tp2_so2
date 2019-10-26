#ifndef _IRQ_DISPATCHER_H_
#define _IRQ_DISPATCHER_H_

#include <keyboard.h>
#include <stdint.h>
#include <graphics.h>
#include <rtc.h>
#include <sound.h>
#include <time.h>
#include <process.h>
#include <memoryManager.h>
#include <scheduler.h>


#define READ 3
#define WRITE 4
#define DRAW_PIXEL 5
#define X_RES 6
#define Y_RES 7
#define CLEAR_SCREEN 8
#define SHADOW_PIXEL 9
#define MOVE_EVERYTHING_UP 10
#define SWAP_BUFFERS 11
#define CLEAR_SHADOW_BUFFER 12
#define TIME 13
#define INIT_GRAPHICS 14
#define COLOR_WRITE 15
#define RESET_CURSOR 16
#define BEEP 17
#define SLEEP 18
#define NEW_LINE 19

int read(int param1, char * param2, int param3);
void write(int param1, char * param2, int param3);
void color_write(char * pointer, int size, int foreground_color, int background_color);
uint64_t sys_mem_get(long size);                          //SYS_CALL 45
int sys_mem_free(uint64_t chunk);                           //SYS_CALL 46
uint64_t sys_create_process(char * name, int priority, uint64_t process); //SYSCALL 47
int sys_run_process(uint64_t process, int state); //SYSCALL 48
int sys_kill_process(int pid); //SYSCAL 49
void sys_print_processes(); //SYSCALL 50

#endif
