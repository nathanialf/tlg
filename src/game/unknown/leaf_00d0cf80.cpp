/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_libc.h"

/* derived names: an entry of a source's table, 12 bytes, its name first */
struct Entry00d0cf80 { /* derived name */
    Name name;         /* +0x0 */
    u8 unknown4[0x8];
};

/* derived names: the object whose entries a map indexes: the table from
 * slot 9, the count at +0x10 */
class Source00d0cf80 /* derived name */
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual const Entry00d0cf80 *entries(); /* slot 9 */

    u8 unknown8[0x8];
    unsigned count; /* +0x10 */
};

/* derived name: an entry's index, -1 for none */
struct Index00d0cf80 { /* derived name */

    Index00d0cf80() : value(-1) {}

    int value;
};

/* derived names: a map of a source's entries (called by FUN_00c6c310 and
 * FUN_00c6ee20): an index per entry, -1 until a list of "name:...;" items
 * gives the i-th the entry whose name the item's begins with */
class Map00d0cf80 /* derived name */
{
  public:
    Map00d0cf80(const char *names, Source00d0cf80 *source);

  private:
    Source00d0cf80 *source;               /* +0x0 */
    Array01343a80<Index00d0cf80> indices; /* +0x8 */
};

/* FUN_00d0cf80 */
Map00d0cf80::Map00d0cf80(const char *names, Source00d0cf80 *source) : source(source)
{
    const unsigned count = source->count;
    indices.resize(count);
    if (count && names && *names) {
        const Entry00d0cf80 *entries = source->entries();
        unsigned i = 0;
        do {
            if (i >= count)
                break;
            const char *next = strchr(names, ';');
            if (!next)
                break;
            const char *colon = strchr(names, ':');
            if (!colon)
                break;
            const char *name = names;
            const unsigned length = colon - name;
            names = next + 1;
            for (unsigned j = 0; j < count; ++j) {
                if (!strncmp(name, entries[j].name.string(), length)) {
                    indices.at(i).value = j;
                    break;
                }
            }
            ++i;
        } while (*names);
    }
}
