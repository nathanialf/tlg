/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013d35e0.h"

/* derived names: an object the record below owns: polymorphic, deleted
 * through its vtable's slot 1 (`call [rax+8]`); nothing else is traced */
class Element004adde0 /* derived name */
{
  public:
    virtual ~Element004adde0();
};

/* derived name: the kind of pool the record below refers to; nothing of it
 * is traced but its base */
class Pool004adde0 : public Pool01343090 /* derived name */
{
};

/* derived names: the record at +0x88 of the record FUN_004816c0 ends (also
 * handed to this function by FUN_0047f7e0): two lists of owned objects, each
 * a block and a signed count (`mov r15d, [r14+8]; test r15d, r15d; jle`, the
 * count read once, the block at each pass), a counted reference at +0x78
 * and a reference to a pool at +0xb0. The rest is not traced. */
struct Record004816c0 {          /* derived name */
    Element004adde0 **elements0; /* +0x0 */
    int count8;                  /* +0x8 */
    u8 unknownc[0xc];
    Element004adde0 **elements18; /* +0x18 */
    int count20;                  /* +0x20 */
    u8 unknown24[0x54];
    AtomicRef0045c470<Object016b9108> held78; /* +0x78 */
    u8 unknown80[0x30];
    PoolRef01343090<Pool004adde0> poolb0; /* +0xb0 */
};

/* derived name: empties the record: both lists' objects deleted and their
 * counts cleared, the pool given up (PoolRef01343090::shutdown()), then the
 * reference at +0x78 emptied */
void FUN_004adde0(Record004816c0 *record) /* derived name */
{
    for (int i = 0, count = record->count8; i < count; ++i)
        delete record->elements0[i];
    for (int i = 0, count = record->count20; i < count; ++i)
        delete record->elements18[i];
    record->count8 = 0;
    record->count20 = 0;
    record->poolb0.shutdown();
    record->held78.clear();
}
