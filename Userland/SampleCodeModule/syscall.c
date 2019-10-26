#include <syscall.h>

void sys_write(char * string, int size){
  _call_int_80((uint64_t) WRITE, 1, (uint64_t) string, (uint64_t)size, 0, 0);
}
char sys_read(char * string, int size){
  return _call_int_80(READ, 1, (uint64_t) string, size, 0, 0);
}

void sys_clear_console(){
	_call_int_80(CLEAR_SCREEN, 0,0,0,0,0);
}

void sys_draw_pixel(int x, int y, int r, int g, int b){
	_call_int_80((uint64_t)DRAW_PIXEL, (uint64_t)x,(uint64_t) y,(uint64_t) r,(uint64_t) g,(uint64_t) b);
}

void sys_shadow_pixel(int x, int y, int r, int g, int b){
	_call_int_80((uint64_t) SHADOW_PIXEL, (uint64_t)x,(uint64_t) y,(uint64_t) r,(uint64_t) g,(uint64_t) b);
}
int sys_time(int selector){
  return _call_int_80((uint64_t) TIME,(uint64_t) selector, 0,0,0,0);
}

void sys_swap_buffers(){
	_call_int_80((uint64_t) SWAP_BUFFERS, 0, 0, 0, 0, 0);
}

void sys_clear_shadow_buffer(){
	_call_int_80((uint64_t) CLEAR_SHADOW_BUFFER, 0, 0, 0, 0, 0);
}

void sys_color_write(char * string, int size, int foreground_color, int background_color){
	_call_int_80((uint64_t) COLOR_WRITE,(uint64_t) string,(uint64_t) size,(uint64_t) foreground_color,(uint64_t) background_color, 0);
}

void sys_reset_cursor(){
	_call_int_80((uint64_t) RESET_CURSOR, 0, 0, 0, 0, 0);
}


void sys_new_line(){
	_call_int_80((uint64_t) NEW_LINE, 0, 0, 0, 0, 0);
}

void sys_sleep(int ticks){
  _call_int_80((uint64_t) SLEEP,(uint64_t) ticks,0,0,0,0);
}

void sys_beep(){
  _call_int_80(BEEP,0,0,0,0,0);
}

//SYS_CALL 45, for memory management
void * sys_get_memory(long size){
	_call_int_80((uint64_t)45, size,0,0,0,0);
}

//SYS_CALL 46, for memory free
int *sys_mem_free(void * chunk){
	_call_int_80((uint64_t)46, chunk,0,0,0,0);
}

//SYS_CALL 47, to create a process
uint64_t sys_create_process(char * name, int priority, uint64_t process){
	_call_int_80((uint64_t)47, name,priority,process,0,0);
}
//SYS CALL 48, to put a process into the scheduler
int sys_run_process(uint64_t process, int state){
	_call_int_80((uint64_t)48, process, state,0,0,0);
}

//SYS CALL 49, to kill a running process
int sys_kill_process(int pid){
	_call_int_80((uint64_t)49, pid,0,0,0,0);
}

//SYS CALL 50, to print processes
void sys_print_processes(){
	_call_int_80((uint64_t)50, 0,0,0,0,0);
}