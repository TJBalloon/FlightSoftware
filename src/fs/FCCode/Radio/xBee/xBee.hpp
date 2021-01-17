#ifndef _XBEE_HPP
#define _XBEE_HPP

#include <string>
#include <SoftwareSerial.h>

class xBee
{
    /*
    Radio class for xBee
    Only thing it does: Read and Write messages
    */
public:
    /*
    Constructor for xBee
    xBee takes in an rx port and a tx port
    */
    xBee(uint rx, uint tx);
    SoftwareSerial xBee_device;

    /*
    Methods to implement for RadioMonitor class
    */
    void send_message(const std::string &msg);
    std::string read_message();
};

#endif;
