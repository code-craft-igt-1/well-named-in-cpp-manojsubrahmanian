#include <iostream>
#include <sstream>
#include "ColorPairConverter.h"

namespace TelCoColorCoder {

    ColorPair ColorPairConverter::GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = 
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int ColorPairConverter::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    std::string ColorPairConverter::GetFormattedColorCoding() {
        std::ostringstream oss;
        int pairNumber = 1;
        for (int major = 0; major < numberOfMajorColors; ++major) {
            for (int minor = 0; minor < numberOfMinorColors; ++minor) {
                oss << "Pair Number: " << pairNumber << " - "
                    << "Major Color: " << MajorColorNames[major] << ", "
                    << "Minor Color: " << MinorColorNames[minor] << "\n";
                ++pairNumber;
            }
        }
        return oss.str();
    }
}