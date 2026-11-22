/* src/include/tlg_game_entry00a925e0.h: the entry whose destructor is
 * 0xa925e0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_ENTRY00A925E0_H
#define TLG_GAME_ENTRY00A925E0_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object013d35e0.h"

/* derived names: the kind of pool the entry refers to; nothing of it is
 * traced but its base */
class Pool00a925e0 : public Pool01343090
{
};

/* derived names: an entry of 0x5e0 bytes whose destructor is 0xa925e0
 * (leaf_00a925e0.cpp): the pool its reference at +0x5b0 holds given up,
 * its word at +0x48 reset first, then the Name at +0x0 released; its only
 * callers are the two destructors of leaf_00a920f0.cpp, one call per
 * entry. The rest is not traced. */
class Entry00a925e0
{
  public:
    ~Entry00a925e0();

  private:
    Name name0; /* +0x0 */
    u8 unknown4[0x5ac];
    PoolRef01343090<Pool00a925e0> pool; /* +0x5b0 */
    u8 unknown5b8[0x28];
};

#endif
