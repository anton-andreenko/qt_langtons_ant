// widgets/widget_paint_area.cpp

#include "widgets/widget_paint_area.hpp"

WidgetPaintArea::WidgetPaintArea(QWidget * parent) :
    QWidget(parent),
    p_field(nullptr)
{
    color.background_black = QColor(0, 0, 0);
    color.background_white = QColor(255, 255, 255);
    color.cell_none = QColor(50, 50, 50);
    color.cell_01 = QColor(250, 250, 250);
    color.cell_02 = QColor(200, 100, 100);
    color.cell_03 = QColor(100, 200, 100);
    color.cell_04 = QColor(40, 120, 170);
    color.cell_05 = QColor(50, 200, 200);
    color.cell_06 = QColor(100, 110, 130);
    color.cell_07 = QColor(200, 200, 50);
    color.cell_08 = QColor(200, 140, 120);
    color.cell_09 = QColor(160, 90, 180);
    color.cell_10 = QColor(140, 140, 40);
    color.cell_11 = QColor(20, 140, 120);
    color.cell_12 = QColor(240, 140, 40);
    pen.background = QPen(color.background_black, 1, Qt::SolidLine);
    brush.background = QBrush(color.background_white, Qt::SolidPattern);
    brush.cell_none = QBrush(color.cell_none, Qt::SolidPattern);
    brush.cell_01 = QBrush(color.cell_01, Qt::SolidPattern);
    brush.cell_02 = QBrush(color.cell_02, Qt::SolidPattern);
    brush.cell_03 = QBrush(color.cell_03, Qt::SolidPattern);
    brush.cell_04 = QBrush(color.cell_04, Qt::SolidPattern);
    brush.cell_05 = QBrush(color.cell_05, Qt::SolidPattern);
    brush.cell_06 = QBrush(color.cell_06, Qt::SolidPattern);
    brush.cell_07 = QBrush(color.cell_07, Qt::SolidPattern);
    brush.cell_08 = QBrush(color.cell_08, Qt::SolidPattern);
    brush.cell_09 = QBrush(color.cell_09, Qt::SolidPattern);
    brush.cell_10 = QBrush(color.cell_10, Qt::SolidPattern);
    brush.cell_11 = QBrush(color.cell_11, Qt::SolidPattern);
    brush.cell_12 = QBrush(color.cell_12, Qt::SolidPattern);
    area.polygon_size_x = 3;
    area.polygon_size_y = 3;
    area.scene_margin = 5;
}

WidgetPaintArea::~WidgetPaintArea()
{
    p_field = nullptr;
}

void WidgetPaintArea::SetField(ClassField * arg)
{
    p_field = arg;
}

void WidgetPaintArea::paintEvent(QPaintEvent * e)
{
    QPainter painter;
    painter.begin(this);
    painter.setPen(pen.background);
    painter.setBrush(brush.background);
    painter.drawRect(
        QRect(0, 0, (this->width() - 1), (this->height() - 1))
    );

    if (nullptr != p_field)
    {
        field_t tmp_field = p_field->OutRawData();
        cell_t tmp_cell = CELL_NONE;
        painter.setPen(Qt::NoPen);

        for (int y = 0; (y < MATRIX_SIZE_Y); y++)
        {
            for (int x = 0; (x < MATRIX_SIZE_X); x++)
            {
                tmp_cell = tmp_field[y][x];

                if (tmp_cell == CELL_NONE)
                {
                    painter.setBrush(brush.cell_none);
                }
                else if (tmp_cell == CELL_01)
                {
                    painter.setBrush(brush.cell_01);
                }
                else if (tmp_cell == CELL_02)
                {
                    painter.setBrush(brush.cell_02);
                }
                else if (tmp_cell == CELL_03)
                {
                    painter.setBrush(brush.cell_03);
                }
                else if (tmp_cell == CELL_04)
                {
                    painter.setBrush(brush.cell_04);
                }
                else if (tmp_cell == CELL_05)
                {
                    painter.setBrush(brush.cell_05);
                }
                else if (tmp_cell == CELL_06)
                {
                    painter.setBrush(brush.cell_06);
                }
                else if (tmp_cell == CELL_07)
                {
                    painter.setBrush(brush.cell_07);
                }
                else if (tmp_cell == CELL_08)
                {
                    painter.setBrush(brush.cell_08);
                }
                else if (tmp_cell == CELL_09)
                {
                    painter.setBrush(brush.cell_09);
                }
                else if (tmp_cell == CELL_10)
                {
                    painter.setBrush(brush.cell_10);
                }
                else if (tmp_cell == CELL_11)
                {
                    painter.setBrush(brush.cell_11);
                }
                else if (tmp_cell == CELL_12)
                {
                    painter.setBrush(brush.cell_12);
                }
                else
                {
                    painter.setBrush(Qt::NoBrush);
                }

                painter.drawRect(
                    QRect(
                        (x * area.polygon_size_x + area.scene_margin),
                        (y * area.polygon_size_y + area.scene_margin),
                        area.polygon_size_x,
                        area.polygon_size_y
                    )
                );
            }
        }
    }

    painter.end();
}
