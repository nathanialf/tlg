/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A name's record (derived names): a value the caller gives and the
 * position the name is written at, offset by a base. */
struct NameRecord001a3510 /* derived name */
{
    NameRecord001a3510(u32 value_, u32 position_) : value(value_), position(position_) {}

    u32 value;
    u32 position;
};

/* derived name: a name written to the stream on a 2-byte boundary with its
 * terminator (0x1a3510, called four times by 0x1a2030), its record pushed
 * first. */
void FUN_001a3510(const char *name, u32 value, int base, hkOstream &stream,
                  hkArray<NameRecord001a3510> &records)
{
    FUN_001a1e80(stream.FUN_00007f80(), 2);
    const int position = stream.FUN_00007f80()->tell() + base;
    records.pushBack(NameRecord001a3510(value, position));
    stream.FUN_000089f0(name, FUN_00017fe0(name) + 1);
}
