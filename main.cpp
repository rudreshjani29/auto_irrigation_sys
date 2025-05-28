#include <Arduino.h>
#include "wifi_manager.h"
#include "config_storage.h"
#include "sensor_manager.h"
#include "pump_controller.h"
#include "web_dashboard.h"

WiFiManager wifiManager;
ConfigStorage config;
SensorManager sensors;
PumpController pump;
WebDashboard web;

void setup() {
    Serial.begin(115200);
    delay(500);

    Serial.println("\nStarting Smart Irrigation System...");

    wifiManager.connect();
    config.begin();
    sensors.begin();
    pump.begin();
    web.begin();

    Serial.println("System initialized.\n");
}

void loop() {
    wifiManager.ensureConnection();  
    pump.update();                   
    delay(1000);                     
}
