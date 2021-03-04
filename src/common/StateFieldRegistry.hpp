#ifndef _STATE_FIELD_REGISTRY_HPP
#define _STATE_FIELD_REGISTRY_HPP

#include <string>
#include <vector>

#include "StateField.hpp"
class StateFieldRegistry
{
private:
    std::vector<ReadableStateFieldBase *> readable_fields;
    std::vector<WritableStateFieldBase *> writable_fields;
    std::vector<InternalStateFieldBase *> internal_fields;

public:
    bool add_readable_field(ReadableStateFieldBase *field);
    bool add_writable_field(WritableStateFieldBase *field);
    bool add_internal_field(InternalStateFieldBase *field);

    ReadableStateFieldBase *find_readable_field(const std::string &);
    WritableStateFieldBase *find_writable_field(const std::string &);
    InternalStateFieldBase *find_internal_field(const std::string &);
};
#endif