//
//  sw_dart_extension.h
//  smith_waterman_dart_extension
//
//  Created by Laurence Bortfeld on 30.05.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#ifndef __smith_waterman_dart_extension__sw_dart_extension__
#define __smith_waterman_dart_extension__sw_dart_extension__

#include "swsingle.h"
#include "stdlib.h"
#include "stdio.h"
#include "dart_api.h"


struct FunctionLookup {
    const char* name;
    Dart_NativeFunction function;
};

#endif /* defined(__smith_waterman_dart_extension__sw_dart_extension__) */
