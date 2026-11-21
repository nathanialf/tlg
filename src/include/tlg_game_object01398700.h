/* src/include/tlg_game_object01398700.h: the settings an object of the
 * class whose vtable is at 0x16cfb98 copies from the simulation it holds at
 * +0xa0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT01398700_H
#define TLG_GAME_OBJECT01398700_H

#include "tlg_game_object016b9108.h"

/* derived names: the 0x34 bytes each of the simulation's first two items
 * holds in its base at +0x40 (the cast keeps a null: `lea rcx, [rax+0x40];
 * test rax, rax; cmove rcx, rax` at 0xb418ab): eleven words copied one by
 * one in their order (`mov eax, [rcx]; mov [rdi+0xb0], eax` and on), then
 * the pair at +0x2c in one 8-byte move */
struct Pair01398700 { /* derived name */
    u32 first;
    u32 second;
};

struct ItemSettings01398700 { /* derived name */
    u32 unknown0;
    u32 unknown4;
    u32 unknown8;
    u32 unknownc;
    u32 unknown10;
    u32 unknown14;
    u32 unknown18;
    u32 unknown1c;
    u32 unknown20;
    u32 unknown24;
    u32 unknown28;
    Pair01398700 unknown2c; /* +0x2c */

    void copy(const ItemSettings01398700 &other) /* derived name */
    {
        unknown0 = other.unknown0;
        unknown4 = other.unknown4;
        unknown8 = other.unknown8;
        unknownc = other.unknownc;
        unknown10 = other.unknown10;
        unknown14 = other.unknown14;
        unknown18 = other.unknown18;
        unknown1c = other.unknown1c;
        unknown20 = other.unknown20;
        unknown24 = other.unknown24;
        unknown28 = other.unknown28;
        unknown2c = other.unknown2c;
    }
};

struct ItemHead01398700 { /* derived name */
    u8 unknown0[0x40];
};

struct Item01398700 : ItemHead01398700, ItemSettings01398700 { /* derived name */
};

/* the 0x18 bytes at +0x40 of the simulation's object at +0x58 */
struct Block01398700_58 { /* derived name */
    u32 unknown0[6];
};

/* the 0xc bytes at +0x40 of the simulation's object at +0x60 */
struct Block01398700_60 { /* derived name */
    u32 unknown0[3];
};

struct Part01398700_58 { /* derived name */
    u8 unknown0[0x40];
    Block01398700_58 unknown40; /* +0x40 */
};

struct Part01398700_60 { /* derived name */
    u8 unknown0[0x40];
    Block01398700_60 unknown40; /* +0x40 */
};

struct Part01398700_40 { /* derived name */
    u8 unknown0[0x4c];
    int mode;      /* +0x4c: 1 sets the flag at +0x98 */
    int unknown50; /* +0x50 */
};

/* the object at +0x48 when its type is the one at 0x5821208 points to */
class Kind01398700 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x34];
    int level; /* +0x58: 3 and 4 select their own id, below 2 the default */
};

struct Target01398700 { /* derived name */
    u8 unknown0[0x40];
    Part01398700_40 *unknown40; /* +0x40 */
    Object016b9108 *unknown48;  /* +0x48 */
    u8 unknown50[0x8];
    Part01398700_58 *unknown58; /* +0x58 */
    Part01398700_60 *unknown60; /* +0x60 */
    Item01398700 **items;       /* +0x68 */
    unsigned itemCount;         /* +0x70 */

    Item01398700 *itemAt(int index) const /* derived name */
    {
        return items[index];
    }
};

struct Object01398700 { /* derived name */
    u8 unknown0[0x64];
    int unknown64;              /* +0x64: 0x12 */
    int unknown68;              /* +0x68: by the level */
    Block01398700_58 unknown6c; /* +0x6c */
    Block01398700_60 unknown84; /* +0x84 */
    int unknown90;              /* +0x90 */
    int present;                /* +0x94: bit 0 the block at +0x6c, bit 1 the one at +0x84 */
    bool unknown98;             /* +0x98 */
    Target01398700 *unknowna0;  /* +0xa0 */
    u8 unknowna8[0x8];
    ItemSettings01398700 settings[2]; /* +0xb0, +0xe4 */
};

#endif
