#include 
#include <PubSubClient.h>
#include <WiFi.h>

class Mqtt {
    private:
        const char* brokerIP;
        const char* brokerPort;
        const char* clientId;
        PubSubClient client;
    
    public:
        Mqtt(const char* brokerIP, const char* brokerPort, const char* clientId);
        void connect();
        void publish(SensorData data);
        bool isConnected();
}

