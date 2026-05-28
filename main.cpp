#include <iostream>
#include "Arsenal.cpp"
#include "MeleeWeapon.cpp"
#include "RangeWeapon.cpp"

int main() {
    Arsenal heroArsenal;

    std::cout << "=== INITIALIZING ARMORY CONTENT ===\n";
    
    // Storing various weapon types into our polymorphically safe collection
    heroArsenal.addWeapon(std::make_unique<Sword>("Excalibur", 40, 2.5));
    heroArsenal.addWeapon(std::make_unique<Axe>("Executioner's Axe", 60, 5.0));
    heroArsenal.addWeapon(std::make_unique<Spear>("Spartan Spear", 35, 1.8));
    
    heroArsenal.addWeapon(std::make_unique<Pistol>("Glock-19", 25, 0.9, 10));
    heroArsenal.addWeapon(std::make_unique<Bow>("Elven Bow", 30, 1.2, 3));
    heroArsenal.addWeapon(std::make_unique<Crossbow>("Steel Crossbow", 55, 4.0, 1));

    heroArsenal.showAll();

    std::cout << "\n=== EXECUTION: MELEE COMBAT SYSTEM ===\n";
    
    heroArsenal.selectWeapon("Executioner's Axe");
    heroArsenal.fireActive();
    
    heroArsenal.selectWeapon("Spartan Spear");
    heroArsenal.fireActive();

    std::cout << "\n=== EXECUTION: RANGED COMBAT SYSTEM ===\n";

    heroArsenal.selectWeapon("Elven Bow");
    heroArsenal.fireActive();
    heroArsenal.fireActive();

    heroArsenal.selectWeapon("Steel Crossbow");
    heroArsenal.fireActive(); // Fires the single loaded bolt
    heroArsenal.fireActive(); // Triggers empty weapon exception log

    return 0;
}