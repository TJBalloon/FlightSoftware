#ifndef _STATE_FIELD_HPP
#define _STATE_FIELD_HPP

#include <string>
class StateFieldBase
{
public:
    virtual const std::string &get_name() const = 0;
};

#endif