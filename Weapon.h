// Weapon.h
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <unordered_map>
#include <vector>

// 定义 Muzzle 枚举类，表示不同的枪口类型
enum class Muzzle {
    Compensator,
    Silencer,
    FlashHider
};

// 定义 Grip 枚举类，表示不同的握把类型
enum class Grip {
    VerticalGrip,
    Triangle,
    Light
};

// 定义 RecoilOffset 结构体，用于表示后坐力偏移量相关信息
struct RecoilOffset {
    int Interval;
    std::unordered_map<int, double> DelayIndexes;
    std::vector<float> DelayArr;
};

// 全局变量：存储不同武器的后坐力偏移量信息
extern std::unordered_map<std::string, RecoilOffset> RecoilOffsets;

// 全局变量：存储不同枪口的因子信息
extern std::unordered_map<Muzzle, double> MuzzleFactor;

// 全局变量：存储不同握把的因子信息
extern std::unordered_map<Grip, double> GripFactor;

// Weapon 类定义
class Weapon {
public:
    Weapon(std::string  name);
    [[nodiscard]] RecoilOffset GetOffsetNew() const;
    [[nodiscard]] RecoilOffset GetOffset() const;
    [[nodiscard]] double GetMuzzleFactor() const;
    [[nodiscard]] double GetGripFactor() const;

private:
    std::string name;
    Muzzle muzzle;
    Grip grip;
};

#endif // WEAPON_H