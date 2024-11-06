//
// Created by admin on 6.11.24.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// 定义Muzzle类型，这里简单用一个枚举来表示不同的枪口类型，实际可根据需求扩展
enum class Muzzle {
    Compensator,
    Silencer,
    FlashHider
};

// 定义Grip类型，同样用一个枚举来表示不同的握把类型，实际可根据需求扩展
enum class Grip {
    VerticalGrip,
    Triangle,
    Light
};

// 定义RecoilOffset结构体，用于表示后坐力偏移量相关信息
struct RecoilOffset {
    int Interval;
    std::unordered_map<int, double> DelayIndexes;
    std::vector<float> DelayArr;
};

// 全局变量，用于存储不同武器的后坐力偏移量信息
std::unordered_map<std::string, RecoilOffset> RecoilOffsets = {
        {"AKM", {8, {{0, 5}, {450, 7}}, {}}},
        {"M416", {10, {{0, 5}, {550, 7.5}}, {}}},
        {"AUG", {8, {{0, 5}, {200, 4}, {350, 5}, {450, 8}, {750, 10}, {1000, 8}}, {}}},
        {"Beryl", {8, {{0, 6.6}, {350, 7}, {550, 9.5}}, {}}},
        {"QBZ", {10, {{0, 3.7}, {450, 7}}, {}}},
        {"ACE32", {10, {{0, 6}, {600, 9}}, {}}},
        {"G36C", {10, {{0, 4.29}, {150, 4.73}, {250, 5.18}, {350, 6.45}, {480, 6.24}, {550, 7.09}}, {}}},
        {"Vector", {10, {{0, 5.5}, {400, 10.5}}, {}}},
        {"P90", {20, {{0, 5.5}, {100, 8}, {250, 5}}, {}}},
        {"Groza", {10, {{0, 4.2}, {450, 5.6}, {550, 7}}, {}}},
};

// 全局变量，用于存储不同枪口的因子信息
std::unordered_map<Muzzle, double> MuzzleFactor = {
        {Muzzle::Compensator, 1.24}
};

// 全局变量，用于存储不同握把的因子信息
std::unordered_map<Grip, double> GripFactor = {
        {Grip::VerticalGrip, 1.25}
};