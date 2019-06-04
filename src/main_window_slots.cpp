// main_window_slots.cpp

#include "main_window.hpp"

void MainWindow::Slot_Action_File_Exit()
{
    QApplication::quit();
}

void MainWindow::Slot_Action_AntAI_ResetAI()
{
    if (false == flag.simulation)
    {
        p_field->ClearField();
        p_ant->ResetAntAI();
        p_ant->ResetAntPosition();
        flag.field_size_limit = false;
        info.iteration_number = 0;
        EnableWidgets(APP_STATE_DEFAULT);
        UpdateWidgetsInfo();
        UpdateWidgetsAntAI();
        DrawGraphicScene();
    }
}

void MainWindow::Slot_Action_AntAI_LoadAIPreset()
{
    if (false == flag.simulation)
    {
        FormLoadAntAIPreset * p_form = new FormLoadAntAIPreset(this);
        Qt::WindowFlags window_flags =
            Qt::Window |
            Qt::WindowCloseButtonHint;
        p_form->setWindowFlags(window_flags);
        p_form->exec();

        if (true == p_form->IsFormAccept())
        {
            p_field->ClearField();
            p_ant->LoadAntAIPreset(p_form->GetAntAIPreset());
            p_ant->ResetAntPosition();
            flag.field_size_limit = false;
            info.iteration_number = 0;
            EnableWidgets(APP_STATE_DEFAULT);
            UpdateWidgetsInfo();
            UpdateWidgetsAntAI();
            DrawGraphicScene();
        }

        delete p_form;
    }
}

void MainWindow::Slot_Action_Help_About()
{
    QString title;
    QString text;
    title.append("About");
    text.append("<div><b>Langton's Ant</b><hr/>Author: Anton Andreenko</div>");
    ShowMessageBox(title, text);
}

void MainWindow::Slot_PushButton_Play()
{
    if ((false == flag.simulation) && (false == flag.field_size_limit))
    {
        if (info.iteration_number == 0)
        {
            p_ant->CorrectAntAI();
            UpdateWidgetsAntAI();
        }

        flag.simulation = true;
        p_timer->start(
            static_cast<int>(1000 / param.fps)
        );
        EnableWidgets(APP_STATE_PLAY);
    }
}

void MainWindow::Slot_PushButton_Pause()
{
    if (true == flag.simulation)
    {
        flag.simulation = false;
        p_timer->stop();
        EnableWidgets(APP_STATE_PAUSE);
    }
}

void MainWindow::Slot_PushButton_Stop()
{
    if (true == flag.simulation)
    {
        flag.simulation = false;
        p_timer->stop();
    }

    p_field->ClearField();
    p_ant->ResetAntPosition();
    flag.field_size_limit = false;
    info.iteration_number = 0;
    EnableWidgets(APP_STATE_STOP);
    UpdateWidgetsInfo();
    DrawGraphicScene();
}

void MainWindow::Slot_PushButton_Next()
{
    if ((false == flag.simulation) && (false == flag.field_size_limit))
    {
        if (info.iteration_number == 0)
        {
            p_ant->CorrectAntAI();
            UpdateWidgetsAntAI();
        }

        DoNextIteration();
        info.iteration_number += 1;

        if (false == flag.field_size_limit)
        {
            EnableWidgets(APP_STATE_NEXT);
        }
        else
        {
            EnableWidgets(APP_STATE_END);
        }

        UpdateWidgetsInfo();
        DrawGraphicScene();
    }
}

void MainWindow::Slot_PushButton_Forward()
{
    if ((false == flag.simulation) && (false == flag.field_size_limit))
    {
        if (info.iteration_number == 0)
        {
            p_ant->CorrectAntAI();
            UpdateWidgetsAntAI();
        }

        for (int i = 0; ((false == flag.field_size_limit) && (i < 50000)); i++)
        {
            DoNextIteration();
            info.iteration_number += 1;
        }

        if (false == flag.field_size_limit)
        {
            EnableWidgets(APP_STATE_FORWARD);
        }
        else
        {
            EnableWidgets(APP_STATE_END);
        }

        UpdateWidgetsInfo();
        DrawGraphicScene();
    }
}

void MainWindow::Slot_PushButton_AntAIStep01()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(0);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep02()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(1);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep03()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(2);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep04()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(3);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep05()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(4);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep06()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(5);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep07()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(6);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep08()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(7);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep09()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(8);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep10()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(9);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep11()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(10);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_PushButton_AntAIStep12()
{
    if (false == flag.simulation)
    {
        p_ant->ChangeAntAI(11);
        UpdateWidgetsAntAI();
    }
}

void MainWindow::Slot_SpinBox_FPS(int value)
{
    param.fps = value;
    p_timer->setInterval(
        static_cast<int>(1000 / param.fps)
    );
}

void MainWindow::Slot_SpinBox_IPF(int value)
{
    param.ipf = value;
}

void MainWindow::Slot_Timer()
{
    for (int i = 0 ; ((false == flag.field_size_limit) && (i < param.ipf)); i++)
    {
        DoNextIteration();
        info.iteration_number += 1;
    }

    if (true == flag.field_size_limit)
    {
        flag.simulation = false;
        p_timer->stop();
        EnableWidgets(APP_STATE_END);
    }

    UpdateWidgetsInfo();
    DrawGraphicScene();
}
