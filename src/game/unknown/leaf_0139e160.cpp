/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: the complete destructor of a scope marker whose vtable is at
 * 0x16d0270 (config/vtables.derived.base.txt; stored by FUN_00bb7bc0,
 * FUN_00bb96e0 and FUN_00bba900, which build it on the stack with a pass name
 * at +0x10 such as "DrawZPass", save the thread-local at 0x16dc080 (tp
 * offset -80) at +0x8 and store the marker's address in it): it stores the
 * vtable and restores the thread-local from +0x8. FUN_0139e190, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
class Object0139e160; /* derived name */

extern __thread Object0139e160 *D_16dc080;

class Object0139e160 /* derived name */
{
  public:
    virtual ~Object0139e160();

  private:
    Object0139e160 *unknown8; /* +0x8: the marker it replaced */
    const char *unknown10;    /* +0x10: the pass name */
};

Object0139e160::~Object0139e160()
{
    D_16dc080 = unknown8;
}
