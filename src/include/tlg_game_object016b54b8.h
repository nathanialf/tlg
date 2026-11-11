/* src/include/tlg_game_object016b54b8.h: the class whose vtable is at
 * 0x16b54b8 and the one derived from it at 0x16b0788 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B54B8_H
#define TLG_GAME_OBJECT016B54B8_H

#include "tlg_types.h"

/* derived names: the record at +0xc0 of Object016b54b8, which FUN_01392bf0
 * tears down, and the one it owns through +0x108, deleted by its destructor
 * (FUN_01392d50, called on the pointer just before operator delete: its row
 * named for it, D15); their fields are not traced. */
struct Object01392bf0 /* derived name */
{
    u8 unknown0[0x48];
};

struct Object01392d50 /* derived name */
{
    ~Object01392d50();
};

void FUN_01392bf0(Object01392bf0 *self); /* derived name */

/* derived name: the base whose destructor is FUN_00ca38f0 (its row named
 * for it, D15) */
class Object00ca38f0 /* derived name */
{
  public:
    virtual ~Object00ca38f0();
};

/* derived names: the class whose vtable is at 0x16b54b8
 * (config/vtables.derived.base.txt), stored by its constructor
 * FUN_00b20380 and by FUN_008ef2f0 and FUN_008ef5c0, which build the
 * classes derived from it (0x16b0788, 0x16b0808). Its destructor is
 * FUN_00b20610 (leaf_00b20610.cpp). The other members are not traced. */
class Object016b54b8 : public Object00ca38f0 /* derived name */
{
  public:
    virtual ~Object016b54b8();

  private:
    u8 unknown8[0xb8];
    Object01392bf0 unknownc0; /* +0xc0 */
    Object01392d50 *owned108; /* +0x108 */
};

/* derived name: the class whose vtable is at 0x16b0788
 * (config/vtables.derived.base.txt), stored by FUN_008ef2f0; its
 * destructor (FUN_008f2ec0, leaf_008f2ec0.cpp) is defined empty, and its
 * base's is inlined in it. */
class Object016b0788 : public Object016b54b8 /* derived name */
{
  public:
    virtual ~Object016b0788();
};

#endif
