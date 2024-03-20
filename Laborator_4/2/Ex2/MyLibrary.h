#pragma once

#include <ostream>

class MyLibrary
{
private:
    std::ostream& output_stream;
    unsigned books_count;
    int* books;
public:

    MyLibrary(std::ostream& output_stream);

    MyLibrary(std::ostream& output_stream, unsigned books_count, int* books);

    MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max);

    MyLibrary(std::ostream& output_stream, const char* books_values);


    MyLibrary(std::ostream& output_stream, unsigned books_count, ...);


    MyLibrary(std::initializer_list<int> v);


    ~MyLibrary();

    void print_books() const;


    void update_book_id_by_index(unsigned book_index, int book_id);

    unsigned get_books_count() const;
    int get_book_id_by_index(unsigned book_index) const;

    MyLibrary(const MyLibrary& other);
    MyLibrary& operator=(const MyLibrary& other);
};
