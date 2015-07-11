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

## parts

Designator(s) | Quantity | Description | Part Number
--- | --- | --- | ---
IC1 | 1 | STM8S 8-bit micro (TSSOP-20) | [STM8S003F3P6](http://www.digikey.com/product-detail/en/STM8S003F3P6/497-11946-5-ND/2765682)
P2 | 1 | 10-pin right-angled header, .1" Pitch | [PPTC101LGBN-RC](http://www.digikey.com/product-search/en?KeyWords=S5446-ND&WT.z_header=search_go)
U1 | 1 | Full speed USB <-> 9-pin Serial (SOP-16) | CH340G
U2 | 1 | 3.3V Regulator (SO-8) | [LD1117D33CTR](http://www.digikey.com/scripts/DkSearch/dksus.dll?Detail&itemSeq=175125035&uq=635712533888642171)
Y1 | 1 | 12Mhz Crystal | [NX3225SA](http://www.digikey.com/product-detail/en/NX3225SA-12.000MHZ-STD-CSR-1/644-1047-1-ND/1128919)
C1 | 1 | 0.1 uF (0603) | ...
C2 | 1 | 10 uF (0603) | ...
C3 | 1 | 1 μF polarized (0603) | ...
C4, C5 | 2 | 20 pF (0603) | ...

* [STM8 Reference design](http://www.st.com/web/en/resource/technical/document/application_note/CD00194637.pdf#page=19)

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
