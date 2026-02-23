#pragma once
#include <Arduino.h>

struct SensorData {
    int sensorId;
    float hydrogenPpm;
    int rawADC;
    float temperature;
    float humidity;
    long timestamp;
};

class Sensor {
private:
    int sensorId;
    int analogPin;

public:
    Sensor(int sensorId, int analogPin);
    SensorData getRealData();
    SensorData getMockData();
};

