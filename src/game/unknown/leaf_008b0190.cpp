/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16af7d0 (stored by FUN_008b00b0 FUN_008b00f0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008b0190 /* derived name */
{
  public:
    virtual Object008b0190 *FUN_008b00b0(void *where); /* derived name */
    virtual Object008b0190 *FUN_008b00f0(void *where); /* derived name */
    virtual void FUN_008b0130(void *argument);         /* derived name */
    virtual const void *FUN_008b0150();                /* derived name */
    virtual void FUN_008b0160(bool deallocate);        /* derived name */
    virtual ~Object008b0190();
    virtual void *FUN_008b01b0(); /* derived name */

  private:
    void *stored; /* +0x8, 8 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object008b0190::FUN_008b0160(bool deallocate)
{
    this->~Object008b0190();
    if (deallocate)
        operator delete(this);
}

Object008b0190::~Object008b0190() {}

void *Object008b0190::FUN_008b01b0()
{
    return &stored;
}
