

/**<
        NIM : 672018178
        NAMA : PAULUS ANDRY LEKSONO
                                        */


#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
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
    gluPerspective(90.0, lebar/tinggi, 5.0, 500.0);
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




void atap (void)
{
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    int i, j=180;
    float r = 0.9, g = 0.9, b = 0.9;
	for(i=1; i<=j; i++){
        r += 0.001;
        g += 0.001;
        b += 0.001;
        glColor3f(r, g, b);
        glVertex3f(0 + 4.5999999999999991 * cos(1 * (3.14159265) * i / j), 16 + 2 * sin(1 * (3.14159265) * i / j), 70 );
        glVertex3f(0 + 4.5999999999999991 * cos(1 * (3.14159265) * i / j), 25.5 + 2 * sin(1 * (3.14159265) * i / j), 48 );
	}
	glEnd();
}

void atap_pjk_kiri(float x, float y, float z, float sudut1_cos, float sudut1_sin, float sudut2, float sudut3)
{
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    int i, j=180;
    float r = 0.9, g = 0.9, b = 0.9;
	for(i=1; i<=j; i++){
        r += 0.001;
        g += 0.001;
        b += 0.001;
        glColor3f(r, g, b);
        glVertex3f(x + 4.5999999999999991 * cos(sudut1_cos * (3.14159265) * i / j), 16 + 2 * sin(sudut1_sin * (3.14159265) * i / j), 70 );
        glVertex3f(x + 4.5999999999999991 * cos(sudut2 * (3.14159265) * i / j), y + 2 * sin(sudut2 * (3.14159265) * i / j), z );
        glVertex3f(x + 4.5999999999999991 * cos(sudut3 * (3.14159265) * i / j), 25.5 + 2 * sin(sudut3 * (3.14159265) * i / j), 48 );
	}
	glEnd();
}

void atap_pjk_kanan(float x, float y, float z, float sudut1, float sudut2, float sudut3_cos, float sudut3_sin)
{
    glPushMatrix();
	glRotatef(180,0,1,0);
	glTranslatef(5,0,-118);
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    int i, j=180;
    float r = 0.9, g = 0.9, b = 0.9;
	for(i=1; i<=j; i++){
        r += 0.001;
        g += 0.001;
        b += 0.001;
        glColor3f(r, g, b);
        glVertex3f(x + 4.9999999999999991 * cos(sudut1 * (3.14159265) * i / j), 16 + 2 * sin(sudut1 * (3.14159265) * i / j), 48 );
        glVertex3f(x + 4.9999999999999991 * cos(sudut2 * (3.14159265) * i / j), y + 2 * sin(sudut2 * (3.14159265) * i / j), z );
        glVertex3f(x + 4.9999999999999991 * cos(sudut3_cos * (3.14159265) * i / j), 25.5 + 2 * sin(sudut3_sin * (3.14159265) * i / j), 70 );
	}
	glEnd();
	glPopMatrix();
}

void under_ground (void)
{
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(70, -5, 90);
    glVertex3f(70, -5, -95);
    glVertex3f(-58, -5, -95);
    glVertex3f(-58, -5, 90);
    glEnd();
}

void ground (void)
{
    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);
    glVertex3f(58, 0, 75);
    glVertex3f(58, 0, -80);
    glVertex3f(-58, 0, -80);
    glVertex3f(-58, 0, 75);
    glEnd();
}

