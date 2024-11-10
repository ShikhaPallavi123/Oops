// formula.cpp
//
// Created by Shikha Pallavi on 10/24/24.
//

#include "formula.h"
#include <cstdlib>
#include <ctime> // Not strictly needed here; can be removed
#include <random> // Include for random number generation

using namespace std;

// Constructor
Formula::Formula(const map<string, int>& inputs, const map<string, int>& outputs)
        : inputResources(inputs), outputResources(outputs), proficiencyLevel(0) {
    if (inputs.empty() || outputs.empty()) {
        throw invalid_argument("Input and output resources must not be empty.");
    }
}

// Copy Constructor
Formula::Formula(const Formula& other)
        : inputResources(other.inputResources), outputResources(other.outputResources), proficiencyLevel(other.proficiencyLevel) {}

// Move Constructor
Formula::Formula(Formula&& other) noexcept
        : inputResources(move(other.inputResources)),
          outputResources(move(other.outputResources)),
          proficiencyLevel(other.proficiencyLevel) {
    other.proficiencyLevel = 0; // Reset the moved-from object's proficiency level
}

// Copy Assignment Operator
Formula& Formula::operator=(const Formula& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }
    inputResources = other.inputResources;
    outputResources = other.outputResources;
    proficiencyLevel = other.proficiencyLevel;
    return *this;
}

// Move Assignment Operator
Formula& Formula::operator=(Formula&& other) noexcept {
    if (this == &other) {
        return *this; // Handle self-assignment
    }
    inputResources = move(other.inputResources);
    outputResources = move(other.outputResources);
    proficiencyLevel = other.proficiencyLevel;
    other.proficiencyLevel = 0; // Reset the moved-from object's proficiency level
    return *this;
}

// Destructor
Formula::~Formula() {
    // No dynamic resources to clean up in this case
}

// Getter for proficiency level
int Formula::getProficiencyLevel() const {
    return proficiencyLevel;
}

// Determines the outcome factor based on proficiency level and a random chance.
double Formula::DetermineOutcomeFactor(double chance) const {
    const double baseFailureRate = 0.25; // Base failure rate for proficiency level 0
    double adjustedFailureRate = baseFailureRate - (0.05 * proficiencyLevel);

    if (chance < adjustedFailureRate) {
        return 0; // Failure
    } else if (chance < adjustedFailureRate + 0.20) {
        return 0.75; // 75% output
    } else if (chance < adjustedFailureRate + 0.70) {
        return 1.0; // Normal output
    } else {
        return 1.10; // Bonus output
    }
}

// Method to apply the formula
map<string, int> Formula::apply() const {
    random_device rd; // Non-deterministic random number generator
    mt19937 gen(rd()); // Initialize Mersenne Twister generator
    uniform_real_distribution<double> dis(0.0, 1.0); // Distribution for [0.0, 1.0)

    double chance = dis(gen); // Get a random chance
    double outcomeFactor = DetermineOutcomeFactor(chance); // Determine outcome factor

    map<string, int> results;
    for (const auto& resource : outputResources) {
        int transformedQuantity = static_cast<int>(resource.second * outcomeFactor);
        results[resource.first] = transformedQuantity;
    }
    return results;
}

// Method to level up proficiency
void Formula::levelUp() {
    proficiencyLevel++;
}

// Get input resources
map<string, int> Formula::getInputResources() const {
    return inputResources;
}

// Get output resources
map<string, int> Formula::getOutputResources() const {
    return outputResources;
}
