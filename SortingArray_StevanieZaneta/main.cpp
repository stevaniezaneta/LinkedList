#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdio>

using namespace std;

string inputFileName = "input-a1q1.txt";
string outFileName = "output-a1q1.txt";

void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

bool asc(int a, int b) {
    return a < b;
}

bool desc(int a, int b) {
    return b < a;
}

void doBubbleSort(vector<int> & numberVector, int sortType )
{
bool swapped;
for (int i = 0; i < numberVector.size() - 1; i++)
{
    swapped = false;
    for (int j = 0; j < numberVector.size() - i - 1; j++)
    {
        if (sortType == 0) {
            if (numberVector[j] > numberVector[j+1]) {
                swap(&numberVector[j], &numberVector[j + 1]);
            swapped = true;
            }
        }
        else {
            if (numberVector[j] < numberVector[j + 1]) {
                swap(&numberVector[j], &numberVector[j + 1]);
                swapped = true;
            }
        }
    }
    if (swapped == false)
        break;
}
}

void doStlSort(vector<int>& numberVector, int sortType) {
    if (sortType == 0) {
        sort(numberVector.begin(), numberVector.end(), asc);
    }
    else {
        sort(numberVector.begin(), numberVector.end(), desc);
    }
}

int main()
{
    ifstream file;
    file.open(inputFileName);
    clock_t startTime = clock();

    if (!file) {
        cout << "Error unable open file";
    }

    string textLine;

    int i = 0;

    int sortType = 0;
    int isBestCase = 0;
    int size = 0;
    string delimiter = " ";
    vector<int> numberVector;

    while (getline(file, textLine)) {
        if (i == 0) {
            sortType = stoi(textLine);
        }
        if (i == 1) {
            isBestCase = stoi(textLine);
        }
        if (i == 2) {
            size = stoi(textLine);
            if (size < 0) {
                cerr << "size input cannot be lower than 0";
                return 0;
            }
        }
        if (i == 3) {
            stringstream ss(textLine);
            int number;
            while (ss >> number) {
                numberVector.push_back(number);
            }
        }
        i++;
    }
    file.close();

    if (sortType != 0 && sortType != 1) {
        cout << "Error you input wrong sort type, sort type only contains 0 or 1";
        return 0;
    }

    if (size != numberVector.size()) {
        cout << "Given size number and number array are not same";
        return 0;
    }

    if (isBestCase == 0) {
        doBubbleSort(numberVector, sortType);
    }
    else {
        doStlSort(numberVector, sortType);
    }
    double time;
    time = (double) (clock() - startTime)/CLOCKS_PER_SEC;

    for (int i = 0; i < numberVector.size(); i++) {
        cout << "Sorted: " << numberVector[i] << endl;
    }

    ofstream outputFile;
    outputFile.open(outFileName);
    outputFile << time << endl;
    for (int i = 0 ; i < numberVector.size() ; i++) {
        outputFile << numberVector[i] << " ";
}
  
  return(0);
}