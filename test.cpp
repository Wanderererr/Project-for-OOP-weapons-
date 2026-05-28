#include <iostream>
#include <cassert> 
#include <memory>

#include "Arsenal.cpp"
#include "MeleeWeapon.cpp"
#include "RangeWeapon.cpp"

void testWeaponInitialization() {
    std::cout << "Running Test 1: Weapon Initialization... ";

    Sword sword("Sting", 30, 1.5);
    Crossbow crossbow("Hunter", 70, 4.5, 5);

    assert(sword.getName() == "Sting");
    assert(sword.getDamage() == 30);

    assert(crossbow.getName() == "Hunter");
    assert(crossbow.getDamage() == 70);

    std::cout << "PASSED ✅\n";
}
void testArsenalSafety() {
    std::cout << "Running Test 2: Arsenal Runtime Safety... ";

    Arsenal testArsenal;

    testArsenal.fireActive(); 

    testArsenal.addWeapon(std::make_unique<BrassKnuckles>("Lead Knuckles", 15, 0.5));

    testArsenal.selectWeapon("Plasma Rifle");
    
    testArsenal.fireActive();

    std::cout << "PASSED ✅\n";
}

void testPolymorphism() {
    std::cout << "Running Test 3: Polymorphic Dispatches... ";

    Arsenal combatArsenal;

    combatArsenal.addWeapon(std::make_unique<Axe>("Orcish Cleaver", 55, 6.0));
    combatArsenal.addWeapon(std::make_unique<Bow>("Shortbow", 20, 1.0, 2));

    combatArsenal.fireActive(); 
    
    combatArsenal.selectWeapon("Shortbow");
    combatArsenal.fireActive(); 

    std::cout << "PASSED ✅\n";
}

int main() {
    std::cout << "===========================================\n";
    std::cout << "      RUNNING AUTOMATED OOP TESTS          \n";
    std::cout << "===========================================\n\n";

    testWeaponInitialization();
    testArsenalSafety();
    testPolymorphism();

    std::cout << "\n===========================================\n";
    std::cout << "🎉 HOORAY! All assertions passed smoothly! \n";
    std::cout << "The project architecture is stable and reliable. \n";
    std::cout << "===========================================\n";

    return 0;
}