void lapangan (float kax, float kay, float kaz, float p, float l)
{
    glBegin(GL_QUADS);
    glColor3f(0.3, 0.7, 0.3);
    glVertex3f(kax, kay, kaz);
    glVertex3f(kax+p, kay, kaz);
    glVertex3f(kax+p, kay, kaz+(-l));
    glVertex3f(kax, kay, kaz+(-l));
    glEnd();

    //samping lapangan (merah)
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.2, 0.2);
    glVertex3f(-50, 0.1, -65);
    glVertex3f(-50, 0.1, 65);
    glVertex3f(kax, kay, 65);
    glVertex3f(kax, kay, -65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.2, 0.2);
    glVertex3f(50, 0.1, -65);
    glVertex3f(50, 0.1, 65);
    glVertex3f(kax+p, kay, 65);
    glVertex3f(kax+p, kay, -65);
    glEnd();

    //samping lapangan (hijau)
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.4, 0.1);
    glVertex3f(kax, kay, kaz);
    glVertex3f(kax+p, kay, kaz);
    glVertex3f(kax+p, kay, 65);
    glVertex3f(kax, kay, 65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.1, 0.4, 0.1);
    glVertex3f(kax, kay, kaz+(-l));
    glVertex3f(kax+p, kay, kaz+(-l));
    glVertex3f(kax+p, kay, -65);
    glVertex3f(kax, kay, -65);
    glEnd();

    //garis luar
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(kax+3, kay+0.1, kaz-3);
    glVertex3f(kax-3+p, kay+0.1, kaz-3);
    glVertex3f(kax-3+p, kay+0.1, kaz+(-l)+3);
    glVertex3f(kax+3, kay+0.1, kaz+(-l)+3);
    glEnd();

    //garis tengah
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex3f(kax+3, kay+0.1, 0);
    glVertex3f(kax-3+p, kay+0.1, 0);
    glEnd();

    //garis pinalti1 belakang
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(kax+15, kay+0.1, kaz+(-l)+3);
    glVertex3f(kax+15, kay+0.1, kaz+(-l)+17);
    glVertex3f(kax-15+p, kay+0.1, kaz+(-l)+17);
    glVertex3f(kax-15+p, kay+0.1, kaz+(-l)+3);
    glEnd();

    //garis pinalti2 belakang
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(kax+23, kay+0.1, kaz+(-l)+3);
    glVertex3f(kax+23, kay+0.1, kaz+(-l)+9);
    glVertex3f(kax-23+p, kay+0.1, kaz+(-l)+9);
    glVertex3f(kax-23+p, kay+0.1, kaz+(-l)+3);
    glEnd();

    //garis pinalti1 depan
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(kax+15, kay+0.1, kaz-3);
    glVertex3f(kax+15, kay+0.1, kaz-17);
    glVertex3f(kax-15+p, kay+0.1, kaz-17);
    glVertex3f(kax-15+p, kay+0.1, kaz-3);
    glEnd();

    //garis pinalti2 belakang
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(kax+23, kay+0.1, kaz-3);
    glVertex3f(kax+23, kay+0.1, kaz-9);
    glVertex3f(kax-23+p, kay+0.1, kaz-9);
    glVertex3f(kax-23+p, kay+0.1, kaz-3);
    glEnd();

    //lingkar tengah
    glBegin(GL_LINE_LOOP);
	int i, j=360;
	for(i=1; i<=j; i++){
        glColor3f(1,1,1);
        glVertex3f(0 + 10 * cos(2 * (3.14159265) * i / j), 0.2 ,0 + 10 * sin(2 * (3.14159265) * i / j));
	}
	glEnd();

    //lingkar belakang
    glBegin(GL_LINE_LOOP);
    i, j=180;
	for(i=1; i<=j; i++){
        glColor3f(1,1,1);
        glVertex3f(0 + 10 * cos(1 * (3.14159265) * i / j), 0.3 ,kaz+(-l)+17 + 5 * sin(1 * (3.14159265) * i / j));
	}
	glEnd();

	//lingkar belakang
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
    glBegin(GL_LINE_LOOP);
    i, j=180;
	for(i=1; i<=j; i++){
        glColor3f(1,1,1);
        glVertex3f(0 + 10 * cos(1 * (3.14159265) * i / j), 0.3 ,kaz+(-l)+17 + 5 * sin(1 * (3.14159265) * i / j));
	}
	glEnd();
	glPopMatrix();

	//tiang gawang depan
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	glColor3f(1,1,1);
	glVertex3f(kax+26, kay+0.1, kaz+(-l)+3);
	glVertex3f(kax+26, kay+3, kaz+(-l)+3);
	glVertex3f(kax-26+p, kay+3, kaz+(-l)+3);
	glVertex3f(kax-26+p, kay+0.1, kaz+(-l)+3);
	glEnd();

	//tiang gawang depan
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);
	glColor3f(1,1,1);
	glVertex3f(kax+26, kay+0.1, kaz+(-l)+3);
	glVertex3f(kax+26, kay+3, kaz+(-l)+3);
	glVertex3f(kax-26+p, kay+3, kaz+(-l)+3);
	glVertex3f(kax-26+p, kay+0.1, kaz+(-l)+3);
	glEnd();

	//tiang gawang depan
	glPushMatrix();
	glLineWidth(1);
	glRotatef(180, 0, 1, 0);
	glBegin(GL_LINE_STRIP);
	glColor3f(1,1,1);
	glVertex3f(kax+26, kay+0.1, kaz+(-l)+3);
	glVertex3f(kax+26, kay+3, kaz+(-l)+3);
	glVertex3f(kax-26+p, kay+3, kaz+(-l)+3);
	glVertex3f(kax-26+p, kay+0.1, kaz+(-l)+3);
	glEnd();
	glPopMatrix();


}

void tiangv (void)
{
    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex3f(-1, 15, 65);
    glVertex3f(0, 0, 65);
    glVertex3f(1, 15, 65);
    glEnd();
}

void tiangav(float tsx, float tfx, float tsz, float tfz)
{
    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex3f(tsx, 15, tsz);
    glVertex3f(tfx, 15, tfz);
    glEnd();
}

