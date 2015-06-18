var SerialPort = require("serialport").SerialPort;
var concat = require('concat-stream');
var assert = require('assert');

var sp = new SerialPort(process.argv[2], {
  baudrate: 57600
}, false); // this is the openImmediately flag [default is true]

var source = 'Tessel Tag\r\n';

sp.open(function (error) {
  console.error('pipe open...');

  var pipe = concat(function (data) {
    // console.log(data.toString());

    // Read until first response
    while (data[0] != 'r'.charCodeAt(0)) {
      data = data.slice(1);
    }
    console.log(data);

    assert.equal(data[0], 'r'.charCodeAt(0));
    assert.equal(data[1], 0x2A);
    return;

    var rawData = data;
    var scaleRange = 1;
    var out = [];
    for (var i = 0; i < 3 ; i++) {
      var gCount = (rawData[i*2] << 8) | rawData[(i*2)+1];  // Combine the two 8 bit registers into one 12-bit number

      gCount = (gCount >> 4); // The registers are left align, here we right align the 12-bit integer

      // If the number is negative, we have to make it so manually (no 12-bit data type)
      if (rawData[i*2] > 0x7F) {
        gCount = -(1 + 0xFFF - gCount); // Transform into negative 2's complement
      }

      out[i] = gCount / ((1<<12)/(2*scaleRange));
    }

    console.log(out);
  });

  sp.on('data', function (data) {
    pipe.write(data);
  })

  var WHOAMI = 0x0D;
  var X_MSB = 0x01;

  var out = new Buffer(17);
  out[0] = 0x02;
  out[1] = WHOAMI;
  out[2] = 0x01;

  sp.write(out, function (err, results) {
    console.error('err?', err, 'bytes written:', results);

    setTimeout(function () {
      console.error('done.');
      // sp.end();
      sp.close();
      pipe.end();
    }, 250);
  });
});
