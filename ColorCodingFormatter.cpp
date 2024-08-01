#include <iostream>
#include <sstream>
#include "ColorCodingFormatter.h"
#include "ColorPair.h"

namespace TelCoColorCoder {

	std::string ColorCodingFormatter::GetFormattedColorCoding() {
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