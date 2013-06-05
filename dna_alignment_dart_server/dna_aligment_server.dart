library dna_aligment_server;

import 'smith_waterman_extension/smith_waterman.dart';

void main() {
  SmithWaterman sw = new SmithWaterman();
  sw.sayHello('Peter').then((e) => print(e));
  // sw.sayHello('Peter').then((List e) => e.forEach((i) => print(i)));
}