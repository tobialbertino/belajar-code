#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

// #define SIGHUP      1
// #define SIGINT      2   // interrupt
// #define SIGQUIT     3   // quit
// #define SIGILL      4   // illegal instruction
// #define SIGTRAP     5
// #define SIGABRT     6
// #define SIGBUS      7
// #define SIGFPE      8
// #define SIGKILL     9
// #define SIGUSR1     10
// #define SIGSEGV     11
// #define SIGUSR2     12
// #define SIGPIPE     13
// #define SIGALRM     14
// #define SIGTERM     15
// #define SIGSTKFLT   16
// #define SIGCHLD     17
// #define SIGCONT     18   // continue
// #define SIGSTOP     19   // stop, unblockable
// #define SIGTSTP     20
// #define SIGTTIN     21
// #define SIGTTOU     22
// #define SIGURG      23
// #define SIGXCPU     24
// #define SIGXFSZ     25
// #define SIGVTALRM   26
// #define SIGPROF     27
// #define SIGWINCH    28
// #define SIGPOLL     29
// #define SIGPWR      30
// #define SIGSYS      31


int main() {
	pid_t child = fork();
	if (child == 0) {       // child process
		while(1) {
			puts("child");
			sleep(1);
		}
	}
	else {                  // parent proses
		sleep(4);					// sleep parent selama 4 detik membiarkan child jalan selama 4 detik
		kill(child, SIGSTOP);		// mengirim sinyal SIGSTOP ke child untuk menghentikan proses pada child
		sleep(3);					// sleep parent selama 3 detik memberi jeda selama 3 detik
		kill(child, SIGCONT);		// mengirim sinyal SIGCONT ke child untuk melanjutkan proses pada child
		sleep(2);					// sleep parent selama 2 detik membiarkan child jalan selama 2 detik
		kill(child, SIGTERM);		// Terminate
	}
return 0;
}
