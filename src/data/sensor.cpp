#include "sensor.h"

Sensor::Sensor(int sensorId, int analogPin) {
    this->sensorId   = sensorId;
    this->analogPin  = analogPin;
    pinMode(analogPin, INPUT);
}

SensorData Sensor::getRealData() {
    SensorData data;
    data.sensorId = this->sensorId;
    data.rawADC = analogRead(this->analogPin);
    data.hydrogenPpm = (data.rawADC / 4095.0f) * 1000.0f;
    data.temperature = 25.0f;  
    data.humidity = 60.0f;
    data.timestamp = millis();
    return data;
}

SensorData Sensor::getMockData() {
    SensorData data;
    data.sensorId = this->sensorId;
    data.rawADC = random(100, 500);
    data.hydrogenPpm = (data.rawADC / 4095.0f) * 1000.0f;
    data.temperature = 24.5f + random(-10, 10) / 10.0f;
    data.humidity = 55.0f + random(-50, 50) / 10.0f;
    data.timestamp = millis();
    
    return data;
}