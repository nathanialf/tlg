/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b7e18
 * (config/vtables.derived.base.txt), over Object01343880 (slots 5, 6 and 8
 * its, slot 7 overridden here). Its constructor FUN_00bff9d0 (not written)
 * clears +0x38 to +0x58, stores 1.0 at +0x5c, 5 as the word at +0x60 and
 * zero at +0x68, then hands a reference to the object to FUN_00bed900. Slot
 * 7 is the class's first virtual not defined in the class, so this unit
 * emits the vtable and with it the inline destructor: its complete
 * destructor 0x13a1bc0 a jump to the base-object one 0x13a1bf0 (D45), its
 * deleting destructor 0x13a1bd0. */
class Object016b7e18 : public Object01343880 /* derived name */
{
  public:
    /* the base-object destructor FUN_013a1bf0: the body is empty; the names
     * at +0x6c and +0x58 and the references at +0x50 and +0x48 are released
     * in that order, then the base's members (Object016b9108's names at
     * +0x10 and +0xc) */
    virtual ~Object016b7e18() {}

    /* slot 7, FUN_00bffb00: named as the base's slot is (an override carries
     * the base's name) */
    virtual void FUN_001af750();

  private:
    void *unknown38;                    /* +0x38: null from the constructor; not traced */
    void *unknown40;                    /* +0x40: null from the constructor; not traced */
    Ref00503fb0<Object016b9108> held48; /* +0x48: released by the destructor */
    Ref00503fb0<Object016b9108> held50; /* +0x50: released by the destructor */
    Name name58;                        /* +0x58: empty from the constructor */
    float unknown5c;                    /* +0x5c: 1.0 from the constructor; not traced */
    u8 unknown60 : 1; /* bit 0 of the byte at +0x60, tested by slot 7; its other bits not traced */
    int unknown64;    /* +0x64: set to 1 by slot 7 */
    int unknown68;    /* +0x68: zero from the constructor; not traced */
    Name name6c;      /* +0x6c: empty from the constructor */
};

/* derived names: slot 7 of the vtable at 0x16b7e18 (its pointer at
 * 0x16b7e60): sets the int at +0x64 to 1 when bit 0 of the byte at +0x60 is
 * set (testb $1: a one-bit field, as a bool member compiles to cmpb $0) */
void Object016b7e18::FUN_001af750()
{
    if (unknown60)
        unknown64 = 1;
}
