/* src/include/tlg_game_object016ce208.h: the class whose vtable is at
 * 0x16ce208 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE208_H
#define TLG_GAME_OBJECT016CE208_H

#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ce208
 * (config/vtables.derived.base.txt, stored by FUN_00a17390 FUN_0138ae00 FUN_0138aea0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0138ae00 tears them down
 * (the record at +0x28); the rest are not traced. */
class Object016ce208 : public Object016b9108 /* derived name */
{
  public:
    Object016ce208(const Name &name); /* FUN_00a17390 */
    /* FUN_00a174c0 (455 bytes, not written): the constructor passes it two
     * Names, a tail call */
    void FUN_00a174c0(const Name &first, const Name &second); /* derived name */
    virtual ~Object016ce208();

  private:
    u8 unknown24[0x4];
    /* +0x28: an array of references with its lock (`mov dword [rbx+0x3c],
     * 0` after the owner's index), torn down by the destructor (`lea rdi,
     * [rbx+0x28]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> array28;
};

#endif
