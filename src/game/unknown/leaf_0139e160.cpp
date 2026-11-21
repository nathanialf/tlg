/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_name.h"

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

extern const char D_15ae95c[]; /* "%s: RenderExt '%s'\n%s" */

/* derived name: the object at +0x18, as far as its name at +0xc */
struct Owner0139e160 {
    u8 unknown0[0xc];
    Name name; /* +0xc */
};

class Object0139e160 /* derived name */
{
  public:
    virtual ~Object0139e160();
    /* derived name: slot 2 (FUN_0139e1d0): the message prefixed with the
     * pass name and the owner's name ("%s: RenderExt '%s'\n%s", formatted
     * into 4 KiB on the stack) and handed on to the marker it replaced */
    virtual void report(const char *message, void *context);

  private:
    Object0139e160 *unknown8; /* +0x8: the marker it replaced */
    const char *unknown10;    /* +0x10: the pass name */
    Owner0139e160 *unknown18; /* +0x18 */
};

Object0139e160::~Object0139e160()
{
    D_16dc080 = unknown8;
}

void Object0139e160::report(const char *message, void *context) /* derived name */
{
    char text[0x1000];
    snprintf(text, sizeof text, D_15ae95c, unknown10, D_17ac870[unknown18->name.index].string0,
             message);
    if (unknown8)
        unknown8->report(text, context);
}
