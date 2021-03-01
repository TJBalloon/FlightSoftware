#include "Serializer.hpp"

template <>
class Serializer<bool> : public SerializerBase<bool>
{
};

template <typename T>
class IntegerSerializer : public SerializerBase<t>
{
    static_assert(std::is_same<T, unsigned int>::value ||
                      std::is_same<T, signed int>::value ||
                      std::is_same<T, unsigned char>::value ||
                      std::is_same<T, signed char>::value,
                  "Requires integer type");
};

template <typename T>
class FloatDoubleSerializer : public SerializerBase<t>
{
    static_assert(std::is_floating_point<T>::value, "Requires float or double type");
};
