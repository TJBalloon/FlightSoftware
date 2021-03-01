#ifndef SERIALIZER_HPP_
#define SERIALIZER_HPP_

template <typename T>
class SerializerBase
{
private:
    size_t strlength;
    size_t bitlength;

protected:
    char *printed_val = nullptr;
    SerializerBase(size_t _strlength, size_t _bitlength) : strlength(_strlength), bitlength(_bitlength)
    {
        this->printed_val = new char[strlength];
        memset(printed_val, '\0', strlength);
    }

public:
    virtual void serialize(const T &src) = 0;

    virtual bool deserialize(const char *val, T *dest) = 0;
};

template <typename T>
class Serializer;

#include "SerializerTypes.inl"
#endif