// classes/class_field.hpp

#ifndef CLASS_FIELD_H
#define CLASS_FIELD_H

#include "aux_header.hpp"

class ClassField
{
public:

    ClassField();
    ~ClassField();
    void InRawData();
    field_t OutRawData();
    cell_t GetCell(int x, int y);
    void SetCell(int x, int y, cell_t cell);
    void ClearField();

private:

    struct
    {
        field_t simulation;
        field_t io;
    } field;

    field_t CreateMatrix();
    void DeleteMatrix(field_t pp_matrix);
    void ClearMatrix(field_t pp_matrix);
    void CopyMatrix(field_t pp_matrix_dest, field_t pp_matrix_src);
};

#endif // CLASS_FIELD_H
