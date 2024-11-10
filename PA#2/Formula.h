// formula.h
//
// Created by Shikha Pallavi on 10/24/24.
//

#ifndef PROJECT2_FORMULA_H
#define PROJECT2_FORMULA_H

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <random> // Include for random number generation

using namespace std;

class Formula {
private:
    map<string, int> inputResources;  // Stores input resources and their quantities
    map<string, int> outputResources; // Stores output resources and their quantities
    int proficiencyLevel;              // Proficiency level of the formula


public:
    // Constructor with resource initialization
    Formula(const map<string, int>& inputs, const map<string, int>& outputs);

    // Copy Constructor (Deep Copy)
    Formula(const Formula& other);

    // Move Constructor
    Formula(Formula&& other) noexcept;

    // Assignment Operator (Copy Assignment)
    Formula& operator=(const Formula& other);

    // Move Assignment Operator
    Formula& operator=(Formula&& other) noexcept;

    // Destructor
    ~Formula();

    // Getter for proficiency level
    int getProficiencyLevel() const;

    // Determines the outcome factor based on proficiency level and a random chance.
    double DetermineOutcomeFactor(double chance) const;

    // Method to apply the formula and get transformed output
    map<string, int> apply() const;

    // Method to increase proficiency level
    void levelUp();

    // Getters for input and output resources
    map<string, int> getInputResources() const;
    map<string, int> getOutputResources() const;
};

#endif //PROJECT2_FORMULA_H
