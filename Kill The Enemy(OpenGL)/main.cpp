#include <iostream>
#include<fstream>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include<GL/gl.h>
#include <GL/glut.h>
#define PI 3.1415927
using namespace std;

//-----------variables-------------
char title[] = "Full-Screen & Windowed Mode";
int windowWidth  = 1080;     // Windowed mode's width
int windowHeight = 650;     // Windowed mode's height
int windowPosX   = 150;      // Windowed mode's top-left corner x
int windowPosY   = 50;
bool fullScreenMode = true; // Full-screen or windowed mode?
bool paused = false;
//------------------------------------
float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
static int press = 0 ;
static int GameOver=0;
static int Left = 0;
static float xAxis=0;
static float rotateZ=0;
static float rotateBall=0;
static float LoadTheBomb = 0;
static int cnt = 0;
static float bomb1 = 0;
static float bomb2 = 0;
static float bomb3 = 0;
static float TranslateBomb1 = 0.0f;
static float b1RotateBall = 0.0f;
static float b1TranslateX = 0.0f;
static float TranslateBomb2 = 0.0f;
static float b2RotateBall = 0.0f;
static float b2TranslateX = 0.0f;
static float TranslateBomb3 = 0.0f;
static float b3RotateBall = 0.0f;
static float b3TranslateX = 0.0f;
static float bomb1Stop=0.0f;
static float bomb2Stop=0.0f;
static float bomb3Stop=0.0f;
static int LoadBomb1=1;
static int LoadBomb2=0;
static int LoadBomb3=0;
static float enemyTranslate=0.0f;
static float enemyTranslateSpeed=0.1f;
static float enemyBombTranslateSpeed=0.06f;
static int enemyTranslateTimer=75;
static float enemyHeart = 1.1f;
static float EnemyBomb1Translate=7.0f;
static float EnemyBomb2Translate=9.0f;
static float EnemyBomb3Translate=6.0f;
static float EnemyBomb4Translate=10.0f;
static float EnemyBomb5Translate=8.0f;
static float EnemyBomb6Translate=7.0f;
static float EnemyBomb7Translate=8.0f;
static float EnemyBomb8Translate=9.0f;
static float EnemyBomb9Translate=6.0f;
static float EnemybombTranslateX =0.0f;
static float EnemybombTranslate =2.15f;
static int enemyBomb=1;
static int enemyAttack1=0;
static int enemyAttack2=0;
static int enemyLife=5,playerLife=3;
static float R =1,G =.75,B =0;
static float BRed =0.0,BGreen =0.50,BBlue =0;
static int collision = 0;
static float bullets = 15.0, totalScore = 0.00,highestScore=0.0;
static float ScoreAngle = 0.0;
static float blastX=0.0,blastY=0.0,bombBlast=0;
static float blast1X=0.0,blast1Y=0.0,bomb1Blast=0;
static float blast2X=0.0,blast2Y=0.0,bomb2Blast=0;
static float blast3X=0.0,blast3Y=0.0,bomb3Blast=0;
static float blast4X=0.0,blast4Y=0.0,bomb4Blast=0;
static float blast5X=0.0,blast5Y=0.0,bomb5Blast=0;
static float blast6X=0.0,blast6Y=0.0,bomb6Blast=0;
static float blast7X=0.0,blast7Y=0.0,bomb7Blast=0;
static float blast8X=0.0,blast8Y=0.0,bomb8Blast=0;
static float blast9X=0.0,blast9Y=0.0,bomb9Blast=0;
static float blast0X=0.0,blast0Y=0.0,bomb0Blast=0;
static float KR=0.5,KG=0.0,KB=0.20;
static float IG=0.6,IR=0.0,IB=0.10;
static float L1R=0.4,L1G=0.0,L1B=0.0,L2R=0.2,L2G=0.8,L2B=0.0;
static float TR=0.5,TG=0.6,TB=0.0,HR=0.10,HG=0.4,HB=0.50,ER=0.50,EG=0.2,EB=0.8;
static float E1R=0.4,E1G=0.5,E1B=0.2,NR=0.0,NG=0.50,NB=0.4,E2R=0.2,E2G=0.30,E2B=0.2,MR=0.5,MG=0.4,MB=0.2,YR=0.5,YG=0.2,YB=0.4;

void draw_cylinder(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;
    glColor3ub(R-40,G-40,B-40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while( angle < 2*PI ) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y , height);
        glVertex3f(x, y , 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*PI ) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y , height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}
