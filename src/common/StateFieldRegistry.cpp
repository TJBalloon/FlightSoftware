#include "StateFieldRegistry.hpp"

bool StateFieldRegistry::add_readable_field(StateFieldBase *field)
{
    if (find_readable_field(field->get_name()) != nullptr)
    {
        return false;
    }
    StateFieldRegistry::readable_fields.push_back(field);
    return true;
}

bool StateFieldRegistry::add_writeable_field(StateFieldBase *field)
{
    if (find_writeable_field(field->get_name()) != nullptr)
    {
        return false;
    }
    StateFieldRegistry::writeable_fields.push_back(field);
    return true;
}

bool StateFieldRegistry::add_internal_field(StateFieldBase *field)
{
    if (find_internal_field(field->get_name()) != nullptr)
    {
        return false;
    }
    StateFieldRegistry::internal_fields.push_back(field);
    return true;
}

std::vector<StateFieldBase *> StateFieldRegistry::get_readable_fields()
{
    return StateFieldRegistry::readable_fields;
}
StateFieldBase *StateFieldRegistry::find_readable_field(const std::string &string_match)
{
    for (StateFieldBase *s : StateFieldRegistry::readable_fields)
    {
        if (s->get_name() == string_match)
        {
            return s;
        }
    }
    return nullptr;
}

StateFieldBase *StateFieldRegistry::find_writeable_field(const std::string &string_match)
{
    for (StateFieldBase *s : StateFieldRegistry::writeable_fields)
    {
        if (s->get_name() == string_match)
        {
            return s;
        }
    }
    return nullptr;
}

StateFieldBase *StateFieldRegistry::find_internal_field(const std::string &string_match)
{
    for (StateFieldBase *s : StateFieldRegistry::internal_fields)
    {
        if (s->get_name() == string_match)
        {
            return s;
        }
    }
    return nullptr;
}
