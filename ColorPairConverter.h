#ifndef COLORPAIRCONVERTER_H
#define COLORPAIRCONVERTER_H

#include "ColorPair.h"

namespace TelCoColorCoder {

    class ColorPairConverter {
    public:
        static ColorPair GetColorFromPairNumber(int pairNumber);
        static int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    };
}

#endif // COLORPAIRCONVERTER_H