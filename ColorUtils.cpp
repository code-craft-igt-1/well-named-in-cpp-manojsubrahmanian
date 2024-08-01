#include <iostream>
#include <sstream>
#include "ColorUtils.h"

namespace TelCoColorCoder {


    ColorPair ColorUtils::GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = 
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int ColorUtils::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    std::string ColorUtils::GetFormattedColorCoding() {
        std::ostringstream oss;
        int pairNumber = 1;
        for (int major = 0; major < numberOfMajorColors; ++major) {
            for (int minor = 0; minor < numberOfMinorColors; ++minor) {
                ColorPair colorPair = GetColorFromPairNumber(pairNumber);
                oss << "Pair Number: " << pairNumber << " - "
                    << "Major Color: " << MajorColorNames[major] << ", "
                    << "Minor Color: " << MinorColorNames[minor] << "\n";
                ++pairNumber;
            }
        }
        return oss.str();
    }
}