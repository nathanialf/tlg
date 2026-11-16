/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01439e30.h"

/* derived name: the 24-byte element of the array at +0x28 of Object016d56e8
 * (as Element01439e30): this unit's own type, as the base holds the array's
 * destructor inlined into each destructor of the unit */
struct Element013fb5f0 : Element01439e30 { /* derived name */
};

/* derived names: the class whose vtable is at 0x16d56e8 (three slots), the
 * part of Object016d5760 and Object016d5710 that FUN_013fb5f0 and FUN_013fb820 destroy after
 * storing this vtable, laid out as Object016d5e90 (tlg_game_object01439e30.h).
 * No destructor of its own in the executable. The slots are not traced. */
class Object016d56e8 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    Array05943280<int> array10;             /* +0x10 */
    Array05943280<Element013fb5f0> array28; /* +0x28 */
    Array05943280<Element01439a20> array40; /* +0x40 */
    u8 unknown58[0x28];
    Array05943280<int> array80; /* +0x80 */
    u8 unknown98[0x8];
};

/* derived names: the class whose vtable is at 0x16d5760 (eight slots),
 * over Object016d56e8, laid out as Object016d5eb8 (tlg_game_object01439e30.h). Its
 * destructor FUN_013fb5f0 is not virtual (no slot holds it). The slots are not
 * traced. */
class Object016d5760 : public Object016d56e8 /* derived name */
{
  public:
    ~Object016d5760();

    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */

  private:
    u8 unknowna0[0x28];
    OwnedBlock05943280 blockc8; /* +0xc8 */
    u8 unknownd0[0x20];
    Array05943280<int> arrayf0; /* +0xf0 */
    u8 unknown108[0x48];
};

/* derived names: the class whose vtable is at 0x16d5710 (eight slots),
 * over Object016d56e8, laid out as Object016d5eb8 (tlg_game_object01439e30.h). Its
 * destructor FUN_013fb820 is not virtual (no slot holds it). The slots are not
 * traced. */
class Object016d5710 : public Object016d56e8 /* derived name */
{
  public:
    ~Object016d5710();

    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(); /* derived name; not traced */
    virtual void slot6(); /* derived name; not traced */
    virtual void slot7(); /* derived name; not traced */

  private:
    u8 unknowna0[0x28];
    OwnedBlock05943280 blockc8; /* +0xc8 */
    u8 unknownd0[0x20];
    Array05943280<int> arrayf0; /* +0xf0 */
    u8 unknown108[0x48];
};

// NONMATCHING: the base part's destructor (Object016d56e8's implicit one, 0x19c
// bytes) has two callers in the unit, so neither stage inlines it (the link's
// single-caller credit is what inlines it into 0x1439e30, one class over its
// base): the build calls it (163 bytes against 556). The base holds it inlined
// in both, as in the six other pairs of this shape (0x140d9d0 to 0x1468170).
/* FUN_013fb5f0: nothing of its own; the members' blocks are released last
 * first, the vtable of each part stored before its members go */
Object016d5760::~Object016d5760() {}

/* FUN_013fb820: the same over the other class */
Object016d5710::~Object016d5710() {}
