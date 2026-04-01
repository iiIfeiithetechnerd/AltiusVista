#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool init;

bool check_reqs(void) {

    bool python_found = false;

    #if defined(__unix__) || defined(__APPLE__)

        if (system("python3 --version >/dev/null 2>&1") == 0 ||
            system("python --version >/dev/null 2>&1") == 0) {
            python_found = true;
        } else {
            python_found = false;
        }

    #elif defined(_WIN32) || defined(_WIN64)

        if (system("python --version > NUL 2>&1") == 0 ||
            system("py --version > NUL 2>&1") == 0) {
            python_found = true;
        } else {
            python_found = false;
        }

    #else

        // unsupported platform 
        fprintf(stderr, "Error: Unsupported platform. This application only supports Windows, macOS, and Linux.\n");
        exit(EXIT_FAILURE);

    #endif

        return python_found;

}

int main(void) {

    init = check_reqs();

    if (init == false) {

        fprintf(stderr, "Error: Python is not installed or not found in PATH.\n");
        return EXIT_FAILURE;

    } else {

        printf("All requirements are met. Starting the application...\n");

    #if defined(__unix__) || defined(__APPLE__)

        if (system("python3 --version >/dev/null 2>&1") == 0) {
            system("python3 ./source_code/init.py");

        } else if (system("python --version >/dev/null 2>&1") == 0) {

            system("python ./source_code/init.py");

        } else {

            fprintf(stderr, "Error: Python interpreter not found.\n");
            return EXIT_FAILURE;

        }
    #elif defined(_WIN32) || defined(_WIN64)

        if (system("python --version > NUL 2>&1") == 0) {

            system("python ./source_code/init.py");

        } else if (system("py --version > NUL 2>&1") == 0) {

            system("py ./source_code/init.py");

        } else {

            fprintf(stderr, "Error: Python interpreter not found.\n");
            return EXIT_FAILURE;

        }

    #else

        fprintf(stderr, "Error: Unsupported platform. This application only supports Windows, macOS, and Linux.\n");
        return EXIT_FAILURE;
        
    #endif

    }

    return EXIT_SUCCESS;
}