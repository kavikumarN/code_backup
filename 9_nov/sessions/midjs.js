const zmq       = require('zeromq')
  ,  requester =zmq.requester;

requester.connect('tcp://127.0.0.1:5555');
var replyNbr = 0;
requester.on('message', function(msg) {
  console.log('got reply', replyNbr, msg.toString());
  replyNbr += 1;

  if( replyNbr < 10 ){
    setTimeout(function(){
      console.log('sending '+replyNbr);
      requester.send("Hello "+replyNbr);
    }, 1000);
  } else {
    process.exit(0);
  }
});

console.log('sending first message');
requester.send("Hello");