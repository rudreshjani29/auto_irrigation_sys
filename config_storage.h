#ifndef CONFIG_STORAGE_H
#define CONFIG_STORAGE_H

class ConfigStorage {
public:
    void begin();
    int getThreshold();
    void setThreshold(int value);
    bool getAutoMode();
    void setAutoMode(bool value);
    void end();
};

#endif
