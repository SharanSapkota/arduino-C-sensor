#include <Arduino.h>
#include "internet/internet.h"
#include "sensor/sensor.h"
#include "mqtt/mqtt.h"

#define ANALOG_PIN  26     
#define SENSOR_ID  1 //We need to update the id according to the sensor
#define USE_MOCK_DATA   true

const char* WIFI_SSID = "your_SSID";
const char* WIFI_PASSWORD = "your_PASSWORD";
const char* MQTT_BROKER = "192.168.1.100";  
const int   MQTT_PORT = 1883;

Internet internet(WIFI_SSID, WIFI_PASSWORD);
Sensor sensor(SENSOR_ID, ANALOG_PIN);
MQTT mqtt(MQTT_BROKER, MQTT_PORT, "picow-sensor-1");

void setup() {
    Serial.begin(115200);
    internet.connectToWifi();
    mqtt.connect();
}

void loop() {
    if (!internet.isConnected()) internet.connectToWifi();
    if (!mqtt.isConnected()) mqtt.connect();

    SensorData data = USE_MOCK_DATA 
        ? sensor.getMockData() 
        : sensor.getRealData();

    mqtt.publish(data);

    delay(5000);
}