#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void install_libraries() {

    #ifdef __linux__

    system("python3 -m venv ./venv");
    system("./venv/bin/python -m pip install -r requirements.txt");

    #else

    system("venv\\Scripts\\pip install -r requirements.txt");

    #endif
    
}

int main() {

    install_libraries();
    return 0;

}
