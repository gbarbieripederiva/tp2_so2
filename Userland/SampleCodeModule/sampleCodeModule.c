#include <utilities.h>
#include <syscall.h>

uint64_t main() {
	uint64_t shellInfo = sys_create_process("shell", 1, shell);
	sys_run_process(shell, READY);
	return 0;
}
