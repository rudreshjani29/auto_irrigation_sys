#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

class SensorManager {
public:
    void begin();
    void updateReadings();
    int getMoisturePercent(int plantIndex);
    int numPlants();
};

#endif
