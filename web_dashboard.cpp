#include "web_dashboard.h"
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "config_storage.h"
#include "pump_controller.h"
#include "sensor_manager.h"

AsyncWebServer server(80);

extern ConfigStorage config;
extern PumpController pump;
extern SensorManager sensors;

void WebDashboard::begin() {
    if (!SPIFFS.begin(true)) {
        Serial.println("Failed to mount SPIFFS");
        return;
    }

    // Serve index.html
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SPIFFS, "/index.html", "text/html");
    });

    // API: /status
    server.on("/status", HTTP_GET, [](AsyncWebServerRequest *request){
        String json = "{";
        json += "\"auto\":" + String(config.getAutoMode() ? "true" : "false") + ",";
        json += "\"threshold\":" + String(config.getThreshold()) + ",";
        json += "\"pump\":" + String(pump.isPumpOn() ? "true" : "false") + ",";
        json += "\"moisture\":[";
        for (int i = 0; i < sensors.numPlants(); i++) {
            json += String(sensors.getMoisturePercent(i));
            if (i < sensors.numPlants() - 1) json += ",";
        }
        json += "]}";
        request->send(200, "application/json", json);
    });

    // API: /setAuto
    server.on("/setAuto", HTTP_POST, [](AsyncWebServerRequest *request){
        if (request->hasParam("value", true)) {
            bool mode = request->getParam("value", true)->value() == "true";
            config.setAutoMode(mode);
            request->send(200, "text/plain", "OK");
        } else {
            request->send(400, "text/plain", "Missing param");
        }
    });

    // API: /setThreshold
    server.on("/setThreshold", HTTP_POST, [](AsyncWebServerRequest *request){
        if (request->hasParam("value", true)) {
            int threshold = request->getParam("value", true)->value().toInt();
            config.setThreshold(threshold);
            request->send(200, "text/plain", "OK");
        } else {
            request->send(400, "text/plain", "Missing param");
        }
    });

    // API: /togglePump
    server.on("/togglePump", HTTP_POST, [](AsyncWebServerRequest *request){
        pump.togglePumpManual();
        request->send(200, "text/plain", "Toggled");
    });

    server.begin();
    Serial.println("🌐 Web dashboard started at http://<ESP32-IP>");
}
