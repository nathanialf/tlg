/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16a9e30 (stored by FUN_0047a6e0): slot 0 the complete destructor, slot 1
 * the deleting one (operator delete of the object). Slot 2 returns the text at
 * +0x8 (slot 3 appends a character at +0x8 plus the int at +0x2000c and sets
 * the bool at +0x20010 when full, slot 4 appends a string through slot 3, slot
 * 5 returns the bool, FUN_0047de50). */
class Object0047dd90 /* derived name */
{
  public:
    virtual ~Object0047dd90();
    virtual const char *FUN_0047ddb0();            /* derived name */
    virtual void FUN_0047ddc0(char character);     /* derived name; not traced past the append */
    virtual void FUN_0047de10(const char *string); /* derived name; not traced past the append */
    virtual bool FUN_0047de50();                   /* derived name */

  private:
    char text
        [131076]; /* +0x8: 0x20000 characters, the slot-3 method writes "..." over the last three when full */
    int length;      /* +0x2000c */
    bool overflowed; /* +0x20010, slot 5 returns it */
};

Object0047dd90::~Object0047dd90() {}

const char *Object0047dd90::FUN_0047ddb0()
{
    return text;
}

bool Object0047dd90::FUN_0047de50()
{
    return overflowed;
}
