/* src/include/tlg_game_object00c1b7f0.h: the class whose destructor is
 * 0xc1b7f0, the part its 59 derived classes hold at +0x40, and the array of
 * named objects such an object is entered in (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT00C1B7F0_H
#define TLG_GAME_OBJECT00C1B7F0_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"
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

/* derived names: the 0x178-byte part at +0x40 of the 59 classes over
 * Object00c1b7f0 whose destructors call 0x13cd320 on it (`lea rdi,
 * [r14+0x40]; call 0x13cd320`, 59 sites and no other caller: the row named
 * as its destructor, D15). No vptr; its fields are not traced. */
class Object013cd320 /* derived name */
{
  public:
    ~Object013cd320();

  private:
    u64 unknown0[0x2f];
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

#endif
