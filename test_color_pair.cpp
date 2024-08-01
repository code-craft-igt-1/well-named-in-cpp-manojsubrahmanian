#include <gtest/gtest.h>
#include "ColorPair.h"


TEST(ColorPairTest, TestConstructor) {
    TelCoColorCoder::ColorPair colorPair(TelCoColorCoder::WHITE, TelCoColorCoder::BLUE);
    ASSERT_EQ(colorPair.getMajor(), TelCoColorCoder::WHITE);
    ASSERT_EQ(colorPair.getMinor(), TelCoColorCoder::BLUE);
}

TEST(ColorPairTest, TestGetMajor) {
    TelCoColorCoder::ColorPair colorPair(TelCoColorCoder::RED, TelCoColorCoder::ORANGE);
    ASSERT_EQ(colorPair.getMajor(), TelCoColorCoder::RED);
}

TEST(ColorPairTest, TestGetMinor) {
    TelCoColorCoder::ColorPair colorPair(TelCoColorCoder::BLACK, TelCoColorCoder::GREEN);
    ASSERT_EQ(colorPair.getMinor(), TelCoColorCoder::GREEN);
}

TEST(ColorPairTest, TestToString) {
    TelCoColorCoder::ColorPair colorPair(TelCoColorCoder::YELLOW, TelCoColorCoder::BROWN);
    std::string expectedString = "Yellow Brown";
    ASSERT_EQ(colorPair.ToString(), expectedString);
}

TEST(ColorPairTest, TestToStringWithDifferentColors) {
    TelCoColorCoder::ColorPair colorPair(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE);
    std::string expectedString = "Violet Slate";
    ASSERT_EQ(colorPair.ToString(), expectedString);
}
