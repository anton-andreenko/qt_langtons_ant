// main_window.hpp

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "ui_main_window.h" // generated header

#include "aux_header.hpp"
#include "forms/form_load_ant_ai_preset.hpp"
#include "classes/class_field.hpp"
#include "classes/class_ant.hpp"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

private:

    Ui::MainWindow * ui;
    QTimer * p_timer;
    ClassField * p_field;
    ClassAnt * p_ant;
    std::vector<QPushButton *> ant_ai_steps;

    struct
    {
        bool simulation;
        bool field_size_limit;
    } flag;

    struct
    {
        int fps; // frames per second
        int ipf; // iterations per frame
    } param;

    struct
    {
        int iteration_number;
    } info;

    void InitApplication();
    void EnableWidgets(enum_t app_state);
    void UpdateWidgetsInfo();
    void UpdateWidgetsAntAI();
    void DrawGraphicScene();
    void ShowMessageBox(QString title, QString text);
    void DoNextIteration();

private slots:

    void Slot_Action_File_Exit();
    void Slot_Action_AntAI_ResetAI();
    void Slot_Action_AntAI_LoadAIPreset();
    void Slot_Action_Help_About();
    void Slot_PushButton_Play();
    void Slot_PushButton_Pause();
    void Slot_PushButton_Stop();
    void Slot_PushButton_Next();
    void Slot_PushButton_Forward();
    void Slot_PushButton_AntAIStep01();
    void Slot_PushButton_AntAIStep02();
    void Slot_PushButton_AntAIStep03();
    void Slot_PushButton_AntAIStep04();
    void Slot_PushButton_AntAIStep05();
    void Slot_PushButton_AntAIStep06();
    void Slot_PushButton_AntAIStep07();
    void Slot_PushButton_AntAIStep08();
    void Slot_PushButton_AntAIStep09();
    void Slot_PushButton_AntAIStep10();
    void Slot_PushButton_AntAIStep11();
    void Slot_PushButton_AntAIStep12();
    void Slot_SpinBox_FPS(int value);
    void Slot_SpinBox_IPF(int value);
    void Slot_Timer();
};

#endif // MAIN_WINDOW_H
