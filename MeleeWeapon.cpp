#pragma once
#include "Weapon.cpp"
#include <iostream>
#include <algorithm>
class MeleeWeapon : public Weapon {
protected:
    int durability; 

public:
    MeleeWeapon(std::string name, int damage, double weight, int durability)
        : Weapon(name, damage, weight), durability(durability) {}

    void repair(int amount) {
        durability = std::min(100, durability + amount);
        std::cout << "🛠️ " << name << " repaired. Durability: " << durability << "%\n";
    }
};

class Sword : public MeleeWeapon {
public:
    Sword(std::string name, int damage, double weight)
        : MeleeWeapon(name, damage, weight, 100) {}

    void attack() override {
        if (durability <= 0) {
            std::cout << "❌ " << name << " is dull! Attack deals minimal damage.\n";
            return;
        }
        durability -= 10;
        std::cout << "⚔️ Blade slashes! " << name << " deals " << baseDamage << " slashing damage.\n";
    }
};

class Axe : public MeleeWeapon {
public:
    Axe(std::string name, int damage, double weight)
        : MeleeWeapon(name, damage, weight, 100) {}

    void attack() override {
        if (durability <= 0) { std::cout << "❌ The shaft of " << name << " snapped!\n"; return; }
        durability -= 20; // Degrades twice as fast as a sword
        std::cout << "🪓 Crushing blow! " << name << " shatters shields, dealing " 
                  << baseDamage * 1.5 << " physical damage! [Durability: " << durability << "%]\n";
    }
};

class Spear : public MeleeWeapon {
public:
    Spear(std::string name, int damage, double weight)
        : MeleeWeapon(name, damage, weight, 100) {}

    void attack() override {
        if (durability <= 0) { std::cout << "❌ The tip of " << name << " is bent!\n"; return; }
        durability -= 5; // High durability retention
        std::cout << "🔱 Swift thrust! " << name << " pierces the enemy from a distance, dealing " 
                  << baseDamage << " piercing damage. [Durability: " << durability << "%]\n";
    }
};

class Saber : public MeleeWeapon {
public:
    Saber(std::string name, int damage, double weight)
        : MeleeWeapon(name, damage, weight, 100) {} 

    void attack() override {
        if (durability <= 0) { std::cout << "❌ The edge of " << name << " is severely chipped!\n"; return; }
        durability -= 12; 
        std::cout << "🗡️ Lightning slash! " << name << " cuts through the enemy at close range, dealing " 
                  << baseDamage << " slashing damage. [Durability: " << durability << "%]\n";
    }
};
class BrassKnuckles : public MeleeWeapon {
public:
    BrassKnuckles(std::string name, int damage, double weight)
        : MeleeWeapon(name, damage, weight, 100) {}

    void attack() override {
        if (durability <= 0) { std::cout << "❌ The straps on " << name << " broke!\n"; return; }
        durability -= 2; // Extremely low degradation rate
        std::cout << "👊 HEAVY HOOK! " << name << " crushes the enemy's jaw, dealing " 
                  << baseDamage << " bludgeoning damage! [Durability: " << durability << "%]\n";
    }
};
