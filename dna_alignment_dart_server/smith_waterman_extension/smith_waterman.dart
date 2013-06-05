library smith_waterman;


import 'dart:async';
import 'dart:isolate';
import 'dart-ext:smith_waterman_dart_extension';

class SmithWaterman {
  static SendPort _port;

  Future<List> sayHello(String name) {
    final args = new List(1);
    args[0] = 1000;
    // args[1] = 100;
  final port = _port;
  return _servicePort.call(args).then((result) {
      if (result != null) {
        return result;
      } else {
        throw new Exception('Hello Dart creation faild');
      }
    });
  }

  SendPort get _servicePort {
    if (_port == null) {
      _port = _newServicePort();
    }
    return _port;
  }

  SendPort _newServicePort() native "echoNumber_ServicePort";
}