#include <windows.h>
#include <stdio.h>

int main() {

    char command[] = "cmd.exe /c venv\\bin\\pip install -r requirements.txt";

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Installing required libraries...\n");

    if (!CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {

        fprintf(stderr, "Error: Failed to create process for installing libraries. Error code: %lu\n", GetLastError());
        return 1;

    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);

    if (exitCode == 0) {

        printf("Libraries installed successfully.\n");
        system("venv\\bin\\python ./source_code/init.py");

    } else {

        fprintf(stderr, "Error: Failed to install libraries. Process exited with code %lu\n", exitCode);

    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}