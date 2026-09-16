# Beam Native Service

A C++20 native-service prototype inspired by real-time meeting/device integration.

## Milestone 1

This milestone models two core responsibilities:

- `MeetingManager`: meeting lifecycle and participant state.
- `DeviceManager`: camera and microphone state.

## Build

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/beam_native_service
```

Expected output:

```text
Beam Native Service started
Meeting: inactive
Camera: disabled
Microphone: disabled
```

## Next milestones

1. Thread-safe event queue
2. Concurrent meeting/device state
3. Native-service event loop
4. IPC/network boundary
5. Go <-> C++ integration
6. Meeting-provider simulation
7. Reliability and latency testing
