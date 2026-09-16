#include "DeviceManager.h"
#include "MeetingManager.h"

#include <iostream>

int main() {
    MeetingManager meeting;
    DeviceManager device;

    std::cout << "Beam Native Service started\n";
    std::cout << "Meeting: "
              << (meeting.isActive() ? "active" : "inactive") << "\n";
    std::cout << "Camera: "
              << (device.cameraEnabled() ? "enabled" : "disabled") << "\n";
    std::cout << "Microphone: "
              << (device.microphoneEnabled() ? "enabled" : "disabled") << "\n";

    return 0;
}
