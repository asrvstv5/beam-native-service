#include "MeetingManager.h"

#include <gtest/gtest.h>

TEST(MeetingManagerTest, StartsMeeting) {
    MeetingManager manager;

    EXPECT_TRUE(manager.startMeeting("meeting-123"));
    EXPECT_TRUE(manager.isActive());
    EXPECT_EQ(manager.meetingId(), "meeting-123");
    EXPECT_EQ(manager.participantCount(), 0u);
}

TEST(MeetingManagerTest, CannotStartTwoMeetings) {
    MeetingManager manager;

    EXPECT_TRUE(manager.startMeeting("meeting-123"));
    EXPECT_FALSE(manager.startMeeting("meeting-456"));
    EXPECT_EQ(manager.meetingId(), "meeting-123");
}

TEST(MeetingManagerTest, TracksParticipants) {
    MeetingManager manager;

    ASSERT_TRUE(manager.startMeeting("meeting-123"));

    EXPECT_TRUE(manager.addParticipant("alice"));
    EXPECT_TRUE(manager.addParticipant("bob"));
    EXPECT_EQ(manager.participantCount(), 2u);

    EXPECT_TRUE(manager.removeParticipant("alice"));
    EXPECT_EQ(manager.participantCount(), 1u);
}

TEST(MeetingManagerTest, EndingMeetingClearsState) {
    MeetingManager manager;

    ASSERT_TRUE(manager.startMeeting("meeting-123"));
    ASSERT_TRUE(manager.addParticipant("alice"));

    EXPECT_TRUE(manager.endMeeting());
    EXPECT_FALSE(manager.isActive());
    EXPECT_TRUE(manager.meetingId().empty());
    EXPECT_EQ(manager.participantCount(), 0u);
}
