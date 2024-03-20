#include "MyLibrary.h"
#include <ostream>
#include <cmath>
#include <cstring>
#include <stdarg.h>
#include <initializer_list>

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream)
{
    books_count = -1;
    books = '\0';
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream)
{
    this->books_count = books_count;
    this->books = new int[books_count];
    for (int i = 0; i < books_count; i++)
    {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) : output_stream(output_stream)
{
    this->books_count = books_count;
    books = new int[books_count];
    for (int i = 0; i < books_count; i++)
    {
        this->books[i] = min + rand() % (max - min);
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream)
{
    books_count = 0;
    int lungime = strlen(books_values);
    int i = 0;
    int id_curent = 0;
    books = new int[4096];

    while (i < lungime)
    {
        if (books_values[i] != ';')
        {
            id_curent = id_curent * 10 + (int)(books_values[i] - '0');
        }
        else
        {
            books[books_count] = id_curent;
            books_count++;
            id_curent = 0;
        }
        i++;
    }
    books[books_count] = id_curent;
    books_count++;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream)
{
    va_list args;
    va_start(args, books_count);

    this->books_count = books_count;
    books = new int[books_count];
    int i = 0;

    while (books_count != 0)
    {
        books[i] = va_arg(args, int);
        i++;
        books_count--;
    }
    va_end(args);
}

MyLibrary::MyLibrary(std::initializer_list<int> v) : output_stream(output_stream)
{
    books_count = 0;
    books = new int[4096];
    for (auto& valoare : v)
    {
        books[books_count] = valoare;
        books_count++;
    }
}

MyLibrary::~MyLibrary()
{
    delete[] books;
}

void MyLibrary::print_books() const
{
    output_stream << "Found " << books_count << " books" << std::endl;
    if (books_count != -1)
    {
        output_stream << "Book IDs: ";
        for (int i = 0; i < books_count; i++)
        {
            output_stream << books[i] << " ";
        }
        output_stream << std::endl;
    }
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id)
{
    books[book_index] = book_id;
}

unsigned MyLibrary::get_books_count() const
{
    return books_count;
}

int MyLibrary::get_book_id_by_index(unsigned book_index) const
{
    return books[book_index];
}

MyLibrary::MyLibrary(const MyLibrary& other) : output_stream(output_stream)
{
    books = new int[books_count];
    for (int i = 0; i < books_count; i++)
    {
        books[i] = other.books[i];
    }
}

MyLibrary& MyLibrary::operator=(const MyLibrary& other)
{
    if (this != &other)
    {
        delete[] books;
        output_stream.rdbuf(other.output_stream.rdbuf()); 
        books_count = other.books_count;
        books = new int[books_count];
        for (int i = 0; i < books_count; i++)
        {
            books[i] = other.books[i];
        }
    }
    return *this;
}
