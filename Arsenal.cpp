#pragma once
#include "Weapon.cpp"
#include <vector>
#include <memory>
#include <iostream>

// ============================================================================
// ARSENAL MANAGER
// ============================================================================
class Arsenal {
private:
    std::vector<std::unique_ptr<Weapon>> weapons;
    Weapon* activeWeapon;

public:
    Arsenal() : activeWeapon(nullptr) {}

    void addWeapon(std::unique_ptr<Weapon> newWeapon) {
        std::cout << "📦 Added to arsenal: " << newWeapon->getName() << "\n";
        if (weapons.empty()) {
            activeWeapon = newWeapon.get(); // Equip automatically if it's the first item
        }
        weapons.push_back(std::move(newWeapon));
    }

    void selectWeapon(const std::string& weaponName) {
        for (const auto& w : weapons) {
            if (w->getName() == weaponName) {
                activeWeapon = w.get();
                std::cout << "🎯 Equipped: " << activeWeapon->getName() << "\n";
                return;
            }
        }
        std::cout << "❌ Weapon \"" << weaponName << "\" is not available in your arsenal!\n";
    }

    void fireActive() {
        if (activeWeapon) {
            activeWeapon->attack(); // Polymorphic dispatch runtime invocation
        } else {
            std::cout << "🔕 Your hands are empty!\n";
        }
    }

    void showAll() const {
        std::cout << "\n--- ARSENAL INVENTORY --- \n";
        for (const auto& w : weapons) {
            std::cout << "- " << w->getName() << " (Base Damage: " << w->getDamage() << ")\n";
        }
        std::cout << "-------------------------\n";
    }
};