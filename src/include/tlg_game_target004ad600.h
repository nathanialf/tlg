/* src/include/tlg_game_target004ad600.h: the two arguments of the handlers
 * FUN_004acae0 stores in its table from 0x57d74c0 ("Marker.fire.enter" and
 * on; game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_TARGET004AD600_H
#define TLG_GAME_TARGET004AD600_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array.h"
#include "tlg_game_object004ac9b0.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived names: a handler's first argument (leaf_004ad600.cpp's self): the
 * name at +0x14 is what FUN_004ab790 looks up in the target */
struct Object004ad600 { /* derived name */
    u8 unknown0[0x14];
    Name unknown14; /* +0x14 */
};

/* derived names: a handler's second argument: four objects at +0xe8 to
 * +0x100, one for each of "Marker.fire1.enter" to "Marker.fire4.enter"
 * (FUN_004ad230, FUN_004ad2f0, FUN_004ad3b0, FUN_004ad470), each tested for
 * the type D_57d76f8 points to; the map FUN_004ab790 searches is at +0x108.
 * "Marker.firerange.enter" (FUN_004ad530) sets the bool at +0x1a8 and reads
 * the two floats after it from self's name ("leave", FUN_004ad5f0, clears it;
 * "Marker.settime.enter", FUN_004ad750, reads them too);
 * "Marker.clearlaunch.enter" (FUN_004ad6b0) empties the two arrays at +0x1b8
 * and +0x1d0, the objects of the first deleted */
struct Target004ad600 { /* derived name */
    u8 unknown0[0xe8];
    Object016b9108 *unknowne8;  /* +0xe8 */
    Object016b9108 *unknownf0;  /* +0xf0 */
    Object016b9108 *unknownf8;  /* +0xf8 */
    Object016b9108 *unknown100; /* +0x100 */
    u8 unknown108[0xa0];
    bool unknown1a8;  /* +0x1a8 */
    float unknown1ac; /* +0x1ac */
    float unknown1b0; /* +0x1b0 */
    u8 unknown1b4[4];
    Array05943280<Object004ac9b0 *> unknown1b8; /* +0x1b8 */
    Array05943280<void *> unknown1d0;           /* +0x1d0: pointers not traced */
};

/* derived names: the record at +0x88 of the record at +0x900 of the record
 * at +0x38 of the object at 0x57c9390, the first argument of FUN_004ae010;
 * "Marker.fire.enter" (FUN_004ad190) hands it its own object at +0xa8 */
struct Manager004ae010 { /* derived name */
    u8 unknown0[0xa8];
    Object016b9108 *unknowna8; /* +0xa8 */
};

struct Record057c9390_38_900 { /* derived name */
    u8 unknown0[0x88];
    Manager004ae010 *unknown88; /* +0x88 */
};

struct Record057c9390_38 { /* derived name */
    u8 unknown0[0x900];
    Record057c9390_38_900 *unknown900; /* +0x900 */
};

/* derived name: the record at +0x80 of the object at 0x57c9390: an object of
 * the class at 0x16b0468 that holds its flag at +0x3c is handed to
 * FUN_008e1020 by its destructor (FUN_008edf10) */
struct Manager008e1020; /* derived name */

struct Record057c9390 { /* derived name */
    u8 unknown0[0x38];
    Record057c9390_38 *unknown38; /* +0x38 */
    u8 unknown40[0x40];
    Manager008e1020 *unknown80; /* +0x80 */
};

extern Record057c9390 *D_57c9390;

/* derived name: the type the fire handlers' objects are tested for (the
 * record FUN_004adaf0 leaves for Object016aa098's constructor) */
extern Type00503fb0 *D_57d76f8;

/* the object leaf_01350fa0.cpp copies a value of; FUN_01352bb0 copies its
 * value at +0x120 */
struct Object01350fa0; /* derived name */

/* derived names: the object of the target's map at +0x108 under the name, or
 * null */
Object01350fa0 *FUN_004ab790(Target004ad600 *target, const Name &name); /* derived name */
void FUN_01352bb0(Float4A &value, Object01350fa0 *self);                /* derived name */
void FUN_004ae010(Manager004ae010 *manager, const Float4A &value,
                  Object016b9108 *object); /* derived name */

#endif
