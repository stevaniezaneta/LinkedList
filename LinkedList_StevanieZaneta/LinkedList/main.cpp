#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <time.h>

using namespace std;

struct Node {
    int value;
    struct Node* next;
};

struct Node* headBeginning = NULL;
void insertNodeAtBeginning(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = headBeginning;
    headBeginning = newNode;
}

void deleteFromBeginning() {
    struct Node* temp;
    struct Node* ptr;
    ptr = headBeginning;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

struct Node* head = NULL;
struct Node* tail = NULL;
void insertNodeAtEnd(int value) {
    if (head == NULL && tail == NULL) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->value = value;
        newNode->next = NULL;
        head = tail = newNode;
        return;
    }
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void deleteFromEnd() {
    struct Node* temp;
    struct Node* ptr;
    ptr = head;
    while (head != NULL) {
        while (ptr->next != tail) {
            ptr = ptr->next;
        }
        temp = tail;
        tail = ptr;
        if (head == tail) {
            temp = ptr;
            head = tail = NULL;
            free(temp);
        }
        else {
            free(temp);
        }
        ptr = head;
    }
}

string inputFileName = "input-a1q2.txt";
char outputFileName[] = "output-a1q2.txt";

int main() {

    ifstream file;

    file.open(inputFileName);

    string textLine;

    int size = 0;

    int i = 0;

    while (getline(file, textLine)) {
        if (i == 0) {
            size = stoi(textLine);
        }
    }
    file.close();

    clock_t startTimeAtBeginning = clock();

    for (int i = 0; i < size; i++) {
        insertNodeAtBeginning(i);
    }

    double timeAtBeginning = (double)(clock() - startTimeAtBeginning) / CLOCKS_PER_SEC;

    clock_t startTimeAtNode = clock();

    for (int i = 0; i < size; i++) {
        insertNodeAtEnd(i);
    }

    double timeAtNode = (double)(clock() - startTimeAtNode) / CLOCKS_PER_SEC;

    clock_t startDeleteTimeAtNode = clock();
    deleteFromBeginning();
    double deleteTimeAtNode = (double)(clock() - startDeleteTimeAtNode) / CLOCKS_PER_SEC;

    clock_t startDeleteTimeAtEnd = clock();
    deleteFromEnd();
    double deleteTimeAtEnd = (double)(clock() - startDeleteTimeAtEnd) / CLOCKS_PER_SEC;

    FILE* fileOutput;
    fopen_s(&fileOutput, outputFileName, "w");
    fprintf_s(fileOutput, "%.4f\n", timeAtBeginning);
    fprintf_s(fileOutput, "%.4f\n", timeAtNode);
    fprintf_s(fileOutput, "%.4f\n", deleteTimeAtNode);
    fprintf_s(fileOutput, "%.4f\n", deleteTimeAtEnd);

    return 0;
}