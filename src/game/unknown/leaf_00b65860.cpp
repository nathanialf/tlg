/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a base class whose destructor does nothing. FUN_00b65860 is
 * slot 1, the complete destructor, of the vtables 0x16b6b50 and 0x16b6b78,
 * each with its own method in slot 0 (FUN_00b659b0, which sets the int at +0x8
 * to -1, and FUN_00b65b10) and its own deleting destructor in slot 2: one body
 * for two classes, as clang gives a derived class whose destructor does
 * nothing the base's destructor (the alias of -mconstructor-aliases). Each
 * derived class below is named by its deleting destructor; the slot-0 method
 * is not traced. */
class Object00b65860 /* derived name */
{
  public:
    virtual ~Object00b65860();
};

Object00b65860::~Object00b65860() {}

/* derived names: the vtable at 0x16b6b50; slot 2, FUN_00b65870, the deleting
 * destructor (operator delete of the object). */
class Object00b65870 : public Object00b65860 /* derived name */
{
  public:
    ~Object00b65870();
};

Object00b65870::~Object00b65870() {}

/* derived names: the vtable at 0x16b6b78; slot 2, FUN_00b65b00, the deleting
 * destructor (operator delete of the object). */
class Object00b65b00 : public Object00b65860 /* derived name */
{
  public:
    ~Object00b65b00();
};

Object00b65b00::~Object00b65b00() {}
