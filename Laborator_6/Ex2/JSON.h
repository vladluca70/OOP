#ifndef JSON_VALUE_H
#define JSON_VALUE_H

#include <iostream>
#include <string>

class JsonValue {
public:
    virtual ~JsonValue() = 0;
    virtual void print(std::ostream& out, int indentation) const = 0;
};

class NullValue : public JsonValue {
public:
    ~NullValue() override;
    void print(std::ostream& out, int indentation) const override;
};

class NumberValue : public JsonValue {
    int number;
public:
    NumberValue(int num);
    void print(std::ostream& out, int indentation) const override;
};

class BoolValue : public JsonValue {
    bool value;
public:
    BoolValue(bool val);
    void print(std::ostream& out, int indentation) const override;
};

class StringValue : public JsonValue {
    std::string value;
public:
    StringValue(const std::string& val);
    void print(std::ostream& out, int indentation) const override;
};

class ArrayValue : public JsonValue {
    JsonValue** values;
    int size;
    int capacity;
public:
    ArrayValue();
    ~ArrayValue();
    void add(JsonValue* val);
    void print(std::ostream& out, int indentation) const override;
};

class ObjectValue : public JsonValue {
    std::pair<std::string, JsonValue*> *values;
    int size;
    int capacity;
public:
    ObjectValue();
    ~ObjectValue();
    void add(const std::string& name, JsonValue* val);
    void print(std::ostream& out, int indentation) const override;
    operator unsigned() const;
};

#endif // JSON_VALUE_H
