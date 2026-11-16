/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b8a80.h"

/* the object at the record's +0x30, of a class over
 * Object016b9108 (not traced): the constructor compares it first with the
 * reference's old object after the exchange (`cmp rcx, rbx` at 0xc93034), as
 * AtomicRef0045c470::set compares a pointer converted from a class over T */
class Node05938c40_38_30 : public Object016b9108 /* derived name */
{
};

/* derived names: the record the pointer at 0x5938c40 holds, and the record
 * at its +0x38, whose object at +0x30 the constructor below takes (`mov
 * rax, [rax+0x38]; mov rcx, [rax+0x30]`). */
struct Member05938c40_38 {
    u8 unknown0[0x30];
    Node05938c40_38_30 *unknown30;
};

struct Object05938c40 {
    u8 unknown0[0x38];
    Member05938c40_38 *unknown38;
};

extern Object05938c40 *D_5938c40;

/* derived name: the constructor (tlg_game_object016b8a80.h): its base
 * Object016b9108 is built from the name passed on, the two references start
 * empty (one 16-byte clear at +0x28); then the body: the reference at +0x30
 * set to the object the global record's member at +0x38 holds at +0x30, and
 * the value at +0x40. */
Object016b8a80::Object016b8a80(const Name &name) : Object016b9108(name)
{
    held30.set(D_5938c40->unknown38->unknown30);
    unknown40 = Float4A(1.0f, 1.0f, 0.0f, 0.0f);
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor is inlined (its vptr store, then the two names). FUN_00c93280, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b8a80::~Object016b8a80() {}
