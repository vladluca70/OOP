#include <iostream>

template <typename T>
class Vector {
private:
    T* vector;
    int length;
    int capacity;

public:
    Vector()
    {
        vector=nullptr;
        length=0;
        capacity=0;
    }

    Vector(const Vector<T>& other)
    {
        length=other.length;
        capacity=other.capacity;

        vector = new T[capacity];
        for (int i = 0; i < length; ++i) {
            vector[i] = other.vector[i];
        }
    }

    Vector(Vector<T>&& other)
    {
        vector=other.vector;
        length=other.length;
        capacity=other.capacity;

        other.vector = nullptr;
        other.length = 0;
        other.capacity = 0;
    }

    ~Vector() {
        delete[] vector;
    }

    Vector<T>& operator=(const Vector<T>& other)
    {
        if (this != &other)
        {
            delete[] vector;
            length = other.length;
            capacity = other.capacity;
            vector = new T[capacity];
            for (int i = 0; i < length; ++i)
                vector[i] = other.vector[i];
        }
        return *this;
    }

    Vector<T>& operator=(Vector<T>&& other)
    {
        if (this != &other)
        {
            delete[] vector;
            vector = other.vector;
            length = other.length;
            capacity = other.capacity;
            other.vector = nullptr;
            other.length = 0;
            other.capacity = 0;
        }
        return *this;
    }

    void insert(int index, const T& value)
    {
        if (index < 0 || index > length)
            throw std::out_of_range("Index out of bounds");

        if (length >= capacity) {
            int newCapacity = capacity == 0 ? 1 : capacity * 2;
            reserve(newCapacity);
        }

        for (int i = length; i > index; --i)
            vector[i] = std::move(vector[i - 1]);

        vector[index] = value;
        ++length;
    }

    void remove(int index) {
        if (index < 0 || index >= length)
             throw std::out_of_range("Index out of bounds");

        for (int i = index; i < length - 1; ++i)
            vector[i] = std::move(vector[i + 1]);

        --length;
    }

    void sort(int (*cmp)(const T&, const T&))
    {
        for (int i = 0; i < length - 1; ++i)
            for (int j = i + 1; j < length; ++j)
                if (cmp(vector[j], vector[i]) < 0)
                {
                    T temp = vector[i];
                    vector[i] = vector[j];
                    vector[j] = temp;
                }
    }

    void sort() {
        sort([](const T& a, const T& b) { return a < b; });
    }

    void print() const {
        for (int i = 0; i < length; ++i) {
            std::cout << vector[i] << " ";
        }
        std::cout << std::endl;
    }

    T& operator[](int index) {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return vector[index];
    }

private:
    void reserve(int newCapacity) {
        T* newVector = new T[newCapacity];
        for (int i = 0; i < length; ++i) {
            newVector[i] = std::move(vector[i]);
        }
        delete[] vector;
        vector = newVector;
        capacity = newCapacity;
    }
};

int compare_ints(const int& x, const int& y) {
    return x - y;
}

