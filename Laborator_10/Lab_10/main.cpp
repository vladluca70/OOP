#include <iostream>
#include <exception>
#include <algorithm>
using namespace std;

// Custom exception classes
class OutOfBoundsException : public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};

class CapacityExceededException : public exception
{
    virtual const char* what() const throw()
    {
        return "Capacitatea listei a fost depasita!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
    int Current;
    T** List;
public:
    ArrayIterator() : Current(0), List(nullptr) {}
    ArrayIterator(T** list, int start) : List(list), Current(start) {}

    ArrayIterator& operator++()
    {
        ++Current;
        return *this;
    }

    ArrayIterator& operator--()
    {
        --Current;
        return *this;
    }

    bool operator==(ArrayIterator<T>& other)
    {
        return List == other.List && Current == other.Current;
    }

    bool operator!=(ArrayIterator<T>& other)
    {
        return !(*this == other);
    }

    T* GetElement()
    {
        return List[Current];
    }
};

template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array()
    {
        delete[] List;
    }

    Array(int capacity) : Capacity(capacity), Size(0)
    {
        List = new T*[Capacity];
    }

    Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size)
    {
        List = new T*[Capacity];
        for (int i = 0; i < Size; ++i)
        {
            List[i] = new T(*otherArray.List[i]);
        }
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= Size)
        {
            throw OutOfBoundsException();
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem)
    {
        if (Size >= Capacity)
        {
            throw CapacityExceededException();
        }
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem)
    {
        if (index < 0 || index > Size)
        {
            throw OutOfBoundsException();
        }
        if (Size >= Capacity)
        {
            throw CapacityExceededException();
        }
        for (int i = Size; i > index; --i)
        {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        ++Size;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        if (index < 0 || index > Size)
        {
            throw OutOfBoundsException();
        }
        if (Size + otherArray.Size > Capacity)
        {
            throw CapacityExceededException();
        }
        for (int i = Size - 1; i >= index; --i)
        {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; ++i)
        {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index)
    {
        if (index < 0 || index >= Size)
        {
            throw OutOfBoundsException();
        }
        delete List[index];
        for (int i = index; i < Size - 1; ++i)
        {
            List[i] = List[i + 1];
        }
        --Size;
        return *this;
    }

    bool operator=(const Array<T>& otherArray)
    {
        if (this != &otherArray)
        {
            delete[] List;
            Capacity = otherArray.Capacity;
            Size = otherArray.Size;
            List = new T*[Capacity];
            for (int i = 0; i < Size; ++i)
            {
                List[i] = new T(*otherArray.List[i]);
            }
        }
        return true;
    }

    void Sort()
    {
        std::sort(List, List + Size, [](T* a, T* b)
        {
            return *a < *b;
        });
    }

    void Sort(int(*compare)(const T&, const T&))
    {
        std::sort(List, List + Size, [compare](T* a, T* b)
        {
            return compare(*a, *b) < 0;
        });
    }

    void Sort(Compare* comparator)
    {
        std::sort(List, List + Size, [comparator](T* a, T* b)
        {
            return comparator->CompareElements(a, b) < 0;
        });
    }

    int BinarySearch(const T& elem)
    {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (*List[mid] == elem)
            {
                return mid;
            }
            if (*List[mid] < elem)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int compResult = compare(*List[mid], elem);
            if (compResult == 0)
            {
                return mid;
            }
            if (compResult < 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator)
    {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int compResult = comparator->CompareElements(List[mid], &elem);
            if (compResult == 0)
            {
                return mid;
            }
            if (compResult < 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }

    int Find(const T& elem)
    {
        for (int i = 0; i < Size; ++i)
        {
            if (*List[i] == elem)
            {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; ++i)
        {
            if (compare(*List[i], elem) == 0)
            {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& elem, Compare* comparator)
    {
        for (int i = 0; i < Size; ++i)
        {
            if (comparator->CompareElements(List[i], &elem) == 0)
            {
                return i;
            }
        }
        return -1;
    }

    int GetSize()
    {
        return Size;
    }

    int GetCapacity()
    {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(List, 0);
    }

    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(List, Size);
    }
};

int main()
{
    try
    {
        Array<int> arr(10);

        arr += 5;
        arr += 3;
        arr += 8;
        arr += 1;
        arr += 9;

        cout << "Array elements before sorting:" << endl;
        for (int i = 0; i < arr.GetSize(); ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        arr.Sort();
        cout << "Array elements after sorting:" << endl;
        for (int i = 0; i < arr.GetSize(); ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        int index = arr.BinarySearch(8);
        if (index != -1)
        {
            cout << "Element 8 found at index: " << index << endl;
        }
        else
        {
            cout << "Element 8 not found." << endl;
        }

        arr.Delete(2);
        cout << "Array elements after deletion:" << endl;
        for (int i = 0; i < arr.GetSize(); ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

    }
    catch (exception& e)
    {
        cout << "Exceptie: " << e.what() << endl;
    }

    return 0;
}
