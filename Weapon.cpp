// Weapon.cpp
#include "Weapon.h"

#include <utility>

// 初始化全局变量
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
        {"Groza", {10, {{0, 4.2}, {450, 5.6}, {550, 7}}, {}}}
};

std::unordered_map<Muzzle, double> MuzzleFactor = {
        {Muzzle::Compensator, 1.24}
};

std::unordered_map<Grip, double> GripFactor = {
        {Grip::VerticalGrip, 1.25}
};

// Weapon 构造函数
Weapon::Weapon(std::string name) : name(std::move(name)), muzzle(Muzzle::Compensator), grip(Grip::VerticalGrip) {}

// 获取新的后坐力偏移量
RecoilOffset Weapon::GetOffsetNew() const {
    auto it = RecoilOffsets.find(name);
    if (it != RecoilOffsets.end()) {
        return it->second;
    }
    return {}; // 返回默认的 RecoilOffset
}

// 获取后坐力偏移量
RecoilOffset Weapon::GetOffset() const {
    auto it = RecoilOffsets.find(name);
    if (it != RecoilOffsets.end()) {
        return it->second;
    }
    return {}; // 返回默认的 RecoilOffset
}

// 获取枪口倍率因子
double Weapon::GetMuzzleFactor() const {
    auto it = MuzzleFactor.find(muzzle);
    if (it != MuzzleFactor.end()) {
        return it->second;
    }
    return 1.0; // 默认值
}

// 获取握把倍率因子
double Weapon::GetGripFactor() const {
    auto it = GripFactor.find(grip);
    if (it != GripFactor.end()) {
        return it->second;
    }
    return 1.0; // 默认值
}