#include <EPD.h>

// #define SPI_BUS HSPI
// #define PIN_CLK 14
// #define PIN_MISO 12
// #define PIN_MOSI 13
// #define PIN_CS 15
// #define PIN_DC 2
// #define PIN_RST 17
// #define PIN_BUSY 16

EPDisplay::EPDisplay(byte spi_bus, byte pin_clk, byte pin_miso, byte pin_mosi, uint16_t pin_cs, uint16_t pin_dc, uint16_t pin_rst, uint16_t pin_busy)
    : _spi_bus(spi_bus),
      _pin_clk(pin_clk),
      _pin_miso(pin_miso),
      _pin_mosi(pin_mosi),
      _pin_cs(pin_cs),
      _pin_dc(pin_dc),
      _pin_rst(pin_rst),
      _pin_busy(pin_busy) {}

EPDisplay::~EPDisplay()
{
    delete select_spi;
    delete display;
}

void EPDisplay::init()
{
    Serial.begin(115200);
    Serial.println();
    Serial.println("setup connection");

    delay(100);

    select_spi = new SPIClass(_spi_bus);                                                                                    // 选择 ESP32 的对应 SPI 总线
    display = new GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT>(GxEPD2_154_D67(_pin_cs, _pin_dc, _pin_rst, _pin_busy)); // GDEH0154D67 1.54" b/w 200x200, SSD1681

    select_spi->begin(_pin_clk, _pin_miso, _pin_mosi, _pin_cs);
    display->epd2.selectSPI(*select_spi, SPISettings(4000000, MSBFIRST, SPI_MODE0));
    display->init();
}
