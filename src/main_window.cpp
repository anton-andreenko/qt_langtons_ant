// main_window.cpp

#include "main_window.hpp"

MainWindow::MainWindow(QWidget * parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    p_timer(nullptr),
    p_field(nullptr),
    p_ant(nullptr)
{
    ui->setupUi(this);
    InitApplication();
    p_ant->LoadAntAIPreset(ANT_AI_PRESET_05);
    EnableWidgets(APP_STATE_DEFAULT);
    UpdateWidgetsInfo();
    UpdateWidgetsAntAI();
    DrawGraphicScene();

    // signals & slots

    connect(ui->Action_AntAI_LoadAIPreset, SIGNAL(triggered(bool)), SLOT(Slot_Action_AntAI_LoadAIPreset()));
    connect(ui->Action_AntAI_ResetAI, SIGNAL(triggered(bool)), SLOT(Slot_Action_AntAI_ResetAI()));
    connect(ui->Action_File_Exit, SIGNAL(triggered(bool)), SLOT(Slot_Action_File_Exit()));
    connect(ui->Action_Help_About, SIGNAL(triggered(bool)), SLOT(Slot_Action_Help_About()));
    connect(ui->PushButton_AntAIStep01, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep01()));
    connect(ui->PushButton_AntAIStep02, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep02()));
    connect(ui->PushButton_AntAIStep03, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep03()));
    connect(ui->PushButton_AntAIStep04, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep04()));
    connect(ui->PushButton_AntAIStep05, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep05()));
    connect(ui->PushButton_AntAIStep06, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep06()));
    connect(ui->PushButton_AntAIStep07, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep07()));
    connect(ui->PushButton_AntAIStep08, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep08()));
    connect(ui->PushButton_AntAIStep09, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep09()));
    connect(ui->PushButton_AntAIStep10, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep10()));
    connect(ui->PushButton_AntAIStep11, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep11()));
    connect(ui->PushButton_AntAIStep12, SIGNAL(released()), SLOT(Slot_PushButton_AntAIStep12()));
    connect(ui->PushButton_Forward, SIGNAL(released()), SLOT(Slot_PushButton_Forward()));
    connect(ui->PushButton_Next, SIGNAL(released()), SLOT(Slot_PushButton_Next()));
    connect(ui->PushButton_Pause, SIGNAL(released()), SLOT(Slot_PushButton_Pause()));
    connect(ui->PushButton_Play, SIGNAL(released()), SLOT(Slot_PushButton_Play()));
    connect(ui->PushButton_Stop, SIGNAL(released()), SLOT(Slot_PushButton_Stop()));
    connect(ui->SpinBox_FPS, SIGNAL(valueChanged(int)), SLOT(Slot_SpinBox_FPS(int)));
    connect(ui->SpinBox_IPF, SIGNAL(valueChanged(int)), SLOT(Slot_SpinBox_IPF(int)));
    connect(p_timer, SIGNAL(timeout()), SLOT(Slot_Timer()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete p_timer;
    delete p_field;
    delete p_ant;
}

void MainWindow::InitApplication()
{
    p_timer = new QTimer(this);
    p_timer->setTimerType(Qt::PreciseTimer);
    p_field = new ClassField();
    p_ant = new ClassAnt();
    ant_ai_steps.clear();
    ant_ai_steps.push_back(ui->PushButton_AntAIStep01);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep02);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep03);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep04);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep05);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep06);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep07);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep08);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep09);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep10);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep11);
    ant_ai_steps.push_back(ui->PushButton_AntAIStep12);
    flag.simulation = false;
    flag.field_size_limit = false;
    param.fps = 30;
    param.ipf = 10;
    info.iteration_number = 0;

    // UI config

    ui->Label_FieldSize->setText(
        QString("Field size: %1 * %2").arg(QString::number(FIELD_SIZE_X), QString::number(FIELD_SIZE_Y))
    );
    ui->Label_IterationNumber->setText(
        QString("Iteration: %1").arg(QString::number(info.iteration_number))
    );
    ui->PushButton_Forward->setIcon(QIcon(":/resources/icons/simulation_forward.png"));
    ui->PushButton_Forward->setIconSize(QSize(40, 40));
    ui->PushButton_Next->setIcon(QIcon(":/resources/icons/simulation_next.png"));
    ui->PushButton_Next->setIconSize(QSize(40, 40));
    ui->PushButton_Pause->setIcon(QIcon(":/resources/icons/simulation_pause.png"));
    ui->PushButton_Pause->setIconSize(QSize(40, 40));
    ui->PushButton_Play->setIcon(QIcon(":/resources/icons/simulation_play.png"));
    ui->PushButton_Play->setIconSize(QSize(40, 40));
    ui->PushButton_Stop->setIcon(QIcon(":/resources/icons/simulation_stop.png"));
    ui->PushButton_Stop->setIconSize(QSize(40, 40));
    ui->SpinBox_FPS->setValue(param.fps);
    ui->SpinBox_IPF->setValue(param.ipf);
    ui->WidgetPaintArea_GraphicScene->SetField(p_field);
}

