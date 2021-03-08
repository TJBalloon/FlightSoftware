#ifndef CONTROL_TASK_HPP_
#define CONTROL_TASK_HPP_

#include "StateFieldRegistry.hpp"
#include <string>

class ControlTask
{

private:
    StateFieldRegistry &_registry;

protected:
    virtual void execute() = 0;

public:
    ControlTask(StateFieldRegistry &registry) : _registry(registry) {}

    template <typename T>
    void add_internal_field(InternalStateField<T> &field)
    {
        this->_registry.add_internal_field(static_cast<InternalStateFieldBase *>(&field));
    }

    template <typename T>
    void add_readable_field(ReadableStateField<T> &field)
    {
        this->_registry.add_readable_field(static_cast<ReadableStateFieldBase *>(&field));
    }

    template <typename T>
    void add_writable_field(WritableStateField<T> &field)
    {
        this->_registry.add_writable_field(static_cast<WritableStateFieldBase *>(&field));
    }

    template <typename T>
    InternalStateField<T> *find_internal_field(const std::string &field_name)
    {
        auto field_ptr = this->_registry.find_internal_field(field_name);
        return static_cast<InternalStateField<T> *>(field_ptr);
    }

    template <typename T>
    ReadableStateField<T> *find_readable_field(const std::string &field_name)
    {
        auto field_ptr = this->_registry.find_readable_field(field_name);
        return static_cast<ReadableStateField<T> *>(field_ptr);
    }

    template <typename T>
    WritableStateField<T> *find_writable_field(const std::string &field_name)
    {
        auto field_ptr = this->_registry.find_writable_field(field_name);
        return static_cast<WritableStateField<T> *>(field_ptr);
    }
};
#endif