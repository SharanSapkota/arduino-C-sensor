#include "connectToWifi.h"
#include <WiFi.h>

Internet::Internet(const char* ssid, const char* password) {
    this->ssid = ssid;
    this->password = password;
}

void Internet::connectToWifi() {
    WiFi.begin(this->ssid, this->password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
}

