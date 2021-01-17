#ifndef _RADIO_HPP
#define _RADIO_HPP

#include <string>
#include <SoftwareSerial.h>
#include <common/StateField.hpp>
#include "TimedControlTask.hpp"
#include <fs/FCCode/Radio/xBee/xBee.hpp>

class RadioMonitor : public TimedControlTask<void>
{
    /*
    Extends TimedControlTask

    Gets data from radio
    Puts the data into the stateField

    Tells radio to send messages back to GS
    */
public:
    /*
    Constructor for RadioMonitor
    Currently takes in StateFieldRegistry
    */
    RadioMonitor(StateFieldRegistry &registry, uint rx, uint tx);
    xBee xBeeRadio;
    /*
    Methods to implement for RadioMonitor class
    */
    void update_state_fields();
    std::string read_message();
    bool send_message(const std::string &);
    void execute() override;

protected:
    InternalStateField<std::string> read_messages;
    InternalStateField<std::string> messages_to_send;
};
#endif;
