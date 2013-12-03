/* 
 * File:   arduStreamSerial.cpp
 * Author: murobocup42
 * 
 * Created on 16 October 2013, 3:25 PM
 */

#include "../arduStreamSerial.hpp"
#include <cstring>

arduStreamSerial::arduStreamSerial(const char* _port, 
            SerialStreamBuf::BaudRateEnum _baud_rate, 
            SerialStreamBuf::CharSizeEnum _char_size): 
            baud_rate(_baud_rate), char_size(_char_size), port(_port){
    
    // Open connection to the port. Note that there is no error checking.
    arduStreamSerial::serial.Open(port);
    // Set Baud rate
    arduStreamSerial::serial.SetBaudRate(baud_rate);
    // Set char size
    arduStreamSerial::serial.SetCharSize(char_size);
}

arduStreamSerial::arduStreamSerial(const char* _port){
    arduStreamSerial(_port,SerialStreamBuf::BAUD_9600,
            SerialStreamBuf::CHAR_SIZE_8);
}

arduStreamSerial::arduStreamSerial(const char* _port,
        SerialStreamBuf::BaudRateEnum _baud_rate){
    arduStreamSerial(_port,_baud_rate,
            SerialStreamBuf::CHAR_SIZE_8);
}

arduStreamSerial::arduStreamSerial(const char* _port,
        SerialStreamBuf::CharSizeEnum _char_size){
    arduStreamSerial(_port,SerialStreamBuf::BAUD_9600,
            _char_size);
}

void arduStreamSerial::getVal( char* buff){    
    serial >> buff;
    return;
}

void arduStreamSerial::getLine(char* buffer, int length){
    serial.getline(buffer, length);
    return;
}

void arduStreamSerial::getLine(char* buffer, int length, char delim){
    serial.getline(buffer,length,delim);
    return;
}

void arduStreamSerial::sendCommand(char command){
    serial << command;
    return;
}

arduStreamSerial::arduStreamSerial(const arduStreamSerial& orig) {
}

arduStreamSerial::~arduStreamSerial() {
}

