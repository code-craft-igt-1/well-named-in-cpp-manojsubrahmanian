#include <iostream>
#include <assert.h>
#include <algorithm> 

#include "ColorPair.h"
#include "ColorPairConverter.h"
#include "ColorCodingFormatter.h"
#include "gtest/gtest.h"

TEST(ColorConverterTest, TestNumberToPair) {
    // Test case 1
    int pairNumber1 = 4;
    TelCoColorCoder::MajorColor expectedMajor1 = TelCoColorCoder::WHITE;
    TelCoColorCoder::MinorColor expectedMinor1 = TelCoColorCoder::BROWN;
    TelCoColorCoder::ColorPair colorPair1 = TelCoColorCoder::ColorPairConverter::GetColorFromPairNumber(pairNumber1);
    ASSERT_EQ(colorPair1.getMajor(), expectedMajor1);
    ASSERT_EQ(colorPair1.getMinor(), expectedMinor1);

    // Test case 2
    int pairNumber2 = 5;
    TelCoColorCoder::MajorColor expectedMajor2 = TelCoColorCoder::WHITE;
    TelCoColorCoder::MinorColor expectedMinor2 = TelCoColorCoder::SLATE;
    TelCoColorCoder::ColorPair colorPair2 = TelCoColorCoder::ColorPairConverter::GetColorFromPairNumber(pairNumber2);
    ASSERT_EQ(colorPair2.getMajor(), expectedMajor2);
    ASSERT_EQ(colorPair2.getMinor(), expectedMinor2);
}

TEST(ColorConverterTest, TestPairToNumber) {
    // Test case 1
    TelCoColorCoder::MajorColor major1 = TelCoColorCoder::BLACK;
    TelCoColorCoder::MinorColor minor1 = TelCoColorCoder::ORANGE;
    int expectedPairNumber1 = 12;
    int pairNumber1 = TelCoColorCoder::ColorPairConverter::GetPairNumberFromColor(major1, minor1);
    ASSERT_EQ(pairNumber1, expectedPairNumber1);

    // Test case 2
    TelCoColorCoder::MajorColor major2 = TelCoColorCoder::VIOLET;
    TelCoColorCoder::MinorColor minor2 = TelCoColorCoder::SLATE;
    int expectedPairNumber2 = 25;
    int pairNumber2 = TelCoColorCoder::ColorPairConverter::GetPairNumberFromColor(major2, minor2);
    ASSERT_EQ(pairNumber2, expectedPairNumber2);
}

