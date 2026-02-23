#include "internet.h"

Internet::Internet(const char* ssid, const char* password) {
    this->ssid = ssid;
    this->password = password;
}

void Internet::connectToWifi() {
    WiFi.begin(this->ssid, this->password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print("Connecting to Wifi ....");
    }
}

bool Internet::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}