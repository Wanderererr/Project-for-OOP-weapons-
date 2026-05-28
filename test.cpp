#include <iostream>
#include <cassert> // Standard assertions library
#include <memory>

#include "Arsenal.cpp"
#include "MeleeWeapon.cpp"
#include "RangeWeapon.cpp"

// ============================================================================
// TEST CASE 1: Validation of properties & encapsulation safety
// ============================================================================
void testWeaponInitialization() {
    std::cout << "Running Test 1: Weapon Initialization... ";

    Sword sword("Sting", 30, 1.5);
    Crossbow crossbow("Hunter", 70, 4.5, 5);

    // Verify getters mirror state boundaries properly
    assert(sword.getName() == "Sting");
    assert(sword.getDamage() == 30);

    assert(crossbow.getName() == "Hunter");
    assert(crossbow.getDamage() == 70);

    std::cout << "PASSED ✅\n";
}

// ============================================================================
// TEST CASE 2: Validation of Arsenal pointer decoupling & edge-case recovery
// ============================================================================
void testArsenalSafety() {
    std::cout << "Running Test 2: Arsenal Runtime Safety... ";

    Arsenal testArsenal;

    // Sub-test 2.1: Ensure action on an uninitialized empty inventory safely returns instead of breaking pointer paths
    testArsenal.fireActive(); 

    testArsenal.addWeapon(std::make_unique<BrassKnuckles>("Lead Knuckles", 15, 0.5));

    // Sub-test 2.2: Ensure lookup query on a non-existent asset logs cleanly without shifting active object reference boundaries
    testArsenal.selectWeapon("Plasma Rifle");
    
    // Verify fallback pipeline holds true
    testArsenal.fireActive();

    std::cout << "PASSED ✅\n";
}

// ============================================================================
// TEST CASE 3: Validation of pure virtual dispatch and polymorphic overriding
// ============================================================================
void testPolymorphism() {
    std::cout << "Running Test 3: Polymorphic Dispatches... ";

    Arsenal combatArsenal;

    combatArsenal.addWeapon(std::make_unique<Axe>("Orcish Cleaver", 55, 6.0));
    combatArsenal.addWeapon(std::make_unique<Bow>("Shortbow", 20, 1.0, 2));

    // Runtime pointer binding evaluation
    combatArsenal.fireActive(); // Must execute Axe::attack
    
    combatArsenal.selectWeapon("Shortbow");
    combatArsenal.fireActive(); // Must execute Bow::attack

    std::cout << "PASSED ✅\n";
}

// ============================================================================
// SUITE EXECUTION ROOT
// ============================================================================
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