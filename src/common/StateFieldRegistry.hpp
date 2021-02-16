#ifndef _STATE_FIELD_REGISTRY_HPP
#define _STATE_FIELD_REGISTRY_HPP

#include <string>
#include <vector>

#include "StateField.hpp"
class StateFieldRegistry
{
private:
    std::vector<ReadableStateFieldBase *> readable_fields;
    std::vector<WriteableStateFieldBase *> writeable_fields;
    std::vector<InternalStateFieldBase *> internal_fields;

public:
    bool add_readable_field(ReadableStateFieldBase *field);
    bool add_writeable_field(WriteableStateFieldBase *field);
    bool add_internal_field(InternalStateFieldBase *field);

    ReadableStateFieldBase *find_readable_field(const std::string &);
    WriteableStateFieldBase *find_writeable_field(const std::string &);
    InternalStateFieldBase *find_internal_field(const std::string &);
};
#endif