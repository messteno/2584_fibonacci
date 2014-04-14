#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include "cell.h"

class Field : public QWidget
{
private:
    Cell *cells_[16];

protected:
    virtual void paintEvent(QPaintEvent *);

public:
    Field(QWidget *parent = 0);
    void onRightButtonPressed();
    void onDownButtonPressed();
    void onLeftButtonPressed();
    void onUpButtonPressed();
    bool isCellsConnectable(Cell *c1, Cell *c2);
    void connectCells(Cell *c1, Cell *c2);
    void generateCell();
};

#endif // FIELD_H
