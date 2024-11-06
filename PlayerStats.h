#ifndef PLAYER_STATS_H
#define PLAYER_STATS_H

#include <vector>
#include <memory>
#include <string>
#include "Weapon.h"

// StandState 类型定义
enum class StandState {
    Stand,
    Sit,
    Lie
};

struct PlayerStatsHold {
    bool Aim = false;
    bool Fire = false;
};

class PlayerStats {
public:
    PlayerStats();
    void SetAim(bool aim);
    void SetFire(bool fire);
    void SetWeapons(const std::vector<std::shared_ptr<Weapon>>& weapons);
    void SetActiveWeapon(int slot);
    [[nodiscard]] std::pair<std::shared_ptr<Weapon>, bool> GetActiveWeapon() const;
    [[nodiscard]] PlayerStatsHold Hold() const;
    [[nodiscard]] bool ReadyRecoil() const;
    [[nodiscard]] double GetStandFactor() const;
    [[nodiscard]] StandState GetStandState() const;
    void SetStandState(StandState state);
    [[nodiscard]] bool IsAvailableBullets() const;
    void SetAvailableBullets(bool available);

private:
    std::vector<std::shared_ptr<Weapon>> weapons;
    PlayerStatsHold hold;
    StandState standState;
    int activeWeaponSlot;
    int sensitive;
    bool availableBullets;
};

#endif // PLAYER_STATS_H