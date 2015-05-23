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
    console.log(data.toString());
    assert.equal(data.toString(), source);
  });

  sp.on('data', function (data) {
    pipe.write(data);
  })

  setTimeout(function () {
    sp.write('!', function (err, results) {
      console.error('err?', err, 'bytes written:', results);

      setTimeout(function () {
        console.error('done.');
        // sp.end();
        sp.close();
        pipe.end();
      }, 1000);
    });
  }, 3000);
});
