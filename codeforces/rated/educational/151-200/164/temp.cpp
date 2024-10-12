#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigprof(int sig) {
    write(STDOUT_FILENO, "SIGPROF received\n", 17);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handle_sigprof;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGPROF, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Setup the ITIMER_PROF timer
    struct itimerval timer;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 100000; // Timer fires every 100 ms
    timer.it_value = timer.it_interval;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
