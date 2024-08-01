#include <iostream>
#include <assert.h>

#include "ColorPair.h"
#include "ColorUtils.h"
#include "gtest/gtest.h"

TEST(ColorUtilsTest, TestNumberToPair) {
    // Test case 1
    int pairNumber1 = 4;
    TelCoColorCoder::MajorColor expectedMajor1 = TelCoColorCoder::WHITE;
    TelCoColorCoder::MinorColor expectedMinor1 = TelCoColorCoder::BROWN;
    TelCoColorCoder::ColorPair colorPair1 = TelCoColorCoder::ColorUtils::GetColorFromPairNumber(pairNumber1);
    ASSERT_EQ(colorPair1.getMajor(), expectedMajor1);
    ASSERT_EQ(colorPair1.getMinor(), expectedMinor1);

    // Test case 2
    int pairNumber2 = 5;
    TelCoColorCoder::MajorColor expectedMajor2 = TelCoColorCoder::WHITE;
    TelCoColorCoder::MinorColor expectedMinor2 = TelCoColorCoder::SLATE;
    TelCoColorCoder::ColorPair colorPair2 = TelCoColorCoder::ColorUtils::GetColorFromPairNumber(pairNumber2);
    ASSERT_EQ(colorPair2.getMajor(), expectedMajor2);
    ASSERT_EQ(colorPair2.getMinor(), expectedMinor2);
}

TEST(ColorUtilsTest, TestPairToNumber) {
    // Test case 1
    TelCoColorCoder::MajorColor major1 = TelCoColorCoder::BLACK;
    TelCoColorCoder::MinorColor minor1 = TelCoColorCoder::ORANGE;
    int expectedPairNumber1 = 12;
    int pairNumber1 = TelCoColorCoder::ColorUtils::GetPairNumberFromColor(major1, minor1);
    ASSERT_EQ(pairNumber1, expectedPairNumber1);

    // Test case 2
    TelCoColorCoder::MajorColor major2 = TelCoColorCoder::VIOLET;
    TelCoColorCoder::MinorColor minor2 = TelCoColorCoder::SLATE;
    int expectedPairNumber2 = 25;
    int pairNumber2 = TelCoColorCoder::ColorUtils::GetPairNumberFromColor(major2, minor2);
    ASSERT_EQ(pairNumber2, expectedPairNumber2);
}

TEST(ColorUtilsTest, GetFormattedColorCoding) {
    std::string formattedString = TelCoColorCoder::ColorUtils::GetFormattedColorCoding();
    
    // Check if the formatted string contains the expected first and last pairs
    ASSERT_TRUE(formattedString.find("Pair Number: 1 - Major Color: White, Minor Color: Blue") != std::string::npos);
    ASSERT_TRUE(formattedString.find("Pair Number: 25 - Major Color: Violet, Minor Color: Slate") != std::string::npos);
    
    // Optionally, check the total number of pairs
    int expectedNumberOfPairs = TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors;
    int actualNumberOfPairs = std::count(formattedString.begin(), formattedString.end(), '\n');
    ASSERT_EQ(actualNumberOfPairs, expectedNumberOfPairs);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}