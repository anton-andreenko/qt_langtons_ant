// widgets/widget_paint_area.hpp

#ifndef WIDGET_PAINT_AREA_H
#define WIDGET_PAINT_AREA_H

#include "aux_header.hpp"
#include "classes/class_field.hpp"

class WidgetPaintArea : public QWidget
{
    Q_OBJECT

public:

    explicit WidgetPaintArea(QWidget * parent = nullptr);
    ~WidgetPaintArea();
    void SetField(ClassField * arg);

private:

    ClassField * p_field;

    struct
    {
        QColor background_black;
        QColor background_white;
        QColor cell_none;
        QColor cell_01;
        QColor cell_02;
        QColor cell_03;
        QColor cell_04;
        QColor cell_05;
        QColor cell_06;
        QColor cell_07;
        QColor cell_08;
        QColor cell_09;
        QColor cell_10;
        QColor cell_11;
        QColor cell_12;
    } color;

    struct
    {
        QPen background;
    } pen;

    struct
    {
        QBrush background;
        QBrush cell_none;
        QBrush cell_01;
        QBrush cell_02;
        QBrush cell_03;
        QBrush cell_04;
        QBrush cell_05;
        QBrush cell_06;
        QBrush cell_07;
        QBrush cell_08;
        QBrush cell_09;
        QBrush cell_10;
        QBrush cell_11;
        QBrush cell_12;
    } brush;

    struct
    {
        int polygon_size_x;
        int polygon_size_y;
        int scene_margin;
    } area;

    void paintEvent(QPaintEvent * e); // override method
};

#endif // WIDGET_PAINT_AREA_H
