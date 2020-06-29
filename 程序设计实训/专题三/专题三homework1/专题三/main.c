#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

void RenderScene()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xAAAA);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.25,0.75,0);
    glVertex3f(0.65,0.75,0);
    glVertex3f(0.25,0.65,0);
    glVertex3f(0.65,0.65,0);
    glVertex3f(0.25,0.55,0);
    glVertex3f(0.65,0.55,0);
    glVertex3f(0.25,0.75,0);
    glVertex3f(0.25,0.55,0);
    glVertex3f(0.35,0.75,0);
    glVertex3f(0.35,0.55,0);
    glVertex3f(0.45,0.75,0);
    glVertex3f(0.45,0.55,0);
    glVertex3f(0.55,0.75,0);
    glVertex3f(0.55,0.55,0);
    glVertex3f(0.65,0.75,0);
    glVertex3f(0.65,0.55,0);
    glVertex3f(0.25,0.75,0);
    glVertex3f(0.30,0.85,0);
    glVertex3f(0.35,0.75,0);
    glVertex3f(0.30,0.85,0);
    glVertex3f(0.60,0.85,0);
    glVertex3f(0.65,0.75,0);
    glVertex3f(0.60,0.85,0);
    glVertex3f(0.55,0.75,0);
    glVertex3f(0.35,0.75,0);glVertex3f(0.35,0.77,0);
    glVertex3f(0.35,0.77,0);glVertex3f(0.37,0.77,0);
    glVertex3f(0.37,0.77,0);glVertex3f(0.37,0.75,0);
    glVertex3f(0.38,0.75,0);glVertex3f(0.38,0.77,0);
    glVertex3f(0.38,0.77,0);glVertex3f(0.40,0.77,0);
    glVertex3f(0.40,0.77,0);glVertex3f(0.40,0.75,0);
    glVertex3f(0.41,0.75,0);glVertex3f(0.41,0.77,0);
    glVertex3f(0.41,0.77,0);glVertex3f(0.43,0.77,0);
    glVertex3f(0.43,0.77,0);glVertex3f(0.43,0.75,0);
    glVertex3f(0.45,0.75,0);glVertex3f(0.45,0.77,0);
    glVertex3f(0.45,0.77,0);glVertex3f(0.47,0.77,0);
    glVertex3f(0.47,0.77,0);glVertex3f(0.47,0.75,0);
    glVertex3f(0.48,0.75,0);glVertex3f(0.48,0.77,0);
    glVertex3f(0.48,0.77,0);glVertex3f(0.50,0.77,0);
    glVertex3f(0.50,0.77,0);glVertex3f(0.50,0.75,0);
    glVertex3f(0.51,0.75,0);glVertex3f(0.51,0.77,0);
    glVertex3f(0.51,0.77,0);glVertex3f(0.53,0.77,0);
    glVertex3f(0.53,0.77,0);glVertex3f(0.53,0.75,0);
    glEnd();
    
    glDisable(GL_LINE_STIPPLE);
    glFlush();
}

void SetupRC(void)
{
    glClearColor(1.0f,1.0f, 1.0f,1.0f);
}

int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE |GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize (1000,1000);
    glutInitWindowPosition (0,0);
    glutCreateWindow (argv[0]);
    glutDisplayFunc(RenderScene);
    
    SetupRC();
    glutMainLoop();
    
    return 0;
}
