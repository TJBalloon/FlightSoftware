#include <fs/FCCode/Radio/xBee/xBee.hpp>

xBee::xBee(uint rx, uint tx)
    : xBee_device(rx, tx)
{
    /*
    This baud rate must match the xBee settings when xBee is set up
    */
    xBee_device.begin(9600);
}

bool xBee::send_message(const std::string &msg)
{
    /*
    Returns true if message is sent without error
    */
    try
    {
        xBee_device.write(msg);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

std::string xBee::read_message()
{
    return (xBee_device.readString());
}