/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a base class whose destructor does nothing. FUN_00b0a9c0 is
 * slot 0, the complete destructor, of the 7 vtables 0x16b48c0, 0x16b4900,
 * 0x16b4940, 0x16b4980, 0x16b49c0, 0x16b4a00, 0x16b4a40 (all stored by
 * FUN_00704230), each with its own deleting destructor in slot 1 and the same
 * slot 2 (hkReferencedObject's 0x69a0): one body for several classes, as clang
 * gives a derived class whose destructor does nothing the base's destructor
 * (the alias of -mconstructor-aliases). Each derived class below is named by
 * its deleting destructor; slot 4 differs, slots 3 and 5 are shared. */
class Object00b0a9c0 /* derived name */
{
  public:
    virtual ~Object00b0a9c0();
};

Object00b0a9c0::~Object00b0a9c0() {}

/* derived names: the vtable at 0x16b48c0; slot 1, FUN_00b0a9d0, the deleting
 * destructor (operator delete of the object). */
class Object00b0a9d0 : public Object00b0a9c0 /* derived name */
{
  public:
    ~Object00b0a9d0();
};

Object00b0a9d0::~Object00b0a9d0() {}

/* derived names: the vtable at 0x16b4900; slot 1, FUN_00b0ac20, the deleting
 * destructor (operator delete of the object). */
class Object00b0ac20 : public Object00b0a9c0 /* derived name */
{
  public:
    ~Object00b0ac20();
};

Object00b0ac20::~Object00b0ac20() {}

/* derived names: the vtable at 0x16b4940; slot 1, FUN_00b0ace0, the deleting
 * destructor (operator delete of the object). */
class Object00b0ace0 : public Object00b0a9c0 /* derived name */
{
  public:
    ~Object00b0ace0();
};

Object00b0ace0::~Object00b0ace0() {}

/* derived names: the vtable at 0x16b4980; slot 1, FUN_00b0ade0, the deleting
 * destructor (operator delete of the object). */
class Object00b0ade0 : public Object00b0a9c0 /* derived name */
{
  public:
    ~Object00b0ade0();
};

Object00b0ade0::~Object00b0ade0() {}

/* derived names: the vtable at 0x16b49c0; slot 1, FUN_00b0ae60, the deleting
 * destructor (operator delete of the object). */
class Object00b0ae60 : public Object00b0a9c0 /* derived name */
{
  public:
    ~Object00b0ae60();
};

Object00b0ae60::~Object00b0ae60() {}

/* derived names: the vtable at 0x16b4a00; slot 1, FUN_00b0aee0, the deleting
 * destructor (operator delete of the object). */
class Object00b0aee0 : public Object00b0a9c0 /* derived name */
{
  public:
    ~Object00b0aee0();
};

Object00b0aee0::~Object00b0aee0() {}

/* derived names: the vtable at 0x16b4a40; slot 1, FUN_00b0b540, the deleting
 * destructor (operator delete of the object). */
class Object00b0b540 : public Object00b0a9c0 /* derived name */
{
  public:
    ~Object00b0b540();
};

Object00b0b540::~Object00b0b540() {}
