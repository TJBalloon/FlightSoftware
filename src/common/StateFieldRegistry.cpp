#include "StateFieldRegistry.hpp"

bool StateFieldRegistry::add_readable_field(ReadableStateFieldBase *field)
{
    if (find_readable_field(field->get_name()) != nullptr)
    {
        return false;
    }
    this->readable_fields.push_back(field);
    return true;
}

bool StateFieldRegistry::add_writeable_field(WriteableStateFieldBase *field)
{
    if (find_writeable_field(field->get_name()) != nullptr)
    {
        return false;
    }
    this->writeable_fields.push_back(field);
    return true;
}

bool StateFieldRegistry::add_internal_field(InternalStateFieldBase *field)
{
    if (find_internal_field(field->get_name()) != nullptr)
    {
        return false;
    }
    this->internal_fields.push_back(field);
    return true;
}

ReadableStateFieldBase *StateFieldRegistry::find_readable_field(const std::string &string_match)
{
    for (ReadableStateFieldBase *s : this->readable_fields)
    {
        if (s->get_name() == string_match)
        {
            return s;
        }
    }
    return nullptr;
}

WriteableStateFieldBase *StateFieldRegistry::find_writeable_field(const std::string &string_match)
{
    for (WriteableStateFieldBase *s : this->writeable_fields)
    {
        if (s->get_name() == string_match)
        {
            return s;
        }
    }
    return nullptr;
}

InternalStateFieldBase *StateFieldRegistry::find_internal_field(const std::string &string_match)
{
    for (InternalStateFieldBase *s : this->internal_fields)
    {
        if (s->get_name() == string_match)
        {
            return s;
        }
    }
    return nullptr;
}