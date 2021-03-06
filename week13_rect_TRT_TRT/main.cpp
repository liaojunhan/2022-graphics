#include<GL/glut.h>
float angle=0,oldX=0;
void mouse(int button,int state,int x,int y)///mouse按下去
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.2);///身體,瘦身
    glPushMatrix();
        glTranslatef(0.3,0.5,0);
        glRotatef(angle,0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.8,0.3);///右上手臂
        glPushMatrix();
            glTranslatef(0.8,0.4,0);///把下手肘掛在關節
            glRotatef(angle,0,0,1);///旋轉
            glTranslatef(-0.8,-0.4,0);///把下手肘的旋轉中心放正中心
            glColor3f(0,1,0);///綠色
            glRectf(0.8,0.5,1.1,0.3);///再畫下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();///交換2倍的buffer
}
int main(int argc,char**argv)
{///進階的main函式
    glutInit(&argc,argv);///初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///兩倍+3D
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");///建視窗
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);///今天用來畫圖的函式
    glutMainLoop();///主要迴圈
    return 0;
}
