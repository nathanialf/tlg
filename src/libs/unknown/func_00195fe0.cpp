/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */

/* derived names: BroadPhaseTree00142a40's complete destructor (its row is
 * the D1 since the layers' destructor 0x140e70, which deletes each layer's
 * tree with it, became the compiler's): it runs the base destructor
 * FUN_00195ff0, which resets the tree and frees its arrays at +0x40, +0x30,
 * +0x10 and +0. Two functions because the destructor was inline where the
 * linker kept it (3.3 aliases D1 to D2 only for a strong definition,
 * CGCXX.cpp TryEmitDefinitionAsAlias); still written as a call over a
 * stand-in until the base destructor's body is. */
struct Object00195ff0; /* derived name */

void FUN_00195ff0(Object00195ff0 *self); /* derived name */

void FUN_00195fe0(Object00195ff0 *self) /* derived name */
{
    FUN_00195ff0(self);
}
