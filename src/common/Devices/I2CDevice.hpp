#ifndef _I2C_DEVICE_HPP
#define _I2C_DEVICE_HPP

class I2CDevice
{
protected:
    uint8_t address;
    uint8_t max_bytes;

    void _request_from(uint8_t);

    void read_all(char *const);
    void transmit(const char *);

public:
    I2CDevice(const std::string &, i2c_t3, uint8_t, uint8_t);
    void setup();
    void reset();
};