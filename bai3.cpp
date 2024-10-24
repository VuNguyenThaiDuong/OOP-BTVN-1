#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Struct to represent a fraction
struct Fraction {
    int numerator;   // The numerator
    int denominator; // The denominator

    // Function to calculate the value of the fraction
    double value() const {
        return static_cast<double>(numerator) / denominator;
    }

    // Function to check if two fractions are equal
    bool isEqual(const Fraction &other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }
};

// Function to find subsets that multiply to a target fraction
// Input: vector of fractions, target fraction, current subset, index
// Output: Prints the first valid subset found
void findSubset(vector<Fraction> &fractions, Fraction target, vector<Fraction> &current, int index) {
    if (index == fractions.size()) {
        return; // Base case
    }

    // Calculate the product of the current subset
    Fraction product = {1, 1}; // Initialize product to 1/1
    for (const auto &frac : current) {
        product.numerator *= frac.numerator;
        product.denominator *= frac.denominator;
    }

    // Check if the product matches the target
    if (product.isEqual(target)) {
        // Sort the current subset and print it
        sort(current.begin(), current.end(), [](const Fraction &a, const Fraction &b) {
            return a.value() < b.value(); // Sort by value
        });

        for (const auto &frac : current) {
            cout << frac.numerator << "/" << frac.denominator << " ";
        }
        cout << endl;
        return; // Stop after finding the first valid subset
    }

    // Explore further including the current fraction
    current.push_back(fractions[index]);
    findSubset(fractions, target, current, index + 1);
    current.pop_back(); // Backtrack

    // Explore further without including the current fraction
    findSubset(fractions, target, current, index + 1);
}

// Main function
int main() {
    int n;
    cout << "Enter the number of fractions: ";
    cin >> n;

    vector<Fraction> fractions(n); // Array to store fractions

    // Input fractions from the user
    for (int i = 0; i < n; ++i) {
        cout << "Fraction " << i + 1 << " (numerator/denominator): ";
        char slash; // To handle the input format a/b
        cin >> fractions[i].numerator >> slash >> fractions[i].denominator;
    }

    Fraction target;
    cout << "Enter target fraction (numerator/denominator): ";
    char slash; // To handle the input format a/b
    cin >> target.numerator >> slash >> target.denominator;

    vector<Fraction> currentSubset; // To store the current subset
    findSubset(fractions, target, currentSubset, 0); // Find the subset

    return 0;
}