#include "PlayerStats.h"
#include <iostream>
#include <memory>

PlayerStats::PlayerStats()
        : standState(StandState::Stand), activeWeaponSlot(0), sensitive(50), availableBullets(false) {}

void PlayerStats::SetAim(bool aim) {
    hold.Aim = aim;
}

void PlayerStats::SetFire(bool fire) {
    hold.Fire = fire;
}

void PlayerStats::SetWeapons(const std::vector<std::shared_ptr<Weapon>>& weapons) {
    this->weapons = weapons;
}

void PlayerStats::SetActiveWeapon(int slot) {
    if (slot <= 0 || slot > static_cast<int>(weapons.size())) {
        return;
    }
    activeWeaponSlot = slot;
}

std::pair<std::shared_ptr<Weapon>, bool> PlayerStats::GetActiveWeapon() const {
    if (activeWeaponSlot == 0 || weapons.empty() || activeWeaponSlot > static_cast<int>(weapons.size())) {
        return { nullptr, false };
    }
    return { weapons[activeWeaponSlot - 1], true };
}

PlayerStatsHold PlayerStats::Hold() const {
    return hold;
}

bool PlayerStats::ReadyRecoil() const {
    auto [activeWeapon, found] = GetActiveWeapon();
    return hold.Aim && hold.Fire && found;
}

double PlayerStats::GetStandFactor() const {
    switch (standState) {
        case StandState::Stand:
            return 1.0;
        case StandState::Sit:
            return 1.3;
        case StandState::Lie:
            return 1.8;
        default:
            return 1.0;
    }
}

StandState PlayerStats::GetStandState() const {
    return standState;
}

void PlayerStats::SetStandState(StandState state) {
    standState = state;
}

bool PlayerStats::IsAvailableBullets() const {
    return availableBullets;
}

void PlayerStats::SetAvailableBullets(bool available) {
    availableBullets = available;
}