#include "cell.h"

Cell::Cell(bool needGenerate)
{
    value_ = 0;
    if (needGenerate == true)
        value_ = (qrand() % 2) + 1;
}

void Cell::setValue(int value)
{
    value_ = value;
}

int Cell::getValue()
{
    return value_;
}




