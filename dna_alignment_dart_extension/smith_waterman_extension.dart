library smith_waterman;

import 'dart_ext:smith_waterman_algorithm';

// The simplest way to call native code: top-level functions
int systemRand() native "SystemRand";
bool sysemSrand(int seed) native "SystemSrand";
