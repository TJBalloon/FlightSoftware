#ifndef _STATE_FIELD_TYPES_INL
#define _STATE_FIELD_TYPES_INL

#include <string>
#include "StateField.hpp"

class ReadableStateFieldBase : public virtual StateFieldBase
{
};

class WriteableStateFieldBase : public virtual StateFieldBase
{
};
class InternalStateFieldBase : public virtual StateFieldBase
{
};

template <class T>
class ReadableStateField : public ReadableStateFieldBase, public StateField<T>
{
public:
    ReadableStateField(const std::string &name)
        : StateField<T>(name){};
    ReadableStateField(const std::string &name, T v)
        : StateField<T>(name)
    {
        this->value = v;
    }
    virtual const std::string &get_name() const
    {
        return this->name;
    }
};

template <typename T>
class InternalStateField : public InternalStateFieldBase, public StateField<T>
{
public:
    InternalStateField(const std::string &name)
        : StateField<T>(name){};
    InternalStateField(const std::string &name, T v)
        : StateField<T>(name)
    {
        this->value = v;
    }
    virtual const std::string &get_name() const
    {
        return this->name;
    }
};

template <typename T>
class WriteableStateField : public virtual StateFieldBase
{
public:
    WriteableStateField(const std::string &name)
        : StateField<T>(name){};
    WriteableStateField(const std::string &name, T v)
        : StateField<T>(name)
    {
        this->value = v;
    }
    virtual const std::string &get_name() const
    {
        return this->name;
    }
};

#endif