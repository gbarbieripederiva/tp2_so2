#include <syscall_dispacher.h>
// usamos la convencion de linux y c para los parametros de las syscalls
uint64_t syscall_dispacher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t r9) {
  switch(rdi){
      case READ:
        read(rsi,(char *)rdx,rcx);
        break;
      case WRITE:
        write(rsi,(char *) rdx, rcx);
        break;
      case DRAW_PIXEL:
        draw_pixel(rsi,rdx,rcx,r8,r9);
        break;
      case X_RES:
        return get_x_res();
      case Y_RES:
        return get_y_res();
      case CLEAR_SCREEN:
        clear_screen();
        break;
      case TIME:
        return get_time(rsi);
      case SHADOW_PIXEL:
        shadow_pixel(rsi, rdx, rcx, r8, r9);
        break;
      case MOVE_EVERYTHING_UP:
        move_everything_up();
        break;
      case SWAP_BUFFERS:
        swap_buffers();
        break;
      case CLEAR_SHADOW_BUFFER:
        clear_shadow_buffer();
        break;
      case INIT_GRAPHICS:
        init_graphics();
        break;
      case COLOR_WRITE:
        color_write((char *)rsi, rdx, rcx,r8);
        break;
      case RESET_CURSOR:
        reset_cursor();
        break;
      case BEEP:
        beep();
        break;
      case SLEEP:
        time_wait(rsi);
        break;
      case NEW_LINE:
        new_line();
        break;
      case 45:
		      return (uint64_t) sys_mem_get((long)rsi);
          break;
        //sys_mem_free: frees memory
      case 46:
          return (int) sys_mem_free((uint64_t) rsi);
          break;
        //sys_create_process: Creates and registers new process
      case 47:
          return (uint64_t) sys_create_process((char *)rsi, (int) rdx, (uint64_t)rcx); 
          break;
        //sys_run_process: Puts process into scheduler with state READY, BLOCKED, HALT
      case 48:
          return (int) sys_run_process((uint64_t) rsi, (int) rdx);
          break;
        //sys_kill_process: stops iterating process from scheduler
      case 49:
          return (int) sys_kill_process((int) rsi);
          break;
      case 50:
          sys_print_processes();
          break;

  }
	return 0;
}
void color_write(char * pointer, int size, int foreground_color, int background_color){
  draw_n_chars_color(pointer,size,foreground_color,background_color);
}

int read(int fd, char * pointer, int size) {
  char c;
  for(int i=0; i<size; i++){
    c=get_char();
    if(c==EOF){
      pointer[i]=c;
      return i;
    }
    pointer[i]=c;
  }
  return size;
}

void write(int fd, char * pointer, int size) {
  // por ahora solo implementamos por salida estandar (en nuestro caso pantalla), y el numero de salida estandar es 1
	if(fd==STD_OUT)
    draw_n_chars_color(pointer,size, OUT_FG_COLOR, OUT_BG_COLOR);
  if(fd==STD_ERR)
    draw_n_chars_color(pointer,size,ERR_FG_COLOR, OUT_BG_COLOR);
  else
    return;
}

//SYSCALL 45 get memory
//TODO
uint64_t sys_mem_get(long size){
	return (uint64_t) giveMeMemory(size);
}

//SYSCALL 46 free memory
int sys_mem_free(uint64_t chunk){
	return (int)unGiveMeMemory((void *)chunk);
}
//SYSCALL 47 creates a new process
uint64_t sys_create_process(char * name, int priority, uint64_t process){
	return (uint64_t) create_process(name, priority, process);
}
//SYSCALL 48 runs a process
int sys_run_process(uint64_t process, int state){
	return run_process((processInfo)process, state);
}
//SYSCALL 49 kills a running process
int sys_kill_process(int pid){
	return kill_process(pid);
}

//SYSCALL 50 prints all running processes
void sys_print_processes(){
	print_running_procs();
}