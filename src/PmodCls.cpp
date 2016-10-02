#include "PmodCls.h"

namespace Constants
{
    const uint8_t NumRows = 2;
    const uint8_t NumCols = 16;
};

PmodCls::PmodCls(WriteFunc writeToDevice) : writeToDevice_{writeToDevice}
{
}

void PmodCls::begin(uint8_t, uint8_t, uint8_t)
{
    clear();

    // Set display mode to wrap at 16 characters.
    writeCommand("0h");
}

void PmodCls::clear()
{
    writeCommand("j");
}

void PmodCls::setCursor(uint8_t col, uint8_t row)
{
    if (col < Constants::NumCols && row < Constants::NumRows)
    {
        char command[6];
        sprintf(command, "%u;%uH", row, col);
        writeCommand(command);
    }
}

size_t PmodCls::write(uint8_t b)
{
    writeToDevice_(b);
    return 1;
}

void PmodCls::writeCommand(const char* command)
{
    write("\x1b[");
    write(command);
}
