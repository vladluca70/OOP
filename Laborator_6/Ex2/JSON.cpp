#include "JSON.h"

JsonValue::~JsonValue() {}

NullValue::~NullValue() {}

void NullValue::print(std::ostream& out, int indentation) const
{
    out << "null";
}

NumberValue::NumberValue(int num) : number(num) {}

void NumberValue::print(std::ostream& out, int indentation) const
{
    out << number;
}

BoolValue::BoolValue(bool val) : value(val) {}

void BoolValue::print(std::ostream& out, int indentation) const
{
    if (value)
        out << "true";
    else
        out << "false";
}

StringValue::StringValue(const std::string& val) : value(val) {}

void StringValue::print(std::ostream& out, int indentation) const
{
    out << "\"" << value << "\"";
}

ArrayValue::ArrayValue() : size(0), capacity(8)
{
    values = new JsonValue*[capacity];
}

ArrayValue::~ArrayValue()
{
    for (int i = 0; i < size; ++i)
        delete values[i];
    delete[] values;
}

void ArrayValue::add(JsonValue* val)
{
    if (size >= capacity)
    {
        capacity *= 2;
        JsonValue** new_values = new JsonValue*[capacity];
        for (int i = 0; i < size; ++i)
            new_values[i] = values[i];
        delete[] values;
        values = new_values;
    }
    values[size++] = val;
}

void ArrayValue::print(std::ostream& out, int indentation) const
{
    out << "[";
    if (size > 0)
    {
        out << std::endl;
        for (int i = 0; i < size; ++i)
        {
            out << std::string(indentation + 4, ' ');
            values[i]->print(out, indentation + 4);
            out << "," << std::endl;
        }
        out << std::string(indentation, ' ');
    }
    out << "]";
}

ObjectValue::ObjectValue() : size(0), capacity(8)
{
    values = new std::pair<std::string, JsonValue*>[capacity];
}

ObjectValue::~ObjectValue()
{
    for (int i = 0; i < size; ++i)
        delete values[i].second;
    delete[] values;
}

void ObjectValue::add(const std::string& name, JsonValue* val)
{
    if (size >= capacity)
    {
        capacity *= 2;
        std::pair<std::string, JsonValue*>* new_values = new std::pair<std::string, JsonValue*>[capacity];
        for (int i = 0; i < size; ++i)
            new_values[i] = values[i];
        delete[] values;
        values = new_values;
    }
    values[size++] = std::make_pair(name, val);
}

void ObjectValue::print(std::ostream& out, int indentation) const
{
    out << "{" << std::endl;
    for (int i = 0; i < size; ++i)
    {
        out << std::string(indentation + 4, ' ') << "\"" << values[i].first << "\": ";
        values[i].second->print(out, indentation + 4);
        out << "," << std::endl;
    }
    out << "}";
}

ObjectValue::operator unsigned() const
{
    return size;
}
