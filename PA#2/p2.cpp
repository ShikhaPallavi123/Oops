////
//// Created by Shikha Pallavi on 10/24/24.
////
//
//#include "plan.h"
//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//    // Seed the random number generator for reproducibility
//    srand(0);
//
//    // Example formulas
//    map<string, int> inputs1 = { {"Iron", 10} };
//    map<string, int> outputs1 = { {"Steel", 5} };
//    Formula f1(inputs1, outputs1);
//
//    map<string, int> inputs2 = { {"Wood", 20} };
//    map<string, int> outputs2 = { {"Planks", 15} };
//    Formula f2(inputs2, outputs2);
//
//    // Creating a plan with initial formulas
//    vector<Formula> initialFormulas = { f1, f2 };
//    Plan plan(initialFormulas);
//
//    // Add a new formula
//    map<string, int> inputs3 = { {"Gold", 5} };
//    map<string, int> outputs3 = { {"Coins", 10} };
//    Formula f3(inputs3, outputs3);
//    plan.addFormula(f3);
//
//    // Replace a formula in the plan
//    map<string, int> inputs4 = { {"Copper", 8} };
//    map<string, int> outputs4 = { {"Bronze", 6} };
//    Formula f4(inputs4, outputs4);
//    plan.replaceFormula(1, f4);
//
//    // Apply all formulas in the plan
//    plan.applyAll();
//
//    // Copying a plan (deep copy)
//    Plan copiedPlan = plan;
//
//    // Moving a plan
//    Plan movedPlan = move(plan);
//
//    return 0;
//}



#include <iostream>
#include "formula.h"
#include "plan.h"

using namespace std;

int main() {
    // Create sample formulas
    Formula formula1({{"Wood", 5}}, {{"Planks", 15}}); // 5 Wood to produce 15 Planks
    Formula formula2({{"Iron", 2}}, {{"Nails", 10}});  // 2 Iron to produce 10 Nails
    Formula formula3({{"Stone", 4}}, {{"Bricks", 8}}); // 4 Stone to produce 8 Bricks

    // Initialize a plan with the first two formulas
    vector<Formula> initialFormulas = {formula1, formula2};
    Plan plan(initialFormulas); // Dependency injection of initial formulas

    // Apply all formulas in the plan
    cout << "Applying all formulas in the initial plan..." << endl;
    plan.applyAll();
    cout << endl;

    // Add a new formula to the end of the sequence
    cout << "Adding the third formula to the plan..." << endl;
    plan.addFormula(formula3);
    plan.applyAll();
    cout << endl;

    // Replace the first formula
    cout << "Replacing the first formula with the third formula..." << endl;
    plan.replaceFormula(0, formula3);
    plan.applyAll();
    cout << endl;

    // Remove the last formula
    cout << "Removing the last formula from the plan..." << endl;
    plan.removeLastFormula();
    plan.applyAll();
    cout << endl;

    // Demonstrate copy semantics
    Plan planCopy = plan; // Copy Constructor
    cout << "Demonstrating copying of Plan object via call by value:" << endl;
    planCopy.applyAll();
    cout << endl;

    // Demonstrate move semantics
    Plan planMove = move(plan); // Move Constructor
    cout << "Demonstrating moving of Plan object:" << endl;
    planMove.applyAll();
    cout << endl;

    // Verify that the original plan is now in a moved state (may not have formulas)
    cout << "Original plan after move operation has the following formulas:" << endl;
    cout << "Size of original plan: " << plan.size() << endl;

    return 0;
}


