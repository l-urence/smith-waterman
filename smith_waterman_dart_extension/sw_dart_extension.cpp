// Copyright (c) 2012, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#include "sw_dart_extension.h"

Dart_NativeFunction ResolveName(Dart_Handle name, int argc);

DART_EXPORT Dart_Handle smith_waterman_dart_extension_Init(Dart_Handle parent_library) {
    if (Dart_IsError(parent_library)) { return parent_library; }
    
    Dart_Handle result_code = Dart_SetNativeResolver(parent_library, ResolveName);
    if (Dart_IsError(result_code)) return result_code;
    
    return Dart_Null();
}

Dart_Handle HandleError(Dart_Handle handle) {
    if (Dart_IsError(handle)) Dart_PropagateError(handle);
    return handle;
}

void echoNumber(Dart_Port desPort, Dart_Port replayPort, Dart_CObject *message) {
    Dart_CObject result;
    result.type = Dart_CObject::kInt32;
    
    if (message->type == Dart_CObject::kArray &&
        1 == message->value.as_array.length) {
        // result.value.as_int32 = message->value.as_array.values[0]->value.as_int32;;
        result.value.as_int32 = devices();
    } else {
        result.value.as_int32 = -1;
    }

    Dart_PostCObject(replayPort, &result);
}

void echoNumberServicePort(Dart_NativeArguments arguments) {
    Dart_EnterScope();
    Dart_SetReturnValue(arguments, Dart_Null());
    Dart_Port service_port =
    Dart_NewNativePort("EchoNumberService", echoNumber, true);
    if (service_port != ILLEGAL_PORT) {
        Dart_Handle send_port = HandleError(Dart_NewSendPort(service_port));
        Dart_SetReturnValue(arguments, send_port);
    }
    Dart_ExitScope();
}

FunctionLookup function_list[] = {
    {"echoNumber_ServicePort", echoNumberServicePort},
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
