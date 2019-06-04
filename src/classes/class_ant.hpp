// classes/class_ant.hpp

#ifndef CLASS_ANT_H
#define CLASS_ANT_H

#include "aux_header.hpp"

class ClassAnt
{
public:

    ClassAnt();
    ~ClassAnt();
    void ResetAntAI();
    void ResetAntPosition();
    ant_ai_t GetAntAI();
    ant_position_t GetAntPosition();
    void SetAntAI(ant_ai_t value);
    void SetAntPosition(ant_position_t value);
    void TurnAnt(ant_turn_t ant_turn);
    bool MoveAnt();
    void LoadAntAIPreset(enum_t ant_ai_preset);
    void ChangeAntAI(int ant_ai_step);
    void CorrectAntAI();

private:

    ant_ai_t ant_ai;
    ant_position_t ant_position;
    void UpdateAntAIRealSize();
};

#endif // CLASS_ANT_H
