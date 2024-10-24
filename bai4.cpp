#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to apply the Arnold's Cat Map transformation
void applyArnoldsCatMap(vector<vector<int>>& matrix, int m) {
    vector<vector<int>> temp(m, vector<int>(m)); // Temporary matrix to store results

    // Perform the transformation
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            int newX = (2 * i + j) % m; // Calculate new x position
            int newY = (i + j) % m;      // Calculate new y position
            temp[newX][newY] = matrix[i][j]; // Store the transformed value
        }
    }

    // Update the original matrix with the results from the temporary matrix
    matrix = temp;
}

// Function to check if the current matrix matches the original matrix
bool isOriginalMatrix(const vector<vector<int>>& matrix, const vector<vector<int>>& original, int m) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] != original[i][j]) {
                return false; // Return false if any element does not match
            }
        }
    }
    return true; // Return true if all elements match
}

// Main function
int main() {
    int m;
    cout << "Enter the size of the matrix (m): ";
    cin >> m;

    vector<vector<int>> matrix(m, vector<int>(m)); // Matrix to store the data
    vector<vector<int>> original(m, vector<int>(m)); // Original matrix to compare

    // Input the matrix data from the user
    cout << "Enter the matrix data:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            original[i][j] = matrix[i][j]; // Save the original matrix
        }
    }

    int k = 0; // Count of transformations
    do {
        applyArnoldsCatMap(matrix, m); // Apply the transformation
        k++; // Increment the transformation count
    } while (!isOriginalMatrix(matrix, original, m)); // Loop until the matrix returns to the original state

    cout << "The cycle period k is: " << k << endl; // Output the cycle period

    return 0;
 return 0;
}