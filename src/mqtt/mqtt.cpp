#include "mqtt.h"

Mqtt::Mqtt(const char* brokerIP, const char* brokerPort, const char* clientId)
    : mqttClient(wifiClient) {
    this->brokerIP = brokerIP;
    this->brokerPort = brokerPort;
    this->clientId = clientId;
    this->client.setServer(brokerIP, atoi(brokerPort));
}
    void Mqtt::connect() {
        mqttClient.setServer(this->brokerIP, atoi(this->brokerPort));
        while (!mqttClient.connected()) {
            Serial.print("Connecting to MQTT broker...");
            if (mqttClient.connect(this->clientId)) {
                Serial.println("connected");
            } else {
                Serial.print("failed");
                Serial.print(mqttClient.state());
                delay(5000);
            }
        }
        public:
            Mqtt(const char* brokerIP, const char* brokerPort, const char* clientId);
    }

    void Mqtt::publish(SensorData data) {
        String payload = "{"
        payload += "\"sensorId\":" + String(data.sensorId) + ",";
        payload += "\"ppm\":" + String(data.hydrogenPpm) + ",";
        payload += "\"rawADC\":" + String(data.rawADC) + ",";
        payload += "\"temp\":" + String(data.temperature) + ",";
        payload += "\"humidity\":" + String(data.humidity) + ",";
        payload += "\"timestamp\":" + String(data.timestamp);
        payload += "}";
    }

    bool Mqtt::isConnected() {
        return mqttClient.connected();
    }

    