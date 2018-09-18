//
//  main.cpp
//  Multi-Color Triangle
//
//  Created by Kaitlyn Walsh on 9/18/18.
//  Copyright © 2018 Kaitlyn Walsh. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
using namespace std;


//VERTEX SHADER
static const char* pVS = "                                                    \n\
#version 330                                                                  \n\
\n\
in vec3 vPosition;                                                              \n\
in vec4 vColor;                                                                  \n\
out vec4 color;                                                                 \n\
\n\
\n\
void main()                                                                     \n\
{                                                                                \n\
gl_Position = vec4(vPosition.x, vPosition.y, vPosition.z, 1.0);  \n\
color = vColor;                            \n\
}";

// Fragment Shader
// Note: no input in this shader, it just outputs the colour of all fragments, in this case set to red (format: R, G, B, A).
static const char* pFS = "                                              \n\
#version 330                                                            \n\
\n\
out vec4 FragColor;                                                      \n\
\n\
void main()                                                               \n\
{                                                                          \n\
FragColor = vec4(1.0, 0.0, 0.0, 1.0);                                     \n\
}";

#pragma region SHADER_FUNCTION
static void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
{
    //create Shader object
    GLuint ShaderObj = glCreateShader(ShaderType);
}


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    glShadeModel(GL_FLAT);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glLoadIdentity();
    
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    
    
    glScalef(1.0, 1.0, 1.0);
    glEnableVertexAttribArray(0);
    
    glShadeModel(GL_SMOOTH);
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f,-1.0f, 0.0f);
    
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(1.0f,-1.0f, 0.0f);
    
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0, 1.0, 0.0);
    glEnd();
    
    static const GLfloat g_vert_buffer_data[] = { -1.0, -1.0, 0.0, 1.0, -1.0, 0.0, 0.0, 1.0, 0.0};
    
    
    GLuint vertexBuffer;
    glGenBuffers(3, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GL_ARB_vertex_buffer_object), g_vert_buffer_data, GL_STATIC_DRAW);
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello Triangle");
    
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
    terminate();
    
    return 0;
}
