/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_nametable.h"

/* derived names: the object an entry owns, deleted through its virtual
 * destructor (slot 1, `call [rax+8]`). Its class is not traced. */
class Object013480b0 /* derived name */
{
  public:
    virtual ~Object013480b0();
};

/* derived names: an entry of the tables of 12 buckets at +0x28c8 and +0x2948
 * of the object FUN_00293bf0 destroys (two calls of 0x13480b0): the hash,
 * the name, the object it owns, the next. The entry deletes its object,
 * then its name is released. */
struct Entry013480b0 { /* derived name */

    ~Entry013480b0()
    {
        delete object;
    }

    u32 hash;               /* +0x0 */
    Name name;              /* +0x4 */
    Object013480b0 *object; /* +0x8 */
    Entry013480b0 *next;    /* +0x10 */
};

/* FUN_013480b0: with entries left they are emptied, then every block freed */
template NameTable<Entry013480b0, 12>::~NameTable();
