// aux_header.hpp

#ifndef AUX_HEADER_H
#define AUX_HEADER_H

#include <QApplication>
#include <QBrush>
#include <QCloseEvent>
#include <QColor>
#include <QDialog>
#include <QGraphicsScene>
#include <QIcon>
#include <QMainWindow>
#include <QMessageBox>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QPushButton>
#include <QRect>
#include <QSize>
#include <QString>
#include <QTimer>
#include <QWidget>

#include <vector>

// aliases

typedef int enum_t;
typedef int cell_t;
typedef cell_t ** field_t;
typedef char ant_turn_t;
typedef char ant_direction_t;

// structs

struct ant_ai_t
{
    std::vector<ant_turn_t> value;
    int full_size;
    int real_size;
};

struct ant_position_t
{
    int cell_x;
    int cell_y;
    ant_direction_t direction;
};

// constants

const int FIELD_SIZE_X = 250;
const int FIELD_SIZE_Y = 250;

const int MATRIX_SIZE_X = FIELD_SIZE_X;
const int MATRIX_SIZE_Y = FIELD_SIZE_Y;

const cell_t CELL_NONE = 0;
const cell_t CELL_01 = 1;
const cell_t CELL_02 = 2;
const cell_t CELL_03 = 3;
const cell_t CELL_04 = 4;
const cell_t CELL_05 = 5;
const cell_t CELL_06 = 6;
const cell_t CELL_07 = 7;
const cell_t CELL_08 = 8;
const cell_t CELL_09 = 9;
const cell_t CELL_10 = 10;
const cell_t CELL_11 = 11;
const cell_t CELL_12 = 12;

const ant_turn_t ANT_TURN_NONE = '-';
const ant_turn_t ANT_TURN_LEFT = 'L';
const ant_turn_t ANT_TURN_RIGHT = 'R';

const ant_direction_t ANT_DIRECTION_UP = 'U';
const ant_direction_t ANT_DIRECTION_DOWN = 'D';
const ant_direction_t ANT_DIRECTION_LEFT = 'L';
const ant_direction_t ANT_DIRECTION_RIGHT = 'R';

const enum_t APP_STATE_DEFAULT = 1;
const enum_t APP_STATE_PLAY = 2;
const enum_t APP_STATE_PAUSE = 3;
const enum_t APP_STATE_STOP = 4;
const enum_t APP_STATE_NEXT = 5;
const enum_t APP_STATE_FORWARD = 6;
const enum_t APP_STATE_END = 7;

const enum_t ANT_AI_PRESET_01 = 1;
const enum_t ANT_AI_PRESET_02 = 2;
const enum_t ANT_AI_PRESET_03 = 3;
const enum_t ANT_AI_PRESET_04 = 4;
const enum_t ANT_AI_PRESET_05 = 5;
const enum_t ANT_AI_PRESET_06 = 6;
const enum_t ANT_AI_PRESET_07 = 7;
const enum_t ANT_AI_PRESET_08 = 8;
const enum_t ANT_AI_PRESET_09 = 9;
const enum_t ANT_AI_PRESET_10 = 10;
const enum_t ANT_AI_PRESET_11 = 11;
const enum_t ANT_AI_PRESET_12 = 12;
const enum_t ANT_AI_PRESET_13 = 13;
const enum_t ANT_AI_PRESET_14 = 14;
const enum_t ANT_AI_PRESET_15 = 15;
const enum_t ANT_AI_PRESET_16 = 16;
const enum_t ANT_AI_PRESET_17 = 17;
const enum_t ANT_AI_PRESET_18 = 18;
const enum_t ANT_AI_PRESET_19 = 19;
const enum_t ANT_AI_PRESET_20 = 20;
const enum_t ANT_AI_PRESET_21 = 21;
const enum_t ANT_AI_PRESET_22 = 22;
const enum_t ANT_AI_PRESET_23 = 23;
const enum_t ANT_AI_PRESET_24 = 24;
const enum_t ANT_AI_PRESET_25 = 25;
const enum_t ANT_AI_PRESET_26 = 26;
const enum_t ANT_AI_PRESET_27 = 27;
const enum_t ANT_AI_PRESET_28 = 28;
const enum_t ANT_AI_PRESET_29 = 29;
const enum_t ANT_AI_PRESET_30 = 30;
const enum_t ANT_AI_PRESET_31 = 31;

#endif // AUX_HEADER_H
