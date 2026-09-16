#pragma once

#include <cstddef>
#include <string>

class MeetingManager {
public:
    bool startMeeting(const std::string& meetingId);
    bool endMeeting();

    bool isActive() const;
    std::string meetingId() const;

    std::size_t participantCount() const;
    bool addParticipant(const std::string& participantId);
    bool removeParticipant(const std::string& participantId);

private:
    bool active_{false};
    std::string meetingId_;
    std::size_t participantCount_{0};
};
