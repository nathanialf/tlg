/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16b7720 (stored by FUN_00bc62a0 FUN_00bd2050 FUN_00bd2b50): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object00bd2be0 /* derived name */
{
  public:
    virtual Object00bd2be0 *FUN_00bd2050(void *where); /* derived name */
    virtual Object00bd2be0 *FUN_00bd2b50(void *where); /* derived name */
    virtual void FUN_00bd20a0(void *argument);         /* derived name */
    virtual const void *FUN_00bd2ba0();                /* derived name */
    virtual void FUN_00bd2bb0(bool deallocate);        /* derived name */
    virtual ~Object00bd2be0();
    virtual void *FUN_00bd2c00(); /* derived name */

  private:
    unsigned char stored[32]; /* +0x8, 32 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object00bd2be0::FUN_00bd2bb0(bool deallocate)
{
    this->~Object00bd2be0();
    if (deallocate)
        operator delete(this);
}

Object00bd2be0::~Object00bd2be0() {}

void *Object00bd2be0::FUN_00bd2c00()
{
    return &stored;
}
