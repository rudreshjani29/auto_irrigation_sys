#include "sensor_manager.h"
#include <Arduino.h>

#define NUM_PLANTS 16

const int sensorPins[NUM_PLANTS] = {
    32, 33, 34, 35, 36, 39, 25, 26,
    27, 14, 12, 13, 4,  15, 2,  0
};

int moistureValues[NUM_PLANTS];

void SensorManager::begin() {
    for (int i = 0; i < NUM_PLANTS; i++) {
        pinMode(sensorPins[i], INPUT);
    }
}

void SensorManager::updateReadings() {
    for (int i = 0; i < NUM_PLANTS; i++) {
        int raw = analogRead(sensorPins[i]);
        moistureValues[i] = constrain(map(raw, 300, 1023, 0, 100), 0, 100);
    }
}

int SensorManager::getMoisturePercent(int plantIndex) {
    if (plantIndex < 0 || plantIndex >= NUM_PLANTS) return -1;
    return moistureValues[plantIndex];
}

int SensorManager::numPlants() {
    return NUM_PLANTS;
}
