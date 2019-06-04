// forms/form_load_ant_ai_preset.cpp

#include "forms/form_load_ant_ai_preset.hpp"

FormLoadAntAIPreset::FormLoadAntAIPreset(QWidget * parent) :
    QDialog(parent),
    ui(new Ui::FormLoadAntAIPreset),
    p_graphics_scene(nullptr)
{
    ui->setupUi(this);
    InitForm();
    UpdateGraphicsScene();

    // signals & slots

    connect(ui->ComboBox_AntAIPreset, SIGNAL(currentIndexChanged(int)), SLOT(Slot_ComboBox_AntAIPreset(int)));
    connect(ui->PushButton_Cancel, SIGNAL(released()), SLOT(Slot_PushButton_Cancel()));
    connect(ui->PushButton_Ok, SIGNAL(released()), SLOT(Slot_PushButton_Ok()));
}

FormLoadAntAIPreset::~FormLoadAntAIPreset()
{
    delete ui;
    delete p_graphics_scene;
}

bool FormLoadAntAIPreset::IsFormAccept()
{
    bool result = flag.form_accept;

    return result;
}

enum_t FormLoadAntAIPreset::GetAntAIPreset()
{
    enum_t result = param.ant_ai_preset;

    return result;
}

void FormLoadAntAIPreset::InitForm()
{
    p_graphics_scene = new QGraphicsScene(this);
    scene.pixmap_01 = QPixmap(":/resources/pictures/ant_ai_preset_01.png");
    scene.pixmap_02 = QPixmap(":/resources/pictures/ant_ai_preset_02.png");
    scene.pixmap_03 = QPixmap(":/resources/pictures/ant_ai_preset_03.png");
    scene.pixmap_04 = QPixmap(":/resources/pictures/ant_ai_preset_04.png");
    scene.pixmap_05 = QPixmap(":/resources/pictures/ant_ai_preset_05.png");
    scene.pixmap_06 = QPixmap(":/resources/pictures/ant_ai_preset_06.png");
    scene.pixmap_07 = QPixmap(":/resources/pictures/ant_ai_preset_07.png");
    scene.pixmap_08 = QPixmap(":/resources/pictures/ant_ai_preset_08.png");
    scene.pixmap_09 = QPixmap(":/resources/pictures/ant_ai_preset_09.png");
    scene.pixmap_10 = QPixmap(":/resources/pictures/ant_ai_preset_10.png");
    scene.pixmap_11 = QPixmap(":/resources/pictures/ant_ai_preset_11.png");
    scene.pixmap_12 = QPixmap(":/resources/pictures/ant_ai_preset_12.png");
    scene.pixmap_13 = QPixmap(":/resources/pictures/ant_ai_preset_13.png");
    scene.pixmap_14 = QPixmap(":/resources/pictures/ant_ai_preset_14.png");
    scene.pixmap_15 = QPixmap(":/resources/pictures/ant_ai_preset_15.png");
    scene.pixmap_16 = QPixmap(":/resources/pictures/ant_ai_preset_16.png");
    scene.pixmap_17 = QPixmap(":/resources/pictures/ant_ai_preset_17.png");
    scene.pixmap_18 = QPixmap(":/resources/pictures/ant_ai_preset_18.png");
    scene.pixmap_19 = QPixmap(":/resources/pictures/ant_ai_preset_19.png");
    scene.pixmap_20 = QPixmap(":/resources/pictures/ant_ai_preset_20.png");
    scene.pixmap_21 = QPixmap(":/resources/pictures/ant_ai_preset_21.png");
    scene.pixmap_22 = QPixmap(":/resources/pictures/ant_ai_preset_22.png");
    scene.pixmap_23 = QPixmap(":/resources/pictures/ant_ai_preset_23.png");
    scene.pixmap_24 = QPixmap(":/resources/pictures/ant_ai_preset_24.png");
    scene.pixmap_25 = QPixmap(":/resources/pictures/ant_ai_preset_25.png");
    scene.pixmap_26 = QPixmap(":/resources/pictures/ant_ai_preset_26.png");
    scene.pixmap_27 = QPixmap(":/resources/pictures/ant_ai_preset_27.png");
    scene.pixmap_28 = QPixmap(":/resources/pictures/ant_ai_preset_28.png");
    scene.pixmap_29 = QPixmap(":/resources/pictures/ant_ai_preset_29.png");
    scene.pixmap_30 = QPixmap(":/resources/pictures/ant_ai_preset_30.png");
    scene.pixmap_31 = QPixmap(":/resources/pictures/ant_ai_preset_31.png");
    flag.form_accept = false;
    param.ant_ai_preset = ANT_AI_PRESET_01;

    // UI config

    ui->ComboBox_AntAIPreset->setCurrentIndex(0);
    ui->GraphicsView_AntAIPreset->setScene(p_graphics_scene);
}