void MainWindow::EnableWidgets(enum_t app_state)
{
    if (
        (app_state == APP_STATE_DEFAULT) ||
        (app_state == APP_STATE_PAUSE) ||
        (app_state == APP_STATE_STOP) ||
        (app_state == APP_STATE_NEXT) ||
        (app_state == APP_STATE_FORWARD)
    )
    {
        ui->Action_AntAI_LoadAIPreset->setEnabled(true);
        ui->Action_AntAI_ResetAI->setEnabled(true);
        ui->PushButton_Forward->setEnabled(true);
        ui->PushButton_Next->setEnabled(true);
        ui->PushButton_Pause->setEnabled(false);
        ui->PushButton_Play->setEnabled(true);
        ui->PushButton_Stop->setEnabled(true);
    }
    else if (app_state == APP_STATE_PLAY)
    {
        ui->Action_AntAI_LoadAIPreset->setEnabled(false);
        ui->Action_AntAI_ResetAI->setEnabled(false);
        ui->PushButton_Forward->setEnabled(false);
        ui->PushButton_Next->setEnabled(false);
        ui->PushButton_Pause->setEnabled(true);
        ui->PushButton_Play->setEnabled(false);
        ui->PushButton_Stop->setEnabled(true);
    }
    else if (app_state == APP_STATE_END)
    {
        ui->Action_AntAI_LoadAIPreset->setEnabled(true);
        ui->Action_AntAI_ResetAI->setEnabled(true);
        ui->PushButton_Forward->setEnabled(false);
        ui->PushButton_Next->setEnabled(false);
        ui->PushButton_Pause->setEnabled(false);
        ui->PushButton_Play->setEnabled(false);
        ui->PushButton_Stop->setEnabled(true);
    }

    if ((app_state == APP_STATE_DEFAULT) || (app_state == APP_STATE_STOP))
    {
        for (int i = 0, size = ant_ai_steps.size(); (i < size); i++)
        {
            ant_ai_steps[i]->setEnabled(true);
        }
    }
    else
    {
        for (int i = 0, size = ant_ai_steps.size(); (i < size); i++)
        {
            ant_ai_steps[i]->setEnabled(false);
        }
    }
}

void MainWindow::UpdateWidgetsInfo()
{
    ui->Label_IterationNumber->setText(
        QString("Iteration: %1").arg(QString::number(info.iteration_number))
    );
}

void MainWindow::UpdateWidgetsAntAI()
{
    ant_ai_t ant_ai = p_ant->GetAntAI();
    ant_turn_t ant_turn = ANT_TURN_NONE;

    for (int i = 0, size = ant_ai_steps.size(); (i < size); i++)
    {
        ant_turn = (i < ant_ai.full_size) ? ant_ai.value[i] : ANT_TURN_NONE;

        if (ant_turn == ANT_TURN_NONE)
        {
            ant_ai_steps[i]->setIcon(QIcon(":/resources/icons/turn_none.png"));
            ant_ai_steps[i]->setIconSize(QSize(20, 20));
            ant_ai_steps[i]->setToolTip("None");
        }
        else if (ant_turn == ANT_TURN_LEFT)
        {
            ant_ai_steps[i]->setIcon(QIcon(":/resources/icons/turn_left.png"));
            ant_ai_steps[i]->setIconSize(QSize(20, 20));
            ant_ai_steps[i]->setToolTip("Turn left");
        }
        else if (ant_turn == ANT_TURN_RIGHT)
        {
            ant_ai_steps[i]->setIcon(QIcon(":/resources/icons/turn_right.png"));
            ant_ai_steps[i]->setIconSize(QSize(20, 20));
            ant_ai_steps[i]->setToolTip("Turn right");
        }
    }
}

