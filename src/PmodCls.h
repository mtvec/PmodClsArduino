#ifndef PMODCLS_H
#define PMODCLS_H

#include <Print.h>

class PmodCls : public Print
{
public:

    typedef void (*WriteFunc)(uint8_t);

    PmodCls(WriteFunc writeToDevice);

    void begin(uint8_t cols = 0, uint8_t rows = 0, uint8_t charsize = 0);

    void clear();
    void setCursor(uint8_t col, uint8_t row);
    void home();
    void cursor();
    void noCursor();
    void blink();
    void noBlink();

    size_t write(uint8_t b) override;
    using Print::write;

private:

    void updateCursor();
    void writeCommand(const char* command);

    WriteFunc writeToDevice_;
    bool showCursor_;
    bool blink_;
};

#endif
