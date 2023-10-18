#ifndef SIM900_H
#define SIM900_H

#include <Arduino.h>
#include <SoftwareSerial.h>

#include <sim900_defs.h>

class SIM900 {
private:
    SoftwareSerial *sim900;
    bool hasAPN = false;

    void sendCommand(String message);
    bool isSuccessCommand();

    String getResponse();
    String getReturnedMode();

    String rawQueryOnLine(uint16_t line);
    String queryResult();

public:
    SIM900(SoftwareSerial *_sim900);
    bool handshake();
    void close();

    bool isCardReady();
    bool changeCardPin(uint8_t pin);

    SIM900DialResult dialUp(String number);
    SIM900DialResult redialUp();
    SIM900DialResult acceptIncomingCall();
    bool hangUp();

    bool sendSMS(String number, String message);

    bool connectAPN(SIM900APN apn);
    bool enableGPRS();
    SIM900HTTPResponse request(SIM900HTTPRequest request);

    SIM900Operator networkOperator();
    SIM900CardAccount cardNumber();

    SIM900RTC rtc();
    bool updateRtc(SIM900RTC config);

    bool savePhonebook(uint8_t index, SIM900CardAccount account);
    bool deletePhonebook(uint8_t index);
    SIM900CardAccount retrievePhonebook(uint8_t index);    

    String manufacturer();
    String softwareRelease();
    String imei();
    String chipModel();
    String chipName();
    String ipAddress();
};

#endif