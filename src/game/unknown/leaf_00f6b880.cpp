/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d3ad0.h"

/* derived names: slot 4 of the classes of the vtables at 0x16bf850 to
 * 0x16bf9e0 (config/vtables.derived.base.txt; made by FUN_00f59e00), the
 * fade's state at +0x58 (tlg_game_object016d3ad0.h). Slots 2, 3, 5 and 6
 * are Object016d3ad0's (slot 2 FUN_013d4610); slot 7 is FUN_00f6a330 for
 * 0x16bf850 to 0x16bf940 and FUN_00f6b940, with a vector, for 0x16bf990 and
 * 0x16bf9e0. Slot 7's parameters are not traced further. */
class FadeState013d4610 : public Object016d3ad0 /* derived name */
{
  public:
    virtual void slot4();
};

class FadeState00f6a330 : public FadeState013d4610 /* derived name */
{
  public:
    virtual void slot7(int, int, float); /* FUN_00f6a330 */
};

class FadeState00f6b940 : public FadeState013d4610 /* derived name */
{
  public:
    virtual void slot7(int, const Vec4 *, float); /* FUN_00f6b940 */
};

class Object016bf8f0 : public FadeState00f6a330 /* derived name */
{
};

class Object016bf940 : public FadeState00f6a330 /* derived name */
{
};

class Object016bf990 : public FadeState00f6b940 /* derived name */
{
};

class Object016bf9e0 : public FadeState00f6b940 /* derived name */
{
};

/* unless the model's source holds the fade (slot 1 of its second base),
 * slot 7 with 0 or 1, 1 and the source's length at +0x520 or +0x558 */
void FUN_00f6b880(Object016bf8f0 *self) /* derived name */
{
    if (self->model->source->unknown1())
        return;
    self->slot7(0, 1, self->model->source->unknown520);
}

void FUN_00f6b8e0(Object016bf940 *self) /* derived name */
{
    if (self->model->source->unknown1())
        return;
    self->slot7(1, 1, self->model->source->unknown558);
}

/* while the source holds the fade: the state turned to fading in (1) from
 * off or fading out when the source's length is above zero, else to fading
 * out (3) from fading in or full, then slot 7 with 0 or 1, a copy of the
 * 12th or 16th target entry's vector and the length */
void FUN_00f6c0c0(Object016bf990 *self) /* derived name */
{
    if (self->model->source->unknown1()) {
        Vec4 target = self->owner->target->entries[11].unknown20;
        if (self->model->source->unknown520 > 0.0f) {
            if (self->state == 3 || self->state == 0)
                self->state = 1;
        } else if (self->state == 1 || self->state == 2) {
            self->state = 3;
        }
        self->slot7(0, &target, self->model->source->unknown520);
    }
}

void FUN_00f6c190(Object016bf9e0 *self) /* derived name */
{
    if (self->model->source->unknown1()) {
        Vec4 target = self->owner->target->entries[15].unknown20;
        if (self->model->source->unknown558 > 0.0f) {
            if (self->state == 3 || self->state == 0)
                self->state = 1;
        } else if (self->state == 1 || self->state == 2) {
            self->state = 3;
        }
        self->slot7(1, &target, self->model->source->unknown558);
    }
}
