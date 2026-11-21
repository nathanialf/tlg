/* src/include/tlg_game_object00d68b80.h: the holder FUN_00d68b80 adds
 * counted objects to (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT00D68B80_H
#define TLG_GAME_OBJECT00D68B80_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: the holder FUN_001db8b0 links its objects through (249
 * calls of FUN_00d68b80): an array of counted references at +0x28 (count
 * +0x30, capacity +0x34, owner +0x38) and flags at +0x20, whose bit 1 says
 * an object was added. The rest is not traced. */
class Object00d68b80 /* derived name */
{
  public:
    /* 0xd68b80: a reference to the object kept once (the elements compared
     * first, `cmp [rax+rcx*8], r12; je`), the flag set; nothing for a null
     * object */
    void add(Object016b9108 *object); /* derived name */

  private:
    void link(const Ref00503fb0<Object016b9108> &held) /* derived name */
    {
        if (!objects.contains(held))
            objects.push(held);
    }

    u8 unknown0[0x20];
    u8 flags20; /* +0x20 */
    u8 unknown21[0x7];
    Array05943280<Ref00503fb0<Object016b9108>> objects; /* +0x28 */
};

#endif
