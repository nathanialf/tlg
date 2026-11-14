/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ccdf0.h"

/* derived names: an element of the array the class below owns: 0x100 bytes,
 * polymorphic, destroyed in place through slot 0 of its vtable
 * (`mov rax, [rdi]; call [rax]`). Its other members are not traced. */
class Entry016b1208 /* derived name */
{
  public:
    virtual ~Entry016b1208();

  private:
    u8 unknown8[0xf8];
};

/* derived names: the class whose vtable is at 0x16b1208
 * (config/vtables.derived.base.txt), derived from Object016ccdf0: its
 * destructor FUN_00967d40 stores that class's vptr and its member's after
 * its own body. Its own fields from +0x50 are traced only where the
 * destructor reads them. */
class Object016b1208 : public Object016ccdf0 /* derived name */
{
  public:
    virtual ~Object016b1208();

  private:
    Entry016b1208 *entries50; /* +0x50: destroyed one by one, then cleared */
    u32 count58;              /* +0x58: the number of entries */
};

/* derived name: the complete destructor: destroys the entries in place where
 * the array is set and clears the pointer; then Object016ccdf0's destructor
 * is inlined. FUN_00967e80, slot 1, is the deleting one. This unit stores
 * Object016ccdf0's vtable, so it emits that class's vtable and its two
 * destructors (FUN_0137f420, FUN_0137f500). */
Object016b1208::~Object016b1208()
{
    if (entries50 != 0) {
        for (u32 i = 0; i < count58; ++i)
            entries50[i].~Entry016b1208();
        entries50 = 0;
    }
}
