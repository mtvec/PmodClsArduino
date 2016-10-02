#include <PmodCls.h>

PmodCls lcd{[](uint8_t b) {Serial.write(b);}};

void setup()
{
    Serial.begin(9600);
    lcd.begin();
    lcd.print("Hello, world!");
}

void loop()
{
    lcd.setCursor(0, 1);
    lcd.print(millis() / 1000);
}

