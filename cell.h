#ifndef CELL_H
#define CELL_H

#include <QPainter>

class Cell
{
private:
    int value_;
public:
    Cell(bool needGenerate);
    void setValue(int value);
    int getValue();
    void draw(QPainter &painter, int size);
};

#endif // CELL_H
