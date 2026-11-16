/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016ad6d8.h"

/* derived name: the constructor (tlg_game_object016ad6d8.h): its base
 * Object00774560 is built from the name passed on (FUN_00774370), the Name at
 * +0xfc and the reference at +0x100 start empty, the base's float at +0x7c is
 * set to 0.2 and the Name at +0xfc to "jt_AttachA", looked up without
 * interning it (`xor ecx, ecx`). */
Object016ad6d8::Object016ad6d8(const Name &name) : Object00774560(name)
{
    unknown7c = 0.2f;
    namefc = Name("jt_AttachA", false);
}

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's
 * destructor FUN_00774560 runs as a tail call. FUN_00794470, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ad6d8::~Object016ad6d8() {}

/* derived name: slot 14: the body put back home, then turned and moved by
 * the pose unless it is held (Object00774560::followFromHome); then the
 * body's int at +0x1b0c copied to +0x3c */
void Object016ad6d8::slot14(Pose0077bac0 *pose)
{
    followFromHome(pose);
    unknown3c = unknown68->unknown1b0c;
}
