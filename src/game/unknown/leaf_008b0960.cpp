/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16af960 (stored by FUN_008b0840 FUN_008b0890): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008b0960 /* derived name */
{
  public:
    virtual Object008b0960 *FUN_008b0840(void *where); /* derived name */
    virtual Object008b0960 *FUN_008b0890(void *where); /* derived name */
    virtual void FUN_008b08e0(void *argument);         /* derived name */
    virtual const void *FUN_008b0920();                /* derived name */
    virtual void FUN_008b0930(bool deallocate);        /* derived name */
    virtual ~Object008b0960();
    virtual void *FUN_008b0980(); /* derived name */

  private:
    unsigned char stored[16]; /* +0x8, 16 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object008b0960::FUN_008b0930(bool deallocate)
{
    this->~Object008b0960();
    if (deallocate)
        operator delete(this);
}

Object008b0960::~Object008b0960() {}

void *Object008b0960::FUN_008b0980()
{
    return &stored;
}
