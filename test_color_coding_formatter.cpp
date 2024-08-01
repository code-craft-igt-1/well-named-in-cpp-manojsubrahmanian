#include <iostream>
#include <assert.h>
#include <algorithm> 

#include "ColorPair.h"
#include "ColorPairConverter.h"
#include "ColorCodingFormatter.h"
#include "gtest/gtest.h"

TEST(ColorCodingFormatterTest, TestFormattedColorCoding) {
    std::string formattedString = TelCoColorCoder::ColorCodingFormatter::GetFormattedColorCoding();
    
    // Check if the formatted string contains the expected first and last pairs
    ASSERT_TRUE(formattedString.find("Pair Number: 1 - Major Color: White, Minor Color: Blue") != std::string::npos);
    ASSERT_TRUE(formattedString.find("Pair Number: 25 - Major Color: Violet, Minor Color: Slate") != std::string::npos);
    
    // Optionally, check the total number of pairs
    int expectedNumberOfPairs = TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors;
    int actualNumberOfPairs = (int)std::count(formattedString.begin(), formattedString.end(), '\n');
    ASSERT_EQ(actualNumberOfPairs, expectedNumberOfPairs);
}
