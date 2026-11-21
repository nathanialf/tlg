/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16d3578
 * (config/vtables.derived.base.txt): a 16-byte class over hkReferencedObject
 * (slots 2 to 4 hkReferencedObject's) with an empty destructor (slot 0 the
 * shared empty body 0x1af750, slot 1 0x13cca40's body). FUN_00e9a5f0 makes
 * one on its stack before the class at 0x16c9fe8 is set over it. */
class Object016d3578 : public hkReferencedObject /* derived name */
{
  public:
    virtual ~Object016d3578() {}
};

/* derived names: what the class at 0x16c9fe8 is given (FUN_00e9a5f0 fills
 * it on its stack before the call to 0xea610): the object it was made for,
 * held counted at +0x10, two pointers into that object's arrays (its +0x60
 * and +0x68 indexed by an entry of its +0x70), the entry's ints at +0x28 and
 * +0x30 and the entry's index at +0x30. Not traced further. */
struct Input016c9fe8 /* derived name */
{
    Ref00503fb0<Object016b9108> owner; /* +0x10 */
    void *unknown18;                   /* +0x18 */
    void *unknown20;                   /* +0x20 */
    int unknown28;                     /* +0x28 */
    int unknown2c;                     /* +0x2c: slot 5 (FUN_00eb2890) returns it */
    int unknown30;                     /* +0x30 */
};

/* derived names: the class whose vtable is at 0x16c9fe8 (stored by
 * FUN_00e9a5f0, FUN_00ea53a0 and FUN_00ea5be0), 0x38 bytes: the base at
 * 0x16d3578 and its input. Its destructor stores no vptr: its own body and
 * fields are empty, the counted reference is the input's (as cookbook 91's
 * array). Its delete frees the class's own size (0x13ccb20: `mov edx, 0x38`
 * after a null test). */
class Object016c9fe8 : public Object016d3578, public Input016c9fe8 /* derived name */
{
  public:
    virtual ~Object016c9fe8();

    static void operator delete(void *object, unsigned long numBytes)
    {
        if (object) {
            D_16dc070->temp58->blockFree(object, int(numBytes));
        }
    }
};

Object016c9fe8::~Object016c9fe8() {}
