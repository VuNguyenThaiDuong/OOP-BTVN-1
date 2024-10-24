#include <iostream>
#include <limits>

using namespace std;

// Struct to represent a fraction
struct Fraction {
    int numerator;   // The numerator of the fraction
    int denominator; // The denominator of the fraction
};

// Function to input a fraction from the user
// Input: A reference to a Fraction object
// Output: User will input a valid numerator and denominator
void inputFraction(Fraction &frac) {
    cout << "Enter numerator: ";
    cin >> frac.numerator;
    
    // Loop until a valid denominator is entered
    do {
        cout << "Enter denominator (cannot be 0): ";
        cin >> frac.denominator;
        if (frac.denominator == 0) {
            cout << "Denominator cannot be 0. Please enter again." << endl;
        }
    } while (frac.denominator == 0);
}

// Function to compare two fractions and return true if first is less than second
// Input: Two Fraction objects
// Output: true if first fraction is less than second, otherwise false
bool isLessThan(Fraction frac1, Fraction frac2) {
    return frac1.numerator * frac2.denominator < frac2.numerator * frac1.denominator;
}

// Function to find the smallest and largest fractions in an array
// Input: An array of Fractions and the number of fractions
// Output: The smallest and largest fractions found
void findMinMaxFractions(Fraction fractions[], int n, Fraction &minFrac, Fraction &maxFrac) {
    minFrac = fractions[0]; // Initialize minFrac to the first fraction
    maxFrac = fractions[0]; // Initialize maxFrac to the first fraction

    for (int i = 1; i < n; ++i) {
        if (isLessThan(fractions[i], minFrac)) {
            minFrac = fractions[i]; // Update minFrac if current is smaller
        }
        if (isLessThan(maxFrac, fractions[i])) {
            maxFrac = fractions[i]; // Update maxFrac if current is larger
        }
    }
}

// Main function to drive the program
int main() {
    int n;
    cout << "Enter the number of fractions: ";
    cin >> n;

    Fraction* fractions = new Fraction[n]; // Dynamically allocate array of fractions

    // Input fractions from the user
    for (int i = 0; i < n; ++i) {
        cout << "Fraction " << i + 1 << ":" << endl;
        inputFraction(fractions[i]);
    }

    Fraction minFrac, maxFrac;
    findMinMaxFractions(fractions, n, minFrac, maxFrac);

    // Output the results
    cout << "Smallest fraction: " << minFrac.numerator << "/" << minFrac.denominator << endl;
    cout << "Largest fraction: " << maxFrac.numerator << "/" << maxFrac.denominator << endl;

    delete[] fractions; // Free the allocated memory
    return 0;
}