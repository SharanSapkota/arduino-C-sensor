#include "sensor.h"
#include <Arduino.h>

// MQ-8 constants
#define MQ8_RL 10.0      
#define MQ8_RO_CLEAN 9.83 
#define MQ8_VREF 3.3     

Sensor::Sensor(int sensorId, int analogPin) {
    this->sensorId = sensorId;
    this->analogPin = analogPin;
}

SensorData Sensor::getRealData() {
    SensorData data;

    int rawADC = analogRead(analogPin);

    // convert ADC to voltage
    float voltage = (rawADC / 4095.0) * MQ8_VREF;

    // convert voltage to sensor resistance (RS)
    float rs = ((MQ8_VREF - voltage) / voltage) * MQ8_RL;

    // convert RS to ppm using MQ-8 datasheet formula
    float ratio = rs / MQ8_RO_CLEAN;
    float ppm = 987.99 * pow(ratio, -2.162); // MQ-8 hydrogen curve

    data.sensorId = this->sensorId;
    data.hydrogenPpm = ppm;
    data.rawADC = rawADC;
    data.temperature = 25.0;  // replace with BME280 reading later
    data.humidity = 50.0;     // replace with BME280 reading later
    data.timestamp = millis();

    return data;
}


SensorData Sensor::getMockData() {
    SensorData data;

    bool isLeaking = (random(0, 100) < 10);

    data.sensorId = this->sensorId;
    data.hydrogenPpm = isLeaking ? random(200, 500) : random(0, 50);
    data.rawADC = random(100, 4095);
    data.temperature = random(20, 35); 
    data.humidity = random(30, 80); 
    data.timestamp = millis();

    return data;
}