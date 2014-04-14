#ifndef FIELD_H
#define FIELD_H

#include "cell.h"

class Field
{
private:
    Cell *cells_[16];
public:
    Field();
    void onRightButtonPressed();
    void onDownButtonPressed();
    void onLeftButtonPressed();
    void onUpButtonPressed();
    bool isCellsConnectable(Cell *c1, Cell *c2);
    void connectCells(Cell *c1, Cell *c2);
    void generateCell();
    void repaint();
};

#endif // FIELD_H
