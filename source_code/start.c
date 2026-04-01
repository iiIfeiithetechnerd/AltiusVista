#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const char *python_cmd = NULL;

bool check_reqs(void) {
    python_cmd = NULL;

#if defined(__unix__) || defined(__APPLE__)
    if (system("python3 --version >/dev/null 2>&1") == 0) {
        python_cmd = "python3";
    } else if (system("python --version >/dev/null 2>&1") == 0) {
        python_cmd = "python";
    }
#elif defined(_WIN32) || defined(_WIN64)
    if (system("python --version > NUL 2>&1") == 0) {
        python_cmd = "python";
    } else if (system("py --version > NUL 2>&1") == 0) {
        python_cmd = "py";
    }
#else
    fprintf(stderr, "Error: Unsupported platform. This application only supports Windows, macOS, and Linux.\n");
    exit(EXIT_FAILURE);
#endif

    return python_cmd != NULL;
}

int main(void) {
    if (!check_reqs()) {
        fprintf(stderr, "Error: Python is not installed or not found in PATH.\n");
        return EXIT_FAILURE;
    }

    printf("All requirements are met. Starting the application...\n");

    char command[256];
    if (snprintf(command, sizeof(command), "%s ./source_code/init.py", python_cmd) < 0) {
        fprintf(stderr, "Error: Failed to construct the Python command.\n");
        return EXIT_FAILURE;
    }

    if (system(command) != 0) {
        fprintf(stderr, "Error: Failed to execute %s.\n", python_cmd);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
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