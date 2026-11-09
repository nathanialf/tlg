/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a base class whose destructor does nothing. FUN_00b09fc0 is
 * slot 0, the complete destructor, of the 2 vtables 0x16b47c0, 0x16b4800 (all
 * stored by FUN_00704230), each with its own deleting destructor in slot 1 and
 * the same slot 2 (hkReferencedObject's 0x69a0): one body for several classes,
 * as clang gives a derived class whose destructor does nothing the base's
 * destructor (the alias of -mconstructor-aliases). Each derived class below is
 * named by its deleting destructor; slot 4 differs, slots 3 and 5 are shared. */
class Object00b09fc0 /* derived name */
{
  public:
    virtual ~Object00b09fc0();
};

Object00b09fc0::~Object00b09fc0() {}

/* derived names: the vtable at 0x16b47c0; slot 1, FUN_00b0a4a0, the deleting
 * destructor (operator delete of the object). */
class Object00b0a4a0 : public Object00b09fc0 /* derived name */
{
  public:
    ~Object00b0a4a0();
};

Object00b0a4a0::~Object00b0a4a0() {}

/* derived names: the vtable at 0x16b4800; slot 1, FUN_00b0a4b0, the deleting
 * destructor (operator delete of the object). */
class Object00b0a4b0 : public Object00b09fc0 /* derived name */
{
  public:
    ~Object00b0a4b0();
};

Object00b0a4b0::~Object00b0a4b0() {}
