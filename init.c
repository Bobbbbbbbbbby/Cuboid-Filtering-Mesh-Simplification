#include "input/input.h"
#include "simplify/simplify.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>

void initScene(double ratio)
{
    readObj(ratio);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, 1, -1, 1);
    //glOrtho(-1000, 1000, -1000, 1000, -1000, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 0, 0, 0, 0, 0, 0, 0);
    glClearColor(0.000f, 0.000f, 0.000f, 1.0f);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    // glEnable(GL_CULL_FACE);
    // glEnable(GL_POLYGON_OFFSET_FILL);
    // glPolygonOffset (-1, 1);
    // glDisable(GL_POLYGON_OFFSET_FILL);
    // glEnable(GL_BLEND);

    static GLfloat glfMatAmbient[] = {0.135f, 0.2225f, 0.1575f, 0.95f};
    static GLfloat glfMatDiffuse[] = {0.54f, 0.89f, 0.63f, 0.95f};
    static GLfloat glfMatSpecular[] = {0.316228f, 0.316228f, 0.316228f, 0.95f};
    static GLfloat glfMatEmission[] = {0.000f, 0.000f, 0.000f, 1.0f};
    static GLfloat fShininess = 12.800f;

    glMaterialfv(GL_FRONT, GL_AMBIENT, glfMatAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, glfMatDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, glfMatSpecular);
    glMaterialfv(GL_FRONT, GL_EMISSION, glfMatEmission);
    glMaterialf(GL_FRONT, GL_SHININESS, fShininess);
}