#include "Number.h"
#include <iostream>
#include <cstring>

Number::Number(const char *value, int base)
{
    initialize(value, base);
}

Number::Number(int value)
{
    char str[20];
    itoa(value, str, 10);
    initialize(str, 10);
}

Number::Number(const Number &other)
{
    initialize(other.value, other.base);
}

Number::Number(Number &&other)
{
    value = other.value;
    base = other.base;
    size = other.size;

    other.value = nullptr;
    other.size = 0;
}

Number::~Number()
{
    delete[] value;
}

Number& Number::operator=(const Number &other)
{
    if (this != &other)
    {
        delete[] value;
        initialize(other.value, other.base);
    }
    return *this;
}

Number& Number::operator=(Number &&other)
{
    if (this != &other)
    {
        delete[] value;
        value = other.value;
        base = other.base;
        size = other.size;

        other.value = nullptr;
        other.size = 0;
    }
    return *this;
}

Number Number::operator+(const Number &other) const
{
    int maxBase = std::max(base, other.base);
    Number result("0", maxBase);

    int carry = 0;
    int i = size - 1;
    int j = other.size - 1;
    int k = result.size - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0) sum += (value[i--] - '0');
        if (j >= 0) sum += (other.value[j--] - '0');

        result.value[k--] = (sum % 10) + '0';
        carry = sum / 10;
    }

    return result;
}

Number Number::operator-(const Number &other) const
{
    int maxBase = std::max(base, other.base);
    Number result("0", maxBase);

    int borrow = 0;
    int i = size - 1;
    int j = other.size - 1;
    int k = result.size - 1;

    while (i >= 0 || j >= 0)
    {
        int diff = borrow;
        if (i >= 0) diff += (value[i--] - '0');
        if (j >= 0) diff -= (other.value[j--] - '0');

        if (diff < 0)
        {
            diff += maxBase;
            borrow = -1;
        }
        else
        {
            borrow = 0;
        }

        result.value[k--] = (diff % maxBase) + '0';
    }

    while (result.size > 1 && result.value[result.size - 1] == '0')
    {
        result.resize(result.size - 1);
    }

    return result;
}

bool Number::operator>(const Number &other) const
{
    if (base != other.base)
    {
        Number temp = *this;
        temp.SwitchBase(std::max(base, other.base));
        Number tempOther = other;
        tempOther.SwitchBase(std::max(base, other.base));
        return temp > tempOther;
    }

    if (size != other.size)
    {
        return size > other.size;
    }

    for (int i = 0; i < size; ++i)
    {
        if (value[i] != other.value[i])
        {
            return value[i] > other.value[i];
        }
    }

    return false;
}

bool Number::operator<(const Number &other) const
{
    return !(*this == other || *this > other);
}

bool Number::operator>=(const Number &other) const
{
    return (*this > other) || (*this == other);
}

bool Number::operator<=(const Number &other) const
{
    return (*this < other) || (*this == other);
}

bool Number::operator==(const Number &other) const
{
    if (base != other.base || size != other.size)
    {
        return false;
    }

    for (int i = 0; i < size; ++i)
    {
        if (value[i] != other.value[i])
        {
            return false;
        }
    }

    return true;
}

char Number::operator[](int index) const
{
    return value[index];
}

Number& Number::operator--()
{
    if (size == 1)
    {
        value[0] = '0';
    }
    else
    {
        for (int i = 0; i < size - 1; ++i)
        {
            value[i] = value[i + 1];
        }
        resize(size - 1);
    }
    return *this;
}

Number Number::operator--(int)
{
    Number temp(*this);
    --(*this);
    return temp;
}

Number& Number::operator+=(const Number &other)
{
    *this = *this + other;
    return *this;
}

void Number::SwitchBase(int newBase)
{
    //n -> baza10
    int decimalValue = 0;
    int power = 1;
    for (int i = size - 1; i >= 0; --i)
    {
        int digitValue = value[i] >= 'A' ? value[i] - 'A' + 10 : value[i] - '0';
        decimalValue += digitValue * power;
        power *= base;
    }

    //n -> newBase
    delete[] value;
    value = new char[20];
    int index = 0;
    do
    {
        int remainder = decimalValue % newBase;
        value[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        decimalValue /= newBase;
    }
    while (decimalValue != 0);

    //pal
    for (int i = 0; i < index / 2; ++i)
    {
        char temp = value[i];
        value[i] = value[index - i - 1];
        value[index - i - 1] = temp;
    }

    size = index;
    base = newBase;
}


void Number::Print() const
{
    std::cout << "Value: " << value << ", Base: " << base << std::endl;
}

int Number::GetDigitsCount() const
{
    return size;
}

int Number::GetBase() const
{
    return base;
}

void Number::initialize(const char *value, int base)
{
    this->base = base;
    this->size = strlen(value);
    this->value = new char[size + 1];
    strcpy(this->value, value);
}

void Number::resize(int newSize)
{
    char *temp = new char[newSize + 1];
    strcpy(temp, value);
    delete[] value;
    value = temp;
    size = newSize;
}
