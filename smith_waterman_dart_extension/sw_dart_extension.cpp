//
//  sw_dart_extension.cpp
//  smith_waterman_dart_extension
//
//  Created by Laurence Bortfeld on 30.05.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#include "sw_dart_extension.h"

// Forward declaration of ResolveName function.
Dart_NativeFunction ResolveName(Dart_Handle name, int argc);

// The name of the initialization function is the extension name followed
// by _Init.
DART_EXPORT Dart_Handle smith_waterman_dart_extension_Init(Dart_Handle parent_library) {
    if (Dart_IsError(parent_library)) return parent_library;
    
    Dart_Handle result_code =
    Dart_SetNativeResolver(parent_library, ResolveName);
    if (Dart_IsError(result_code)) return result_code;
    
    return Dart_Null();
}

Dart_Handle HandleError(Dart_Handle handle) {
    if (Dart_IsError(handle)) Dart_PropagateError(handle);
    return handle;
}


char* helloDart(char *name) {
    return name;
}

void helloDartWrapper(Dart_Port destPortId, Dart_Port replyPortId, Dart_CObject *message) {
    if (message->type == Dart_CObject::kArray &&
        1 == message->value.as_array.length) {
        
        Dart_CObject *param = message->value.as_array.values[0];

        char *name = helloDart(param->value.as_string);
        
        if (name != NULL) {
            Dart_CObject result;
            result.value.as_string = name;
            Dart_PostCObject(replyPortId, &result);
            return;
        }
    }
}

void helloDartServeicePort(Dart_NativeArguments arguments) {
    Dart_EnterScope();
    
    Dart_SetReturnValue(arguments, Dart_Null());
    Dart_Port servicePort = Dart_NewNativePort("helloDartService", helloDartWrapper, true);
    
    if (servicePort != ILLEGAL_PORT) {
        Dart_Handle sendPort = HandleError(Dart_NewSendPort(servicePort));
        Dart_SetReturnValue(arguments, sendPort);
    }
    Dart_ExitScope();
}



FunctionLookup function_list[] = {
    {"helloDart_ServicePort", helloDartServeicePort},
    {NULL, NULL}};


Dart_NativeFunction ResolveName(Dart_Handle name, int argc) {
    if (!Dart_IsString(name)) return NULL;
    Dart_NativeFunction result = NULL;
    Dart_EnterScope();
    const char* cname;
    HandleError(Dart_StringToCString(name, &cname));
    
    for (int i=0; function_list[i].name != NULL; ++i) {
        if (strcmp(function_list[i].name, cname) == 0) {
            result = function_list[i].function;
            break;
        }
    }
    Dart_ExitScope();
    return result;
}
