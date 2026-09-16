#pragma once

class DeviceManager {
public:
    void enableCamera();
    void disableCamera();

    void enableMicrophone();
    void disableMicrophone();

    bool cameraEnabled() const;
    bool microphoneEnabled() const;

private:
    bool cameraEnabled_{false};
    bool microphoneEnabled_{false};
};
