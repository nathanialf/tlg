/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01439e30.h"
#include "tlg_game_object016d7eb0.h"

/* derived names: the class whose vtable is at 0x16d56e8 (three slots), the
 * part of Object016d5760 and Object016d5710 that FUN_013fb5f0 and FUN_013fb820 destroy after
 * storing this vtable, with the fields of Object016d52c8 (as the parts of
 * tlg_game_object0143e060.h: its destructor, implicit, is inlined into
 * both).
 * No destructor of its own in the executable. The slots are not traced. */
class Object016d56e8 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */

  private:
    u8 unknown8[0x8];
    OwnedBlock05943280 block10; /* +0x10 */
    u8 unknown18[0x10];
    Array05943280<List013e72e0<Pair014715d0>> lists28; /* +0x28: tlg_game_object016d7eb0.h */
    OwnedBlock05943280 block40;                        /* +0x40 */
    u8 unknown48[0x38];
    OwnedBlock05943280 block80; /* +0x80 */
    u8 unknown88[0x18];
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

/* FUN_013fb5f0: nothing of its own; the members' blocks are released last
 * first, the vtable of each part stored before its members go */
Object016d5760::~Object016d5760() {}

/* FUN_013fb820: the same over the other class */
Object016d5710::~Object016d5710() {}
