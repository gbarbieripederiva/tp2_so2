#ifndef _SYSCALL_H
#define _SYSCALL_H

#define BLOCKED 0
#define READY 1

#include <stdint.h>
#include <call_int_80.h>

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

void sys_write(char * string, int size);
char sys_read(char * string, int size);
void sys_clear_console();
void sys_draw_pixel(int x, int y, int r, int g, int b);
void sys_shadow_pixel(int x, int y, int r, int g, int b);
void sys_swap_buffers(void);
void sys_clear_shadow_buffer();
void sys_color_write(char * string, int size, int foreground_color, int background_color);
void sys_reset_cursor(void);
void sys_beep(void);
void sys_sleep(int ticks);
void sys_new_line(void);
int sys_time(int selector);
//SYS_CALL 45, for memory management
uint64_t sys_get_memory(long size);

//SYS_CALL 46, for memory free
int *sys_mem_free(void * chunk);

//SYS_CALL 47, to create a process
uint64_t sys_create_process(char * name, int priority, uint64_t process);

//SYS CALL 48, to put a process into the scheduler
int sys_run_process(uint64_t process, int state);

//SYS CALL 49, to kill a running process
int sys_kill_process(int pid);

//SYS CALL 50, to print processes
void sys_print_processes();

#endif
