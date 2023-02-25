#ifndef _EPD_CONFIG_H
#define _EPD_CONFIG_H

#include <Arduino.h>

class EPDisplay
{
public:
    EPDisplay(byte spi_bus, byte pin_clk, byte pin_miso, byte pin_mosi, uint16_t pin_cs, uint16_t pin_dc, uint16_t pin_rst, uint16_t pin_busy);
    ~EPDisplay();

    void init() const;

private:
    byte _spi_bus;
    byte _pin_clk;
    byte _pin_miso;
    byte _pin_mosi;
    uint16_t _pin_cs;
    uint16_t _pin_dc;
    uint16_t _pin_rst;
    uint16_t _pin_busy;
};

#endif
