/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */

/* derived names: a class whose destructor does nothing, the vtable at
 * 0x16af910 (stored by FUN_008b0660 FUN_008b06b0): slot 5 the complete
 * destructor, slot 6 the deleting one (operator delete of the object). A
 * callable holder: slots 0 and 1 copy what it holds at +0x8 (into a new block
 * when given none), slot 7 returns its address. */
class Object008b0810 /* derived name */
{
  public:
    virtual Object008b0810 *FUN_008b0660(void *where); /* derived name */
    virtual Object008b0810 *FUN_008b06b0(void *where); /* derived name */
    virtual void FUN_008b0700(void *argument);         /* derived name */
    virtual const void *FUN_008b07d0();                /* derived name */
    virtual void FUN_008b07e0(bool deallocate);        /* derived name */
    virtual ~Object008b0810();
    virtual void *FUN_008b0830(); /* derived name */

  private:
    unsigned char stored[32]; /* +0x8, 32 bytes copied by slots 0 and 1 */
};

/* slot 4: destroys the object through its virtual destructor, then frees
 * the storage when asked */
void Object008b0810::FUN_008b07e0(bool deallocate)
{
    this->~Object008b0810();
    if (deallocate)
        operator delete(this);
}

Object008b0810::~Object008b0810() {}

void *Object008b0810::FUN_008b0830()
{
    return &stored;
}
