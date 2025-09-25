//
//  CSC2210-003
//  Dr. Hasker
//  Fall 2025
//
//  Author: Anthony Higareda
//  SPA 2: Histograms
//  Created: 25 September 2025
//

#include <iostream>

using namespace std;

void initializeArray(int array[][2], int xSize, int minBound) { // Sets up the array to
                                                                // store the processed data
    for (int i = 0; i < xSize; i++) { // Iterates across the "width" of the array
        array[i][0] = minBound + i; // Starts at the minimum bound and sets the first item in each
                                    // sub-array to the value of minBound plus the distance from the min
        array[i][1] = 0; // Initializes the amount of occurrences of each number to 0
        cout << array[i][0] << " " << array[i][1] << endl; // TODO remove test prints
    }
}

void readData(int data[][2], int xSize) {
    while (cin) { // Loops until input is empty
        int readNumber;
        cin >> readNumber; // Reads a number from input
        for (int i = 0; i < xSize; i++) {
            if (readNumber < data[0][0] || readNumber > data[xSize - 1][0]) { // Verifies that the number read
                                                                              // is within the specified bounds
                cout << "Error: value of " << readNumber << " is out of range" << endl;
                break; // Exits the for loop
            } else if (readNumber == data[i][0]) { // Looks through the array until it finds its container
                ++data[i][1]; // Increments the count of occurrences
                break; // Exits the for loop
            }
        }
    }
}

int main() {
    int minBound, maxBound;
    cin >> minBound >> maxBound;
    const int arrayWidth = maxBound - minBound + 1;
    int bars[arrayWidth][2];
    cout << "Initializing Array..." << endl;
    initializeArray(bars, arrayWidth, minBound);
    readData(bars, arrayWidth);
    return 0;
}