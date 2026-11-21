/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b7670.h"
#include "tlg_game_shared.h"

/* derived name: a shared object's reference dropped and the pointer
 * cleared, nothing done for a null one (`test rdi, rdi; je` around the
 * release, then the pointer's `mov qword [rbx+off], 0`) */
static inline void dropShared(Shared00901550 *&shared)
{
    if (shared) {
        shared->release();
        shared = 0;
    }
}

/* derived names: the class whose vtable is at 0x16b7108
 * (config/vtables.derived.base.txt; built by FUN_008f4020 and others), over
 * Object016b7670, holding three shared objects (+0x20, +0x28, +0x30). Its
 * complete destructor (0xb893e0) clears the pointer at +0x38 and the int at
 * +0x40, drops the shared objects at +0x28, +0x30 and +0x20 in that order,
 * then runs the base's. The other fields are not traced. */
class Object016b7108 : public Object016b7670 /* derived name */
{
  public:
    virtual ~Object016b7108();

  private:
    u8 unknown8[0x18];
    Shared00901550 *shared20; /* +0x20 */
    Shared00901550 *shared28; /* +0x28 */
    Shared00901550 *shared30; /* +0x30 */
    void *unknown38;          /* +0x38 */
    int unknown40;            /* +0x40 */
};

Object016b7108::~Object016b7108()
{
    unknown38 = 0;
    unknown40 = 0;
    dropShared(shared28);
    dropShared(shared30);
    dropShared(shared20);
}

/* derived names: the class whose vtable is at 0x16b7840
 * (config/vtables.derived.base.txt; built by FUN_00b981a0 and others), over
 * Object016b7670, holding three shared objects (+0x40, +0x48, +0x50). Its
 * complete destructor (0xbd8540; the deleting one 0xbd8600) clears the int
 * at +0x28, drops the shared objects at +0x48, +0x50 and +0x40 in that
 * order, then runs the base's. The other fields are not traced. */
class Object016b7840 : public Object016b7670 /* derived name */
{
  public:
    virtual ~Object016b7840();

  private:
    u8 unknown8[0x20];
    int unknown28; /* +0x28 */
    u8 unknown2c[0x14];
    Shared00901550 *shared40; /* +0x40 */
    Shared00901550 *shared48; /* +0x48 */
    Shared00901550 *shared50; /* +0x50 */
};

Object016b7840::~Object016b7840()
{
    unknown28 = 0;
    dropShared(shared48);
    dropShared(shared50);
    dropShared(shared40);
}

/* derived names: the class whose vtable is at 0x16b7690
 * (config/vtables.derived.base.txt), over Object016b7840 with one more
 * shared object at +0x60. Its complete destructor (0xbc3910; the deleting
 * one 0xbc3a10) drops it, then the base's destructor is inlined.
 * NONMATCHING (0xbc3a10): the base inlines the 245-byte complete destructor
 * into the deleting one; the build calls it. */
class Object016b7690 : public Object016b7840 /* derived name */
{
  public:
    virtual ~Object016b7690();

  private:
    u8 unknown58[0x8];
    Shared00901550 *shared60; /* +0x60 */
};

Object016b7690::~Object016b7690()
{
    dropShared(shared60);
}
