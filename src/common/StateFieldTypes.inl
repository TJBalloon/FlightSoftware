#ifndef _STATE_FIELD_TYPES_INL
#define _STATE_FIELD_TYPES_INL

#include <string>
#include "StateField.hpp"
#include "Serializer.hpp"
class InternalStateFieldBase : public virtual StateFieldBase
{
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

class SerializableStateFieldBase : virtual public StateFieldBase
{
public:
    virtual void serialize() = 0;
    virtual void deserialize() = 0;
    virtual const char *print() const = 0;
};

template <typename T>
class SerializableStateField : public StateField<T>, virtual public SerializableStateFieldBase
{
protected:
    Serializer<T> _serializer;
};

class ReadableStateFieldBase : public virtual StateFieldBase
{
};

class WriteableStateFieldBase : public virtual StateFieldBase
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