/* 
 * File:   arduStreamSerial.hpp
 * Author: murobocup42
 *
 * Created on 16 October 2013, 3:25 PM
 */

#ifndef ARDUSTREAMSERIAL_HPP
#define	ARDUSTREAMSERIAL_HPP

#include <cstdlib>
#include <cstdio>
#include <SerialStream.h>
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace LibSerial;

class arduStreamSerial {
public:
    /**
     * arduStreamSerial
     * 
     * Creates a serial stream intended for use with an Arduino.
     * @param port Port name of the comm device
     * @param baud_rate Baud rate of Arduino (generally BAUD_9600)
     * @param char_size Char size used by Arduino (generally CHAR_SIZE_8)
    */
    arduStreamSerial(const char* port, 
            SerialStreamBuf::BaudRateEnum baud_rate, 
            SerialStreamBuf::CharSizeEnum char_size);
    
    /**
     * arduStreamSerial
     * 
     * Creates a serial stream intended for use with an Arduino
     * defaults to BAUD_9600 and CHAR_SIZE_8
     * @param port Port name of the comm device
     */
    arduStreamSerial(const char* port);
    
    /**
     * arduStreamSerial
     * 
     * Creates a serial stream intended for use with an Arduino.
     * defaults to  CHAR_SIZE_8
     * @param port Port name of the comm device
     * @param baud_rate Baud rate of Arduino (generally BAUD_9600)
    */
    arduStreamSerial(const char* port, 
            SerialStreamBuf::BaudRateEnum baud_rate);
    
    /**
     * arduStreamSerial
     * 
     * Creates a serial stream intended for use with an Arduino.
     * defaults to BAUD_9600 
     * @param port Port name of the comm device
     * @param baud_rate Baud rate of Arduino (generally BAUD_9600)
    */
    arduStreamSerial(const char* port, 
            SerialStreamBuf::CharSizeEnum char_size);
    
    arduStreamSerial(const arduStreamSerial& orig);
    virtual ~arduStreamSerial();
    
    /**
     * getVal
     * 
     * Gets value from the serial output.
     * @param buff Buffer to store output
     */
    void getVal(char* buff);
    
    void getLine(char* buffer, int length);
    
    void getLine(char* buffer, int length, char delim);
    
    /**
     * sendCommand
     * 
     * Send a command to the serial device. Sends a single char.
     * @param command Command signal
     */
    void sendCommand(char command);
    
private:
    SerialStream serial;
    const char* port;
    SerialStreamBuf::BaudRateEnum baud_rate; 
    SerialStreamBuf::CharSizeEnum char_size;
};

#endif	/* ARDUSTREAMSERIAL_HPP */

