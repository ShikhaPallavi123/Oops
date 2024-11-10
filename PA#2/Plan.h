//
// Created by Shikha Pallavi on 10/24/24.
//

#ifndef PROJECT2_PLAN_H
#define PROJECT2_PLAN_H

#include "formula.h"
#include <vector>

using namespace std;


class Plan {
private:
    vector<Formula> formulas;

public:
    // Constructor with dependency injection
    Plan(const vector<Formula>& initialFormulas);

    // Copy Constructor (Deep Copy)
    Plan(const Plan& other);

    // Move Constructor
    Plan(Plan&& other) noexcept;

    // Assignment Operator (Copy Assignment)
    Plan& operator=(const Plan& other);

    // Move Assignment Operator
    Plan& operator=(Plan&& other) noexcept;

    // Destructor
    ~Plan();

    // Add a new Formula to the end
    void addFormula(const Formula& formula);

    // Remove the last Formula
    void removeLastFormula();

    // Replace a Formula at a given index
    void replaceFormula(int index, const Formula& newFormula);

    // Get Formula sequence size
    size_t size() const;

    // Apply all Formulas in the Plan
    void applyAll() const;
};

#endif //PROJECT2_PLAN_H
