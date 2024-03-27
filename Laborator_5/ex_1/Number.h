class Number {
private:
    char *value;
    int base;
    int size;

public:
    Number(const char *value, int base);
    Number(int value);
    Number(const Number &other);
    Number(Number &&other);
    ~Number();

    Number& operator=(const Number &other);
    Number& operator=(Number &&other);

    Number operator+(const Number &other) const;
    Number operator-(const Number &other) const;
    bool operator>(const Number &other) const;
    bool operator<(const Number &other) const;
    bool operator>=(const Number &other) const;
    bool operator<=(const Number &other) const;
    bool operator==(const Number &other) const;
    char operator[](int index) const;
    Number& operator+=(const Number&other);
    Number& operator--();
    Number operator--(int);

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;

private:
    void initialize(const char *value, int base);
    void resize(int newSize);
};
