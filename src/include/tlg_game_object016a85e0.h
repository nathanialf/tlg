/* src/include/tlg_game_object016a85e0.h: the class whose vtable is at
 * 0x16a85e0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A85E0_H
#define TLG_GAME_OBJECT016A85E0_H

#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a85e0
 * (config/vtables.derived.base.txt, stored by FUN_00325330 FUN_003255b0),
 * derived from Object016b9108: its slots 2 to 4 are the base's. 0x80 bytes
 * (the factory FUN_00325330 allocates 0x80). Its own fields from +0x24 are
 * traced where its destructor FUN_003255b0 tears them down (the Names at
 * +0x58, +0x28, +0x24) and where reset() (FUN_003254b0, called by the factory
 * and by FUN_00301810) empties them: the names made empty, the 32 bytes at
 * +0x30 and +0x60 and the 8 at +0x50 cleared; the rest are not traced. */
class Object016a85e0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a85e0();

    void reset();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    u32 unknown2c;
    u8 unknown30[0x20]; /* +0x30 */
    u64 unknown50;      /* +0x50 */
    Name name58;        /* +0x58: released by the destructor (`mov eax, [rbx+0x58]; shl 5`) */
    u32 unknown5c;
    u8 unknown60[0x20]; /* +0x60 */
};

#endif
