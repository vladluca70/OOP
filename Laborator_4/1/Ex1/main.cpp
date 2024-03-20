#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
    Sort test1(5, 10, 20);
    test1.Print();
    cout << endl;
    test1.BubbleSort(false);
    test1.Print();
    cout << endl;

    Sort test2({ 9, 6, 3, 2, 10, 4 });
    cout << endl;
    test2.Print();


    int v[] = { 3, 5, 1, 0, 8};
    Sort test3(v, 5);
    cout << endl;
    test3.Print();
    cout << endl;
    test3.InsertSort(false);
    test3.Print();

    Sort test4(1, 2, 4, 3, 10);
    cout << endl;
    test4.Print();
    cout << endl;
    test4.QuickSort(false);
    test4.Print();

    Sort test5("10,40,100,5,70");
    cout << endl;
    test5.Print();

    return 0;
}

