#include <unistd.h>
#include <signal.h>

int main() {
    kill(getpid(), SIGABRT);
}
