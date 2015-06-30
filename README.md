# radius

![](https://cloud.githubusercontent.com/assets/80639/8431800/d7c6bc7c-1f09-11e5-9089-ed34c545b8b4.png)

## testing

```
make
make flash
make test
```

If OS X reports contention for your device:

```
sudo kextunload -b com.apple.driver.AppleUSBCardReader
sudo kextunload -b com.apple.iokit.IOUSBMassStorageClass
```

## pin mapping

* GND
* 3.3V
* SCL - PB4
* SDA - PB5
* SCK - PC5
* MISO - PC7
* MOSI - PC6
* TXD - PD2
* RXD - PD0
* G3 - PD1

USB:

* TXD - PD6
* RXD - PD5

## docs

Reference manual: http://www.st.com/web/en/resource/technical/document/reference_manual/CD00190271.pdf

 * SPI: http://www.st.com/web/en/resource/technical/document/reference_manual/CD00190271.pdf#page=259
 * I2C: http://www.st.com/web/en/resource/technical/document/reference_manual/CD00190271.pdf#page=285
 * GPIO: http://www.st.com/web/en/resource/technical/document/reference_manual/CD00190271.pdf#page=106
 * UART: http://www.st.com/web/en/resource/technical/document/reference_manual/CD00190271.pdf#page=318

CPU reference: http://www.st.com/web/en/resource/technical/document/programming_manual/CD00161709.pdf

Product Datasheet: http://www.st.com/web/en/resource/technical/document/datasheet/DM00024550.pdf

 * Memory map: http://www.st.com/web/en/resource/technical/document/datasheet/DM00024550.pdf#page=32
 * Pin map: http://www.st.com/web/en/resource/technical/document/datasheet/DM00024550.pdf#page=22

 Errata: http://postar.sino-star.com/public/uploads/20120214161049_871.pdf

## CH340G

Datasheet: http://www.seeedstudio.com/wiki/images/7/7c/CH340DS1_EN.PDF

## tools

https://github.com/vdudouyt/stm8flash

```
brew install sdcc
```

http://www.colecovision.eu/stm8/128-EVAL%20Dhrystone.shtml

## license

MIT/ASL2
