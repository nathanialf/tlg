/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c0a50 (stored by FUN_01005850 FUN_010058a0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object01005950 /* derived name */
{
  public:
    virtual Object01005950 *FUN_01005850(void *where); /* derived name */
    virtual Object01005950 *FUN_010058a0(void *where); /* derived name */
    virtual void FUN_010058f0(void *argument);         /* derived name */
    virtual const void *FUN_01005910();                /* derived name */
    virtual void FUN_01005920(bool deallocate);        /* derived name */
    virtual ~Object01005950();
    virtual void *FUN_01005970(); /* derived name */

  private:
    unsigned char stored[16]; /* +0x8, 16 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object01005950::FUN_01005920(bool deallocate)
{
    this->~Object01005950();
    if (deallocate)
        operator delete(this);
}

Object01005950::~Object01005950() {}

void *Object01005950::FUN_01005970()
{
    return &stored;
}
