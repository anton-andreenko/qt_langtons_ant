// forms/form_load_ant_ai_preset_slots.cpp

#include "forms/form_load_ant_ai_preset.hpp"

void FormLoadAntAIPreset::Slot_PushButton_Ok()
{
    flag.form_accept = true;
    QDialog::accept();
}

void FormLoadAntAIPreset::Slot_PushButton_Cancel()
{
    flag.form_accept = false;
    QDialog::reject();
}

void FormLoadAntAIPreset::Slot_ComboBox_AntAIPreset(int index)
{
    if (index == 0)
    {
        param.ant_ai_preset = ANT_AI_PRESET_01;
    }
    else if (index == 1)
    {
        param.ant_ai_preset = ANT_AI_PRESET_02;
    }
    else if (index == 2)
    {
        param.ant_ai_preset = ANT_AI_PRESET_03;
    }
    else if (index == 3)
    {
        param.ant_ai_preset = ANT_AI_PRESET_04;
    }
    else if (index == 4)
    {
        param.ant_ai_preset = ANT_AI_PRESET_05;
    }
    else if (index == 5)
    {
        param.ant_ai_preset = ANT_AI_PRESET_06;
    }
    else if (index == 6)
    {
        param.ant_ai_preset = ANT_AI_PRESET_07;
    }
    else if (index == 7)
    {
        param.ant_ai_preset = ANT_AI_PRESET_08;
    }
    else if (index == 8)
    {
        param.ant_ai_preset = ANT_AI_PRESET_09;
    }
    else if (index == 9)
    {
        param.ant_ai_preset = ANT_AI_PRESET_10;
    }
    else if (index == 10)
    {
        param.ant_ai_preset = ANT_AI_PRESET_11;
    }
    else if (index == 11)
    {
        param.ant_ai_preset = ANT_AI_PRESET_12;
    }
    else if (index == 12)
    {
        param.ant_ai_preset = ANT_AI_PRESET_13;
    }
    else if (index == 13)
    {
        param.ant_ai_preset = ANT_AI_PRESET_14;
    }
    else if (index == 14)
    {
        param.ant_ai_preset = ANT_AI_PRESET_15;
    }
    else if (index == 15)
    {
        param.ant_ai_preset = ANT_AI_PRESET_16;
    }
    else if (index == 16)
    {
        param.ant_ai_preset = ANT_AI_PRESET_17;
    }
    else if (index == 17)
    {
        param.ant_ai_preset = ANT_AI_PRESET_18;
    }
    else if (index == 18)
    {
        param.ant_ai_preset = ANT_AI_PRESET_19;
    }
    else if (index == 19)
    {
        param.ant_ai_preset = ANT_AI_PRESET_20;
    }
    else if (index == 20)
    {
        param.ant_ai_preset = ANT_AI_PRESET_21;
    }
    else if (index == 21)
    {
        param.ant_ai_preset = ANT_AI_PRESET_22;
    }
    else if (index == 22)
    {
        param.ant_ai_preset = ANT_AI_PRESET_23;
    }
    else if (index == 23)
    {
        param.ant_ai_preset = ANT_AI_PRESET_24;
    }
    else if (index == 24)
    {
        param.ant_ai_preset = ANT_AI_PRESET_25;
    }
    else if (index == 25)
    {
        param.ant_ai_preset = ANT_AI_PRESET_26;
    }
    else if (index == 26)
    {
        param.ant_ai_preset = ANT_AI_PRESET_27;
    }
    else if (index == 27)
    {
        param.ant_ai_preset = ANT_AI_PRESET_28;
    }
    else if (index == 28)
    {
        param.ant_ai_preset = ANT_AI_PRESET_29;
    }
    else if (index == 29)
    {
        param.ant_ai_preset = ANT_AI_PRESET_30;
    }
    else if (index == 30)
    {
        param.ant_ai_preset = ANT_AI_PRESET_31;
    }

    UpdateGraphicsScene();
}
