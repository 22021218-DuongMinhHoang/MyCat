#include "Cell.h"

Cell::Cell()
{
    //ctor
}

Cell::~Cell()
{
    //dtor
}

Cell& Cell::operator=(const Cell& c)
{
    Pos.x = c.Pos.x; Pos.y = c.Pos.y;
    prev = c.prev;
    type = c.type;
    g = c.g; h = c.h; f = c.f;
    cellx = c.cellx; celly = c.celly;
    cHandle = c.cHandle;
}
