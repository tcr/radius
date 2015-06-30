
--------  --------
WRIPKT
  -------- --------
  RECV RX

RX faster than TX

async events have no ack, simply are expected to be sent out when buffered and have their buffer cleared before more data comes in

thus tx needs to be faster than rx for async
if there are two async streams, faster than both buffers filling simultaneously
double-buffered so it's always cleared first


swapped buffers for data reception for each channel
so, 4 out + 4 in + 2 active buffers

I2C TRANSFER OUT

TX double buffer
RX double buffer

enum ack_t {
	NACK = 0x00,
	ACK,
}

enum out_t {
	OUT_CONTROL = 0x10,
	OUT_I2C,
	OUT_UART,
	OUT_SPI,
};

enum in_t {
	IN_UART = 0x20,
	IN_SPI,
	IN_I2C,
	IN_GPIO (interupt or read)
};


SETUP [CONTROL TRANSFER]
- begin i2c transfer; tx and rx
- begin spi transfer; tx and rx
- begin uart transfer; tx
- set gpio output and/or read
- 

data packets
-> [byte] [16 bytes]
<- [ack] or [nack]
<- or impulse


OUT -> I2C MASTER TX
OUT -> UART TX
OUT -> SPI MASTER TX

IN -> UART RX (hi-pri)
IN -> I2C MASTER RX
IN -> SPI MASTER RX
IN -> GPIO INTERRUPT OR READ


1. uart fills buffers
2. main loop handles control elements buffers
3. other loops handle other buffers
4. acks only when empty

(so data packet of i2c data preceding i2c transfer is ok)




