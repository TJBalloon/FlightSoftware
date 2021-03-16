#include <SoftwareSerial.h>
const int RX = 2, TX = 3; // rx and tx connected pins
SoftwareSerial XBee(RX, TX);

void setup()
{
    Serial.begin(9600);
    XBee.begin(9600);
}

String read()
{
    /*
    * Reads and return message read from XBee
    */
    String read_message = "";
    while (XBee.available())
    {
        read_message += XBee.read();
    }
    return read_message;
}

void write(String write_message = "Hello World!")
{
    /*
    * Sends message through XBee
    * Default message if not given argument is Hello World
    */
    XBee.print(write_message);
}

void loop()
{
    /*
    * Test code for arduino to read and write messages with XBee
    */
    Serial.println(read());
    write();
}