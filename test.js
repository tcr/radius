var SerialPort = require("serialport").SerialPort;
var concat = require('concat-stream');
var assert = require('assert');

var sp = new SerialPort("/dev/tty.usbserial", {
  baudrate: 19200
}, false); // this is the openImmediately flag [default is true]

var source = 'hello world!';

sp.open(function (error) {
  console.error('pipe open...');

  var pipe = concat(function (data) {
    console.log(data.toString());
    assert.equal(data.toString(), source);
  });

  sp.on('data', function (data) {
    pipe.write(data);
  })

  sp.write(source, function (err, results) {
    console.error('err:', err, 'bytes written:', results);

    setTimeout(function () {
      console.error('done.');
      // sp.end();
      sp.close();
      pipe.end();
    }, 1000);
  });
});
