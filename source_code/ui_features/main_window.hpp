#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <windows.h>
#include <string>
#include <iostream>

class MainWindow {
public:
    MainWindow(HINSTANCE hInstance = GetModuleHandleW(nullptr))
        : hInstance(hInstance), width(800), height(600), title(L"AltiusVista"), hwnd(nullptr), button(nullptr)
    {
        WNDCLASSW wc = {};
        wc.lpfnWndProc = MainWindow::WndProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = windowClassName;
        wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
        wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);

        if (!RegisterClassW(&wc)) {
            std::cerr << "RegisterClassW failed\n";
            return;
        }

        hwnd = CreateWindowExW(
            0,
            windowClassName,
            title.c_str(),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            width,
            height,
            nullptr,
            nullptr,
            hInstance,
            this);

        if (!hwnd) {
            std::cerr << "CreateWindowExW failed\n";
            return;
        }

        SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

        button = CreateWindowExW(
            0,
            L"BUTTON",
            L"Click Me",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
            10,
            10,
            100,
            30,
            hwnd,
            reinterpret_cast<HMENU>(1),
            hInstance,
            nullptr);
    }

    void show() {
        if (hwnd) {
            ShowWindow(hwnd, SW_SHOWDEFAULT);
            UpdateWindow(hwnd);

            MSG msg;
            while (GetMessageW(&msg, nullptr, 0, 0)) {
                TranslateMessage(&msg);
                DispatchMessageW(&msg);
            }
        }
    }

private:
    HINSTANCE hInstance;
    HWND hwnd;
    HWND button;
    int width;
    int height;
    std::wstring title;
    static constexpr const wchar_t* windowClassName = L"AltiusVistaWindow";

    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        MainWindow* self = reinterpret_cast<MainWindow*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
        switch (msg) {
            case WM_COMMAND:
                if (LOWORD(wParam) == 1) {
                    std::cout << "Button clicked!" << std::endl;
                }
                return 0;
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
        }
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
};

#endif // WINDOW_HPP