// classes/class_field.cpp

#include "classes/class_field.hpp"

ClassField::ClassField() :
    field{nullptr, nullptr}
{
    field.simulation = CreateMatrix();
    field.io = CreateMatrix();
    ClearMatrix(field.simulation);
    ClearMatrix(field.io);
}

ClassField::~ClassField()
{
    DeleteMatrix(field.simulation);
    DeleteMatrix(field.io);
    field.simulation = nullptr;
    field.io = nullptr;
}

void ClassField::InRawData()
{
    CopyMatrix(field.simulation, field.io);
}

field_t ClassField::OutRawData()
{
    CopyMatrix(field.io, field.simulation);

    return field.io;
}

cell_t ClassField::GetCell(int x, int y)
{
    cell_t result = field.simulation[y][x];

    return result;
}

void ClassField::SetCell(int x, int y, cell_t cell)
{
    field.simulation[y][x] = cell;
}

void ClassField::ClearField()
{
    ClearMatrix(field.simulation);
}

field_t ClassField::CreateMatrix()
{
    cell_t ** pp_matrix = new cell_t * [MATRIX_SIZE_Y];

    for (int y = 0; (y < MATRIX_SIZE_Y); y++)
    {
        pp_matrix[y] = new cell_t [MATRIX_SIZE_X];
    }

    return pp_matrix;
}

void ClassField::DeleteMatrix(field_t pp_matrix)
{
    for (int y = 0; (y < MATRIX_SIZE_Y); y++)
    {
        delete[] pp_matrix[y];
    }

    delete[] pp_matrix;
}

void ClassField::ClearMatrix(field_t pp_matrix)
{
    for (int y = 0; (y < MATRIX_SIZE_Y); y++)
    {
        for (int x = 0; (x < MATRIX_SIZE_X); x++)
        {
            pp_matrix[y][x] = CELL_NONE;
        }
    }
}

void ClassField::CopyMatrix(field_t pp_matrix_dest, field_t pp_matrix_src)
{
    for (int y = 0; (y < MATRIX_SIZE_Y); y++)
    {
        for (int x = 0; (x < MATRIX_SIZE_X); x++)
        {
            pp_matrix_dest[y][x] = pp_matrix_src[y][x];
        }
    }
}
