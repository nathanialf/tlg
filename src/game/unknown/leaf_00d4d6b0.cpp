/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the class whose complete destructor is 0xd237d0 (its row
 * named for it, D15), as leaf_0081b370.cpp declares it */
class Object00d237d0 /* derived name */
{
  public:
    virtual ~Object00d237d0();
};

/* derived names: the object D_5835fb0 points to, as far as the destructor
 * below reads it: the record at +0x45f0 it hands to FUN_00b88940 */
struct Record00d4d6b0 {
    u8 unknown0[0x1];
};

struct Object05835fb0 {
    u8 unknown0[0x45f0];
    Record00d4d6b0 record45f0; /* +0x45f0 */
};

extern Object05835fb0 *D_5835fb0;

void FUN_00b88940(Record00d4d6b0 *record, int index); /* derived name; not traced */

/* derived names: elements of the two arrays below with nothing to release
 * (not traced) */
struct Element00d4d6b0 {
    u8 unknown0[0x4];
};

/* derived names: the class whose vtable is at 0x16ba730
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00d4d3b0
 * and its destructor FUN_00d4d6b0), derived from Object00d237d0 (the class
 * whose destructor is 0xd237d0): the base's slots and fields are not
 * traced, so the bytes below the first member here are the base's or this
 * class's. Its own fields are traced where the destructor reads them or
 * tears them down: counted references from +0xf8 to +0x260, an index at
 * +0x160 (none when negative), two arrays at +0x168 and +0x200 and a name
 * at +0x258. */
class Object016ba730 : public Object00d237d0 /* derived name */
{
  public:
    virtual ~Object016ba730();

  private:
    u8 unknown8[0xf0];
    Ref00503fb0<Object016b9108> heldF8;  /* +0xf8 */
    Ref00503fb0<Object016b9108> held100; /* +0x100 */
    u8 unknown108[0x58];
    int index160; /* +0x160: handed back to the record when not negative */
    u8 unknown164[0x4];
    Array05943280<Element00d4d6b0> array168; /* +0x168 */
    u8 unknown180[0x60];
    Ref00503fb0<Object016b9108> held1e0; /* +0x1e0 */
    Ref00503fb0<Object016b9108> held1e8; /* +0x1e8 */
    u8 unknown1f0[0x8];
    Ref00503fb0<Object016b9108> held1f8;     /* +0x1f8 */
    Array05943280<Element00d4d6b0> array200; /* +0x200 */
    u8 unknown218[0x38];
    Ref00503fb0<Object016b9108> held250; /* +0x250 */
    Name name258;                        /* +0x258 */
    u8 unknown25c[0x4];
    Ref00503fb0<Object016b9108> held260; /* +0x260 */
};

/* derived name: the complete destructor FUN_00d4d6b0: the index handed to
 * FUN_00b88940 with the record at +0x45f0 of D_5835fb0 when it is not
 * negative; the members are released, last first, then the base's
 * destructor 0xd237d0 runs as a tail call. FUN_00d4db40, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ba730::~Object016ba730()
{
    if (index160 >= 0)
        FUN_00b88940(&D_5835fb0->record45f0, index160);
}
