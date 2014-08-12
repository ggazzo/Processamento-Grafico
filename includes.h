//
//  includes.h
//  Teste
//
//  Created by Guilherme Gazzo on 12/08/14.
//  Copyright (c) 2014 Guilherme Gazzo. All rights reserved.
//

#ifndef Teste_includes_h
#define Teste_includes_h

#ifdef __APPLE__
#include <GLUT/glut.h>          /* Open GL Util    APPLE */
#else

    #ifdef _WIN32
        #include <Windows.h>
    #endif

#include <GL/glut.h>            /* Open GL Util    OpenGL*/


#endif

#endif
