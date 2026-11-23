/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "stdlib.h"

#include "tlg_game_object016c3be0.h"
#include "tlg_sce_record001af730.h"

/* derived names: one of the four 0x100-byte stages of the class whose vtable
 * is at 0x16c3c80: an SDK record (tlg_sce_record001af730.h) at its start,
 * entries at +0x88 and +0x90 handed back to the list at +0x100b8 of the
 * object 0x5adaaa8 points at, one at +0xf0 to the list at +0x100e8, a block
 * at +0x98 freed through the C library's free (0x14b0238) and a counted
 * reference at +0xe0; the stage's resources are released only while it holds
 * the block. The other fields are not traced. */
struct Stage01326700 /* derived name */
{
    /* the reference dropped, the entries handed back, the block freed (the
     * entry at +0x90 only in the last stage) */
    void releaseResources(bool second)
    {
        if (block98) {
            if (reference)
                reference->Release();
            returnEntry(entry88);
            if (second)
                returnEntry(entry90);
            returnEntryE8(entryf0);
            free(block98);
        }
    }

    Record001af730 record; /* +0x0 */
    u8 unknown80[0x8];
    void *entry88; /* +0x88 */
    void *entry90; /* +0x90 */
    void *block98; /* +0x98 */
    u8 unknowna0[0x40];
    JsUnknown *reference; /* +0xe0 */
    u8 unknowne8[0x8];
    void *entryf0; /* +0xf0 */
    u8 unknownf8[0x8];
};

/* derived names: the class whose vtable is at 0x16c3c80
 * (config/vtables.derived.base.txt; built by FUN_01325f10), over
 * Object0130acb0. Its complete destructor (0x1326700) erases the object from
 * the array at +0x48 of the object 0x5adaaa8 points at (found from the
 * start, its slot cleared, the rest moved down), releases its four stages'
 * resources in order, destroys their records from the last (four members, each record its own call) and runs the
 * base's as a tail call; the deleting one (0x1326a20) calls it, then frees
 * the storage. The other fields are not traced. */
class Object016c3c80 : public Object0130acb0 /* derived name */
{
  public:
    virtual ~Object016c3c80();

  private:
    Stage01326700 stage0; /* +0x30 */
    Stage01326700 stage1; /* +0x130 */
    Stage01326700 stage2; /* +0x230 */
    Stage01326700 stage3; /* +0x330 */
};

Object016c3c80::~Object016c3c80()
{
    JsDevice *owner = D_5adaaa8;
    void **object = owner->objects48;
    while (object != owner->objects48End && *object != this) {
        ++object;
    }
    if (object != owner->objects48End) {
        *object = 0;
        memmove(object, object + 1, (owner->objects48End - (object + 1)) * sizeof(void *));
        --owner->objects48End;
    }
    stage0.releaseResources(false);
    stage1.releaseResources(false);
    stage2.releaseResources(false);
    stage3.releaseResources(true);
}
