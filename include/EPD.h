#ifndef _EPD_CONFIG_H
#define _EPD_CONFIG_H

#include <Arduino.h>

#include <GxEPD2_BW.h> //GxEPD2 lib
#include <GxEPD2_3C.h>

class EPDisplay
{
public:
    EPDisplay(byte spi_bus, byte pin_clk, byte pin_miso, byte pin_mosi, uint16_t pin_cs, uint16_t pin_dc, uint16_t pin_rst, uint16_t pin_busy);
    ~EPDisplay();

    void init();
    void showTime(int day, int hours, int minutes) const;
    void showBG(int wallpaper_code) const;

private:
    SPIClass *select_spi = NULL;
    GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> *display = NULL;

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

