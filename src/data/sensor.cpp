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
    bool isLeak = random(0, 10) > 7;

    if (isLeak) {
        data.hydrogenPpm = random(5000, 10000); 
    } else {
        data.hydrogenPpm = random(0, 500);
    }
    data.rawADC      = (data.hydrogenPpm / (float)SENSOR_MAX_PPM) * 4095;
    data.temperature = 24.5f + random(-20, 20) / 10.0f;
    data.humidity    = 55.0f + random(-50, 50) / 10.0f;
    data.timestamp   = millis();
    
    return data;
}