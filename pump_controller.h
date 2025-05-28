#ifndef PUMP_CONTROLLER_H
#define PUMP_CONTROLLER_H

class PumpController {
public:
    void begin();
    void update();
    void togglePumpManual();
    bool isPumpOn();
private:
    void setPump(bool state);
};

#endif
