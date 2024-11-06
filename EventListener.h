#pragma once

#ifdef _WIN32
#include <windows.h>
#endif
#include <functional>
#include <map>

class EventListener {
public:
    using Callback = std::function<void()>;

    EventListener();
    ~EventListener();

    void RegisterKeyDown(int keyCode, Callback callback);
    void RegisterKeyUp(int keyCode, Callback callback);
    void RegisterMouseClick(int mouseButton, Callback callback);

    void Start();
    void Stop();

private:
    static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);

    static HHOOK keyboardHook;
    static HHOOK mouseHook;

    static std::map<int, Callback> keyDownCallbacks;
    static std::map<int, Callback> keyUpCallbacks;
    static std::map<int, Callback> mouseClickCallbacks;

    static bool running;
};