void tiangat(void)
{
    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.94,0.94,0.94);
    glVertex3f(0, 16, 70);
    glColor3f(1,1,1);
    glVertex3f(0, 25.5, 48);
    glEnd();
}

void tiangatp(float p)
{
    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glColor3f(1,1,1);
    glVertex3f(0, 16, 70);
    glVertex3f(0, 22.5, p);
    glEnd();
}

void tiang_pt(float p)
{
    glLineWidth(6);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.97,0.97,0.97);
    glVertex3f(-1.5, 9, p);
    glVertex3f(-1.5, 15, 65);
    glVertex3f(0, 16, 69.5);
    glVertex3f(1.5, 15, 65);
    glVertex3f(1.5, 9, p);
    glEnd();
}

void tribun_ats(float tsx, float tfx, float tsz, float tfz)
{
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(tsx, 16.8, tsz);
    glVertex3f(tsx, 10.8, tfz);
    glVertex3f(tfx, 10.8, tfz);
    glVertex3f(tfx, 16.8, tsz);
    glEnd();

}

void tribun_atss(float tsx, float tfx, float tsz, float tfz)
{
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(tsx, 16.8, tsz);
    glVertex3f(tsx, 16.8, tfz);
    glVertex3f(tfx, 10.8, tfz);
    glVertex3f(tfx, 10.8, tsz);
    glEnd();

}
//    tribun_ats(50, 42, -56.533, 54.533);

void tribun_bwh(void)
{

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-33,0.2,50);
    glVertex3f(33,0.2,50);
    glVertex3f(43,0.2,60);
    glVertex3f(-43,0.2,60);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(43,0.2,60);
    glVertex3f(-43,0.2,60);
    glVertex3f(-43,7,60);
    glVertex3f(43,7,60);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glVertex3f(-33,0.2,-50);
    glVertex3f(33,0.2,-50);
    glVertex3f(43,0.2,-60);
    glVertex3f(-43,0.2,-60);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(43,0.2,-60);
    glVertex3f(-43,0.2,-60);
    glVertex3f(-43,7,-60);
    glVertex3f(43,7,-60);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glVertex3f(35,0.2,48);
    glVertex3f(35,0.2,-48);
    glVertex3f(45,0.2,-58);
    glVertex3f(45,0.2,58);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(45,0.2,-58);
    glVertex3f(45,0.2,58);
    glVertex3f(45,7,58);
    glVertex3f(45,7,-58);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glVertex3f(-35,0.2,48);
    glVertex3f(-35,0.2,-48);
    glVertex3f(-45,0.2,-58);
    glVertex3f(-45,0.2,58);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-45,0.2,-58);
    glVertex3f(-45,0.2,58);
    glVertex3f(-45,7,58);
    glVertex3f(-45,7,-58);
    glEnd();
}

void tribun_pntp(float tsx, float tfx, float tsz, float tfz)
{
    glBegin(GL_QUADS);
    glColor3f(0.9,0.9,0.9);
    glVertex3f(tsx, 15.5, tsz);
    glVertex3f(tfx, 15.5, tfz);
    glVertex3f(tfx, 18, tfz);
    glVertex3f(tsx, 18, tsz);
    glEnd();
}

