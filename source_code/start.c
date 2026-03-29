#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_reqs(void) {
    bool python_found = false;

    #if defined(__unix__) || defined(__APPLE__)
        if (system("python3 --version >/dev/null 2>&1") == 0 ||
            system("python --version >/dev/null 2>&1") == 0) {
            python_found = true;
        }
    #elif defined(_WIN32) || defined(_WIN64)
        if (system("python --version > NUL 2>&1") == 0 ||
            system("py --version > NUL 2>&1") == 0) {
            python_found = true;
        }
    #else
        // unsupported platform 
    #endif

        return python_found;
}

int main(void) {
    if (!check_reqs()) {
        fprintf(stderr, "Error: Python is not installed or not found in PATH.\n");
        return EXIT_FAILURE;
    }

    printf("All requirements are met. Starting the application...\n");

    return EXIT_SUCCESS;
}