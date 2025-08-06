#include <iostream>
//used for set precision, fixed
#include <iomanip>
using namespace std;

// Function prototypes and objects to be called in the Main
void enterGrades(float grades[], int& size);
void displayGrades(const float grades[], int size);
float calculateAverage(const float grades[], int size);
float findMax(const float grades[], int size);
float findMin(const float grades[], int size);
int countInRange(const float grades[], int size, float min, float max);
int searchGrade(const float grades[], int size, float target);

int main() {
    float grades[100];
    int size = 0;
    int choice;
//User display screen on which choice they will choose for grade display
    do {
        cout << "===============================" << endl;
        cout << "    Grade Management System    " << endl;
        cout << "===============================" << endl;
        cout << "1. Enter grades" << endl;
        cout << "2. Display all grades" << endl;
        cout << "3. Calculate average grade" << endl;
        cout << "4. Find highest and lowest grades" << endl;
        cout << "5. Count grades in a specific range" << endl;
        cout << "6. Search for a specific grade" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
//switch case to help which the choice of the grade display and user input
        switch (choice) {
            case 1:
                enterGrades(grades, size);
                break;
            case 2:
                displayGrades(grades, size);
                break;
            case 3:
                if (size > 0) {
                    cout << fixed << setprecision(2);
                    cout << "Average grade: " << calculateAverage(grades, size) << endl;
                } else {
                    cout << "No grades entered yet." << endl;
                }
                break;
            case 4:
                if (size > 0) {
                    cout << fixed << setprecision(2);
                    cout << "Highest grade: " << findMax(grades, size) << endl;
                    cout << "Lowest grade: " << findMin(grades, size) << endl;
                } else {
                    cout << "No grades entered yet." << endl;
                }
                break;
            case 5:
                if (size > 0) {
                    float minRange, maxRange;
                    cout << "Enter range (e.g., 60 79): ";
                    cin >> minRange >> maxRange;
                    int count = countInRange(grades, size, minRange, maxRange);
                    cout << "Grades in range: " << count << endl;
                } else {
                    cout << "No grades entered yet." << endl;
                }
                break;
            case 6:
                if (size > 0) {
                    float target;
                    cout << "Enter grade to search for: ";
                    cin >> target;
                    int index = searchGrade(grades, size, target);
                    if (index != -1) {
                        cout << "Grade found at position #" << index + 1 << endl;
                    } else {
                        cout << "Grade not found." << endl;
                    }
                } else {
                    cout << "No grades entered yet." << endl;
                }
                break;
            case 7:
                cout << "Exiting Grade Management System." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;

    } while (choice != 7);

    return 0;
}

void enterGrades(float grades[], int& size) {
    int num;
    cout << "How many grades to enter (max 100)? ";
    cin >> num;
    if (num <= 0 || num > 100) {
        cout << "Invalid number of grades." << endl;
        return;
    }
    size = num;
    for (int i = 0; i < size; i++) {
        float g;
        do {
            cout << "Enter grade #" << i + 1 << ": ";
            cin >> g;
            if (g < 0 || g > 100) {
                cout << "Invalid grade. Must be between 0 and 100." << endl;
            }
        } while (g < 0 || g > 100);
        grades[i] = g;
    }
}
//For choice #1 of entering the grades
void displayGrades(const float grades[], int size) {
    if (size == 0) {
        cout << "No grades to display." << endl;
        return;
    }
    cout << "Grades entered:" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < size; i++) {
        cout << "Grade #" << i + 1 << ": " << grades[i] << endl;
    }
}
//Choice #2 of finding the average
float calculateAverage(const float grades[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }
    return sum / size;
}
//Finding the highest grade
float findMax(const float grades[], int size) {
    float max = grades[0];
    for (int i = 1; i < size; i++) {
        if (grades[i] > max) {
            max = grades[i];
        }
    }
    return max;
}
//Finding the lowest grade
float findMin(const float grades[], int size) {
    float min = grades[0];
    for (int i = 1; i < size; i++) {
        if (grades[i] < min) {
            min = grades[i];
        }
    }
    return min;
}
//Choice #5 for finding which range you want to find for grade input
int countInRange(const float grades[], int size, float min, float max) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (grades[i] >= min && grades[i] <= max) {
            count++;
        }
    }
    return count;
}
//choice #6 for searching for a specific grade choice
int searchGrade(const float grades[], int size, float target) {
    for (int i = 0; i < size; i++) {
        if (grades[i] == target) {
            return i;
        }
    }
    return 0;
}
