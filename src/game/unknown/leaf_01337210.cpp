/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_01337210: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_creation.h"

/* derived names: under the spin lock at +0x38 of the record at +0x98 of the
 * object the pointer at 0x57c9390 holds, calls slot 3 of the object at +0x48
 * of the object the pointer at 0x5938c40 holds with the record's pointer at
 * +0x28 and 1, then gives back the record's second lock at +0x130, taken
 * elsewhere. FUN_0069d360 calls slot 4 with the same pointer. The classes,
 * the slot's second parameter and return type are not traced. */
struct Member057c9390_98_28; /* derived name */

class Member05938c40_48 /* derived name */
{
  public:
    virtual void slot0();                                         /* derived name; not traced */
    virtual void slot1();                                         /* derived name; not traced */
    virtual void slot2();                                         /* derived name; not traced */
    virtual void slot3(Member057c9390_98_28 *value, int unknown); /* derived name; not traced */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x48];
    Member05938c40_48 *unknown48; /* +0x48 */
};

extern Object05938c40 *D_5938c40;

struct Member057c9390_98 { /* derived name */
    u8 unknown0[0x28];
    Member057c9390_98_28 *unknown28; /* +0x28 */
    u8 unknown30[0x8];
    Lock059458a4 lock38; /* +0x38 */
    u8 unknown3c[0xf4];
    Lock059458a4 lock130; /* +0x130 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0x98];
    Member057c9390_98 *unknown98; /* +0x98 */
};

extern Object057c9390 *D_57c9390;

void FUN_01337210() /* derived name */
{
    Member057c9390_98 *record = D_57c9390->unknown98;
    record->lock38.lock();
    D_5938c40->unknown48->slot3(record->unknown28, 1);
    record->lock130.unlock();
    record->lock38.unlock();
}
