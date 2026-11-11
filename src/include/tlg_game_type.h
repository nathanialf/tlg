/* src/include/tlg_game_type.h: the game's run-time type of a component (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_TYPE_H
#define TLG_GAME_TYPE_H

/* derived names: a type is a chain of types linked by their first field;
 * an object's type pointer is compared along the chain with the address a
 * global holds (FUN_00503fb0, FUN_00644eb0, FUN_013937c0) */
struct Type00503fb0 {     /* derived name */
    Type00503fb0 *parent; /* +0x0 */
};

/* the type itself or one it derives from */
inline bool isKindOf(const Type00503fb0 *t, const Type00503fb0 *type) /* derived name */
{
    do {
        if (t == type)
            return true;
        t = t->parent;
    } while (t);
    return false;
}

#endif
