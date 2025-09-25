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
#include <iomanip>

using namespace std;

void initializeArray(int array[][2], int xSize, int minBound) { // Sets up the array to
                                                                // store the processed data
    for (int i = 0; i < xSize; i++) { // Iterates across the "width" of the array
        array[i][0] = minBound + i; // Starts at the minimum bound and sets the first item in each
                                    // sub-array to the value of minBound plus the distance from the min
        array[i][1] = 0; // Initializes the amount of occurrences of each number to 0
    }
}

void readData(int data[][2], int xSize) { // Reads data from input, validates it, and stores it in the data array
    int readNumber;
    cin >> readNumber;
    while (cin) { // Loops until input is empty
        for (int i = 0; i < xSize; i++) {
            if (readNumber < data[0][0] || readNumber > data[xSize - 1][0]) { // Verifies that the number read
                                                                              // is within the specified bounds
                cout << "Error: value " << readNumber << " is out of range" << endl;
                break; // Exits the for loop
            }
            if (readNumber == data[i][0]) { // Looks through the array until it finds its container
                ++data[i][1]; // Increments the count of occurrences
                break; // Exits the for loop
            }
        }
        cin >> readNumber; // Reads a number from input
    }
}

void drawBars(int data[][2], int xSize) { // Draws the horizontal bars
    for (int i = xSize - 1; i >= 0; i--) { // Iterates through the array starting with the largest value
        cout << setw(3) << data[i][0] << " |"; // Prints the y-axis label
        for (int j = 0; j < data[i][1]; j++) { // Prints the correct amount of # per amount of occurrences
            cout << "#";
        }
        cout << endl;
    }
}

int getLongestBar(int data[][2], int xSize) { // Retrieves the size of the longest bar on the histogram
    int longestBar = 0;
    for (int i = 0; i < xSize; i++) { // Standard "max value" logic
        if (data[i][1] > longestBar) {
            longestBar = data[i][1];
        }
    }
    return longestBar;
}

void drawXAxis(int data[][2], int xSize) { // Draws the x-axis of the histogram
    int longestBar = getLongestBar(data, xSize); // Gets the length of the longest bar
    cout << "    +----+----+"; // Draws the default minimum width of 10
    longestBar -= 10;
    while (longestBar > 0) { // Repeats until we have drawn to a multiple of 10 past the longest bar
        cout << "----+----+";
        longestBar -= 10;
    }
    cout << endl;
}

void drawXAxisLabels(int data[][2], int xSize) { // Draws the labels for the x-axis
    int longestBar = getLongestBar(data, xSize); // Gets the length of the longest bar
    cout << "    0    5    10"; // Draws the default minimum width of 10
    longestBar -= 10;
    int labelNumber = 15; // Variable that increments by 5 for each tick mark
    while (longestBar > 0) { // Repeats until we have drawn to a multiple of 10 past the longest bar
        cout << "   " << labelNumber << "   " << labelNumber + 5; // Prints whitespace and the tick labels
        longestBar -= 10;
        labelNumber += 10;
    }
    cout << endl;
}

int main() {
    int minBound, maxBound;
    cin >> minBound >> maxBound;
    const int arrayWidth = maxBound - minBound + 1;
    int bars[arrayWidth][2];
    initializeArray(bars, arrayWidth, minBound);
    readData(bars, arrayWidth);
    drawBars(bars, arrayWidth);
    drawXAxis(bars, arrayWidth);
    drawXAxisLabels(bars, arrayWidth);
    return 0;
}