#include "MeetingManager.h"

bool MeetingManager::startMeeting(const std::string& meetingId) {
    if (active_ || meetingId.empty()) {
        return false;
    }

    active_ = true;
    meetingId_ = meetingId;
    participantCount_ = 0;
    return true;
}

bool MeetingManager::endMeeting() {
    if (!active_) {
        return false;
    }

    active_ = false;
    meetingId_.clear();
    participantCount_ = 0;
    return true;
}

bool MeetingManager::isActive() const {
    return active_;
}

std::string MeetingManager::meetingId() const {
    return meetingId_;
}

std::size_t MeetingManager::participantCount() const {
    return participantCount_;
}

bool MeetingManager::addParticipant(const std::string& participantId) {
    if (!active_ || participantId.empty()) {
        return false;
    }

    ++participantCount_;
    return true;
}

bool MeetingManager::removeParticipant(const std::string& participantId) {
    if (!active_ || participantId.empty() || participantCount_ == 0) {
        return false;
    }

    --participantCount_;
    return true;
}
