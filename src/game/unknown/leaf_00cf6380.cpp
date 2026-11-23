/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_buffer00d650e0.h"

/* derived names: no direct caller; the first argument is not read. A
 * resource not yet set up (the byte at +0x94) has its view of the data at
 * +0x28 cleared, then, when it holds data, built from the data's header:
 * three pointers from the offsets at +0x0, +0x8 and +0x10, the three counts
 * at +0x4, +0xc and +0x14, a fourth pointer from +0x18 with its count at
 * +0x1c; the resource is handed to slot 5 of the object at +0xb0 of the
 * object the pointer at 0x5938c40 holds, and marked set up. FUN_00cf65a0
 * undoes it: the mark cleared, slot 6 with the resource, the fourth pointer
 * and its count, then the data's buffer reset (its block released unless
 * it is not its own: tlg_game_buffer00d650e0.h, the flags read again after
 * the release) and the view cleared. */
struct Header00cf6380 { /* derived name */
    u32 offset0;        /* +0x0 */
    int count4;         /* +0x4 */
    u32 offset8;        /* +0x8 */
    int countc;         /* +0xc */
    u32 offset10;       /* +0x10 */
    int count14;        /* +0x14 */
    u32 offset18;       /* +0x18 */
    int count1c;        /* +0x1c */
};

/* derived name: the three pointers and their counts, built from a header */
struct View00cf6380 {
    View00cf6380() : pointer0(0), pointer8(0), pointer10(0), count18(0), count1c(0), count20(0) {}

    explicit View00cf6380(const Header00cf6380 *header)
        : pointer0(reinterpret_cast<const u8 *>(reinterpret_cast<u64>(header) + header->offset0)),
          pointer8(reinterpret_cast<const u8 *>(reinterpret_cast<u64>(header) + header->offset8)),
          pointer10(reinterpret_cast<const u8 *>(reinterpret_cast<u64>(header) + header->offset10)),
          count18(header->count4), count1c(header->countc), count20(header->count14)
    {
    }

    const u8 *pointer0;  /* +0x0 */
    const u8 *pointer8;  /* +0x8 */
    const u8 *pointer10; /* +0x10 */
    int count18;         /* +0x18 */
    int count1c;         /* +0x1c */
    int count20;         /* +0x20 */
};

struct Resource00cf6380 { /* derived name */

    const Header00cf6380 *header() const
    {
        return static_cast<const Header00cf6380 *>(data.block);
    }

    u8 unknown0[0x28];
    Buffer00d650e0 data; /* +0x28: the block is the header */
    u8 unknown40[0x20];
    View00cf6380 view;   /* +0x60 */
    const u8 *pointer88; /* +0x88 */
    int count90;         /* +0x90 */
    bool setUp;          /* +0x94 */
};

class Device05938c40_b0 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; not traced */
    virtual void slot1(); /* derived name; not traced */
    virtual void slot2(); /* derived name; not traced */
    virtual void slot3(); /* derived name; not traced */
    virtual void slot4(); /* derived name; not traced */
    virtual void slot5(Resource00cf6380 *resource, const u8 *data, int count); /* derived name */
    virtual void slot6(Resource00cf6380 *resource, const u8 *data, int count); /* derived name */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0xb0];
    Device05938c40_b0 *unknownb0; /* +0xb0 */
};

extern Object05938c40 *D_5938c40;

void FUN_00cf6380(void *, Resource00cf6380 *resource) /* derived name */
{
    if (resource->setUp)
        return;
    resource->pointer88 = 0;
    resource->count90 = 0;
    resource->view = View00cf6380();
    if (const Header00cf6380 *header = resource->header()) {
        resource->view = View00cf6380(header);
        resource->pointer88 =
            reinterpret_cast<const u8 *>(reinterpret_cast<u64>(header) + header->offset18);
        resource->count90 = header->count1c;
        D_5938c40->unknownb0->slot5(resource, resource->pointer88, resource->count90);
        resource->setUp = true;
    }
}

void FUN_00cf65a0(Resource00cf6380 *resource) /* derived name */
{
    resource->setUp = false;
    D_5938c40->unknownb0->slot6(resource, resource->pointer88, resource->count90);
    resource->data.reset();
    resource->pointer88 = 0;
    resource->count90 = 0;
    resource->view = View00cf6380();
}
