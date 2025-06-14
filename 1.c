#include<math.h>
#include<stdio.h>
#include<GL/glut.h>
int x1, y11, x2, y2,dx,dy;
void display();
void init();
void bresenhams(int,int,int,int);
void main(int argc,char**argv)
{
glutInit(&argc,argv);
printf("enter the end points of the line");
scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
glutCreateWindow("Bresenhams Line Drawing");
init();
glutDisplayFunc(display);
glutMainLoop();
}
void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500, 500, -500, 500);
glMatrixMode(GL_MODELVIEW);
}
void display()
{
glClearColor(1, 1, 1, 0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1, 0, 0);
bresenhams(x1, y11, x2, y2);
glFlush();
}
void plotline(int x, int y)
{
glPointSize(2);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
}
void bresenhams(int x1, int y11, int x2, int y2)
{
int dx, dy,pk,xinc,yinc,x,y;
dx = x2 - x1;
dy = y2 - y11;
x = x1, y = y11;
plotline(x, y);
if (dx > 0)
xinc = 1;
else
xinc = -1;
if (dy > 0)
yinc = 1;
else
yinc = -1;
if (fabs(dx) > fabs(dy))
{
pk = 2 * fabs(dy) - fabs(dx);
for (int i = 0; i <= fabs(dx) - 1; i++)
{
if (pk > 0)
{
pk = pk + 2 * fabs(dy) - 2 * fabs(dx);
y = y+yinc;
}
else
{
pk = pk + 2 * fabs(dy);
y = y;
}
x = x + xinc;
plotline(x, y);
}
}
else
{
pk = 2 * fabs(dx) - fabs(dy);
for (int i = 0; i <= fabs(dy) - 1; i++)
{
if (pk > 0)
{
pk = pk + 2 * fabs(dx) - 2 * fabs(dy);
x = x + xinc;
}
else
{
pk = pk + 2 * fabs(dx);
x = x;
}
y = y + yinc;
plotline(x, y);
}
}
}
STEPS TO EXECUTE
1 gedit bresen.c
2 gcc bresen.c -lGL -lGLU -lglut
3 ./a.out
