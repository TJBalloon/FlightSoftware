#include <StateField.hpp>
#include <string>

template <typename T>
class WriteableStateField : public virtual StateFieldBase
{
protected:
    const std::string name;
    T value;

public:
    WriteableStateField(const std::string &n, T &v)
        : name(n),
          value(v){};

    const std::string &get_name() const { return this->name; }

    const T get_value() const { return this->value; }
    void set_value(T value) { this->value = value; }
}