void FormLoadAntAIPreset::UpdateGraphicsScene()
{
    p_graphics_scene->clear();

    if (param.ant_ai_preset == ANT_AI_PRESET_01)
    {
        p_graphics_scene->addPixmap(scene.pixmap_01);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_02)
    {
        p_graphics_scene->addPixmap(scene.pixmap_02);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_03)
    {
        p_graphics_scene->addPixmap(scene.pixmap_03);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_04)
    {
        p_graphics_scene->addPixmap(scene.pixmap_04);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_05)
    {
        p_graphics_scene->addPixmap(scene.pixmap_05);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_06)
    {
        p_graphics_scene->addPixmap(scene.pixmap_06);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_07)
    {
        p_graphics_scene->addPixmap(scene.pixmap_07);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_08)
    {
        p_graphics_scene->addPixmap(scene.pixmap_08);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_09)
    {
        p_graphics_scene->addPixmap(scene.pixmap_09);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_10)
    {
        p_graphics_scene->addPixmap(scene.pixmap_10);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_11)
    {
        p_graphics_scene->addPixmap(scene.pixmap_11);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_12)
    {
        p_graphics_scene->addPixmap(scene.pixmap_12);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_13)
    {
        p_graphics_scene->addPixmap(scene.pixmap_13);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_14)
    {
        p_graphics_scene->addPixmap(scene.pixmap_14);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_15)
    {
        p_graphics_scene->addPixmap(scene.pixmap_15);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_16)
    {
        p_graphics_scene->addPixmap(scene.pixmap_16);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_17)
    {
        p_graphics_scene->addPixmap(scene.pixmap_17);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_18)
    {
        p_graphics_scene->addPixmap(scene.pixmap_18);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_19)
    {
        p_graphics_scene->addPixmap(scene.pixmap_19);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_20)
    {
        p_graphics_scene->addPixmap(scene.pixmap_20);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_21)
    {
        p_graphics_scene->addPixmap(scene.pixmap_21);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_22)
    {
        p_graphics_scene->addPixmap(scene.pixmap_22);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_23)
    {
        p_graphics_scene->addPixmap(scene.pixmap_23);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_24)
    {
        p_graphics_scene->addPixmap(scene.pixmap_24);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_25)
    {
        p_graphics_scene->addPixmap(scene.pixmap_25);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_26)
    {
        p_graphics_scene->addPixmap(scene.pixmap_26);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_27)
    {
        p_graphics_scene->addPixmap(scene.pixmap_27);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_28)
    {
        p_graphics_scene->addPixmap(scene.pixmap_28);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_29)
    {
        p_graphics_scene->addPixmap(scene.pixmap_29);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_30)
    {
        p_graphics_scene->addPixmap(scene.pixmap_30);
    }
    else if (param.ant_ai_preset == ANT_AI_PRESET_31)
    {
        p_graphics_scene->addPixmap(scene.pixmap_31);
    }
}

void FormLoadAntAIPreset::closeEvent(QCloseEvent * e)
{
    flag.form_accept = false;
    e->accept();
}
