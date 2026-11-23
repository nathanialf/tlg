/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: the object whose name the record keeps, at +0xc */
struct Owner00b0c450 { /* derived name */
    u8 unknown0[0xc];
    Name name; /* +0xc */
};

/* derived names: one record of the ring, 0x50 bytes: three vectors, five
 * values and the owner's name */
struct Entry00b0c450 { /* derived name */
    Vector4 a;         /* +0x0 */
    Vector4 b;         /* +0x10 */
    Vector4 c;         /* +0x20 */
    int unknown30;     /* +0x30 */
    int unknown34;     /* +0x34 */
    int unknown38;     /* +0x38 */
    int unknown3c;     /* +0x3c */
    int used40;        /* +0x40: 1 once written */
    int unknown44;     /* +0x44 */
    Name name;         /* +0x48 */
};

/* derived names: a ring of 60 records (FUN_00b07b90 passes the one at +0x9360
 * of its object) and the index of the next one written */
struct Ring00b0c450 {          /* derived name */
    Entry00b0c450 entries[60]; /* +0x0 */
    unsigned next;             /* +0x12c0 */

    void add(const Vector4 &a, const Vector4 &b, const Vector4 &c, int p, int q, int r, int s,
             int t, const Owner00b0c450 *owner);
};

/* FUN_00b0c450: the three vectors copied first, then the owner's name, then
 * the record at the next index written and the index moved on.
 * NONMATCHING: 94/99, 382 bytes as the base. The entry name's address for its
 * assignment is the GEP of the stores' block, kept in a register and sunk to
 * the top of the increment's block by MachineSink (`lea r13` first); the base
 * forms it in that block after the table's `lea` (CodeGenPrepare's sunk
 * address: a non-local addressing instruction there, which the merged GEP
 * with its x80 index does not give). */
void Ring00b0c450::add(const Vector4 &a, const Vector4 &b, const Vector4 &c, int p, int q, int r,
                       int s, int t, const Owner00b0c450 *owner) /* derived name */
{
    Vector4 lines[3] = {a, b, c};
    Name name;
    if (owner)
        name = owner->name;
    unsigned index = next;
    Entry00b0c450 &entry = entries[index];
    entry.a = lines[0];
    entry.b = lines[1];
    entry.c = lines[2];
    entry.unknown30 = p;
    entry.unknown34 = q;
    entry.unknown38 = r;
    entry.unknown3c = s;
    entry.used40 = 1;
    entry.unknown44 = t;
    entry.name = name;
    next = (index + 1) % 60;
}
