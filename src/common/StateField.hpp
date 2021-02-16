#ifndef _STATE_FIELD_HPP
#define _STATE_FIELD_HPP

#include <string>
#include <iostream>
class StateFieldBase
{
public:
    virtual const std::string &get_name() const = 0;
};

template <typename T>
class StateField : public StateFieldBase
{
protected:
    std::string name;
    T value;

public:
    StateField(const std::string &n)
        : name(n), value{} {};

    virtual const std::string &get_name() const
    {
        return this->name;
    }
    const T get_value() const { return this->value; }
    void set_value(T value) { this->value = value; }
};

#include "StateFieldTypes.inl"
#endif