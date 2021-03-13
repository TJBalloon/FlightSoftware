#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_
#include <cstring>
template <typename T>
class SerializerBase
{
private:
    size_t strlength;

protected:
    char *printed_val = nullptr;
    SerializerBase(size_t _strlength) : strlength(_strlength)
    {
        this->printed_val = new char[strlength];
        memset(printed_val, '\0', strlength);
    }

public:
    virtual void serialize(const T &src) = 0;

    const char *print() { return printed_val; }

    virtual ~SerializerBase();
};

template <typename T>
SerializerBase<T>::~SerializerBase()
{
    delete[] printed_val;
}

template <typename T>
class Serializer;

#include "SerializerTypes.inl"
#endif