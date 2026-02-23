#include "mqtt.h"

MQTT::MQTT(const char* brokerIP, int brokerPort, const char* clientId)
    : mqttClient(wifiClient) {
    this->brokerIP = brokerIP;
    this->brokerPort = brokerPort;
    this->clientId = clientId;

    mqttClient.setServer(brokerIP, brokerPort);
}

    void MQTT::connect() {
        while (!mqttClient.connected()) {
            Serial.print("Connecting to MQTT broker...");
            if (mqttClient.connect(this->clientId)) {
            Serial.println("connected!");
            } else {
            Serial.println(mqttClient.state());
            delay(5000);
        }
    }
}

void MQTT::publish(SensorData data) {
    String payload = "{";
    payload += "\"sensorId\":" + String(data.sensorId)     + ",";
    payload += "\"ppm\":" + String(data.hydrogenPpm)  + ",";
    payload += "\"rawADC\":" + String(data.rawADC)       + ",";
    payload += "\"temp\":" + String(data.temperature)  + ",";
    payload += "\"humidity\":" + String(data.humidity)     + ",";
    payload += "\"timestamp\":" + String(data.timestamp);
    payload += "}";

    mqttClient.publish("hydrogen/sensors", payload.c_str());
    Serial.println("Published: " + payload);
}

    bool MQTT::isConnected() {
        return mqttClient.connected();
    }