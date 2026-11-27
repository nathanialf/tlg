/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_string01331840.h"
#include "tlg_game_textbuffer00d705f0.h"
#include "tlg_libc.h"

/* derived names: what FUN_0135b0f0 prints: an object named by the Name at
 * +0x28, a table of entries pairing a value with such an object (+0xa8,
 * their count at +0xb0) and the float at +0x4 of an entry's value */
struct Key0135b0f0 { /* derived name */
    u8 unknown0[0x28];
    Name name; /* +0x28 */
};

struct Value0135b0f0 { /* derived name */
    u8 unknown0[0x4];
    float weight; /* +0x4 */
};

struct Entry0135b0f0 {    /* derived name */
    Value0135b0f0 *value; /* +0x0 */
    Key0135b0f0 *key;     /* +0x8 */
};

struct Table0135b0f0 { /* derived name */
    u8 unknown0[0xa8];
    Entry0135b0f0 *entries; /* +0xa8 */
    u32 count;              /* +0xb0 */

    /* the index of the last entry of a key, searched from the end (the
     * key is there: the search has no bound) */
    int indexOf(const Key0135b0f0 *key) const /* derived name */
    {
        u32 i = count;
        do
            --i;
        while (entries[i].key != key);
        return i;
    }
};

/* derived name: one line of the buffer: the prefix, then ", " and the
 * key's name after its last '/' with its entry's weight ("%s, %f"), then a
 * new line */
void FUN_0135b0f0(TextBuffer00d705f0 *buffer, const char *prefix, Key0135b0f0 *const *key,
                  const Table0135b0f0 *table)
{
    buffer->FUN_00d705f0(prefix);
    String01331840 text;
    text.length = 0;
    text.text[0] = 0;
    text.text[sizeof(text.text) - 1] = 0;
    const Value0135b0f0 *value = table->entries[table->indexOf(*key)].value;
    FUN_00317070(&text, "%s, %f", strrchr((*key)->name.string(), '/') + 1, value->weight);
    buffer->FUN_00d706c0(", %s", text.text);
    buffer->FUN_00d705f0("\n");
}
