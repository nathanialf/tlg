/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16c0130 (stored by FUN_00fa5620 FUN_00fbdb30 FUN_00fbdb80): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object00fbdd00 /* derived name */
{
  public:
    virtual Object00fbdd00 *FUN_00fbdb30(void *where); /* derived name */
    virtual Object00fbdd00 *FUN_00fbdb80(void *where); /* derived name */
    virtual void FUN_00fbdbd0(void *argument);         /* derived name */
    virtual const void *FUN_00fbdcc0();                /* derived name */
    virtual void FUN_00fbdcd0(bool deallocate);        /* derived name */
    virtual ~Object00fbdd00();
    virtual void *FUN_00fbdd20(); /* derived name */

  private:
    unsigned char stored[16]; /* +0x8, 16 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object00fbdd00::FUN_00fbdcd0(bool deallocate)
{
    this->~Object00fbdd00();
    if (deallocate)
        operator delete(this);
}

Object00fbdd00::~Object00fbdd00() {}

void *Object00fbdd00::FUN_00fbdd20()
{
    return &stored;
}
