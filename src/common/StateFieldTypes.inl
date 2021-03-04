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
    virtual const char *print() const = 0;
};

template <typename T>
class SerializableStateField : public StateField<T>, virtual public SerializableStateFieldBase
{
protected:
    Serializer<T> _serializer;

public:
    SerializableStateField(const std::string &name, const Serializer<T> &s)
        : StateField<T>(name)
    {
        this->_serializer = s;
    };
    SerializableStateField(const std::string &name, T v, const Serializer<T> &s)
        : StateField<T>(name)
    {
        this->value = v;
        this->_serializer = s;
    };

    void serialize() override { _serializer.serialize(this->_val); }

    const char *print() const override { return _serializer.print(this->_val); }
};

class ReadableStateFieldBase : virtual public SerializableStateFieldBase
{
};

class WritableStateFieldBase : virtual public SerializableStateFieldBase
{
};

template <class T>
class ReadableStateField : public ReadableStateFieldBase, public SerializableStateField<T>
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
class WritableStateField : public virtual WritableStateFieldBase, public SerializableStateField<T>
{
public:
    WritableStateField(const std::string &name)
        : StateField<T>(name){};
    WritableStateField(const std::string &name, T v)
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