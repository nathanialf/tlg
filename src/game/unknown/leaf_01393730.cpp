/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16cee58 (config/vtables.derived.base.txt), slot 1: slot 0 is a method
 * declared before it (FUN_013936a0, which reads the record the pointer at +0x8
 * holds), slot 2 the deleting destructor, 0x21a00, the shared `jmp operator
 * delete` body (its stores dead before the delete). It stores the vtable (its
 * body is not empty) and nulls the pointer at +0x8. The vtable is also stored
 * by FUN_00b32dd0. The method's parameters are not traced. */
class Object01393730 /* derived name */
{
  public:
    virtual void slot0(); /* derived name; FUN_013936a0, not traced */
    virtual ~Object01393730();

  private:
    void *unknown8; /* +0x8 */
};

// NONMATCHING: the vtable is reached through the GOT (`lea` after relaxation, then `add rax, 0x10`) where the base folds the address point into one `lea`: the class's key function is slot 0 (FUN_013936a0, not written), so this file emits the vtable only available_externally and no game file defines it; equal once FUN_013936a0 is written in this file
Object01393730::~Object01393730()
{
    unknown8 = 0;
}
