#include "canvas.h"
#include <iostream>
#include <cstdarg>

Canvas::Canvas(int lines, int columns) {
    lines_ = lines;
    columns_ = columns;
    initialize_canvas();
    clear();
}

void Canvas::initialize_canvas() {
    canvas_ = new char*[lines_];
    for (int i = 0; i < lines_; ++i) {
        canvas_[i] = new char[columns_];
    }
}

void Canvas::set_pixel(int x, int y, char value) {
    if (x >= 0 && x < lines_ && y >= 0 && y < columns_) {
        canvas_[x][y] = value;
    }
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        char value = static_cast<char>(va_arg(args, int));
        set_pixel(x, y, value);
    }

    va_end(args);
}

void Canvas::clear() {
    for (int i = 0; i < lines_; ++i) {
        for (int j = 0; j < columns_; ++j) {
            canvas_[i][j] = ' ';
        }
    }
}

void Canvas::print() const {
    for (int i = 0; i < lines_; ++i) {
        for (int j = 0; j < columns_; ++j) {
            std::cout << canvas_[i][j];
        }
        std::cout << std::endl;
    }
}
