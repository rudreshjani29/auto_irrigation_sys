#include "pump_controller.h"
#include <Arduino.h>
#include "config_storage.h"
#include "sensor_manager.h"

#define PUMP_PIN 5
#define MOISTURE_CHECK_INTERVAL 10000 // ms

extern ConfigStorage config;
extern SensorManager sensors;

bool pumpState = false;
unsigned long lastCheck = 0;

void PumpController::begin() {
    pinMode(PUMP_PIN, OUTPUT);
    digitalWrite(PUMP_PIN, LOW); // pump off
}

void PumpController::update() {
    if (!config.getAutoMode()) return;

    unsigned long now = millis();
    if (now - lastCheck < MOISTURE_CHECK_INTERVAL) return;
    lastCheck = now;

    bool needsWater = false;
    sensors.updateReadings();

    int threshold = config.getThreshold();

    for (int i = 0; i < sensors.numPlants(); i++) {
        if (sensors.getMoisturePercent(i) < threshold) {
            needsWater = true;
            break;
        }
    }

    setPump(needsWater);
}

void PumpController::setPump(bool state) {
    pumpState = state;
    digitalWrite(PUMP_PIN, state ? HIGH : LOW);
    Serial.printf("💧 Pump turned %s\n", state ? "ON" : "OFF");
}

void PumpController::togglePumpManual() {
    bool manualState = !pumpState;
    config.setAutoMode(false); // auto off when manually controlled
    setPump(manualState);
}

bool PumpController::isPumpOn() {
    return pumpState;
}
