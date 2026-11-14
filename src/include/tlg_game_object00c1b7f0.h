/* src/include/tlg_game_object00c1b7f0.h: the class whose destructor is
 * 0xc1b7f0, the part its 59 derived classes hold at +0x40, and the array of
 * named objects such an object is entered in (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT00C1B7F0_H
#define TLG_GAME_OBJECT00C1B7F0_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose complete destructor is 0xc1b7f0 (its row
 * named for it, D15; its vtable is at 0x16b8118, stored by FUN_00c1b680 and
 * that destructor). The destructor stores that vtable, releases the Name at
 * +0x28, then stores 0x16b9118 and releases the Names at +0x10 and +0xc: the
 * class is over Object016b9108, whose slots 2 to 4 its vtable repeats. The
 * destructor is not written, so nothing here emits the vtable; the fields
 * from +0x2c are not traced. */
class Object00c1b7f0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object00c1b7f0();

  private:
    u8 unknown24[0x4];
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    u8 unknown2c[0x14];
};

/* derived names: the 0x28-byte element of the array at +0x108 of
 * Object013cd320: an array made with new[] at +0x0 (FUN_013cd5c0 reads its
 * count at -8 of the pointer) and a counted reference at +0x18, released
 * when the element is destroyed (0x13cd39a: `lea rcx, [rcx+rcx*4]; mov
 * r15, [rax+rcx*8+0x18]`). The rest is not traced. */
struct Element013cd320 { /* derived name */
    void *unknown0;
    u8 unknown8[0x10];
    Ref00503fb0<Node00503fb0> ref18; /* +0x18 */
    u8 unknown20[0x8];
};

/* derived names: the 0x178-byte part at +0x40 of the 59 classes over
 * Object00c1b7f0 whose destructors call 0x13cd320 on it (`lea rdi,
 * [r14+0x40]; call 0x13cd320`, 59 sites and no other caller: the row named
 * as its destructor, D15). No vptr. The destructor calls FUN_013cd5c0 on
 * the object, deletes the arrays at +0x130 and +0x138 and clears the two
 * pointers; then the members go: the array at +0x108, the blocks of the
 * four arrays at +0xa8, +0x90, +0x78 and +0x60 (0x18 bytes each; their
 * elements are not traced) and the Name at +0x30. The rest is not
 * traced. */
class Object013cd320 /* derived name */
{
  public:
    ~Object013cd320();

    void FUN_013cd5c0(); /* derived name: called first by the destructor; not traced */

  private:
    u8 unknown0[0x30];
    Name name30; /* +0x30 */
    u8 unknown34[0x2c];
    OwnedBlock05943280 block60; /* +0x60 */
    u8 unknown68[0x10];
    OwnedBlock05943280 block78; /* +0x78 */
    u8 unknown80[0x10];
    OwnedBlock05943280 block90; /* +0x90 */
    u8 unknown98[0x10];
    OwnedBlock05943280 blocka8; /* +0xa8 */
    u8 unknownb0[0x58];
    Array05943280<Element013cd320> array108; /* +0x108 */
    u8 unknown120[0x10];
    u8 *array130; /* +0x130: made with new[]; the element is not traced */
    u8 *array138; /* +0x138: made with new[]; the element is not traced */
    u8 unknown140[0x38];
};

/* derived names: an object of those classes under the name it was made for:
 * the 16-byte element of the array at +0xd8 of the owner (FUN_00fc5680 looks
 * a name up in it at 0xfc56e7, `cmp [rcx+rdi+8], edx`, and appends the
 * object it made with the array's push FUN_00f516f0; an object's destructor
 * looks itself up, `cmp [r12+rcx], r14` at 0xf1a997) */
struct Entry00f516f0 { /* derived name */

    bool operator==(const Object00c1b7f0 *other) const
    {
        return object == other;
    }

    Object00c1b7f0 *object; /* +0x0 */
    Name name;              /* +0x8 */
};

/* the owner's array of them; an object keeps a pointer to the array it is
 * in (FUN_00fc5680: `mov [rsi+0x1d8], rbx` at 0xfc5788) and takes itself
 * out in its destructor */
class Registry00f516f0 : public Array05943280<Entry00f516f0> /* derived name */
{
  public:
    void remove(const Object00c1b7f0 *object) /* derived name */
    {
        int index = find(object);
        if (index >= 0)
            removeAt(index);
    }
};

/* derived names: what several of those classes hold while they are active
 * and let go of in their destructors: an object released through slot 3 of
 * its vtable where it is set, the pointer cleared either way (FUN_0101ece0: `mov rdi,
 * [r14+0x258]; test rdi, rdi; je; mov rax, [rdi]; call [rax+0x18]; mov
 * [r14+0x258], 0`). The other slots are not traced. */
class Released0101ece0 /* derived name */
{
  public:
    virtual void slot0();   /* derived name; not traced */
    virtual void slot1();   /* derived name; not traced */
    virtual void slot2();   /* derived name; not traced */
    virtual void release(); /* derived name: slot 3 */
};

/* derived names: the 0xa0-byte element of the array several of those
 * classes hold: a Name at +0x0, released for each element when the array is
 * destroyed (FUN_0101ece0: `lea rdx, [rcx+rcx*4]; shl rdx, 5; mov ecx,
 * [r13+rdx]` at 0x101ee63). The rest is not traced. */
struct Element0101ece0 { /* derived name */
    Name name;           /* +0x0 */
    u8 unknown4[0x9c];
};

#endif
