/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016c81c0.h"
#include "tlg_sce_kernel.h"

/* derived names: the class whose vtable is at 0x16b0be0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_009091b0
 * and its destructors), over Object016c81c0 (the destructor tail-calls
 * 0xd687e0): an array at +0x98, three records at +0xb0, +0xc8 and +0xe0, and
 * two semaphores at +0x108 and +0x110; the rest is not traced */
class Object016b0be0 : public Object016c81c0 /* derived name */
{
  public:
    virtual ~Object016b0be0();

  private:
    friend void FUN_0090cfa0(Object016b0be0 *self);

    Array05943280<u32> array98; /* +0x98: its elements not traced */
    Object0134f620 recordB0;    /* +0xb0 */
    Object0134f620 recordC8;    /* +0xc8 */
    Object0134f620 recordE0;    /* +0xe0 */
    u8 unknownf8[0x10];
    SceKernelSema sema108; /* +0x108 */
    SceKernelSema sema110; /* +0x110 */
};

/* derived name: not traced */
void FUN_0090cfa0(Object016b0be0 *self);

/* derived names: the complete destructor: FUN_0090cfa0 first, then each
 * semaphore deleted where there is one and its handle cleared, the later
 * one first; then the members, last first, and the base's destructor as a
 * tail call. FUN_0090d290, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016b0be0::~Object016b0be0()
{
    FUN_0090cfa0(this);
    if (sema110) {
        sceKernelDeleteSema(sema110);
        sema110 = 0;
    }
    if (sema108) {
        sceKernelDeleteSema(sema108);
        sema108 = 0;
    }
}
