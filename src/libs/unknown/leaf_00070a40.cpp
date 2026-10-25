/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: a collector of 0x60-byte records, 0x3f0 bytes (vtable
 * address point 0x169b110; its deleting destructor 0x70970 frees 0x3f0
 * bytes). Slot 3 (0x70a10) resets it: clears the int at +8, reloads the
 * vector at +0x10 from a constant and empties the array at +0x20; slot 4
 * (0x70a50) appends a record; slot 6 (this function) tells whether any
 * record is held. */
struct CollectedRecord; /* derived name: 0x60 bytes */

class RecordCollector /* derived name */
{
  public:
    virtual ~RecordCollector();
    bool FUN_00070a40() const; /* vtable slot 6; derived name */

    int count8;                       /* derived name */
    Vec4 vector10;                    /* derived name */
    hkArray<CollectedRecord> records; /* derived name */
};

bool RecordCollector::FUN_00070a40() const /* derived name */
{
    return records.size != 0;
}
