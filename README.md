# radius

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

## docs

Reference manual: http://www.st.com/web/en/resource/technical/document/reference_manual/CD00190271.pdf

* SPI: http://www.st.com/web/en/resource/technical/document/reference_manual/CD00190271.pdf#page=259
* GPIO: http://www.st.com/web/en/resource/technical/document/reference_manual/CD00190271.pdf#page=106

CPU reference: http://www.st.com/web/en/resource/technical/document/programming_manual/CD00161709.pdf

Product Datasheet: http://www.st.com/web/en/resource/technical/document/datasheet/DM00024550.pdf

* Memory map: http://www.st.com/web/en/resource/technical/document/datasheet/DM00024550.pdf#page=32

## tools

https://github.com/vdudouyt/stm8flash

```
brew install sdcc
```

http://www.colecovision.eu/stm8/128-EVAL%20Dhrystone.shtml

## license

MIT/ASL2