void tribun_pntpb(float tsx, float tfx, float tsz, float tfz)
{
    glBegin(GL_QUADS);
    glColor3f(0.9,0.9,0.9);
    glVertex3f(tsx, 8, tsz);
    glVertex3f(tfx, 8, tfz);
    glVertex3f(tfx, 12, tfz);
    glVertex3f(tsx, 12, tsz);
    glEnd();
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


    under_ground();
    ground();
    lapangan(-30, 0.1, 45, 60, 90);
    atap();

    //tribun_ats();
    tribun_bwh();



    //depan
    glPushMatrix();
    int tz = -41.667;
    glTranslatef(tz, 0, 0);
    tiangv();
    tiang_pt(56);
    tiangatp(55);
    for(int i = 1; i<10; i++){
        int tzz = 9.533333333333333;
        glTranslatef(tzz, 0, 0);
        tiangv();
        if(i<9)tiangat();
        else tiangatp(53);
        tiang_pt(54);

    }
    glPopMatrix();
    tiangav(-42.667, 41.667, 65, 65);
    tribun_pntp(-41.667, 41.667, 65, 65);
    tribun_pntpb(-41.667, 41.667, 54, 54);
    tribun_ats(-41.667, 42.667, 65, 54);

    glPushMatrix();
    glTranslatef(-36.5,0,0);
    for(int i = 1; i<9; i++){
        int tzz = 9.533333333333333;
        glTranslatef(tzz, 0, 0);
        if(i<8)atap();
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-37,0,0);
    atap_pjk_kiri(0, 20, 55, 1, 1, 0.75, 0.2);
    glPopMatrix();
    glPushMatrix();
    tz = -41.667;
    glTranslatef(tz, 0, 0);
    for(int i = 1; i<=9; i++){
        int tzz = 9.533333333333333;
        glTranslatef(tzz, 0, 0);
        if(i>8)atap_pjk_kanan(0, 20, 66, 1, 1, 0.45, 1);
    }
    glPopMatrix();




    //belakang
    glPushMatrix();
    glRotatef(180,0,1,0);
    tz = -41.667;
    glTranslatef(tz, 0, 0);
    tiangv();
    tiangatp(55);
    tiang_pt(56);
    for(int i = 1; i<10; i++){
        int tzz = 9.533333333333333;
        glTranslatef(tzz, 0, 0);
        tiangv();
        if(i<9)tiangat();
        else tiangatp(53);
        tiang_pt(54);
    }
    glPopMatrix();
    tiangav(-42.667, 41.667, -65, -65);
    tribun_pntp(-42.667, 41.667, -65, -65);
    tribun_pntpb(-42.667, 41.667, -54, -54);
    tribun_ats(-42.667, 41.667, -65, -54);

    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(-36.5,0,0);
    for(int i = 1; i<8; i++){
        int tzz = 9.533333333333333;
        glTranslatef(tzz, 0, 0);
        if(i<8)atap();
    }
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,1,0);
    glTranslatef(-37,0,0);
    atap_pjk_kiri(0, 20, 53.5, 1, 1, 0.75, 0.3);
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,1,0);
    tz = -41.667;
    glTranslatef(tz, 0, 0);
    for(int i = 1; i<=9; i++){
        int tzz = 9.533333333333333;
        glTranslatef(tzz, 0, 0);
        if(i>8)atap_pjk_kanan(0, 20, 65.5, 1, 1, 0.45, 1);
    }
    glPopMatrix();



    //kanan
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    tz = -53.533;
    glTranslatef(tz, 0, -15);
    tiangv();
    tiangatp(55);
    tiang_pt(56);
    for(int i = 1; i<13; i++){
        int tzz = 9.9999999999999991;
        glTranslatef(tzz, 0, 0);
        tiangv();
        if(i<12)tiangat();
        else tiangatp(56);
        tiang_pt(57);
    }
    glPopMatrix();
    tiangav(50, 50, -56.533, 54.533);
    tribun_pntp(50, 50, -56.533, 54.533);
    tribun_pntpb(42, 42, -56.533, 54.533);
    tribun_atss(50, 42, -56.533, 54.533);

    glPushMatrix();
    glRotatef(90, 0,1,0);
    glTranslatef(-48.5,0,-15);
    for(int i = 1; i<11; i++){
        int tzz = 9.533333333333333;
        glTranslatef(tzz, 0, 0);
        if(i<11)atap();
    }
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    tz = -49.533;
    glTranslatef(tz,0,-15);
    atap_pjk_kiri(0, 20, 55, 1, 1, 0.75, 0.4);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    tz = -53.533;
    glTranslatef(tz, 0, -15);
    for(int i = 1; i<=12; i++){
        int tzz = 9.533333333333333;
        glTranslatef(tzz, 0, 0);
        if(i>11)atap_pjk_kanan(0, 20, 61, 1, 1, 0.3, 1);
    }
    glPopMatrix();



    //kiri
    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    tz = -53.533;
    glTranslatef(tz, 0, -15);
    tiangv();
    tiangatp(55);
    tiang_pt(56);
    for(int i = 1; i<13; i++){
        int tzz = 9.9999999999999991;
        glTranslatef(tzz, 0, 0);
        tiangv();
        if(i<12)tiangat();
        else tiangatp(55);
        tiang_pt(56);
    }
    glPopMatrix();
    tiangav(-50, -50, -56.533, 54.533);
    tribun_pntp(-50, -50, -56.533, 54.533);
    tribun_pntpb(-41, -41, -56.533, 54.533);
    tribun_atss(-50, -41, -56.533, 54.533);

    glPushMatrix();
    glRotatef(-90, 0,1,0);
    glTranslatef(-48.5,0,-15);
    for(int i = 1; i<11; i++){
        int tzz = 9.533333333333333;
        glTranslatef(tzz, 0, 0);
        if(i<11)atap();
    }
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    tz = -49.533;
    glTranslatef(tz,0,-15);
    atap_pjk_kiri(0, 20, 55, 1, 1, 0.75, 0.4);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    tz = -53.533;
    glTranslatef(tz, 0, -15);
    for(int i = 1; i<=12; i++){
        int tzz = 9.533333333333333;
        glTranslatef(tzz, 0, 0);
        if(i>11)atap_pjk_kanan(0, 20, 62, 1, 1, 0.35, 1);
    }
    glPopMatrix();



    glFlush();
    glutSwapBuffers();

}
