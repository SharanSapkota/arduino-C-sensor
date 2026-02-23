struct SensorData {
    int sensorId;
    float hydrogenPpm;
    int rawADC;
    float temperature;
    float humidity;
    unsigned long timestamp;
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

