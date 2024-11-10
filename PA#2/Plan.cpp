#include "plan.h"
#include <iostream>

using namespace std;

// Constructor
Plan::Plan(const vector<Formula>& initialFormulas)
        : formulas(initialFormulas) {}

// Copy Constructor
Plan::Plan(const Plan& other)
        : formulas(other.formulas) {}

// Move Constructor
Plan::Plan(Plan&& other) noexcept
        : formulas(move(other.formulas)) {}

// Copy Assignment Operator
Plan& Plan::operator=(const Plan& other) {
    if (this == &other) {
        return *this;
    }
    formulas = other.formulas;
    return *this;
}

// Move Assignment Operator
Plan& Plan::operator=(Plan&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    formulas = move(other.formulas);
    return *this;
}

// Destructor
Plan::~Plan() {
    // No dynamic resources, but clean-up would go here
}

// Add a new Formula to the end of the Plan
void Plan::addFormula(const Formula& formula) {
    formulas.push_back(formula);
}

// Remove the last Formula from the Plan
void Plan::removeLastFormula() {
    if (!formulas.empty()) {
        formulas.pop_back();
    }
}

// Replace a Formula at a given index
void Plan::replaceFormula(int index, const Formula& newFormula) {
    if (index >= 0 && index < formulas.size()) {
        formulas[index] = newFormula;
    }
}

// Get the size of the formula sequence
size_t Plan::size() const {
    return formulas.size();
}

// Apply all Formulas in the sequence
void Plan::applyAll() const {
    for (const auto& formula : formulas) {
        auto output = formula.apply();
        cout << "Applied Formula: " << endl;
        for (const auto& res : output) {
            cout << res.first << ": " << res.second << endl;
        }
    }
}

