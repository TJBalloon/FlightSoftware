#include <fs/FCCode/Radio/RadioMonitor/RadioMonitor.hpp>

RadioMonitor::RadioMonitor(StateFieldRegistry &registry, uint rx, uint tx)
    : TimedControlTask<void>(registry, "radio_monitor"),
      read_messages("radio_monitor.read_message"),
      messages_to_send("radio_monitor.send_message"),
      xBeeRadio(rx, tx)
{
    /*
    Add the statefields to the registry 
    */
    add_internal_field(read_messages);
    add_internal_field(messages_to_send);
}

void RadioMonitor::update_state_fields()
{
    // if new messages from radio, add to read_messages field
    // if new messages to send to GS, add up to messages_to_send field, send to GS
    // ! data from messsages_to_send will likely come from DataCollection and IMU
}

std::string RadioMonitor::read_message()
{
    std::string msg = xBeeRadio.read_message();
    read_messages.set(msg); //add msg to statefield
    // need to parse message?
}

bool RadioMonitor::send_message(const std::string &msg)
{
    /*
    Returns true if message sends without error
    */
    return (xBeeRadio.send_message(msg));
}

void RadioMonitor::execute()
{
    while (xBeeRadio.xBee_device.available())
    {
        read_message(); // messages must be added to statefield
        // look at messages_to_send state field
        // send_message(str) for each message to send from statefield
    }
}