#ifndef CELL_H
#define CELL_H

class Cell
{
private:
    int value_;
public:
    Cell(bool needGenerate);
    void setValue(int value);
    int getValue();
    void draw(QPainter &painter, int position);
};

#endif // CELL_H
