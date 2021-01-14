template <typename T>
class WritableStateField : public StateField
{

public:
    WritableStateField(const std::string &n, const boolean gr, const boolean gw, T data)
        : name(n),
          ground_readable(gr);
    ground_writable(gw);
    value(data);

    void write(T newVal) { this->value = newVal }
}