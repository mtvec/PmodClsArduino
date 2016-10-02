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

    size_t write(uint8_t b) override;
    using Print::write;

private:

    void writeCommand(const char* command);

    WriteFunc writeToDevice_;
};

#endif
