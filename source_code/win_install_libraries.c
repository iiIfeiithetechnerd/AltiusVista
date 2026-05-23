#include <windows.h>
#include <stdio.h>
#include <sys/stat.h>

int directory_exists(const char* path) {
    struct stat info;
    if (stat(path, &info) != 0) return 0;
    return (info.st_mode & S_IFDIR) != 0;
}

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    
    printf("Creating virtual environment...\n");
    if (system("python -m venv venv") != 0) {
        fprintf(stderr, "Error: Python is not installed or not in your system PATH.\n");
        return 1;
    }

    if (!directory_exists("venv")) {
        fprintf(stderr, "Error: Virtual environment directory was not created.\n");
        return 1;
    }

    printf("Installing required libraries...\n");
    
    char command[MAX_PATH] = "cmd.exe /k venv\\Scripts\\python.exe -m pip install -r requirements.txt";


    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcessA(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Error: Failed to initiate process. Windows Error code: %lu\n", GetLastError());
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    if (exitCode == 0) {
        printf("Libraries installed successfully.\n");
        printf("Running initialization script...\n");
        system("venv\\Scripts\\python.exe init.py");
    } else {
        fprintf(stderr, "Error: Installation process exited with code %lu\n", exitCode);
    }

    return 0;
}
