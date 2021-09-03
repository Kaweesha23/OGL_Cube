// OGL_Cube.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <glut.h>
int c = 0;
GLfloat T = 0;
void Spin()
{
    T = T + 0.05;
    if (T > 360)
        T = 0;
    glutPostRedisplay();
}

void MyInit()
{
    glClearColor(0, 0, 0, 0);
    glColor3f(0, 0, 1);
    //glShadeModel(GL_SMOOTH);
}

void Face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[])
{

    glBegin(GL_POLYGON);

    glShadeModel(GL_SMOOTH);
    glColor3f(0, 1, 0);
    glVertex3fv(A);

    //glColor3f(1, 0, 0);
    glColor3f(0, 0, c / 255.0);
    glVertex3fv(B);

    //glColor3f(0, 0, 1);
    glColor3f(c / 255.0, 0, 0);
    glVertex3fv(C);

    //glColor3f(1, 0, 1);
    glColor3f(c / 255.0, 0, c / 255.0);
    glVertex3fv(D);

    glEnd();
}

void Cube(GLfloat V0[], GLfloat V1[], GLfloat V2[], GLfloat V3[], GLfloat V4[], GLfloat V5[], GLfloat V6[], GLfloat V7[])
{

    //glColor3f(1, 0, 0);
    Face(V0, V1, V2, V3); //Front

    //glColor3f(0, 1, 0);
    Face(V4, V5, V6, V7); //Back

    //glColor3f(0, 0, 1);
    Face(V0, V3, V7, V4);  //Left

    //glColor3f(1, 0, 1);
    Face(V1, V2, V6, V5);  //Right

    //glColor3f(1, 1, 0);
    Face(V0, V1, V5, V4);  //Top

    glColor3f(1, 0, 0);
    Face(V3, V2, V6, V7);  //Bottom

}
void mydisplay()
{
    GLfloat V[8][3] =
    {
        {-0.5, 0.5, 0.5},
        { 0.5, 0.5, 0.5},
        { 0.5,-0.5, 0.5},
        {-0.5,-0.5, 0.5},

        {-0.5, 0.5,-0.5},
        { 0.5, 0.5,-0.5},
        { 0.5,-0.5,-0.5},
        {-0.5,-0.5,-0.5},
    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(T, 1, 1, 1);

    Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);

    glutSwapBuffers();
}

int main()
{
    char* str = new char[0];
    int arg = 0;
    glutInit(&arg, &str);
    glutInitWindowPosition(250, 50);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("OpenGl Programe");
    MyInit();
    glutDisplayFunc(mydisplay);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
