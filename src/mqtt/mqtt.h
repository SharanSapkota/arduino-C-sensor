#pragma once
#include <WiFi.h>
#include <PubSubClient.h> 
#include "../sensor/sensor.h"

class MQTT {
private:
    WiFiClient   wifiClient;
    PubSubClient mqttClient;
    const char*  brokerIP;
    int brokerPort;
    const char*  clientId;

public:
    MQTT(const char* brokerIP, int brokerPort, const char* clientId);
    void connect();
    void publish(SensorData data);
    bool isConnected();
};

