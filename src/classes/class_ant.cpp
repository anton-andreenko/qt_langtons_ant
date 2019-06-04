// classes/class_ant.cpp

#include "classes/class_ant.hpp"

ClassAnt::ClassAnt()
{
    ResetAntAI();
    ResetAntPosition();
}

ClassAnt::~ClassAnt()
{}

void ClassAnt::ResetAntAI()
{
    ant_ai.value.clear();
    ant_ai.value = { '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' };
    ant_ai.full_size = ant_ai.value.size();
    ant_ai.real_size = 0;
}

void ClassAnt::ResetAntPosition()
{
    ant_position.cell_x = static_cast<int>(FIELD_SIZE_X / 2);
    ant_position.cell_y = static_cast<int>(FIELD_SIZE_Y / 2);
    ant_position.direction = ANT_DIRECTION_UP;
}

ant_ai_t ClassAnt::GetAntAI()
{
    ant_ai_t result = ant_ai;

    return result;
}

ant_position_t ClassAnt::GetAntPosition()
{
    ant_position_t result = ant_position;

    return result;
}

void ClassAnt::SetAntAI(ant_ai_t value)
{
    ant_ai = value;
}

void ClassAnt::SetAntPosition(ant_position_t value)
{
    ant_position = value;
}

void ClassAnt::TurnAnt(ant_turn_t ant_turn)
{
    ant_direction_t ant_direction = ant_position.direction;

    if (ant_turn == ANT_TURN_LEFT)
    {
        if (ant_direction == ANT_DIRECTION_UP)
        {
            ant_position.direction = ANT_DIRECTION_LEFT;
        }
        else if (ant_direction == ANT_DIRECTION_DOWN)
        {
            ant_position.direction = ANT_DIRECTION_RIGHT;
        }
        else if (ant_direction == ANT_DIRECTION_LEFT)
        {
            ant_position.direction = ANT_DIRECTION_DOWN;
        }
        else if (ant_direction == ANT_DIRECTION_RIGHT)
        {
            ant_position.direction = ANT_DIRECTION_UP;
        }
    }
    else if (ant_turn == ANT_TURN_RIGHT)
    {
        if (ant_direction == ANT_DIRECTION_UP)
        {
            ant_position.direction = ANT_DIRECTION_RIGHT;
        }
        else if (ant_direction == ANT_DIRECTION_DOWN)
        {
            ant_position.direction = ANT_DIRECTION_LEFT;
        }
        else if (ant_direction == ANT_DIRECTION_LEFT)
        {
            ant_position.direction = ANT_DIRECTION_UP;
        }
        else if (ant_direction == ANT_DIRECTION_RIGHT)
        {
            ant_position.direction = ANT_DIRECTION_DOWN;
        }
    }
}

bool ClassAnt::MoveAnt()
{
    bool result = false;
    bool is_up = (ant_position.cell_y > 0);
    bool is_down = (ant_position.cell_y < (FIELD_SIZE_Y - 1));
    bool is_left = (ant_position.cell_x > 0);
    bool is_right = (ant_position.cell_x < (FIELD_SIZE_X - 1));

    if (ant_position.direction == ANT_DIRECTION_UP)
    {
        if (true == is_up)
        {
            result = true;
            ant_position.cell_y -= 1;
        }
    }
    else if (ant_position.direction == ANT_DIRECTION_DOWN)
    {
        if (true == is_down)
        {
            result = true;
            ant_position.cell_y += 1;
        }
    }
    else if (ant_position.direction == ANT_DIRECTION_LEFT)
    {
        if (true == is_left)
        {
            result = true;
            ant_position.cell_x -= 1;
        }
    }
    else if (ant_position.direction == ANT_DIRECTION_RIGHT)
    {
        if (true == is_right)
        {
            result = true;
            ant_position.cell_x += 1;
        }
    }

    return result;
}

