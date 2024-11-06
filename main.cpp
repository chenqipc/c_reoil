#include <iostream>
#include <uiohook.h>

bool ctrlPressed = false;
bool rightPressed = false;
bool leftPressed = false;

void handleEvent(uiohook_event *event) {
    switch (event->type) {
        case EVENT_KEY_PRESSED:
            if (event->data.keyboard.keycode == VC_TAB) {
                std::cout << "Tab pressed: scanning started\n";
                // 设置扫描状态
            } else if (event->data.keyboard.keycode == VC_CONTROL_L || event->data.keyboard.keycode == VC_CONTROL_R) {
                ctrlPressed = true;
            } else if (event->data.keyboard.keycode == VC_1) {
                if (!ctrlPressed) {
                    std::cout << "Weapon 1 selected\n";
                    // 设置为武器1
                }
            } else if (event->data.keyboard.keycode == VC_2) {
                if (!ctrlPressed) {
                    std::cout << "Weapon 2 selected\n";
                    // 设置为武器2
                }
            } else if (event->data.keyboard.keycode == VC_C) {
                std::cout << "C key pressed: toggle stance\n";
                // 切换站立状态
            } else if (event->data.keyboard.keycode == VC_Z) {
                std::cout << "Z key pressed: toggle prone\n";
                // 切换趴下状态
            } else if (event->data.keyboard.keycode == VC_SPACE) {
                std::cout << "Space pressed: standing up\n";
                // 切换成站立状态
            }
            break;

        case EVENT_KEY_RELEASED:
            if (event->data.keyboard.keycode == VC_CONTROL_L || event->data.keyboard.keycode == VC_CONTROL_R) {
                ctrlPressed = false;
            }
            break;

        case EVENT_MOUSE_PRESSED:
            if (event->data.mouse.button == MOUSE_BUTTON1) { // 左键
                leftPressed = true;
                std::cout << "Mouse left button pressed: Fire\n";
                // 设置射击状态
            } else if (event->data.mouse.button == MOUSE_BUTTON3) { // 右键
                rightPressed = true;
                std::cout << "Mouse right button pressed: Aim\n";
                // 设置瞄准状态
            }
            break;

        case EVENT_MOUSE_RELEASED:
            if (event->data.mouse.button == MOUSE_BUTTON1) { // 左键
                leftPressed = false;
                std::cout << "Mouse left button released: Stop firing\n";
                // 停止射击
            } else if (event->data.mouse.button == MOUSE_BUTTON3) { // 右键
                rightPressed = false;
                std::cout << "Mouse right button released: Stop aiming\n";
                // 停止瞄准
            }
            break;

        default:
            break;
    }
}

int main() {
    // 初始化 libuiohook
    if (hook_run() != UIOHOOK_SUCCESS) {
        std::cerr << "Failed to initialize uiohook!" << std::endl;
        return -1;
    }

    // 注册事件处理函数
    hook_set_dispatch_proc(handleEvent);

    // 启动事件钩子循环
    hook_run();

    // 当循环结束时注销钩子
    hook_stop();
    return 0;
}