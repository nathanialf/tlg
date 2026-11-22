/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the object FUN_00abf490 constructs (its owner at +0x0, then
 * one object of each of the state classes whose vtables it stores, 0x16b3740
 * at +0x8, 0x16b3790 at +0x18 and the rest), held at +0x370 of the object
 * FUN_0042e5e0 tears down, which runs this destructor and frees the block
 * (`call 0xabf750; mov rdi, rbx; call operator delete`). The destructor
 * clears the owner and deletes the fourteen states from +0x8 to +0x70 in
 * their order, each through its deleting destructor (slot 1). */
class State00abf750 /* derived name */
{
  public:
    virtual ~State00abf750();
};

class Object00abf490 /* derived name */
{
  public:
    ~Object00abf490();

  private:
    void *owner;              /* +0x0: the second argument of FUN_00abf490; not traced */
    State00abf750 *unknown8;  /* +0x8 */
    State00abf750 *unknown10; /* +0x10 */
    State00abf750 *unknown18; /* +0x18 */
    State00abf750 *unknown20; /* +0x20 */
    State00abf750 *unknown28; /* +0x28 */
    State00abf750 *unknown30; /* +0x30 */
    State00abf750 *unknown38; /* +0x38 */
    State00abf750 *unknown40; /* +0x40 */
    State00abf750 *unknown48; /* +0x48 */
    State00abf750 *unknown50; /* +0x50 */
    State00abf750 *unknown58; /* +0x58 */
    State00abf750 *unknown60; /* +0x60 */
    State00abf750 *unknown68; /* +0x68 */
    State00abf750 *unknown70; /* +0x70 */
};

Object00abf490::~Object00abf490()
{
    owner = 0;
    delete unknown8;
    delete unknown10;
    delete unknown18;
    delete unknown20;
    delete unknown28;
    delete unknown30;
    delete unknown38;
    delete unknown40;
    delete unknown48;
    delete unknown50;
    delete unknown58;
    delete unknown60;
    delete unknown68;
    delete unknown70;
}
