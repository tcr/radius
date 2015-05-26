var SerialPort = require("serialport").SerialPort;
var concat = require('concat-stream');
var assert = require('assert');

var sp = new SerialPort(process.argv[2], {
  baudrate: 19200
}, false); // this is the openImmediately flag [default is true]

var source = 'Tessel Tag\r\n';

sp.open(function (error) {
  console.error('pipe open...');

  var pipe = concat(function (data) {
    // console.log(data.toString());
    console.log(data);
    assert.equal(data[0], 0x2A);
  });

  sp.on('data', function (data) {
    pipe.write(data);
  })

  var WHOAMI = 0x0D;
  var X_MSB = 0x01;

  sp.write(new Buffer(['R'.charCodeAt(0), WHOAMI]), function (err, results) {
    console.error('err?', err, 'bytes written:', results);

    setTimeout(function () {
      console.error('done.');
      // sp.end();
      sp.close();
      pipe.end();
    }, 250);
  });
});
