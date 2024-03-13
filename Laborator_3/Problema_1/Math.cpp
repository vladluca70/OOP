#include "Math.h"
#include <cstdarg>
//#include <cstring>

int Math::Add(int a, int b)
{
    return a + b;
}

int Math::Add(int a, int b, int c)
{
    return a + b + c;
}

int Math::Add(double a, double b)
{
    return int(a + b);
}

int Math::Add(double a, double b, double c)
{
    return int(a + b + c);
}

int Math::Mul(int a, int b)
{
    return a * b;
}

int Math::Mul(int a, int b, int c)
{
    return a * b * c;
}

int Math::Mul(double a, double b)
{
    return int(a * b);
}

int Math::Mul(double a, double b, double c)
{
    return int(a * b * c);
}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);

    int s = 0;
    for (int i = 0; i < count; ++i)
    {
        s =s+va_arg(args, int);
    }

    va_end(args);
    return s;
}

char* Math::Add(const char* str1, const char* str2)
{
    if (str1 == nullptr || str2 == nullptr)
    {
        return nullptr;
    }

    int lg1=0, lg2=0;

    while(str1[lg1]!='\0')
        lg1++;
    lg1--;

    while(str2[lg2]!='\0')
        lg2++;
    lg2--;

    char* result = new char[lg1 + lg2 + 1];

    int i=0;
    while(str1[i]!='\0')
    {
        result[i]=str1[i];
        i++;
    }

    int j=0;
    while(str2[j]!='\0')
    {
        result[i]=str2[j];
        i++;
        j++;
    }
    result[i]='\0';
    return result;
}
