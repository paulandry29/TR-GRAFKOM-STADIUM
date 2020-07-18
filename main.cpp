

/**<
        NIM : 672018178
        NAMA : PAULUS ANDRY LEKSONO
                                        */


#include <windows.h>
#include <GL/glut.h>

void init(void);
void tampil(void);
void keyboard(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mousemotion(int x, int y);


float   xrot = 0.0f, yrot = 0.0f,
        xdiff = 0.0f, ydiff = 0.0f,
        keyy = 0.0, keyx = 0.0, keyz = 0.0;

bool mousedown = false;

int is_depth;


int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("PAULUS ANDRY LEKSONO - 672018178");

    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    //glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
    glutSpecialFunc(keyboard);

    glutIdleFunc(tampil);
    init();

    glutMainLoop();
    return 0;
}

void idle()
{
    if(!mousedown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void keyboard(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_F5 :
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else{
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
        break;

    case GLUT_KEY_DOWN :
        keyy -= 3.0;
        break;

    case GLUT_KEY_UP :
        keyy += 3.0;
        break;

    case GLUT_KEY_LEFT :
        keyx -= 3.0;
        break;

    case GLUT_KEY_RIGHT :
        keyx += 3.0;
        break;

    case GLUT_KEY_HOME :
        keyz += 3.0;
        break;

    case GLUT_KEY_END :
        keyz -= 3.0;
        break;
    }

    tampil();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    {
        mousedown = false;
    }


}

void mousemotion(int x, int y)
{
    if(mousedown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if(tinggi ==0 ) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar/tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
    glClearColor(0.4, 0.6, 0.6, 1.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth =1;
    glMatrixMode(GL_MODELVIEW);
}



void tampil(void)
{
    if(is_depth){

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    else{
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glLoadIdentity();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glTranslatef(keyx, keyy, keyz);





    glFlush();
    glutSwapBuffers();

}
