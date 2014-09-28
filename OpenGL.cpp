// OpenGL.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<gl/glut.h>
#include<math.h>

const int n = 32;
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536f;

void myDisplay(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);	//�����ɫ

	glBegin(GL_POLYGON);
	for(i = 0;i<n;i++)
	{
		float x=R*cos(2*Pi/n*i),y = R*sin(2*Pi/n*i);
		glVertex2f(x, y);
		printf("��������[%d/%d](x:%f,y:%f)\n",i+1,n,x,y);
	}
	glEnd();
	printf("������Ϣ���ѻ������");

	//glRectf(-0.5f,-0.5f,0.5f,0.5f);	//��һ������
	glFlush();	//��ǰ�����������ִ�ж������ڻ���������fflush(stdout)��������
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);    //��ʼ��glut,������ã����������仰����  
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //������ʾ��ʽ��RGB�������塣��Ȼ����GLUT_INDEX������ɫ GLUT_DOUBLE˫����(Qt�п�����˫����)  
	glutInitWindowPosition(100,100);   //λ��  
	glutInitWindowSize(400,400);//���ڴ�С  
	glutCreateWindow("OpenGL");  //�������ڣ����ñ���  
	glutDisplayFunc(&myDisplay);  // �����ƴ���ʱ����myDisplay����Cocos2d-xˢ֡Draw�еĲ���  
	glutMainLoop();  //��Ϣѭ��  
	return 0;
}

