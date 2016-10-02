#include "PmodCls.h"

namespace Constants
{
    const uint8_t NumRows = 2;
    const uint8_t NumCols = 16;
};

PmodCls::PmodCls(WriteFunc writeToDevice)
    : writeToDevice_{writeToDevice}, showCursor_{false}, blink_{false}
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

void PmodCls::home()
{
    setCursor(0, 0);
}

void PmodCls::cursor()
{
    showCursor_ = true;
    updateCursor();
}

void PmodCls::noCursor()
{
    showCursor_ = false;
    updateCursor();
}

void PmodCls::blink()
{
    blink_ = true;
    updateCursor();
}

void PmodCls::noBlink()
{
    blink_ = false;
    updateCursor();
}

void PmodCls::scrollDisplay(int numCols)
{
    if (numCols < Constants::NumCols && numCols > -Constants::NumCols)
    {
        char code = 'A';

        if (numCols < 0)
        {
            code = '@';
            numCols = -numCols;
        }

        char command[4];
        sprintf(command, "%u%c", numCols, code);
        writeCommand(command);
    }
}

void PmodCls::scrollDisplayLeft(unsigned numCols)
{
    scrollDisplay(-numCols);
}

void PmodCls::scrollDisplayRight(unsigned numCols)
{
    scrollDisplay(numCols);
}

size_t PmodCls::write(uint8_t b)
{
    writeToDevice_(b);
    return 1;
}

void PmodCls::updateCursor()
{
    unsigned cursorMode = 0;

    if (showCursor_)
        cursorMode = blink_ ? 2 : 1;

    char command[3];
    sprintf(command, "%uc", cursorMode);
    writeCommand(command);
}

void PmodCls::writeCommand(const char* command)
{
    write("\x1b[");
    write(command);
}
