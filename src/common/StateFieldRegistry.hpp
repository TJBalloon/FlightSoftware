#ifndef _STATE_FIELD_REGISTRY_HPP
#define _STATE_FIELD_REGISTRY_HPP

#include <string>
#include <vector>

#include "StateField.hpp"
class StateFieldRegistry
{
private:
    vector<ReadableStatefieldBase *> readableFields;
    vector<WriteableStatefieldBase *> writableFields;
    vector<InternalStatefieldBase *> internalFields;

    bool addReadableField(ReadableStateFieldBase *field);
    bool addWritableField(WritableStatefieldBase *field);
    bool addInternalField(InternalStateFieldBase *field);

    ReadableStateFieldBase *findReadableField(const std::string &);
    WritableStatefieldBase *findWritableField(const std::string &);
    InternalStateFieldBase *findInternalField(const std::string &);
}
#endif