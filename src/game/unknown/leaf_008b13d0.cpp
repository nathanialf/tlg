/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16afb40 (stored by FUN_008b0ff0 FUN_008b1040): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008b13d0 /* derived name */
{
  public:
    virtual Object008b13d0 *FUN_008b0ff0(void *where); /* derived name */
    virtual Object008b13d0 *FUN_008b1040(void *where); /* derived name */
    virtual void FUN_008b1090(void *argument);         /* derived name */
    virtual const void *FUN_008b1390();                /* derived name */
    virtual void FUN_008b13a0(bool deallocate);        /* derived name */
    virtual ~Object008b13d0();
    virtual void *FUN_008b13f0(); /* derived name */

  private:
    unsigned char stored[56]; /* +0x8, 56 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object008b13d0::FUN_008b13a0(bool deallocate)
{
    this->~Object008b13d0();
    if (deallocate)
        operator delete(this);
}

Object008b13d0::~Object008b13d0() {}

void *Object008b13d0::FUN_008b13f0()
{
    return &stored;
}
