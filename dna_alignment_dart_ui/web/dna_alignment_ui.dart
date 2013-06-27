import 'dart:html';
import 'package:web_ui/web_ui.dart';

// initial value for click-counter
int startingCount = 5;
const SERVER_URL = 'ws://127.0.0.1:4711';


/**
 * Learn about the Web UI package by visiting
 * http://www.dartlang.org/articles/dart-web-components/.
 */
void main() {
  // Enable this to use Shadow DOM in the browser.
  //useShadowDom = true;
  connectToServer(SERVER_URL);

}

void connectToServer(url) {
  final ws = new WebSocket(url);

  ws.onOpen.listen((Event e) {
    ws.send("Test");
  });
  ws.onMessage.listen((MessageEvent e) { 
    print(e.data);
    ws.close();
    });
  ws.onError.listen((Event err) => print(err));
}