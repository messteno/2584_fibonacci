#include <QtGlobal>
#include <QTime>

#include "field.h"

Field::Field()
{
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());

    int firstCellToGenerate = qrand() % 16;
    int secondCellToGenerate = firstCellToGenerate;

    while (secondCellToGenerate == firstCellToGenerate)
    {
        secondCellToGenerate = qrand() % 16;
    }

    for (int i = 0; i < 16; ++i)
    {
        if (i == firstCellToGenerate ||
            i == secondCellToGenerate)
        {
            cells_[i] = new Cell(true);
        }
        else
        {
            cells_[i] = new Cell(false);
        }
    }
}

void Field::onRightButtonPressed()
{/*
    for(int j = 2; j >= 0; --j)
    {
        for(int i = 0; i < 4; ++i)
        {
            Cell *cell = cells_[4 * i + j];
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
        }
    }*/
}


