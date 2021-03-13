#include "Serializer.hpp"

template <>
class Serializer<bool> : public SerializerBase<bool>
{
public:
    Serializer() : SerializerBase<bool>(10) // need to set constants
    {
    }

    virtual void serialize(const bool &src)
    {
        if (src == true)
        {
            strcpy(this->printed_val, "true");
        }
        else
        {
            strcpy(this->printed_val, "false");
        }
        return;
    }
};
