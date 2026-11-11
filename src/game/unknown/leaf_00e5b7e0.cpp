/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_mutex.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16bdb40 (config/vtables.derived.base.txt): it stores the vtable and
 * destroys the mutex member at +0x110, whose destructor (leaf_013847e0.cpp)
 * the module inlines; slot 8, FUN_00e5bc80, opens a handle for its argument
 * through slot 3 (with 0), takes slot 7's answer for it and closes it
 * through slot 4, null without a handle. The other members and slots are
 * not traced. The destructor is
 * the class's key function, so this file emits the vtable. */
class Object00e5b7e0 /* derived name */
{
  public:
    virtual ~Object00e5b7e0();
    virtual void slot2();                        /* derived name; not traced */
    virtual void *slot3(void *key, int unknown); /* derived name; not traced */
    virtual void slot4(void *handle);            /* derived name; not traced */
    virtual void slot5();                        /* derived name; not traced */
    virtual void slot6();                        /* derived name; not traced */
    virtual void *slot7(void *handle);           /* derived name; not traced */
    virtual void *slot8(void *key);              /* derived name */

  private:
    u8 unknown8[0x108];
    Mutex013847e0 unknown110; /* +0x110 */
};

// NONMATCHING (the deleting destructor FUN_00e5b830 only): DeadStoreElimination's
// handleFree removes the inlined mutex destructor's two clearing stores before
// operator delete; the base keeps them (also at 0xa07ac7 and 0xcf1be7, the same
// member before a delete), a question of where the cross-file inlining ran.
Object00e5b7e0::~Object00e5b7e0() {}

void *Object00e5b7e0::slot8(void *key)
{
    void *handle = slot3(key, 0);
    if (!handle)
        return 0;
    void *result = slot7(handle);
    slot4(handle);
    return result;
}
