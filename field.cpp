#include <QtGlobal>
#include <QTime>

#include <QPainter>
#include "field.h"


Field::Field(QWidget *parent) :
    QWidget(parent)
{
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());

    for (int i = 0; i < 16; ++i)
        cells_[i] = new Cell(false);
    generateCell();
    generateCell();
}

void Field::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    painter.fillRect(0, 0, width(), height(),
                     QColor(0xbb, 0xaa, 0xaa));

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            painter.save();
            painter.translate(width() / 4 * j,
                              height() / 4 * i);
            cells_[4 * i + j]->draw(painter, width() / 4);
            painter.restore();
        }
    }

    painter.end();
}

void Field::onRightButtonPressed()
{
    for(int j = 2; j >= 0; --j)
    {
        for(int i = 0; i < 4; ++i)
        {
            Cell *cell = cells_[4 * i + j];
            if (cell->getValue() == 0)
                continue;

            int notEmptyCol = 4;
            for (int k = j + 1; k < 4; ++k)
            {
                if (cells_[4 * i + k]->getValue() != 0)
                {
                    notEmptyCol = k;
                    break;
                }
            }
            if (notEmptyCol == 4)
            {
                int value = cell->getValue();
                cells_[4 * i + 3]->setValue(value);
                cell->setValue(0);
                continue;
            }

            Cell *cell2 = cells_[4 * i + notEmptyCol];
            if (isCellsConnectable(cell, cell2))
            {
                int value = cell->getValue() +
                            cell2->getValue();
                cell2->setValue(value);
                cell2->setUpdated(true);
                cell->setValue(0);
            }
            else if (notEmptyCol == j + 1)
            {
                 continue;
            }
            else
            {
                cell2 = cells_[4 * i + notEmptyCol - 1];
                int value = cell->getValue();
                cell2->setValue(value);
                cell->setValue(0);
            }
        }
    }

    for (int i =0; i < 16; ++i)
        cells_[i]->setUpdated(false);
    generateCell();
    update();
}

bool Field::isCellsConnectable(Cell *c1, Cell *c2)
{
    return false;
}

void Field::generateCell()
{
    int emptyCount = 0;
    for (int i = 0 ; i < 16; ++i)
    {
        if (cells_[i]->getValue() == 0)
            emptyCount ++;
    }

    if (emptyCount == 0)
        return;

    int position = qrand() % emptyCount;

    emptyCount = 0;
    for (int i = 0 ; i < 16; ++i)
    {
        if (cells_[i]->getValue() == 0)
        {
            if (emptyCount == position)
            {
                cells_[i]->setValue(qrand() % 2 + 1);
                break;
            }
            emptyCount ++;
        }
    }
}
