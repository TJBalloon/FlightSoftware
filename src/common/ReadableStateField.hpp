#include "StateField.hpp"
#include <string>

template <typename T>
class ReadableStateField : public virtual StateFieldBase
{
protected:
    const std::string name;
    T value;

public:
    ReadableStateField(const std::string &n, T &v)
        : name(n),
          value(v){};
    ReadableStateField(const std::string &n)
        : name(n){};
    const std::string &get_name() const { return this->name; }

    const T get_value() const { return this->value; }
    void set_value(T value) { this->value = value; }
};
