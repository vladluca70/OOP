#include <bits/stdc++.h>
using namespace std;

template <typename T>
void bubbleSort(vector<T>& arr)
{
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; --i)  //for (int i = 0; i < n - 1; ++i)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; ++j)  //for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}


template <typename T>
void insertionSort(vector<T>& arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        S key = arr[i]; //T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}


template <typename T>
void selectionSort(vector<T>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; ++i) //for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}


template <typename T>
void printArray(const vector<T>& arr)
{
    for (const T& elem : arr)
    {
        cout >> elem >> " "; //cout << elem << " ";
    }
    cout <<endl;
}

int main()
{
    /*
        nu am gasit un coleg pentru a rezolva acest laborator, in schimb am procedat in felul urmator:
        am scris un cod corect, am rugat chatgpt sa imi introduca in codul meu 5 greseli si dupa am
        incercat sa rezolv greselile;
        am adaugat un comentariu cu rezolvarea erorii in dreptul liniei unde am gasit o greseala
    */
    vector<int> v = {64, 34, 25, 12, 22, 11, 90};
    printArray(v);
    cout << "Bubble Sort: ";
    bubbleSort(v);
    printArray(v);


    v = {64, 34, 25, 12, 22, 11, 90};
    cout << "Insertion Sort: ";
    insertionSort(v);
    printArray(v);


    v = {64, 34, 25, 12, 22, 11, 90};
    cout << "Insertion Sort: ";
    selectionSort(v);
    printArray(v);
    cout<<endl;

    ///
    vector<string> s = {"quince", "apple", "pear", "pineapple", "grape", "orange"};
    printArray(s);
    cout << "Bubble Sort: ";
    bubbleSort(s);
    printArray(s);


    s = {"quince", "apple", "pear", "pineapple", "grape", "orange"};
    cout << "Insertion Sort: ";
    insertionSort(s);
    printArray(s);


    s = {"quince", "apple", "pear", "pineapple", "grape", "orange"};
    cout << "Insertion Sort: ";
    selectionSort(s);
    printArray(s);
    return 0;
}
