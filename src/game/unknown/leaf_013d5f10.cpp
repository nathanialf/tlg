/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fade013d2490.h"
#include "tlg_game_fadeparam013f9ca0.h"

/* derived names: a rig's update of its elements and of its model's layer:
 * each element told its index (slot 5), then slots 4 and 6, the array and
 * the count read again at each (an unsigned counter through at(int): the
 * index sign-extended at each pass); then the state of the model's layer (the
 * set's element of the skeleton's id, or the set's own) set from the rig's
 * mode: 1 for the modes 1 and 2, 0 for mode 0, 2 for mode 3 */
void FUN_013d5f10(Object016d7b30 *self) /* derived name */
{
    for (unsigned i = 0; i < self->elements.size(); ++i) {
        self->elements.at(i)->slot5(i);
        self->elements.at(i)->slot4();
        self->elements.at(i)->slot6();
    }
    switch (self->unknown1c) {
    case 1:
    case 2:
        self->model->skeleton.layers->elementOrOwn(&self->model->skeleton.layerId)->state = 1;
        break;
    case 0:
        self->model->skeleton.layers->elementOrOwn(&self->model->skeleton.layerId)->state = 0;
        break;
    case 3:
        self->model->skeleton.layers->elementOrOwn(&self->model->skeleton.layerId)->state = 2;
        break;
    }
}
