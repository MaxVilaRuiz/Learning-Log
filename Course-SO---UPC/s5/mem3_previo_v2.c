#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int *p;

static void segv_handler(int sig, siginfo_t *si, void *unused) {
    char buff[] = "Segmentation fault (SIGSEGV)\n";
    (void)unused;
    (void)sig;
    write(1, buff, strlen(buff));

    _exit(128 + SIGSEGV);
}

void Usage(char *arg) {
    char buf[128];

    sprintf(buf, "%s: parametros invalidos\n%s: usage: %s\n", arg, arg, arg);
    write(2, buf, strlen(buf));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    char buff[256];

    if (argc != 1) Usage(argv[0]);

    // Configurar el tratamiento del signal
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = segv_handler;
    sa.sa_flags = SA_SIGINFO;  
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    sprintf(buff, "Dirección de p: %p\n", &p);
    write(1, buff, strlen (buff));
    sprintf(buff, "Valor de p: %p\n", p);
    write(1, buff, strlen (buff));

    *p = 5;

    exit(EXIT_SUCCESS);
}
