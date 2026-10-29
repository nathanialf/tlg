/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkOstream &hkOstream::FUN_00008600(float value)
{
    char buffer[10024];
    FUN_00017e80(buffer, sizeof(buffer), "%f", value);
    writer->write(buffer, FUN_00017fe0(buffer));
    return *this;
}
