#ifndef COLORUTILS_H
#define COLORUTILS_H

#include "ColorPair.h"

namespace TelCoColorCoder {


    class ColorUtils {
    public:
        static ColorPair GetColorFromPairNumber(int pairNumber);
        static int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    };
}

#endif // COLORUTILS_H