#include "DeviceManager.h"

#include <gtest/gtest.h>

TEST(DeviceManagerTest, DevicesStartDisabled) {
    DeviceManager manager;

    EXPECT_FALSE(manager.cameraEnabled());
    EXPECT_FALSE(manager.microphoneEnabled());
}

TEST(DeviceManagerTest, CanToggleCamera) {
    DeviceManager manager;

    manager.enableCamera();
    EXPECT_TRUE(manager.cameraEnabled());

    manager.disableCamera();
    EXPECT_FALSE(manager.cameraEnabled());
}

TEST(DeviceManagerTest, CanToggleMicrophone) {
    DeviceManager manager;

    manager.enableMicrophone();
    EXPECT_TRUE(manager.microphoneEnabled());

    manager.disableMicrophone();
    EXPECT_FALSE(manager.microphoneEnabled());
}
