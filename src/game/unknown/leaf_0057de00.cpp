/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_mutex.h"
#include "tlg_game_object016b7938.h"

/* derived names: the object at 0x5938c40 as slot 9 sees it: the record at
 * +0xb8 whose mutex at +0x18 the slot holds */
struct Record05938c40_b8 { /* derived name */
    u8 unknown0[0x18];
    Mutex013847e0 mutex; /* +0x18 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xb8];
    Record05938c40_b8 *unknownb8; /* +0xb8 */
};

extern Object05938c40 *D_5938c40;

/* derived names: the object of the reference at +0x60 as slot 9 sees it:
 * a count at +0x8c */
class Owner0057de00 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x68];
    int unknown8c; /* +0x8c */
};

/* derived names: the class whose vtable is at 0x16ab758
 * (config/vtables.derived.base.txt, stored by FUN_0057cf50 FUN_0057def0),
 * derived from Object016b7938 */
class Object016ab758 : public Object016b7938 /* derived name */
{
  public:
    virtual ~Object016ab758();         /* FUN_0057def0, not written */
    virtual int slot9(void *argument); /* derived name: FUN_0057de00 */
};

void FUN_0057d360(Object016ab758 *self); /* derived name */

/* derived names: slot 9 of the vtable at 0x16ab758 (its pointer at
 * 0x16ab7b0): with the object at +0x60 counting more than 0, nothing (0)
 * unless there is an argument and the names at +0x28 and +0x2c differ;
 * otherwise, under the mutex of the record at +0xb8 of the object at
 * 0x5938c40, the base class's slot 9 (FUN_00be0c40), and when it succeeds
 * with the names differing, FUN_0057d360; returns whether it succeeded.
 * The names are compared before anything is called. Class and method
 * unknown. */
// NONMATCHING: the names' comparison: the base sets it as a flag before the tests (`cmp edx, ecx;
// sete r15b` on each path) and keeps it across the calls, testing the count first, then the
// argument, then the names again (`setne al`); the build folds the argument and the names into one
// `or` before the count and spills the two indices, comparing them after the base's slot 9
// (self in rbx where the base has r13). Nested tests give the same
int Object016ab758::slot9(void *argument)
{
    bool same = name2c == name28;
    Owner0057de00 *owner = static_cast<Owner0057de00 *>(held60.get());
    if (owner && owner->unknown8c > 0 && (!argument || same))
        return 0;
    Mutex013847e0 &mutex = D_5938c40->unknownb8->mutex;
    mutex.lock();
    int result = FUN_00be0c40(this, argument);
    if (result && !same)
        FUN_0057d360(this);
    mutex.unlock();
    return result != 0;
}
