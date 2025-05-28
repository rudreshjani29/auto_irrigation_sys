#include <Preferences.h>
#include "config_storage.h"

Preferences preferences;

void ConfigStorage::begin() {
    preferences.begin("irrigation", false);
}

int ConfigStorage::getThreshold() {
    return preferences.getInt("threshold", 30); // default 30%
}

void ConfigStorage::setThreshold(int value) {
    preferences.putInt("threshold", value);
}

bool ConfigStorage::getAutoMode() {
    return preferences.getBool("auto_mode", true); // default is auto ON
}

void ConfigStorage::setAutoMode(bool value) {
    preferences.putBool("auto_mode", value);
}

void ConfigStorage::end() {
    preferences.end();
}
