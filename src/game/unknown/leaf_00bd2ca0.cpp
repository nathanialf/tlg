/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16b7770 (stored by FUN_00bc62a0 FUN_00bd2140 FUN_00bd2c10): slot 5 the
 * complete destructor, slot 6 the deleting one (operator delete of the
 * object). A callable holder: slots 0 and 1 copy what it holds at +0x8 (into a
 * new block when given none), slot 7 returns its address. */
class Object00bd2ca0 /* derived name */
{
  public:
    virtual Object00bd2ca0 *FUN_00bd2140(void *where); /* derived name */
    virtual Object00bd2ca0 *FUN_00bd2c10(void *where); /* derived name */
    virtual void FUN_00bd2190(void *argument);         /* derived name */
    virtual const void *FUN_00bd2c60();                /* derived name */
    virtual void FUN_00bd2c70(bool deallocate);        /* derived name */
    virtual ~Object00bd2ca0();
    virtual void *FUN_00bd2cc0(); /* derived name */

  private:
    unsigned char stored[32]; /* +0x8, 32 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object00bd2ca0::FUN_00bd2c70(bool deallocate)
{
    this->~Object00bd2ca0();
    if (deallocate)
        operator delete(this);
}

Object00bd2ca0::~Object00bd2ca0() {}

void *Object00bd2ca0::FUN_00bd2cc0()
{
    return &stored;
}
