#include <utilities.h>
#include <syscall.h>

uint64_t main() {
	print_f("In sample Code");
	sys_print_processes();
	uint64_t shellInfo = sys_create_process("shell", 1, shell);
	sys_run_process(shell, READY);
	return 0;
}
