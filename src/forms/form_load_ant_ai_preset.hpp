// forms/form_load_ant_ai_preset.hpp

#ifndef FORM_LOAD_ANT_AI_PRESET_H
#define FORM_LOAD_ANT_AI_PRESET_H

#include "ui_form_load_ant_ai_preset.h" // generated header

#include "aux_header.hpp"

namespace Ui
{
    class FormLoadAntAIPreset;
}

class FormLoadAntAIPreset : public QDialog
{
    Q_OBJECT

public:

    explicit FormLoadAntAIPreset(QWidget * parent = nullptr);
    ~FormLoadAntAIPreset();
    bool IsFormAccept();
    enum_t GetAntAIPreset();

private:

    Ui::FormLoadAntAIPreset * ui;
    QGraphicsScene * p_graphics_scene;

    struct
    {
        QPixmap pixmap_01;
        QPixmap pixmap_02;
        QPixmap pixmap_03;
        QPixmap pixmap_04;
        QPixmap pixmap_05;
        QPixmap pixmap_06;
        QPixmap pixmap_07;
        QPixmap pixmap_08;
        QPixmap pixmap_09;
        QPixmap pixmap_10;
        QPixmap pixmap_11;
        QPixmap pixmap_12;
        QPixmap pixmap_13;
        QPixmap pixmap_14;
        QPixmap pixmap_15;
        QPixmap pixmap_16;
        QPixmap pixmap_17;
        QPixmap pixmap_18;
        QPixmap pixmap_19;
        QPixmap pixmap_20;
        QPixmap pixmap_21;
        QPixmap pixmap_22;
        QPixmap pixmap_23;
        QPixmap pixmap_24;
        QPixmap pixmap_25;
        QPixmap pixmap_26;
        QPixmap pixmap_27;
        QPixmap pixmap_28;
        QPixmap pixmap_29;
        QPixmap pixmap_30;
        QPixmap pixmap_31;
    } scene;

    struct
    {
        bool form_accept;
    } flag;

    struct
    {
        enum_t ant_ai_preset;
    } param;

    void InitForm();
    void UpdateGraphicsScene();
    void closeEvent(QCloseEvent * e); // override method

private slots:

    void Slot_PushButton_Ok();
    void Slot_PushButton_Cancel();
    void Slot_ComboBox_AntAIPreset(int index);
};

#endif // FORM_LOAD_ANT_AI_PRESET_H
