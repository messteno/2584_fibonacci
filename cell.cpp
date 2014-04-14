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

void Cell::draw(QPainter &painter, int size)
{
    QRect rect = QRect(5, 5, size - 10, size - 10);
    painter.setBrush(QColor(0xdd, 0xcc, 0xbb));
    painter.setPen(QColor(0xdd, 0xcc, 0xbb));
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawRoundedRect(rect, 5, 5);

    if (value_ != 0)
    {
        QString text = QString::number(value_);
        painter.setPen(QColor(0x88, 0x77, 0x66));

        QFont font("Arial");
        font.setBold(true);

        QFontMetrics fm(font);

        double textWidth = fm.width(text);
        double textHeight = fm.height();
        double scaleWidth = rect.width() / textWidth / 1.1;
        double scaleHeight = rect.height() / textHeight / 1.5;
        double scale = scaleWidth < scaleHeight ?
                    scaleWidth : scaleHeight;

        double fontSize = font.pointSizeF();
        fontSize *= scale;
        font.setPointSizeF(fontSize);

        painter.setFont(font);
        painter.drawText(rect, Qt::AlignCenter, text);
    }
}




