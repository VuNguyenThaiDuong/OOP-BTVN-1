#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to represent a rectangle
struct Rectangle {
    int x; // Top-left corner x-coordinate
    int y; // Top-left corner y-coordinate
    int w; // Width of the rectangle
    int h; // Height of the rectangle
};

// Function to find rectangles in a binary matrix
void findRectangles(const vector<vector<int>>& matrix, vector<Rectangle>& rectangles, int m, int n) {
    // Iterate through each cell in the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Check if we found a top-left corner of a rectangle
            if (matrix[i][j] == 1) {
                // Find the width of the rectangle
                int width = 0;
                while (j + width < n && matrix[i][j + width] == 1) {
                    width++;
                }
                // Find the height of the rectangle
                int height = 0;
                bool validRectangle = true;
                while (i + height < m && validRectangle) {
                    for (int w = 0; w < width; ++w) {
                        if (matrix[i + height][j + w] != 1) {
                            validRectangle = false;
                            break;
                        }
                    }
                    if (validRectangle) {
                        height++;
                    }
                }
                // Only add rectangles of size at least 2x2
                if (width >= 2 && height >= 2) {
                    rectangles.push_back({j, i, width, height});
                }
                // Move to the right of the rectangle
                j += width - 1; // Skip to the end of the rectangle
            }
        }
    }
}

// Main function
int main() {
    int m, n;
    cout << "Enter the dimensions of the matrix (m n): ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n)); // Binary matrix

    // Input the binary matrix
    cout << "Enter the binary matrix (0s and 1s):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<Rectangle> rectangles; // To store found rectangles
    findRectangles(matrix, rectangles, m, n); // Find rectangles

    // Output the found rectangles
    cout << "Found rectangles (x, y, width, height):" << endl;
    for (const auto& rect : rectangles) {
        cout << "[" << rect.x << ", " << rect.y << ", " << rect.w << ", " << rect.h << "]" << endl;
    }

    return 0;
}