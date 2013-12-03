/* 
 * File:   main.cpp
 * Author: murobocup42
 *
 * Created on 16 October 2013, 12:39 PM
 */

#include <cstdlib>
#include <cstdio>
#include <SerialStream.h>
#include <iostream>
#include <unistd.h>
#include "./arduStreamSerial/arduStreamSerial.hpp"

#define PORT "/dev/ttyACM0"

using namespace std;
using namespace LibSerial;

int main(int argc, char** argv) {
    int j;
    
    SerialStream test;
    
//    test.Open(PORT);
//    test.SetBaudRate(SerialStreamBuf::BAUD_9600);
//    test.SetCharSize(SerialStreamBuf::CHAR_SIZE_8);

    arduStreamSerial ardu(PORT,SerialStreamBuf::BAUD_9600,
            SerialStreamBuf::CHAR_SIZE_8);
    
    char str[50];
    char pstr[5];
    while(1){

        
//        ardu.getVal(str);
        ardu.getLine(str,50);
 
        // Print String out directly 
        // Note every delimiter is read as a separate string.
        printf("%s\n",str);
        
        // Flush the cout buffer
        flush(cout);
//        while sscanf(str,)
//        ardu.sendCommand('a');
    }
    
    return 0;
}

