#pragma once
#include "Weapon.cpp"
#include <iostream>
class RangedWeapon : public Weapon {
protected:
    int maxAmmo;
    int currentAmmo;
    std::string ammoName; 

public:
    RangedWeapon(std::string name, int damage, double weight, int maxAmmo, std::string ammo)
        : Weapon(name, damage, weight), maxAmmo(maxAmmo), currentAmmo(maxAmmo), ammoName(ammo) {}

    void reload() {
        currentAmmo = maxAmmo;
        std::cout << "🔄 " << name << " reloaded. Loaded fresh " << ammoName << " [" << currentAmmo << " pcs.]\n";
    }
};

class Pistol : public RangedWeapon {
public:
    Pistol(std::string name, int damage, double weight, int maxAmmo)
        : RangedWeapon(name, damage, weight, maxAmmo, "bullets") {}

    void attack() override {
        if (currentAmmo > 0) {
            currentAmmo--;
            std::cout << "💥 BANG! " << name << " fires a round! Damage: " << baseDamage 
                      << ". Remaining bullets: " << currentAmmo << "\n";
        } else {
            std::cout << "⚠️ *Click*! " << name << " is out of ammunition!\n";
        }
    }
};

class Bow : public RangedWeapon {
public:
    Bow(std::string name, int damage, double weight, int maxAmmo)
        : RangedWeapon(name, damage, weight, maxAmmo, "arrows") {}

    void attack() override {
        if (currentAmmo > 0) {
            currentAmmo--;
            std::cout << "🏹 *Whiz!* " << name << " looses a deadly arrow! Damage: " 
                      << baseDamage << ". Remaining arrows: " << currentAmmo << "\n";
        } else {
            std::cout << "🪶 You draw the string of " << name << ", but your quiver is empty!\n";
        }
    }
};

class Crossbow : public RangedWeapon {
public:
    Crossbow(std::string name, int damage, double weight, int maxAmmo)
        : RangedWeapon(name, damage, weight, maxAmmo, "bolts") {}

    void attack() override {
        if (currentAmmo > 0) {
            currentAmmo--;
            std::cout << "🏹 *CLICK!* The heavy latch of " << name << " releases a bolt! Massive damage: " 
                      << baseDamage * 1.3 << ". Remaining bolts: " << currentAmmo << "\n";
        } else {
            std::cout << "⚠️ The mechanism of " << name << " is empty. A bolt must be loaded.\n";
        }
    }
};
