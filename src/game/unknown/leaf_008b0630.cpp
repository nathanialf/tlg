/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16aff00 (stored by FUN_008b0550 FUN_008b0590): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008b0630 /* derived name */
{
  public:
    virtual Object008b0630 *FUN_008b0550(void *where); /* derived name */
    virtual Object008b0630 *FUN_008b0590(void *where); /* derived name */
    virtual void FUN_008b05d0(void *argument);         /* derived name */
    virtual const void *FUN_008b05f0();                /* derived name */
    virtual void FUN_008b0600(bool deallocate);        /* derived name */
    virtual ~Object008b0630();
    virtual void *FUN_008b0650(); /* derived name */

  private:
    char stored; /* +0x8, 1 byte copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object008b0630::FUN_008b0600(bool deallocate)
{
    this->~Object008b0630();
    if (deallocate)
        operator delete(this);
}

Object008b0630::~Object008b0630() {}

void *Object008b0630::FUN_008b0650()
{
    return &stored;
}
