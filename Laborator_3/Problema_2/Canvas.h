class Canvas {
public:
    Canvas(int lines, int columns);
    void set_pixel(int x, int y, char value);
    void set_pixels(int count, ...);
    void clear();
    void print() const;

private:
    int lines_;
    int columns_;
    char** canvas_;
    void initialize_canvas();
};


