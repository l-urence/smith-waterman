//
//  opencl_devices.h
//  smith_waterman_dart_extension
//
//  Created by Laurence Bortfeld on 06.06.13.
//  Copyright (c) 2013 Hochschule fuer Technik und Wirtschaft. All rights reserved.
//

#ifndef __smith_waterman_dart_extension__opencl_devices__
#define __smith_waterman_dart_extension__opencl_devices__

#include <stdio.h>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

int devices();

#endif /* defined(__smith_waterman_dart_extension__opencl_devices__) */
