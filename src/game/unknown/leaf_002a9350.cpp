/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_002a9350: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016a7db8.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57cb378]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57cb378;

/* derived name: the creator of Object016a7db8, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x150 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor FUN_002a94b0, which is not inlined. */
Object016b9108 *FUN_002a9350(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016a7db8));
    D_59458a4.lock();
    D_59458a8 = D_57cb378;
    return new (memory) Object016a7db8(name);
}

/* derived name: the constructor (tlg_game_object016a7db8.h): its base
 * Object016b9108 is built from the name passed on, the seven arrays start
 * empty; then the body sets the fields and empties the arrays again (their
 * counts cleared), in this order. */
Object016a7db8::Object016a7db8(const Name &name) : Object016b9108(name)
{
    unknown30.set(0.0f, 0.0f, 0.0f, 1.0f);
    unknown40.set(0.0f, 0.0f, 0.0f, 1.0f);
    unknown50.set(0.0f, 0.0f, 0.0f, 1.0f);
    unknown60 = 0;
    array68.removeAll();
    array80.removeAll();
    array98.removeAll();
    arrayb0.removeAll();
    arrayc8.removeAll();
    unknowne0 = 0;
    unknownf0.set(0.0f, 0.0f, 0.0f, 1.0f);
    unknown100 = 0;
    unknown104 = 0.0f;
    unknown108 = 0.0f;
    unknown10c = 1.0f;
    unknown110 = 0.0f;
    unknown114 = 0;
    unknown118 = 0;
    unknown11c = 1.0f;
    array120.removeAll();
    array138.removeAll();
}