void MainWindow::DrawGraphicScene()
{
    ui->WidgetPaintArea_GraphicScene->update();
}

void MainWindow::ShowMessageBox(QString title, QString text)
{
    QMessageBox message_box(QMessageBox::NoIcon, title, text);
    message_box.exec();
}

void MainWindow::DoNextIteration()
{
    bool is_ant_move = false;
    ant_ai_t ant_ai = p_ant->GetAntAI();
    ant_position_t ant_position = p_ant->GetAntPosition();
    ant_turn_t ant_turn = ANT_TURN_NONE;
    cell_t old_cell = p_field->GetCell(ant_position.cell_x, ant_position.cell_y);
    cell_t new_cell = CELL_NONE;

    if (ant_ai.real_size > 0)
    {
        if ((old_cell == CELL_NONE) || (old_cell == CELL_01))
        {
            ant_turn = ant_ai.value[0];
            new_cell = (ant_ai.real_size != 1) ? CELL_02 : CELL_01;
        }
        else if (old_cell == CELL_02)
        {
            ant_turn = (ant_ai.real_size > 1) ? ant_ai.value[1] : ANT_TURN_NONE;
            new_cell = (ant_ai.real_size != 2) ? CELL_03 : CELL_01;
        }
        else if (old_cell == CELL_03)
        {
            ant_turn = (ant_ai.real_size > 2) ? ant_ai.value[2] : ANT_TURN_NONE;
            new_cell = (ant_ai.real_size != 3) ? CELL_04 : CELL_01;
        }
        else if (old_cell == CELL_04)
        {
            ant_turn = (ant_ai.real_size > 3) ? ant_ai.value[3] : ANT_TURN_NONE;
            new_cell = (ant_ai.real_size != 4) ? CELL_05 : CELL_01;
        }
        else if (old_cell == CELL_05)
        {
            ant_turn = (ant_ai.real_size > 4) ? ant_ai.value[4] : ANT_TURN_NONE;
            new_cell = (ant_ai.real_size != 5) ? CELL_06 : CELL_01;
        }
        else if (old_cell == CELL_06)
        {
            ant_turn = (ant_ai.real_size > 5) ? ant_ai.value[5] : ANT_TURN_NONE;
            new_cell = (ant_ai.real_size != 6) ? CELL_07 : CELL_01;
        }
        else if (old_cell == CELL_07)
        {
            ant_turn = (ant_ai.real_size > 6) ? ant_ai.value[6] : ANT_TURN_NONE;
            new_cell = (ant_ai.real_size != 7) ? CELL_08 : CELL_01;
        }
        else if (old_cell == CELL_08)
        {
            ant_turn = (ant_ai.real_size > 7) ? ant_ai.value[7] : ANT_TURN_NONE;
            new_cell = (ant_ai.real_size != 8) ? CELL_09 : CELL_01;
        }
        else if (old_cell == CELL_09)
        {
            ant_turn = (ant_ai.real_size > 8) ? ant_ai.value[8] : ANT_TURN_NONE;
            new_cell = (ant_ai.real_size != 9) ? CELL_10 : CELL_01;
        }
        else if (old_cell == CELL_10)
        {
            ant_turn = (ant_ai.real_size > 9) ? ant_ai.value[9] : ANT_TURN_NONE;
            new_cell = (ant_ai.real_size != 10) ? CELL_11 : CELL_01;
        }
        else if (old_cell == CELL_11)
        {
            ant_turn = (ant_ai.real_size > 10) ? ant_ai.value[10] : ANT_TURN_NONE;
            new_cell = (ant_ai.real_size != 11) ? CELL_12 : CELL_01;
        }
        else if (old_cell == CELL_12)
        {
            ant_turn = (ant_ai.real_size > 11) ? ant_ai.value[11] : ANT_TURN_NONE;
            new_cell = CELL_01;
        }

        p_field->SetCell(ant_position.cell_x, ant_position.cell_y, new_cell);
        p_ant->TurnAnt(ant_turn);
        is_ant_move = p_ant->MoveAnt();

        if (false == is_ant_move)
        {
            flag.field_size_limit = true;
        }
    }
}
