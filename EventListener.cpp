#include "EventListener.h"
#include <iostream>

HHOOK EventListener::keyboardHook = nullptr;
HHOOK EventListener::mouseHook = nullptr;
std::map<int, EventListener::Callback> EventListener::keyDownCallbacks;
std::map<int, EventListener::Callback> EventListener::keyUpCallbacks;
std::map<int, EventListener::Callback> EventListener::mouseClickCallbacks;
bool EventListener::running = false;

EventListener::EventListener() {}

EventListener::~EventListener() {
    Stop();
}

void EventListener::RegisterKeyDown(int keyCode, Callback callback) {
    keyDownCallbacks[keyCode] = callback;
}

void EventListener::RegisterKeyUp(int keyCode, Callback callback) {
    keyUpCallbacks[keyCode] = callback;
}

void EventListener::RegisterMouseClick(int mouseButton, Callback callback) {
    mouseClickCallbacks[mouseButton] = callback;
}

void EventListener::Start() {
    if (!running) {
        running = true;
        keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, nullptr, 0);
        mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, nullptr, 0);

        // Start a message loop to keep the hooks alive
        MSG msg;
        while (GetMessage(&msg, nullptr, 0, 0) && running) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}

void EventListener::Stop() {
    if (running) {
        running = false;
        UnhookWindowsHookEx(keyboardHook);
        UnhookWindowsHookEx(mouseHook);
    }
}

LRESULT CALLBACK EventListener::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT*)lParam;
        int keyCode = pKeyBoard->vkCode;

        if (wParam == WM_KEYDOWN && keyDownCallbacks.find(keyCode) != keyDownCallbacks.end()) {
            keyDownCallbacks[keyCode]();
        } else if (wParam == WM_KEYUP && keyUpCallbacks.find(keyCode) != keyUpCallbacks.end()) {
            keyUpCallbacks[keyCode]();
        }
    }
    return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

LRESULT CALLBACK EventListener::MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        if (wParam == WM_LBUTTONDOWN && mouseClickCallbacks.find(WM_LBUTTONDOWN) != mouseClickCallbacks.end()) {
            mouseClickCallbacks[WM_LBUTTONDOWN]();
        } else if (wParam == WM_RBUTTONDOWN && mouseClickCallbacks.find(WM_RBUTTONDOWN) != mouseClickCallbacks.end()) {
            mouseClickCallbacks[WM_RBUTTONDOWN]();
        }
    }
    return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}