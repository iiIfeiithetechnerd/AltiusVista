#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void install_library(const char *library_name) {

    char command[512];

    #ifdef __linux__

        if (access("/usr/bin/pacman", F_OK) == 0) {

            snprintf(command, sizeof(command), "sudo pacman -S --noconfirm %s", library_name);

        } else if (access("/usr/bin/apt-get", F_OK) == 0) {

            snprintf(command, sizeof(command), "sudo apt-get install -y %s", library_name);

        } else {

            fprintf(stderr, "Error: No supported package manager found (pacman or apt-get).\n");
            exit(EXIT_FAILURE);

        }
    
    #else

        snprintf(command, sizeof(command), "venv\\bin\\pip install %s", library_name);

    #endif


    int result = system(command);
    if (result != 0) {

        fprintf(stderr, "Failed to install library: %s\n", library_name);
        exit(EXIT_FAILURE);

    }
}