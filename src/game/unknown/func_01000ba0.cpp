/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_fade013d2490.h"
#include "tlg_game_joint013eb0a0.h"
#include "tlg_game_name.h"
#include "tlg_game_rotation.h"
#include "tlg_game_vector.h"

/* derived names: FUN_01000ba0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt) that the fade entries' resize reads. Among its
 * objects are 1 list of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x1005070, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry01000ba0 { /* derived name */

    Entry01000ba0(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_15c9ed8[6];
extern const char D_15c9ede[7];
extern const char D_15c9ee5[6];

// NONMATCHING: the file's initializer (FUN_01000ba0): only the lists are
// written; its other objects are not.
static Entry01000ba0 D_5acf7a0[] = {Name(D_15c9ed8), Name(D_15c9ede), Name(D_15c9ee5)};

/* derived name: this file's fade entry (tlg_game_fade013d2490.h): one
 * element type per file, as the base holds one resize of them per file */
struct FadeEntry01000ba0 : FadeEntry013d2490 { /* derived name */
};

/* FUN_013ea7b0 */
template void Array05943280<FadeEntry01000ba0>::resize(unsigned);

/* derived name: this file's copy of FUN_013d4610 (func_00f6d1a0.cpp) */
void FUN_013ea8a0(Fade013d2490 *self) /* derived name */
{
    self->state = 1;
    FadeTarget013d2490 *target = self->owner->target;
    for (int i = 0; i < target->count; ++i) {
        FadeEntry013d2490 &entry = self->entries[i];
        reinterpret_cast<Vector4 &>(entry.unknown50) =
            self->model->skeleton.poses[target->unknown28[i]].rotation;
        makeWPositive(entry.unknown50);
        setLanes(entry.unknown60, VECTOR_W);
    }
}

/* derived name: slot 2 of a vtable of this file (jointFrame; its copies
 * 0x13eb510, 0x13eb6f0 here and 0x1480ed0, 0x1481320, 0x1481470 in
 * func_0126c7f0.cpp wait on it) */
// NONMATCHING: every instruction but the registers: the base forms the
// negation's address (`lea r15, [rbp-0x40]`) before the call and holds it in
// a saved register (r12 pushed, `sub rsp, 0x30`); the build forms it after
// the call (75/79 by position)
JointFrame013eb0a0 FUN_013eb0a0(void *self, const Joint013eb0a0 *joint) /* derived name */
{
    return jointFrame(joint);
}

/* derived name: a virtual method of this file (nodeFrame) */
JointFrame013eb0a0 FUN_013eb210(const Placed013eb210 *self) /* derived name */
{
    return nodeFrame(self);
}

/* derived name: this file's copy of FUN_013d0470 (func_00f509e0.cpp) */
int FUN_013ebd10(Fade013d2490 *self); /* derived name */

/* derived name: this file's copy of FUN_013d2570 (func_00f509e0.cpp) */
void FUN_013ed0d0(Fade013d2490 *self) /* derived name */
{
    if (self->state != 0 && self->unknown6c != 0 && FUN_013ebd10(self) != 0) {
        FadeTarget013d2490 *target = self->owner->target;
        for (int i = 0; i < target->count; ++i)
            takePose(target->entries[i].unknown70, self->model, target->unknown28[i]);
    }
}

/* derived name: the class whose slot 1 calls FUN_013ecce0 */
struct Object013ecea0 : FadeRig013d1440 { /* derived name */
};

/* derived name: this file's copy of FUN_013d1440 (func_00f509e0.cpp) */
void FUN_013ecce0(Object013ecea0 *self) /* derived name */
{
    FadeTarget013d2490 *target = self->target;
    for (int i = 0; i < target->count; ++i) {
        FadeTargetEntry013d2490 &entry = target->entries[i];
        FadeModel013d4610 *model = self->model;
        const int index = target->unknown28[i];
        FUN_013ce2d0(&model->skeleton, &entry.unknown50, index, model->skeleton.poses);
        FUN_013ce660(&model->skeleton, &entry.unknown60, index, model->skeleton.poses);
        takePose(entry.unknown70, self->model, target->unknown28[i]);
    }
}
