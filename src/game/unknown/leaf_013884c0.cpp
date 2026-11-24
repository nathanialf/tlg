/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_namelist.h"
#include "tlg_libc.h"

/* derived names: the holder of a list of named values at +0x10 (slot 6 of
 * the vtable at 0x16c72e0 and of the other classes that hold such a list,
 * their pointers at 0x16bdad0, 0x16cb248, 0x16cb320 and 0x16cb3e8). The
 * other fields are not traced. */
struct Object013884c0 /* derived name */
{
    u8 unknown0[0x10];
    NamedValueList013883d0<1> list; /* +0x10; its extent not traced */
};

/* derived name: the value of the entry the string names (interned as a
 * copy: the last argument of FUN_013baad0 0; a null or empty string names
 * nothing), 0 when no entry has that name: the entries compared by the
 * name's index from the first (0x1388520), the name released before the
 * return. */
unsigned FUN_013884c0(const Object013884c0 *self, const char *string) /* derived name */
{
    const unsigned interned = Name::intern(string);
    Name name(interned);
    for (unsigned i = 0; i < self->list.count; ++i) {
        if (self->list.entries[i].name == name)
            return self->list.entries[i].value;
    }
    return 0;
}
