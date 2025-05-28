#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

class WiFiManager {
public:
    void connect();
    bool isConnected();
    void ensureConnection();
};

#endif
