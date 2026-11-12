/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_simd.h"
#include "tlg_types.h"

/* derived names: a 0x40-byte entry of the array FUN_003de0a0 builds with
 * `new[]` (sixteen of them, the count in the 16-byte cookie): a 0x2000-byte
 * block at +0x0, an int at +0x8, two vectors at +0x10 from one 32-byte
 * constant, a 0x8000-byte block of 0x80-byte records at +0x30 and two
 * floats at +0x38 (0 and FLT_MAX). Its destructor frees each block when set
 * and clears the pointer. */
struct Entry016c7770 { /* derived name */

    ~Entry016c7770()
    {
        if (block) {
            delete[] block;
            block = 0;
        }
        if (records) {
            delete[] records;
            records = 0;
        }
    }

    u8 *block; /* +0x0 */
    int unknown8;
    Vec4 unknown10[2];
    u8 *records;     /* +0x30 */
    float unknown38; /* +0x38 */
    float unknown3c; /* +0x3c */
};

/* derived names: the class of the vtable at 0x16c7770 (config/vtables.derived.base.txt),
 * made by FUN_003de0a0 as a 0x28-byte object: a reference count at +0x8
 * (0xdeadc0de once released), the entry array at +0x10, a pointer at +0x18
 * and an int at +0x20 (slot 4, FUN_0134f200, clears it). Slot 0 is the
 * complete destructor, slot 1 the deleting one, slot 2 FUN_000069a0. The
 * class at 0x16a8f10, which FUN_003de0a0 stores last, derives from it. */
class Object016c7770 /* derived name */
{
  public:
    virtual ~Object016c7770();

  protected:
    int referenceCount;     /* +0x8 */
    Entry016c7770 *entries; /* +0x10 */
    void *unknown18;
    int unknown20;
};

Object016c7770::~Object016c7770()
{
    if (entries) {
        delete[] entries;
        entries = 0;
    }
}

/* derived names: the class of the vtable at 0x16a8f10, the object
 * FUN_003de0a0 finishes (its vptr stored last). It overrides slots 3, 5 and 6
 * (FUN_003df1b0, FUN_003df2d0, FUN_003df420) and adds nothing to destroy: its
 * destructors (FUN_0134f210, FUN_0134f2a0) are the base's, whose vptr store
 * makes its own dead. */
class Object016a8f10 : public Object016c7770 /* derived name */
{
  public:
    virtual ~Object016a8f10();
};

Object016a8f10::~Object016a8f10() {}
