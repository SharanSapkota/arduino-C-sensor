#pragma once
#include <WiFi.h>

class Internet {
private:
    const char* ssid;
    const char* password;

public:
    Internet(const char* ssid, const char* password);
    void connectToWifi();
    bool isConnected();
};

