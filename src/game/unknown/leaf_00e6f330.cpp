/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_string01331840.h"
#include "tlg_hks.h"

/* derived names: the script C function "FileExists" (the name FUN_00e705b0's
 * registration gives it, lea at 0xe705d7): the first argument's string
 * (FUN_00db6b20, null without one) is asked of slot 6 of the object at
 * +0x28 of the object the pointer at 0x5938c40 holds; when it answers 0, the
 * path formed from the name at +0x90 of the record at +0xe8 and the string
 * (the format at 0x15b6d40, two strings joined by a slash) is asked again.
 * Pushes whether either answered nonzero and returns 1. The classes are not
 * traced. */
class Files00e6f330 /* derived name */
{
  public:
    virtual void slot0();                 /* derived name; not traced */
    virtual void slot1();                 /* derived name; not traced */
    virtual void slot2();                 /* derived name; not traced */
    virtual void slot3();                 /* derived name; not traced */
    virtual void slot4();                 /* derived name; not traced */
    virtual void slot5();                 /* derived name; not traced */
    virtual int exists(const char *path); /* derived name */
};

struct Record00e6f330 { /* derived name */
    u8 unknown0[0x90];
    Name name90; /* +0x90 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x28];
    Files00e6f330 *files; /* +0x28 */
    u8 unknown30[0xb8];
    Record00e6f330 *unknownE8; /* +0xe8 */
};

extern Object05938c40 *D_5938c40;

extern const char D_15b6d40[6]; /* derived name: the format of a path in a directory */

/* derived name: the path of a file in a directory, formed into the text */
static inline const char *pathIn(String01331840 *path, const char *directory, const char *name)
{
    FUN_01331840(path, D_15b6d40, directory, name);
    return path->text;
}

// NONMATCHING: register assignment only: the base forms the path's address in r12 (the stack
// guard's address loaded again after the format) and keeps the slot in r13; the build forms the
// path in r13 and spills the slot to the frame
int FUN_00e6f330(lua_State *state) /* derived name */
{
    const char *name = 0;
    if (state->base < state->top)
        name = FUN_00db6b20(state, state->base, 0);
    Files00e6f330 *files = D_5938c40->files;
    bool exists = true;
    if (!files->exists(name)) {
        String01331840 path;
        exists = files->exists(pathIn(&path, D_17ac870[D_5938c40->unknownE8->name90.index].string0,
                                      name)) != 0;
    }
    pushBoolean(state, exists);
    return 1;
}
