#ifndef _STATE_FIELD_REGISTRY_HPP
#define _STATE_FIELD_REGISTRY_HPP

#include <string>
#include <vector>

#include "StateField.hpp"
class StateFieldRegistry
{
private:
    std::vector<StateFieldBase *> readable_fields;
    std::vector<StateFieldBase *> writeable_fields;
    std::vector<StateFieldBase *> internal_fields;

public:
    bool add_readable_field(StateFieldBase *field);
    bool add_writeable_field(StateFieldBase *field);
    bool add_internal_field(StateFieldBase *field);

    std::vector<StateFieldBase *> get_readable_fields();
    std::vector<StateFieldBase *> get_writeable_fields();
    std::vector<StateFieldBase *> get_internal_fields();

    StateFieldBase *find_readable_field(const std::string &);
    StateFieldBase *find_writeable_field(const std::string &);
    StateFieldBase *find_internal_field(const std::string &);
};
#endif