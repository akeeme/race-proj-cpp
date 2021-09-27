#include "Hare.h"
//File name: /Users/laptopuser/Documents/student_code/HareTortoise/TestHare.cpp
#include <iostream>
using namespace std;

int main()
{
    Hare rabbit;
    int* pattern = rabbit.getPattern();
    int length = rabbit.getPatternLength();
    for (int i = 0; i < length; i++)
        cout << pattern[i] << ", ";
    cout << endl;

    int rabbit2_pattern[] = {1, 2, 3, -1};
    int rabbit2_length = sizeof(rabbit2_pattern) / sizeof(int);
    Hare rabbit2(rabbit2_pattern, rabbit2_length, 2);
    int* pattern2 = rabbit2.getPattern();
    int length2 = rabbit2.getPatternLength();
    for (int i = 0; i < length2; i++)
        cout << pattern2[i] << ", ";
    cout << endl;
    
    int position = rabbit2.getPosition();
    cout << "position = " << position << endl;

    return 0;
}