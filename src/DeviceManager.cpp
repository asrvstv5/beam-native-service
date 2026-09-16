#include "DeviceManager.h"

void DeviceManager::enableCamera() {
    cameraEnabled_ = true;
}

void DeviceManager::disableCamera() {
    cameraEnabled_ = false;
}

void DeviceManager::enableMicrophone() {
    microphoneEnabled_ = true;
}

void DeviceManager::disableMicrophone() {
    microphoneEnabled_ = false;
}

bool DeviceManager::cameraEnabled() const {
    return cameraEnabled_;
}

bool DeviceManager::microphoneEnabled() const {
    return microphoneEnabled_;
}