void blast(void){

//-------------top spark--------------
     glTranslatef(blastX,blastY,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}
void blast1(void){
//-------------top spark--------------
     glTranslatef(blast1X,blast1Y,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}
void blast2(void){
//-------------top spark--------------
     glTranslatef(blast2X,blast2Y,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}
void blast3(void){
//-------------top spark--------------
     glTranslatef(blast3X,blast3Y,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}
void blast4(void){
//-------------top spark--------------
     glTranslatef(blast4X,blast4Y,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}
void blast5(void){
//-------------top spark--------------
     glTranslatef(blast5X,blast5Y,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}
void blast6(void){
//-------------top spark--------------
     glTranslatef(blast6X,blast6Y,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}
void blast7(void){
//-------------top spark--------------
     glTranslatef(blast7X,blast7Y,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}
void blast8(void){
//-------------top spark--------------
     glTranslatef(blast8X,blast8Y,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}
void blast9(void){
//-------------top spark--------------
     glTranslatef(blast9X,blast9Y,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    //glTranslatef(0.11,0.56,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}
void blast0(void){
//-------------top spark--------------
     glTranslatef(blast0X,blast0Y,0.0);
     glScalef(0.90,0.90,0.90);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.04,0.66, 0.0);
	glVertex3f(0.0, 1.05, 0.0);
	glVertex3f(0.04,0.66, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom spark--------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.045,0.16, 0.0);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.045,0.16, 0.0);
	glEnd();
    glPopMatrix();
//-------------right spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(0.25,0.45, 0.0);
	glVertex3f(0.65, 0.40, 0.0);
	glVertex3f(0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------left spark------------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(3.0,0.78,.1);
	glVertex3f(-0.25,0.45, 0.0);
	glVertex3f(-0.65, 0.40, 0.0);
	glVertex3f(-0.25,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------top left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.07,0.56, 0.0);
	glVertex3f(-0.4, 0.9, 0.0);
	glVertex3f(-0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.07,0.56, 0.0);
	glVertex3f(0.9, 1.3, 0.0);
	glVertex3f(0.18,0.55, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent down--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.20,0.56, 0.0);
	glVertex3f(0.65, 0.75, 0.0);
	glVertex3f(0.21,0.48, 0.0);
	glEnd();
    glPopMatrix();
//--------------top right adjacent up--------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.05,0.66, 0.0);
	glVertex3f(0.25, 1.2, 0.0);
	glVertex3f(0.1,0.58, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom right spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(0.12,0.35, 0.0);
	glVertex3f(0.4, -0.10, 0.0);
	glVertex3f(0.01,0.3, 0.0);
	glEnd();
    glPopMatrix();
    //-------------bottom left spark---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.12,0.40, 0.0);
	glVertex3f(-1.0, -0.30, 0.0);
	glVertex3f(-0.01,0.35, 0.0);
	glEnd();
    glPopMatrix();
//-------------bottom left adjacent spark down---------
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.2,0.0);
	glVertex3f(-0.18,0.17, 0.0);
	glVertex3f(-0.5, -0.40, 0.0);
	glVertex3f(-0.01,0.25, 0.0);
	glEnd();
    glPopMatrix();
//-------------top right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------top left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.56,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom right outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------bottom left outer---------
    glPushMatrix();
    glColor3f(3.0,0.78,.1);
    glTranslatef(-0.11,0.255,0);
    glutSolidSphere(0.1,20,20);
    glPopMatrix();
//-------------right inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------left inner---------
    glPushMatrix();
    glColor3f(1.0,.50,.17);
    glTranslatef(-0.18,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------bottom inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.21,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------top inner---------
    glPushMatrix();
    glColor3f(0.9,0.3,.1);
    glTranslatef(0.0,0.59,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
//-------------inner------------
    glPushMatrix();
    glColor3f(0.9,.40,.17);
    glTranslatef(0.0,0.4,0);
    glutSolidSphere(0.15,20,20);
    glPopMatrix();
}

void BackGround(void)
{
	glBegin(GL_POLYGON);
    glColor3f(0.60,0.66,1.50);
	glVertex3f(-4.2,-0.8, 0.0);
	glVertex3f(-6.2, 2.9, 0.0);
	glVertex3f(-4.9,2.9, 0.0);
	glVertex3f(-4.1,-0.8, 0.0);
	glEnd();
	glPopMatrix();
//---------------ray 1---------------
    glPushMatrix();
	glBegin(GL_POLYGON);
    glColor3f(0.60,0.66,1.50);
	glVertex3f(-4.0,-0.8, 0.0);
	glVertex3f(-4.2, 2.9, 0.0);
	glVertex3f(-3.6,2.9, 0.0);
	glVertex3f(-3.8,-0.8, 0.0);
	glEnd();
	glPopMatrix();
//---------------ray 2----------------
    glPushMatrix();
	glBegin(GL_POLYGON);
    glColor3f(0.60,0.66,1.50);
	glVertex3f(-3.6,-0.8, 0.0);
	glVertex3f(-2.8, 2.9, 0.0);
	glVertex3f(-2.1,2.9, 0.0);
	glVertex3f(-3.4,-0.8, 0.0);
	glEnd();
	glPopMatrix();
//---------------ray 3----------------
    glPushMatrix();
	glBegin(GL_POLYGON);
    glColor3f(0.60,0.66,1.50);
	glVertex3f(-3.5,-1.0, 0.0);
	glVertex3f(-1.1, 2.9, 0.0);
	glVertex3f(0.0,2.9, 0.0);
	glVertex3f(-3.3,-1.0, 0.0);
	glEnd();
	glPopMatrix();
//---------------ray 4----------------
    glPushMatrix();
	glBegin(GL_POLYGON);
    glColor3f(0.60,0.66,1.50);
	glVertex3f(-3.4,-1.0, 0.0);
	glVertex3f(1.2, 2.9, 0.0);
	glVertex3f(2.5,2.9, 0.0);
	glVertex3f(-3.6,-1.3, 0.0);
	glEnd();
	glPopMatrix();
//---------------ray 5----------------
    glPushMatrix();
	glBegin(GL_POLYGON);
    glColor3f(0.60,0.66,1.50);
	glVertex3f(-2.8,-0.7, 0.0);
	glVertex3f(4.1, 3.0, 0.0);
	glVertex3f(5.9,3.0, 0.0);
	glVertex3f(-2.6,-0.8, 0.0);
	glEnd();
	glPopMatrix();
	//---------------ray 6----------------
    glPushMatrix();
	glBegin(GL_POLYGON);
    glColor3f(0.60,0.66,1.50);
	glVertex3f(-2.6,-0.8, 0.0);
	glVertex3f(8.5, 3.0, 0.0);
	glVertex3f(14.7,3.0, 0.0);
	glVertex3f(-2.8,-1.0, 0.0);
	glEnd();
	glPopMatrix();
//---------------ray 7----------------
    glPushMatrix();
	glBegin(GL_POLYGON);
    glColor3f(0.60,0.66,1.50);
	glVertex3f(-2.9,-1.0, 0.0);
	glVertex3f(23.5, 2.5, 0.0);
	glVertex3f(48.7,1.5, 0.0);
	glVertex3f(-3.2,-1.2, 0.0);
	glEnd();
	glPopMatrix();
//-------------cloud 1-------------
    glPushMatrix();
    glColor3f(0.90,0.86,1.5);
    glTranslatef(-5.0,-0.6,0);
    glutSolidSphere(0.67,20,20);
    glPopMatrix();
//-------------cloud 4-------------
    glPushMatrix();
    glColor3f(0.90,0.86,1.5);
    glTranslatef(-2.9,-0.39,0);
    glutSolidSphere(0.65,20,20);
    glPopMatrix();
  //-------------cloud 2-----------
    glPushMatrix();
    glColor3f(.90,0.86,1.5);
    glTranslatef(-4.4,-0.075,0);
    glutSolidSphere(0.40,20,20);
    glPopMatrix();
//-------------cloud 3-------------
    glPushMatrix();
    glColor3f(.90,0.86,1.5);
    glTranslatef(-3.65,-0.12,0);
    glutSolidSphere(0.35,20,20);
    glPopMatrix();
//-------------cloud 5-------------
    glPushMatrix();
    glColor3f(0.90,0.86,1.5);
    glTranslatef(-2.4,-1.10,0);
    glutSolidSphere(0.60,20,20);
    glPopMatrix();
//-------------ball---------------------
    glPushMatrix();
    glColor3f(0.7,0.2,0.5);
    glTranslatef(3.04,-0.24,0);
    glutSolidSphere(0.2,20,20);
    glPopMatrix();
    //--------------fire ----------------
    glPushMatrix();
    glScalef(0.2,1.5,0.2);
    glTranslatef(15.0,-0.9,0.1);
    glColor3f(0.4,0.2,0.5);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.921,-0.4,0.2);
    glRotated(90,1.0,0.0,0.0);
    glColor3f(0.4,0.2,0.5);
    glutSolidCone(0.5,0.5,20,20);
    glPopMatrix();
//------------back forest1------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(-2.7,-1.7,0);
    glutSolidSphere(0.47,20,20);
    glPopMatrix();
//------------back forest2------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(-2.2,-2.0,0);
    glutSolidSphere(0.45,20,20);
    glPopMatrix();
//------------back forest 3---------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(-1.4,-1.8,0);
    glutSolidSphere(0.45,20,20);
    glPopMatrix();
//------------back forest 4---------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(-0.5,-1.6,0);
    glutSolidSphere(0.70,20,20);
    glPopMatrix();
//------------back forest 7---------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(2.2,-1.7,0);
    glutSolidSphere(0.70,20,20);
    glPopMatrix();
//------------back forest 5---------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(0.38,-1.3,0);
    glutSolidSphere(0.50,20,20);
    glPopMatrix();
//------------back forest 6---------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(1.2,-1.3,0);
    glutSolidSphere(0.50,20,20);
    glPopMatrix();
//------------back forest 8---------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(3.2,-1.8,0);
    glutSolidSphere(0.50,20,20);
    glPopMatrix();
//------------back forest 9---------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(3.9,-1.5,0);
    glutSolidSphere(0.50,20,20);
    glPopMatrix();
//------------back forest 10---------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(4.9,-1.4,0);
    glutSolidSphere(0.65,20,20);
    glPopMatrix();
//------------back forest 11 left side---------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(-4.6,-1.2,0);
    glutSolidSphere(0.3,20,20);
    glPopMatrix();
//------------back forest 12 left side---------------------
    glPushMatrix();
    glColor3f(1.0,1.2,0.0);
    glTranslatef(-5.1,-1.5,0);
    glutSolidSphere(0.3,20,20);
    glPopMatrix();
//----------------tree 1--------------------------
    glPushMatrix();
    glTranslatef(-2.3, -1.8, 0.0);
    glScalef(0.3,2.2,-0.1);
    glColor3f(.7,.5,.1);
    glutSolidCube(0.3);
    glPopMatrix();
//-----------------left leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.42,-1.4,0);
    glutSolidSphere(0.18,20,20);
    glPopMatrix();
//-----------------right leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.158,-1.4,0);
    glutSolidSphere(0.18,20,20);
    glPopMatrix();
//-----------------top leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.27,-1.12,0);
    glutSolidSphere(0.16,20,20);
    glPopMatrix();
    //----------------tree  2--------------------------
    glPushMatrix();
    glTranslatef(1.5, 0.44, 0.0);
    glScalef(1.2,1.1,-0.1);
    glPushMatrix();
    glTranslatef(-2.3, -1.8, 0.0);
    glScalef(0.3,2.2,-0.1);
    glColor3f(.7,.5,.1);
    glutSolidCube(0.3);
    glPopMatrix();
//-----------------left leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.42,-1.4,0);
    glutSolidSphere(0.18,20,20);
    glPopMatrix();
//-----------------right leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.158,-1.4,0);
    glutSolidSphere(0.18,20,20);
    glPopMatrix();
//-----------------top leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.27,-1.12,0);
    glutSolidSphere(0.16,20,20);
    glPopMatrix();
    glPopMatrix();
    //----------------tree  3--------------------------
    glPushMatrix();
    glTranslatef(6.0, 0.18, 0.0);
    glPushMatrix();
    glTranslatef(-2.3, -1.8, 0.0);
    glScalef(0.3,2.2,-0.1);
    glColor3f(.7,.5,.1);
    glutSolidCube(0.3);
    glPopMatrix();
//-----------------left leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.42,-1.4,0);
    glutSolidSphere(0.18,20,20);
    glPopMatrix();
//-----------------right leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.158,-1.4,0);
    glutSolidSphere(0.18,20,20);
    glPopMatrix();
//-----------------top leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.27,-1.12,0);
    glutSolidSphere(0.16,20,20);
    glPopMatrix();
    glPopMatrix();
//----------------tree  4--------------------------
    glPushMatrix();
    glTranslatef(5.0, 0.44, 0.0);
    glScalef(1.2,1.1,-0.1);
    glPushMatrix();
    glTranslatef(-2.3, -1.8, 0.0);
    glScalef(0.3,2.2,-0.1);
    glColor3f(.7,.5,.1);
    glutSolidCube(0.3);
    glPopMatrix();
//-----------------left leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.42,-1.4,0);
    glutSolidSphere(0.18,20,20);
    glPopMatrix();
//-----------------right leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.158,-1.4,0);
    glutSolidSphere(0.18,20,20);
    glPopMatrix();
//-----------------top leaf----------------------
    glPushMatrix();
    glColor3f(0.0,0.5,0.0);
    glTranslatef(-2.27,-1.12,0);
    glutSolidSphere(0.16,20,20);
    glPopMatrix();
    glPopMatrix();
//------------forest 1*1---------------------
    glPushMatrix();
    glColor3f(0.22,1.5,0.10);
    glTranslatef(-2.8,-2.1,0);
    glutSolidSphere(0.45,20,20);
    glPopMatrix();
//------------forest 1---------------------
    glPushMatrix();
    glColor3f(0.22,1.5,0.10);
    glTranslatef(-2.1,-2.2,0);
    glutSolidSphere(0.40,20,20);
    glPopMatrix();
//------------forest 2---------------------
    glPushMatrix();
    glColor3f(0.22,1.5,0.10);
    glTranslatef(-1.4,-2.0,0);
    glutSolidSphere(0.45,20,20);
    glPopMatrix();
//------------forest 3---------------------
    glPushMatrix();
    glColor3f(0.22,1.5,0.10);
    glTranslatef(-0.5,-2.1,0);
    glutSolidSphere(0.65,20,20);
    glPopMatrix();
//------------forest 4---------------------
    glPushMatrix();
    glColor3f(0.22,1.5,0.10);
    glTranslatef(2.2,-2.1,0);
    glutSolidSphere(0.55,20,20);
    glPopMatrix();
//------------forest 5---------------------
    glPushMatrix();
    glColor3f(0.22,1.5,0.10);
    glTranslatef(2.9,-2.2,0);
    glutSolidSphere(0.50,20,20);
    glPopMatrix();
//------------forest 6---------------------
    glPushMatrix();
    glColor3f(0.22,1.5,0.10);
    glTranslatef(3.7,-2.2,0);
    glutSolidSphere(0.55,20,20);
    glPopMatrix();
//------------forest 7---------------------
    glPushMatrix();
    glColor3f(0.22,1.5,0.10);
    glTranslatef(4.7,-1.8,0);
    glutSolidSphere(0.65,20,20);
    glPopMatrix();
//------------forest 8 left side---------------------
    glPushMatrix();
    glColor3f(0.22,1.5,0.10);
    glTranslatef(-4.7,-2.0,0);
    glutSolidSphere(0.65,20,20);
    glPopMatrix();
//-----------Cylinder_1--------------------
    glPushMatrix();
    glTranslatef(-4.8,0.0,-1.0);
    glRotatef(-90,-1.0,0.0,0);
    draw_cylinder(.7,3.5,234567,160,100);
    glPopMatrix();
//---------------cylinder 2---------------
    glPushMatrix();
    glTranslatef(-3.8,-0.5,-1.0);
    glRotatef(-90,-1.0,0.0,0);
    draw_cylinder(.6,3.5,5646000,16453630,100);
    glPopMatrix();
    //-----------vertical ground---------------
    glPushMatrix();
	glScalef(0.5,1.7,0.5);
	glTranslatef(6.4, -1.6, 0.0);
	glBegin(GL_POLYGON);
    glColor3f(.7,.5,.1);
	glVertex3f(1.4,0.8, 0.0);
	glVertex3f(2.4, 1.0, 0.0);
	glVertex3f(4.3,0.5, 0.0);
	glVertex3f(4.2,0.0, 0.0);
	glEnd();
	glPopMatrix();
//---------------ground1--------------
    glPushMatrix();
    glTranslatef(0.0, -2.6, 0.0);
    glPushMatrix();
    glScalef(12.5,0.6,-0.7);
    glColor3f(.7,.5,.1);
    glutSolidCube(0.8);
    glPopMatrix();
    for(float i=-5.0;i<5.0;i=i+0.3)
 {
     for(float j=-0.2;j<0.15;j=j+0.15)
     {
         glPushMatrix();
	     glTranslatef(i,j, 0.0);
         glScalef(0.2,0.1,0.0);
         glColor3f(0.65,0.35,0.20);
         glutSolidSphere(0.1,10,10);
         glPopMatrix();
     }
}
     for(float a=-5.0;a<5.0;a=a+0.15)
 {
     for(float b=-0.15;b<0.1;b=b+0.11)
     {
         glPushMatrix();
	     glTranslatef(a,b, 0.0);
         glScalef(0.1,0.1,0.0);
         glColor3f(0.65,0.35,0.20);
         glutSolidSphere(0.1,10,10);
         glPopMatrix();
     }
}
    glPopMatrix();
//---------------ground1_Layer ------
    glPushMatrix();
	glTranslatef(0.0, -2.3, 0.0);
    glScalef(12.5,0.01,-0.9);
    glColor3f(0.0,0.5,0.0);
    glutSolidCube(0.8);
    glPopMatrix();
//----------ground_2----------------
    glPushMatrix();
	glTranslatef(0.6, -1.98, 0.0);
    glScalef(3.5,0.6,-0.5);
    glColor3f(.7,.5,.1);
    glutSolidCube(0.8);
    glPopMatrix();
//---------ground_2Layer------------
    glPushMatrix();
	glTranslatef(0.58, -1.68, 0.05);
    glScalef(3.4,0.01,-0.6);
    glColor3f(0.0,0.5,0.0);
    glutSolidCube(0.8);
    glPopMatrix();
//----------ground_3----------------
    glPushMatrix();
	glTranslatef(0.85, -1.4, 0.0);
    glScalef(2.2,0.56,-0.5);
    glColor3f(.7,.5,.1);
    glutSolidCube(0.8);
    glPopMatrix();
//----------ground_3Layer----------------
    glPushMatrix();
	glTranslatef(0.855, -1.17, 0.0);
    glScalef(2.17,0.02,-0.55);
    glColor3f(0.0,0.5,0.0);
    glutSolidCube(0.8);
    glPopMatrix();
}
void EnemyBomb()
{
glTranslatef(EnemybombTranslateX,EnemybombTranslate,0.0);
glPushMatrix();//bomb
glColor3f(.90,0.0,0.0);
glScalef(.24,.24,.24);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void EnemyBomb1()
{
if(EnemyBomb1Translate<=-1.5)
{if(xAxis<-4.2&&xAxis>=-5.0)
{
    if(playerLife>0)
    {
        playerLife--;
    }
    blast1X=-3.0;
    blast1Y=EnemyBomb1Translate;
    bomb1Blast=1;
    EnemyBomb1Translate=7.0;
    cout<<"Collision with EnemyBomb-1"<<endl;
}
}
glTranslatef(-3.0,EnemyBomb1Translate,0.0);
glPushMatrix();//bomb
glColor3f(1.0,.50,.17);
glScalef(.24,.24,.24);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void EnemyBomb2()
{
    if(EnemyBomb2Translate<=-1.5)
{if(xAxis<-3.3&&xAxis>=-3.8)
{
    if(playerLife>0)
    {
        playerLife--;
    }
    blast2X=-2.3;
    blast2Y=EnemyBomb2Translate;
    bomb2Blast=1;
    EnemyBomb2Translate=9.0;
    cout<<"Collision with EnemyBomb-2"<<endl;
}
}
glTranslatef(-2.3,EnemyBomb2Translate,0.0);
glPushMatrix();//bomb
glColor3f(1.0,.50,.17);
glScalef(.24,.24,.24);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void EnemyBomb3()
{
    if(EnemyBomb3Translate<=-1.5)
{if(xAxis<-1.1&&xAxis>=-1.7)
{
    if(playerLife>0)
    {
        playerLife--;
    }
    blast3X=-0.90;
    blast3Y=EnemyBomb3Translate;
    bomb3Blast=1;
    EnemyBomb3Translate=6.0;
    cout<<"Collision with EnemyBomb-3"<<endl;
}
}
glTranslatef(-.90,EnemyBomb3Translate,0.0);
glPushMatrix();//bomb
glColor3f(1.0,.50,.17);
glScalef(.24,.24,.24);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void EnemyBomb4()
{
    if(EnemyBomb4Translate<=-1.5)
{if(xAxis<3.3&&xAxis>=2.8)
{
    if(playerLife>0)
    {
        playerLife--;
    }
    blast4X=2.0;
    blast4Y=EnemyBomb4Translate;
    bomb4Blast=1;
    EnemyBomb4Translate=10.0;
    cout<<"Collision with EnemyBomb-4"<<endl;
}
}
glTranslatef(2.0,EnemyBomb4Translate,0.0);
glPushMatrix();//bomb
glColor3f(1.0,.50,.17);
glScalef(.24,.24,.24);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void EnemyBomb5()
{
if(EnemyBomb5Translate<=-1.5)
{if(xAxis<5.6&&xAxis>=5.0)
{
    if(playerLife>0)
    {
        playerLife--;
    }
    blast5X=3.5;
    blast5Y=EnemyBomb5Translate;
    bomb5Blast=1;
    EnemyBomb5Translate=8.0;
    cout<<"Collision with EnemyBomb-5"<<endl;
}
}
glTranslatef(3.5,EnemyBomb5Translate,0.0);
glPushMatrix();//bomb
glColor3f(1.0,.50,.17);
glScalef(.24,.24,.24);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void EnemyBomb6()
{
if(EnemyBomb6Translate<=-1.5)
{if(xAxis<=-6.4&&xAxis>=-7.1)
{
    if(playerLife>0)
    {
        playerLife--;

    }
    blast6X=-4.4;
    blast6Y=EnemyBomb6Translate;
    bomb6Blast=1;
    EnemyBomb6Translate=7.0;
   cout<<"Collision with EnemyBomb-6"<<endl;
}
}
glTranslatef(-4.4,EnemyBomb6Translate,0.0);
glPushMatrix();//bomb
glColor3f(1.0,.50,.17);
glScalef(.24,.24,.24);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void EnemyBomb7()
{
if(EnemyBomb7Translate<=-1.5)
{if(xAxis<0.3&&xAxis>=-0.3)
{
    if(playerLife>0)
    {
        playerLife--;
    }
    blast7X=0.0;
    blast7Y=EnemyBomb7Translate;
    bomb7Blast=1;
    EnemyBomb7Translate=8.0;
   cout<<"Collision with EnemyBomb-7"<<endl;
}
}
glTranslatef(0.0,EnemyBomb7Translate,0.0);
glPushMatrix();//bomb
glColor3f(1.0,.50,.17);
glScalef(.24,.24,.24);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void EnemyBomb8()
{
if(EnemyBomb8Translate<=-1.5)
{if(xAxis<=1.8&&xAxis>=1.2)
{
    if(playerLife>0)
    {
        playerLife--;
    }
    blast8X=1.0;
    blast8Y=EnemyBomb8Translate;
    bomb8Blast=1;
    EnemyBomb8Translate=9.0;
   cout<<"Collision with EnemyBomb-8"<<endl;
}
}
glTranslatef(1.0,EnemyBomb8Translate,0.0);
glPushMatrix();//bomb
glColor3f(1.0,.50,.17);
glScalef(.24,.24,.24);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void EnemyBomb9()
{
if(EnemyBomb9Translate<=-1.5)
{if(xAxis<=7.1&&xAxis>=6.4)
{
    if(playerLife>0)
    {
        playerLife--;
    }
    blast9X=4.4;
    blast9Y=EnemyBomb9Translate;
    bomb9Blast=1;
    EnemyBomb9Translate=6.0;
   cout<<"Collision with EnemyBomb-9"<<endl;
}
}
glTranslatef(4.4,EnemyBomb9Translate,0.0);
glPushMatrix();//bomb
glColor3f(1.0,.50,.17);
glScalef(.24,.24,.24);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void Bomb1()
{
    if(bomb1==1.0f)
    {
        if(b1RotateBall!=0||b1TranslateX!=0)
        {
                glTranslatef((float)b1TranslateX,0.0,0.0);
                glRotatef((float)b1RotateBall,0.0,0.0,1.0);
        }
        glTranslatef(0.0,TranslateBomb1,0.0);
    }
glPushMatrix();//bomb
glColor3f(.0775,.50,.17);
glTranslatef(0.0,1.0,0.0);
glScalef(.24,.24,0.0);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void Bomb2()
{
   if(bomb2==1.0f)
    {
        if(b2RotateBall!=0||b2TranslateX!=0)
        {
                glTranslatef((float)b2TranslateX,0.0,0.0);
                glRotatef((float)b2RotateBall,0.0,0.0,1.0);
        }
        glTranslatef(0.0,TranslateBomb2,0.0);
    }
glPushMatrix();//bomb
glColor3f(1.0,.50,.17);
glTranslatef(0.0,1.0,0.0);
glScalef(.24,.24,0.0);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void Bomb3()
{
    if(bomb3==1.0f)
    {
        if(b3RotateBall!=0||b3TranslateX!=0)
        {
                glTranslatef((float)b3TranslateX,0.0,0.0);
                glRotatef((float)b3RotateBall,0.0,0.0,1.0);
        }
        glTranslatef(0.0,TranslateBomb3,0.0);
    }
glPushMatrix();//bomb
glColor3f(.0775,.50,1.0);
glTranslatef(0.0,1.0,0.0);
glScalef(.24,.24,0.0);
glutSolidSphere(.46,30,30);
glPopMatrix();//end
}
void Spring()
{
glPushMatrix();//spring
glTranslatef(0.0,(float)LoadTheBomb,0.0);
glPushMatrix();
glColor3f(0.0,1.0,0.9);
glTranslatef(0.0,0.85,0.0);
glScalef(.26,.1,0.0);
glutSolidCube(.8);
glPopMatrix();
glPushMatrix();
glColor3f(1,0,0.9);
glTranslatef(0.0,0.52,0.0);
glScalef(.025,.59,0.0);
glutSolidCube(1);
glPopMatrix();
glPopMatrix();//endSparing
}
void PlayerBody()
{
glPushMatrix();
glColor3f(1,0,0);
glTranslatef(-0.15,.58,0.0);
glScalef(.05,.9,0.0);
glutSolidCube(.9);
glPopMatrix();
glPushMatrix();
glColor3f(1,0,0);
glTranslatef(0.15,.57,0.0);
glScalef(.05,.9,0.0);
glutSolidCube(.9);
glPopMatrix();
glPushMatrix();
glColor3f(1.0,0.0,0.0);
glTranslatef(0.0,0.28,0.0);
glScalef(.4,.15,0.0);
glutSolidCube(.8);
glPopMatrix();
glPushMatrix();//main
glColor3f(1.0,1.0,1);
glScalef(.25,.25,0.0);
glPushMatrix();
glRotatef(rotateBall,0.0,0.0,1.0);
glutWireSphere(.9,10,10);
glPushMatrix();
glColor3f(0.50,0.50,0.50);
glScalef(.6,.6,0.0);
glutSolidSphere(.9,55,55);
glPopMatrix();
glPopMatrix();
glPopMatrix();
}
void EnemyBody(void)
{
    glTranslatef(enemyTranslate,0.0,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glPushMatrix();
    glTranslatef(0.0,2.2,0.0);
    glScalef(1.75,1.75,1.75);
    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glScalef(.30,0.30,.30);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glColor3f(R,G,B);
    glScalef(.10,0.10,.10);
    glutSolidSphere(enemyHeart,30,30);
    glPopMatrix();
    glPopMatrix();
}
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
void KillTheEnemyText()
{
    glPushMatrix();//K
    glColor3f(KR,KG,KB);
    glPushMatrix();
    glTranslatef(-0.01,0.0,0.0);
    glScalef(.04,0.350,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.06,-0.05,0.0);
    glRotatef(45,0.0,0.0,1.0);
    glScalef(.04,0.27,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.06,0.05,0.0);
    glRotatef(-45,0.0,0.0,1.0);
    glScalef(.04,0.27,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//I
    glColor3f(IR,IG,IB);
    glTranslatef(0.2,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();//L
    glColor3f(L1R,L1G,L1B);
    glPushMatrix();
    glTranslatef(0.3,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.4,-0.14,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//L
    glColor3f(L2R,L2G,L2B);
    glPushMatrix();
    glTranslatef(0.55,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.65,-0.14,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//T
    glColor3f(TR,TG,TB);
    glPushMatrix();
    glTranslatef(0.95,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.95,0.15,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.3,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//H
    glColor3f(HR,HG,HB);
    glPushMatrix();
    glTranslatef(1.15,0.0,0.0);
    glColor3f(YR,YG,YB);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.25,0.0,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glColor3f(YR,YG,YB);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.35,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//E
    glColor3f(ER,EG,EB);
    glPushMatrix();
    glTranslatef(1.450,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.55,-0.14,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.55,0.0,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.55,0.14,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//E
    glColor3f(E1R,E1G,E1B);
    glPushMatrix();
    glTranslatef(1.850,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.95,-0.14,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.95,0.0,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.95,0.14,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//N
    glColor3f(NR,NG,NB);
    glPushMatrix();
    glTranslatef(2.1,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.2,0.0,0.0);
    glRotatef(35,0.0,0.0,1.0);
    glScalef(.04,0.4,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.3,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//E
    glColor3f(E2R,E2G,E2B);
    glPushMatrix();
    glTranslatef(2.4,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.5,-0.14,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.5,0.0,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.5,0.14,0.0);
    glRotatef(90,0.0,0.0,1.0);
    glScalef(.04,0.21,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//M
    glColor3f(MR,MG,MB);
    glPushMatrix();
    glTranslatef(2.7,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.77,0.05,0.0);
    glRotatef(35,0.0,0.0,1.0);
    glScalef(.04,0.25,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.88,0.05,0.0);
    glRotatef(-35,0.0,0.0,1.0);
    glScalef(.04,0.25,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.95,0.0,0.0);
    glScalef(.04,0.35,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//Y
    glColor3f(YR,YG,YB);
    glPushMatrix();
    glTranslatef(3.10,0.05,0.0);
    glRotatef(35,0.0,0.0,1.0);
    glScalef(.04,0.25,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.2,0.05,0.0);
    glRotatef(-35,0.0,0.0,1.0);
    glScalef(.04,0.25,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.15,-0.07,0.0);
    glScalef(.04,0.20,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    glPopMatrix();
}
//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
void BulletRemainingText()
{
    char text[32];
    sprintf(text, "Bullet Remaining : %.0f",bullets);
    glColor3f(BRed, BGreen, BBlue);
    glRasterPos3f( -0.55 , 2.28 , 1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void PlayerLifeText()
{
    char text[32];
    sprintf(text, "Player Life : ");
    glColor3f(0.0,0.0,0.0);
    glRasterPos3f( -3.9 , 2.29 , 1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void EnemyLifeText()
{
    char text[32];
    sprintf(text, " : Enemy Life ");
    glColor3f(0.0,0.0,0.0);
    glRasterPos3f( 3.25 , 2.29 , 1);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void TotalScoreText1()
{
    char text[32];
    sprintf(text, "Total Score : ");
    glColor3f(0.0,0.0,0.0);
    glRasterPos3f( -0.25, 0.40 , 3);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void TotalScoreText2()
{
    char text[32];
    sprintf(text, " %.0f ",totalScore);
    glColor3f(0.0,0.0,0.0);
    glRasterPos3f( -0.10, 0.30 , 3);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void HighestScoreText1()
{
    char text[32];
    sprintf(text, " Highest Score : ");
    glColor3f(0.0,0.0,0.0);
    glRasterPos3f( -0.31, 0.20 , 3);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void HighestScoreText2()
{
    char text[32];
    sprintf(text, " %.0f ",highestScore);
    glColor3f(0.0,0.0,0.0);
    glRasterPos3f( -0.10, 0.10 , 3);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void TotalScoreText3()
{
    char text[32];
    sprintf(text, " GAME OVER ");
    glColor3f(0.80,0.0,0.0);
    glRasterPos3f( -0.30, 0.60 , 3);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void TotalScoreText4()
{
    char text[32];
    sprintf(text, " Press F11 to Play Again ");
    glColor3f(0.0,0.0,0.0);
    glRasterPos3f( -0.49, -0.05 , 3);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void TotalScoreText5()
{
    char text[32];
    sprintf(text, " Press ESC to Exit ");
    glColor3f(0.0,0.0,0.0);
    glRasterPos3f( -0.40, -0.19 , 3);
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}
void PlayerLife()
{
    glPushMatrix();
    glTranslatef(-2.3,2.72,0.0);
    glColor3f(0.0,0.0,0.0);
    glScalef(3.0,0.15,0.0);
    glutWireCube(.9);
    glPopMatrix();
    if(playerLife==3)
    {
        glPushMatrix();
        glTranslatef(-2.3,2.72,0.0);
        glColor3f(0.0,1.0,0.0);
        glScalef(2.98,0.132,0.0);
        glutSolidCube(.9);
        glPopMatrix();
    }
    if(playerLife==2)
    {
        glPushMatrix();
        glTranslatef(-2.85,2.72,0.0);
        glColor3f(1.0,1.0,0.0);
        glScalef(1.75,0.132,0.0);
        glutSolidCube(.9);
        glPopMatrix();
    }
        if(playerLife==1)
    {
        glPushMatrix();
        glTranslatef(-3.33,2.72,0.0);
        glColor3f(1.0,0.0,0.0);
        glScalef(0.70,0.132,0.0);
        glutSolidCube(.9);
        glPopMatrix();
    }
}
void EnemyLife()
{
    glPushMatrix();
    glTranslatef(2.3,2.72,0.0);
    glColor3f(0.0,0.0,0.0);
    glScalef(3.0,0.15,0.0);
    glutWireCube(.9);
    glPopMatrix();
    if(enemyLife==5)
    {
    glPushMatrix();
    glTranslatef(2.3,2.72,0.0);
    glColor3f(0.0,1.0,0.0);
    glScalef(2.99,0.132,0.0);
    glutSolidCube(.9);
    glPopMatrix();
    }
if(enemyLife==4)
{
    glPushMatrix();
    glTranslatef(2.70,2.72,0.0);
    glColor3f(0.70,1.0,0.0);
    glScalef(2.1,0.132,0.0);
    glutSolidCube(.9);
    glPopMatrix();
}
if(enemyLife==3)
{
    glPushMatrix();
    glTranslatef(3.03,2.72,0.0);
    glColor3f(1.0,1.0,0.0);
    glScalef(1.38,0.132,0.0);
    glutSolidCube(.9);
    glPopMatrix();
}
if(enemyLife==2)
{
    glPushMatrix();
    glTranslatef(3.33,2.72,0.0);
    glColor3f(0.90,0.30,0.0);
    glScalef(0.70,0.132,0.0);
    glutSolidCube(.9);
    glPopMatrix();
}
if(enemyLife==1)
{
    glPushMatrix();
    glTranslatef(3.51,2.72,0.0);
    glColor3f(1.0,0.0,0.0);
    glScalef(0.30,0.132,0.0);
    glutSolidCube(.9);
    glPopMatrix();
}
}
void ScoreScreenPlayer()
{
    glPushMatrix();
    glRotatef(ScoreAngle,0.0,1.0,0.0);
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-0.15,.58,0.0);
    glScalef(.05,.9,0.20);
    glutSolidCube(.9);
    glPopMatrix();
    glPushMatrix();//bomb
    glColor3f(1.0,.50,.17);
    glTranslatef(0.0,1.0,0.0);
    glScalef(0.30,0.30,0.30);
    glutSolidSphere(.46,30,30);
    glPopMatrix();//end
glPushMatrix();//spring
glPushMatrix();
glColor3f(0.0,1.0,0.9);
glTranslatef(0.0,0.85,0.0);
glScalef(.26,0.1,0.20);
glutSolidCube(.8);
glPopMatrix();
glPushMatrix();
glColor3f(1,0,0.9);
glTranslatef(0.0,0.52,0.0);
glScalef(.025,.59,0.10);
glutSolidCube(1);
glPopMatrix();
glPopMatrix();//endSparing
glPushMatrix();
glColor3f(1,0,0);
glTranslatef(0.15,.57,0.0);
glScalef(.05,.9,0.20);
glutSolidCube(.9);
glPopMatrix();
glPushMatrix();
glColor3f(1.0,0.0,0.0);
glTranslatef(0.0,0.28,0.0);
glScalef(.4,.15,0.20);
glutSolidCube(.8);
glPopMatrix();
glPushMatrix();//main
glColor3f(1.0,1.0,1);
glScalef(.25,.25,0.16);
glPushMatrix();
glutWireSphere(.9,20,20);
glPushMatrix();
glColor3f(0.50,0.50,0.50);
glScalef(.6,.6,0.50);
glutSolidSphere(.9,55,55);
glPopMatrix();
glPopMatrix();
glPopMatrix();
glPopMatrix();
}
void ScoreScreen()
{
    glPushMatrix();
    BackGround();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0,-0.1,0.0);
    glPushMatrix();
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(0.0,0.50,0.0);
    glScalef(5.5,3.5,1.0);
    glutWireCube(.9);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.90,0.90,0.0);
    glTranslatef(0.0,0.50,0.0);
    glScalef(5.3,3.3,1.0);
    glutWireCube(.9);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.0,0.50,0.50);
    glTranslatef(0.0,0.50,0.0);
    glScalef(5.1,3.1,1.0);
    glutWireCube(.9);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5,0.0,0.0);
    ScoreScreenPlayer();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5,0.0,0.0);
    ScoreScreenPlayer();
    glPopMatrix();
    glPushMatrix();
    TotalScoreText1();
    TotalScoreText2();
    TotalScoreText3();
    HighestScoreText1();
    HighestScoreText2();
    TotalScoreText4();
    TotalScoreText5();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.6,1.5,0.0);
    KillTheEnemyText();
    glPopMatrix();
}
void updateScoreScreen(int value)
{
    if(GameOver==1)
    {
	ScoreAngle += 2.0f;
	if (ScoreAngle > 360) {
		ScoreAngle -= 360;
		glColor3f(1.0,1.0,0.0);
    	}
    	KR+=0.01f;
    KG+=0.01f;
    KB+=0.01f;
    IR+=0.01f;
    IG+=0.01f;
    IB+=0.01f;
    L1R+=0.01f;
    L1G+=0.01f;
    L1B+=0.01f;
    L2R+=0.01f;
    L2G+=0.01f;
    L2B+=0.01f;
    TR+=0.01f;
    TG+=0.01f;
    TB+=0.01f;
    HR+=0.01f;
    HG+=0.01f;
    HB+=0.01f;
    ER+=0.01f;
    EG+=0.01f;
    EB+=0.01f;
    E1R+=0.01f;
    E1G+=0.01f;
    E1B+=0.01f;
    NR+=0.01f;
    NG+=0.01f;
    NB+=0.01f;
    E2R+=0.01f;
    E2G+=0.01f;
    E2B+=0.01f;
    MR+=0.01f;
    MG+=0.01f;
    MB+=0.01f;
    YR+=0.01f;
    YG+=0.01f;
    YB+=0.01f;
    if(KR>=1.0)
    {KR=0.0;}
    if(KG>=1.0)
    {KG=0.0;}
    if(KB>=1.0)
    {KB=0.0;}
    if(IG>=1.0)
    {IG=0.0;}
    if(IR>=1.0)
    {IR=0.0;}
    if(IB>=1.0)
    {IB=0.0;}
    if(L1R>=1.0)
    {L1R=0.0;}
    if(L1G>=1.0)
    {L1G=0.0;}
    if(L1B>=1.0)
    {L1B=0.0;}
    if(L2R>=1.0)
    {L2R=0.0;}
    if(L2G>=1.0)
    {L2G=0.0;}
    if(L2B>=1.0)
    {L2B=0.0;}
    if(TR>=1.0)
    {TR=0.0;}
    if(TG>=1.0)
    {TG=0.0;}
    if(TB>=1.0)
    {TB=0.0;}
    if(HR>=1.0)
    {HR=0.0;}
    if(HG>=1.0)
    {HG=0.0;}
    if(HB>=1.0)
    {HB=0.0;}
    if(ER>=1.0)
    {ER=0.0;}
    if(EG>=1.0)
    {EG=0.0;}
    if(EB>=1.0)
    {EB=0.0;}
    if(E1R>=1.0)
    {E1R=0.0;}
    if(E1G>=1.0)
    {E1G=0.0;}
    if(E1B>=1.0)
    {E1B=0.0;}
    if(NR>=1.0)
    {NR=0.0;}
    if(NG>=1.0)
    {NG=0.0;}
    if(NB>=1.0)
    {NB=0.0;}
    if(E2R>=1.0)
    {E2R=0.0;}
    if(E2G>=1.0)
    {E2G=0.0;}
    if(E2B>=1.0)
    {E2B=0.0;}
    if(MR>=1.0)
    {MR=0.0;}
    if(MG>=1.0)
    {MG=0.0;}
    if(MB>=1.0)
    {MB=0.0;}
    if(YR>=1.0)
    {YR=0.0;}
    if(YG>=1.0)
    {YG=0.0;}
    if(YB>=1.0)
    {YB=0.0;}
	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(25, updateScoreScreen, 0);
}
}
//Draws the scene
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glTranslatef(0.0, 0.0, -7.0);
    glClearColor (0.5, 0.60, 1.0, 1.0);
    if(highestScore==0)
    {
        ifstream input("HighestScore.txt");
        input>>highestScore;
    }
if(bullets<0||playerLife==0||enemyLife==0)
    {
        if(bullets>0)
        {
            totalScore=(bullets*((playerLife*5)+(2*(collision*5))+1))-(enemyLife*5);
            if(totalScore<0)
            {
                totalScore=0;
            }
        }
        if(bullets<=0)
        {
            totalScore=((playerLife*5)+(2*(collision*5))+1)-(enemyLife*5);
            if(totalScore<0)
            {
                totalScore=0;
            }
        }
        if(GameOver==0)
        {
            GameOver=1;
            if(highestScore<totalScore)
            {
                highestScore=totalScore;
                ofstream output("HighestScore.txt");
                output<<highestScore<<endl;
            }
            glutTimerFunc(25, updateScoreScreen, 0);
        }
        glPushMatrix();
        ScoreScreen();
        glPopMatrix();
    }
if(GameOver==0)
{
    cout<<xAxis<<endl;
glPushMatrix();
BackGround();
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,-2.15,0.0);
glScalef(0.65,0.65,0.0);
glPushMatrix();
if(bullets>=0)
{
    glPushMatrix();
if(LoadBomb1==1)
{
    if(bomb1!=1)
{
    glTranslatef((float)xAxis,0.0,0.0);
    glRotatef(rotateZ,0.0,0.0,1.0);
    glTranslatef(0.0,(float)LoadTheBomb,0.0);
}
if(bomb0Blast==1&&GameOver==0)
    {
        blast0();
        bomb0Blast=0;
    }
Bomb1();
}
glPopMatrix();
glPushMatrix();
if(LoadBomb2==1)
{
    if(bomb2!=1)
 {
    glTranslatef((float)xAxis,0.0,0.0);
    glRotatef(rotateZ,0.0,0.0,1.0);
    glTranslatef(0.0,(float)LoadTheBomb,0.0);
 }
 if(bomb0Blast==1&&GameOver==0)
    {
        blast0();
        bomb0Blast=0;
    }
Bomb2();
}
glPopMatrix();
glPushMatrix();
if(LoadBomb3==1)
{
    if(bomb3!=1)
{
    glTranslatef((float)xAxis,0.0,0.0);
    glRotatef(rotateZ,0.0,0.0,1.0);
    glTranslatef(0.0,(float)LoadTheBomb,0.0);
}
if(bomb0Blast==1&&GameOver==0)
    {
        blast0();
        bomb0Blast=0;
    }
Bomb3();
}
glPopMatrix();
}
glPopMatrix();
glPushMatrix();
glTranslatef((float)xAxis,0.0,0.0);
glRotatef(rotateZ,0.0,0.0,1.0);
glPushMatrix();
Spring();
glPopMatrix();
PlayerBody();
glPopMatrix();
glPopMatrix();
if(enemyAttack1==1)
{
    glPushMatrix();
    if(bombBlast==1)
    {
        blast();
        bombBlast=0;
    }
    EnemyBomb();
    glPopMatrix();
}
glPushMatrix();
EnemyBody();
glPopMatrix();
if(enemyAttack2==1)
{
    glPushMatrix();
    if(bomb1Blast==1)
    {
        blast1();
        bomb1Blast=0;
    }
    EnemyBomb1();
    glPopMatrix();
    glPushMatrix();
    if(bomb2Blast==1)
    {
        blast2();
        bomb2Blast=0;
    }
    EnemyBomb2();
    glPopMatrix();
    glPushMatrix();
    if(bomb3Blast==1)
    {
        blast3();
        bomb3Blast=0;
    }
    EnemyBomb3();
    glPopMatrix();
    glPushMatrix();
    if(bomb4Blast==1)
    {
        blast4();
        bomb4Blast=0;
    }
    EnemyBomb4();
    glPopMatrix();
    glPushMatrix();
    if(bomb5Blast==1)
    {
        blast5();
        bomb5Blast=0;
    }
    EnemyBomb5();
    glPopMatrix();
    glPushMatrix();
    if(bomb6Blast==1)
    {
        blast6();
        bomb6Blast=0;
    }
    EnemyBomb6();
    glPopMatrix();
    glPushMatrix();
    if(bomb7Blast==1)
    {
        blast7();
        bomb7Blast=0;
    }
    EnemyBomb7();
    glPopMatrix();
    glPushMatrix();
    if(bomb8Blast==1)
    {
        blast8();
        bomb8Blast=0;
    }
    EnemyBomb8();
    glPopMatrix();
    glPushMatrix();
    if(bomb9Blast==1)
    {
        blast9();
        bomb9Blast=0;
    }
    EnemyBomb9();
    glPopMatrix();
}
glPushMatrix();
BulletRemainingText();
glPopMatrix();
glPushMatrix();
PlayerLifeText();
glPopMatrix();
glPushMatrix();
EnemyLifeText();
glPopMatrix();
glPushMatrix();
PlayerLife();
glPopMatrix();
glPushMatrix();
EnemyLife();
glPopMatrix();
}
glutSwapBuffers();
}
void ClearAll()
{
GameOver=0;
bullets=15.0;
xAxis=0;
rotateZ=0;
rotateBall=0;
LoadTheBomb = 0;
cnt = 0;
bomb1 = 0;
bomb2 = 0;
bomb3 = 0;
TranslateBomb1 = 0.0f;
b1RotateBall = 0.0f;
b1TranslateX = 0.0f;
TranslateBomb2 = 0.0f;
b2RotateBall = 0.0f;
b2TranslateX = 0.0f;
TranslateBomb3 = 0.0f;
b3RotateBall = 0.0f;
b3TranslateX = 0.0f;
bomb1Stop=0.0f;
bomb2Stop=0.0f;
bomb3Stop=0.0f;
LoadBomb1=1;
LoadBomb2=0;
LoadBomb3=0;
enemyTranslate=0.0f;
enemyTranslateSpeed=0.1f;
enemyBombTranslateSpeed=0.06f;
enemyTranslateTimer=75;
enemyHeart = 1.1f;
EnemyBomb1Translate=7.0f;
EnemyBomb2Translate=9.0f;
EnemyBomb3Translate=6.0f;
EnemyBomb4Translate=10.0f;
EnemyBomb5Translate=8.0f;
EnemyBomb6Translate=7.0f;
EnemyBomb7Translate=8.0f;
EnemyBomb8Translate=9.0f;
EnemyBomb9Translate=6.0f;
EnemybombTranslateX =0.0f;
EnemybombTranslate =2.15f;
enemyBomb=1;
enemyAttack1=0;
enemyAttack2=0;
enemyLife=5;
playerLife=3;
R =1;
G =.75;
B =0;
BRed =0.0;
BGreen =0.50;
BBlue =0;
collision = 0;
totalScore=0.0;
}
void keyboard(int key, int x, int y)
{
switch (key)
 {
     case GLUT_KEY_F1:    // F1: Toggle between full-screen and windowed mode
         fullScreenMode = !fullScreenMode;         // Toggle state
         if (fullScreenMode) {                     // Full-screen mode
            windowPosX   = glutGet(GLUT_WINDOW_X); // Save parameters for restoring later
            windowPosY   = glutGet(GLUT_WINDOW_Y);
            windowWidth  = glutGet(GLUT_WINDOW_WIDTH);
            windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
            glutFullScreen();                      // Switch into full screen
         } else {                                         // Windowed mode
            glutReshapeWindow(windowWidth, windowHeight); // Switch into windowed mode
            glutPositionWindow(windowPosX, windowPosX);   // Position top-left corner
         }
         break;
case GLUT_KEY_LEFT :
    if(xAxis>-7.0f)
    {
        rotateBall+=5.0f;
        xAxis-=0.1f;
    }
   glutPostRedisplay();
       break;
case GLUT_KEY_RIGHT :
    if(xAxis<7.0f)
    {
        rotateBall-=5.0f;
        xAxis+=0.1f;
    }
    glutPostRedisplay();
    break;
case GLUT_KEY_F11 :
    if(bullets<0||playerLife==0||enemyLife==0)
    {
     ClearAll();
     glutPostRedisplay();
    }
    break;
default:
break;
}
}
void updateBomb1(int value) {
    TranslateBomb1+=0.09f;
    cout<<"B1Translate "<<TranslateBomb1<<endl;
    if(TranslateBomb1>=5.9f&&TranslateBomb1<=6.3f)
    {
        if((enemyTranslate+(enemyTranslate*0.5f)<=b1TranslateX+0.55f)&&(enemyTranslate+(enemyTranslate*0.5f)>=b1TranslateX-0.55f))
        {
        blast0X=enemyTranslate-(enemyTranslate*0.7f);
        blast0Y=TranslateBomb1;
        bomb0Blast=1;
        collision++;
        if(enemyLife>=0)
        {
            enemyLife--;
        }
        if(enemyHeart>0)
        {enemyHeart-=0.2f;}
        cout<<"collision"<<endl;
        //enemyTranslateTimer=55;
        R=0;
        G=1;
        B=0;
        bomb1Stop=1.0f;
        LoadBomb1=0;
        bomb1=0;
        bomb2Stop=0.0f;
        bomb3Stop=0.0f;
        if(bullets==0)
        {
            bullets--;
        }
      }
    }
    if(TranslateBomb1>=4.7f&&LoadBomb2!=1)
    {
        TranslateBomb2=0.0f;
        if(bullets>0)
        {
            LoadBomb2=1;
            }
        press=0;
    }
    if(TranslateBomb1>7.0f)
    {
        bomb1Stop=1.0f;
        LoadBomb1=0;
        bomb1=0;
        bomb2Stop=0.0f;
        bomb3Stop=0.0f;
        if(bullets==0)
        {

            bullets--;
        }
    }
    if(bomb1Stop==0.0f&&LoadBomb1==1)
        {
        glutTimerFunc(25, updateBomb1, 0);//Tell GLUT to call update again in 25 milliseconds
        }
        glutPostRedisplay();
}
void updateBomb2(int value) {
    TranslateBomb2+=0.09f;
    cout<<"B2Translate "<<TranslateBomb2<<endl;
    cout<<"Bomb-2 "<<b2RotateBall<<"\n"<<"enemy  "<<enemyTranslate+(enemyTranslate*0.5f)<<endl;
    if(TranslateBomb2>=5.9f&&TranslateBomb2<=6.3f)
       {if((enemyTranslate+(enemyTranslate*0.5f)<=b2TranslateX+0.55f)&&(enemyTranslate+(enemyTranslate*0.5f)>=b2TranslateX-0.55f))
      {
        blast0X=enemyTranslate-(enemyTranslate*0.7f);
        blast0Y=TranslateBomb2;
        bomb0Blast=1;
        collision++;
        if(enemyLife>=0)
        {
            enemyLife--;
        }
        if(enemyHeart>0)
        {enemyHeart-=0.2f;}
        cout<<"collision"<<endl;
        //enemyTranslateTimer=55;
        R=1;
        G=0;
        B=0;
        bomb2Stop=1.0f;
        LoadBomb2=0;
        bomb2=0;
        bomb1Stop=0.0f;
        bomb3Stop=0.0f;
        if(bullets==0)
        {
            bullets--;
        }
      }
       }
    if(TranslateBomb2>=4.7f&&LoadBomb3!=1)
    {
        TranslateBomb3=0.0f;
        if(bullets>0)
        {
            LoadBomb3=1;
            }
        press=0;
    }
    if(TranslateBomb2>7.0f)
    {
        bomb2Stop=1.0f;
        LoadBomb2=0;
        bomb2=0;
        bomb1Stop=0.0f;
        bomb3Stop=0.0f;
        if(bullets==0)
        {
            bullets--;
        }
    }
    if(bomb2Stop==0.0f&&LoadBomb2==1)
        {
        glutTimerFunc(25, updateBomb2, 0);//Tell GLUT to call update again in 25 milliseconds
        }
        glutPostRedisplay();
}
void updateBomb3(int value) {
    TranslateBomb3+=0.09f;
    cout<<"Bomb-3 "<<b3RotateBall<<"\n"<<"enemy  "<<enemyTranslate+(enemyTranslate*0.5f)<<endl;
    if(TranslateBomb3>=5.9f&&TranslateBomb3<=6.3f)
       {if((enemyTranslate+(enemyTranslate*0.5f)<=b3TranslateX+0.55f)&&(enemyTranslate+(enemyTranslate*0.5f)>=b3TranslateX-0.55f))
        {
        blast0X=enemyTranslate-(enemyTranslate*0.7f);
        blast0Y=TranslateBomb3;
        bomb0Blast=1;
        collision++;
        if(enemyLife>=0)
        {
            enemyLife--;
        }
        if(enemyHeart>0)
        {enemyHeart-=0.2f;}
        cout<<"collision"<<endl;
        //enemyTranslateTimer=55;
        R=0;
        G=0;
        B=1;
        bomb3Stop=1.0f;
        LoadBomb3=0;
        bomb3=0;
        bomb1Stop=0.0f;
        bomb2Stop=0.0f;
        if(bullets==0)
        {
            bullets--;
        }
      }
       }
    if(TranslateBomb3>=4.7f&&LoadBomb1!=1)
    {
        TranslateBomb1=0.0f;
        if(bullets>0)
        {
            LoadBomb1=1;
            }
        press=0;
    }
    if(TranslateBomb3>7.0f)
    {
        bomb3Stop=1.0f;
        LoadBomb3=0;
        bomb3=0;
        bomb1Stop=0.0f;
        bomb2Stop=0.0f;
        if(bullets==0)
        {
            bullets--;
        }
    }
    if(bomb3Stop==0.0f&&LoadBomb3==1)
        {
        glutTimerFunc(25, updateBomb3, 0);//Tell GLUT to call update again in 25 milliseconds
        }
        glutPostRedisplay();
}

void updateForLoadBomb(int value) {
    LoadTheBomb-=0.03f;
    if(LoadTheBomb<-0.45f)
    {
    cnt=0;
    LoadTheBomb=0.0f;
    if(bullets>0.0f)
    {
        if(bullets<=8)
        {
            BRed=1.0;
            BGreen=1.0;
            BBlue=0.0;
        }
        if(bullets<=4)
        {
            BRed=0.90;
            BGreen=0.0;
            BBlue=0.0;
        }
        bullets--;
    }
    glutPostRedisplay();
     if(LoadBomb1==1&&LoadBomb2!=1)
       {
           bomb1=1;
          if(rotateZ!=0 || xAxis!=0.0f)
         {
          b1RotateBall= rotateZ;
          b1TranslateX = xAxis;
         }
           glutTimerFunc(25, updateBomb1, 0);
        }
    if(LoadBomb2==1)
       {
            bomb2=1;
           if(rotateZ!=0 || xAxis!=0.0f)
          {
            b2RotateBall= rotateZ;
            b2TranslateX = xAxis;
          }
           glutTimerFunc(25, updateBomb2, 0);
        }
    if(LoadBomb3==1)
       {
            bomb3=1;
           if(rotateZ!=0 || xAxis!=0.0f)
          {
            b3RotateBall= rotateZ;
            b3TranslateX = xAxis;
          }
           glutTimerFunc(25, updateBomb3, 0);
        }
    }
	glutPostRedisplay(); //Tell GLUT that the display has changed

    if(cnt==1)
	{
	    glutTimerFunc(25, updateForLoadBomb, 0);//Tell GLUT to call update again in 25 milliseconds

	}
}
void updateEnemyBomb(int value) {
    if(GameOver==0)
    {if(EnemyBomb1Translate>-2.3)
    {
        EnemyBomb1Translate-=0.05f;
    }
    if(EnemyBomb2Translate>-2.3)
    {
        EnemyBomb2Translate-=0.07f;
    }
    if(EnemyBomb3Translate>-2.3)
    {
        EnemyBomb3Translate-=0.08f;
    }
    if(EnemyBomb4Translate>-2.3)
    {
        EnemyBomb4Translate-=0.09f;
    }
    if(EnemyBomb5Translate>-2.3)
    {
        EnemyBomb5Translate-=0.05f;
    }
    if(EnemyBomb6Translate>-2.3)
    {
        EnemyBomb6Translate-=0.08f;
    }
    if(EnemyBomb7Translate>-2.3)
    {
        EnemyBomb7Translate-=0.05f;
    }
    if(EnemyBomb8Translate>-2.3)
    {
        EnemyBomb8Translate-=0.07f;
    }
    if(EnemyBomb9Translate>-2.3)
    {
        EnemyBomb9Translate-=0.06f;
    }
    if(EnemyBomb1Translate<=-2.3)
    {
        bomb1Blast=1;
        blast1X=-3.0;
        blast1Y=EnemyBomb1Translate;
        EnemyBomb1Translate=7.0f;
    }
    if(EnemyBomb2Translate<=-2.3)
    {
        blast2X=-2.3;
        blast2Y=EnemyBomb2Translate;
        bomb2Blast=1;
        EnemyBomb2Translate=9.0f;
    }
    if(EnemyBomb3Translate<=-2.3)
    {
        blast3X=-0.90;
        blast3Y=EnemyBomb3Translate;
        bomb3Blast=1;
        EnemyBomb3Translate=6.0f;
    }
    if(EnemyBomb4Translate<=-2.3)
    {
        blast4X=2.0;
        blast4Y=EnemyBomb4Translate;
        bomb4Blast=1;
        EnemyBomb4Translate=10.0f;
    }
    if(EnemyBomb5Translate<=-2.3)
    {
        blast5X=3.5;
        blast5Y=EnemyBomb5Translate;
        bomb5Blast=1;
        EnemyBomb5Translate=8.0f;
    }
    if(EnemyBomb6Translate<=-2.3)
    {
        blast6X=-4.4;
        blast6Y=EnemyBomb6Translate;
        bomb6Blast=1;
        EnemyBomb6Translate=7.0f;
    }
    if(EnemyBomb7Translate<=-2.3)
    {
        blast7X=0.0;
        blast7Y=EnemyBomb7Translate;
        bomb7Blast=1;
        EnemyBomb7Translate=8.0f;
    }
    if(EnemyBomb8Translate<=-2.3)
    {
        blast8X=1.0;
        blast8Y=EnemyBomb8Translate;
        bomb8Blast=1;
        EnemyBomb8Translate=9.0f;
    }
    if(EnemyBomb9Translate<=-2.3)
    {
        blast9X=4.4;
        blast9Y=EnemyBomb9Translate;
        bomb9Blast=1;
        EnemyBomb9Translate=6.0f;
    }
        glutTimerFunc(25, updateEnemyBomb, 0);//Tell GLUT to call update again in 25 milliseconds
        glutPostRedisplay();
    }
}
void updateEnemyMainBomb(int value)
{
    if(GameOver==0)
   {
       if(EnemybombTranslate<=-1.5)
{
    cout<<"EnemyBomb "<<xAxis<<" "<<EnemybombTranslateX<<endl;
if((EnemybombTranslateX+(EnemybombTranslateX*0.5f)>=xAxis-0.30f)&&(EnemybombTranslateX+(EnemybombTranslateX*0.5f)<=xAxis+0.30f))
{
    if(playerLife>0)
    {
        playerLife--;
    }
    blastX=EnemybombTranslateX;
    blastY=EnemybombTranslate;
    bombBlast=1;
    EnemybombTranslate=2.15f;
    EnemybombTranslateX=enemyTranslate;
    cout<<"Collision with EnemyBomb"<<endl;
}
}
     if(EnemybombTranslate>-2.3)
    {
        EnemybombTranslate-=enemyBombTranslateSpeed;
    }

    if(EnemybombTranslate<=-2.2)
   {
       blastX=EnemybombTranslateX;
       blastY=EnemybombTranslate;
       bombBlast=1;
        EnemybombTranslateX=enemyTranslate;
        EnemybombTranslate=2.15;
    }
    if(enemyHeart<=0.7f&&enemyAttack2!=1)
    {
        enemyAttack2=1;
        glutTimerFunc(25, updateEnemyBomb, 0);
    }
    glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25,updateEnemyMainBomb, 0);
   }
}
void TranslateEnemyLeftRight(int value) {
	    _angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	if(Left==0)
    {
	enemyTranslate -= enemyTranslateSpeed;
	if (enemyTranslate <= -4.8)
	 {
            Left=1;
	 }
    }
    if(Left==1)
    {
	enemyTranslate += enemyTranslateSpeed;
	if (enemyTranslate > 4.7)
	 {
            Left=0;
	 }
    }
    if(enemyHeart<=0.9f&&enemyAttack1!=1)
    {
        enemyAttack1=1;
        EnemybombTranslateX=enemyTranslate;
        glutTimerFunc(25, updateEnemyMainBomb, 0);
    }
	glutPostRedisplay(); //Tell GLUT that the display has changed
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(enemyTranslateTimer, TranslateEnemyLeftRight, 0);
}
void MyKeyboardFunc(unsigned char Key, int x, int y)
{
switch(Key)
{
case 27:     // ESC key
         exit(0);
         break;
case 'f' :
    if(press==0)
    {
        cnt=1;
        press=1;
        glutTimerFunc(25, updateForLoadBomb, 0);
    }
    break;
default:
    break;
}
}
void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
                 1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
        glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
                 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth,windowHeight);
	glutInitWindowPosition (windowPosX, windowPosY);
	//Create the window
	glutCreateWindow("Kill The Enemy");
	//Set handler functions
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutReshapeFunc(handleResize);
    glutSpecialFunc(keyboard);
    glutKeyboardFunc(MyKeyboardFunc);
    glutFullScreen();
	glutTimerFunc(25, TranslateEnemyLeftRight, 0); //Add a timer
	glutMainLoop();
	return 0;
}