void ClassAnt::LoadAntAIPreset(enum_t ant_ai_preset)
{
    ResetAntAI();

    if (ant_ai_preset == ANT_AI_PRESET_01)
    {
        ant_ai.value = { 'R', 'L', 'R', 'L', 'R', 'L', 'L', 'R', 'L', 'R', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_02)
    {
        ant_ai.value = { 'L', 'L', 'R', 'L', 'L', 'L', 'R', 'R', '-', '-', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_03)
    {
        ant_ai.value = { 'L', 'R', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_04)
    {
        ant_ai.value = { 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'L', 'R', 'L', 'L', 'R' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_05)
    {
        ant_ai.value = { 'R', 'R', 'L', 'R', 'L', 'R', 'R', '-', '-', '-', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_06)
    {
        ant_ai.value = { 'R', 'R', 'L', 'L', 'L', 'R', 'L', 'L', 'L', 'R', 'R', 'R' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_07)
    {
        ant_ai.value = { 'R', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'L', 'L', 'L', 'R' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_08)
    {
        ant_ai.value = { 'R', 'R', 'L', 'R', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_09)
    {
        ant_ai.value = { 'L', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'R', 'R', 'R', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_10)
    {
        ant_ai.value = { 'L', 'L', 'L', 'R', 'L', 'L', 'R', 'R', 'L', 'L', 'L', 'L' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_11)
    {
        ant_ai.value = { 'R', 'R', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'L', 'R' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_12)
    {
        ant_ai.value = { 'R', 'L', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'R', 'R', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_13)
    {
        ant_ai.value = { 'L', 'L', 'R', 'L', '-', '-', '-', '-', '-', '-', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_14)
    {
        ant_ai.value = { 'R', 'R', 'L', 'R', 'L', 'L', 'R', 'L', 'R', 'R', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_15)
    {
        ant_ai.value = { 'L', 'R', 'R', 'R', 'R', 'L', 'L', 'L', 'R', 'R', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_16)
    {
        ant_ai.value = { 'L', 'R', 'R', 'R', 'R', 'R', 'L', 'L', 'R', '-', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_17)
    {
        ant_ai.value = { 'R', 'R', 'L', 'R', 'R', '-', '-', '-', '-', '-', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_18)
    {
        ant_ai.value = { 'L', 'L', 'L', 'R', 'L', 'L', 'R', 'R', 'R', 'L', 'L', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_19)
    {
        ant_ai.value = { 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'L', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_20)
    {
        ant_ai.value = { 'L', 'L', 'R', 'R', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_21)
    {
        ant_ai.value = { 'L', 'R', 'L', 'R', 'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_22)
    {
        ant_ai.value = { 'R', 'L', 'R', '-', '-', '-', '-', '-', '-', '-', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_23)
    {
        ant_ai.value = { 'R', 'R', 'L', 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'R' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_24)
    {
        ant_ai.value = { 'L', 'R', 'L', 'L', 'R', 'R', 'R', 'R', 'R', '-', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_25)
    {
        ant_ai.value = { 'R', 'L', 'L', 'R', '-', '-', '-', '-', '-', '-', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_26)
    {
        ant_ai.value = { 'L', 'L', 'R', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_27)
    {
        ant_ai.value = { 'R', 'R', 'L', 'L', 'L', 'R', 'L', 'L', 'L', 'R', '-', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_28)
    {
        ant_ai.value = { 'L', 'L', 'R', 'R', 'R', 'L', 'R', 'R', 'R', 'R', 'R', '-' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_29)
    {
        ant_ai.value = { 'R', 'R', 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'L', 'R', 'R' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_30)
    {
        ant_ai.value = { 'L', 'L', 'R', 'R', 'L', 'L', 'L', 'R', 'L', 'R', 'R', 'R' };
    }
    else if (ant_ai_preset == ANT_AI_PRESET_31)
    {
        ant_ai.value = { 'L', 'L', 'R', 'R', '-', '-', '-', '-', '-', '-', '-', '-' };
    }

    ant_ai.full_size = ant_ai.value.size();
    UpdateAntAIRealSize();
}

void ClassAnt::ChangeAntAI(int ant_ai_step)
{
    ant_turn_t ant_turn = ANT_TURN_NONE;

    if (ant_ai_step < ant_ai.full_size)
    {
        ant_turn = ant_ai.value[ant_ai_step];

        if (ant_turn == ANT_TURN_NONE)
        {
            ant_ai.value[ant_ai_step] = ANT_TURN_LEFT;
        }
        else if (ant_turn == ANT_TURN_LEFT)
        {
            ant_ai.value[ant_ai_step] = ANT_TURN_RIGHT;
        }
        else if (ant_turn == ANT_TURN_RIGHT)
        {
            ant_ai.value[ant_ai_step] = ANT_TURN_NONE;
        }
    }
}

void ClassAnt::CorrectAntAI()
{
    bool flag_clear = false;

    for (int i = 0; (i < ant_ai.full_size); i++)
    {
        if (true == flag_clear)
        {
            ant_ai.value[i] = ANT_TURN_NONE;
        }
        else if (ant_ai.value[i] == ANT_TURN_NONE)
        {
            flag_clear = true;
        }
    }

    UpdateAntAIRealSize();
}

void ClassAnt::UpdateAntAIRealSize()
{
    ant_ai.real_size = 0;

    for (int i = 0; (i < ant_ai.full_size); i++)
    {
        if (ant_ai.value[i] != ANT_TURN_NONE)
        {
            ant_ai.real_size += 1;
        }
        else
        {
            i = ant_ai.full_size;
        }
    }
}
