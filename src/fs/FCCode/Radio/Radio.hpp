#ifndef _RADIO_HPP
#define _RADIO_HPP

#include<string>
#include<common/Devices/I2CDevice.hpp>
#include<SoftwareSerial.h>

class Radio:
public virtual I2CDevice
{
    private:
        uint pin;
    public:
        Radio(uint);
        std::string read_message();
        void send_message(const std::string&);
};