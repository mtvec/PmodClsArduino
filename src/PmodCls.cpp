#include "PmodCls.h"

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
