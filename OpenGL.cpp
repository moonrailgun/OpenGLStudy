// OpenGL.cpp : 定义控制台应用程序的入口点。
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
	glClear(GL_COLOR_BUFFER_BIT);	//清除颜色

	glBegin(GL_POLYGON);
	for(i = 0;i<n;i++)
	{
		float x=R*cos(2*Pi/n*i),y = R*sin(2*Pi/n*i);
		glVertex2f(x, y);
		printf("绘制坐标[%d/%d](x:%f,y:%f)\n",i+1,n,x,y);
	}
	glEnd();
	printf("调试信息：已绘制完毕");

	//glRectf(-0.5f,-0.5f,0.5f,0.5f);	//画一个矩形
	glFlush();	//让前面的命令立即执行而不是在缓冲区，与fflush(stdout)作用类似
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);    //初始化glut,必须调用，复制黏贴这句话即可  
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //设置显示方式，RGB、单缓冲。当然还有GLUT_INDEX索引颜色 GLUT_DOUBLE双缓冲(Qt中看到过双缓冲)  
	glutInitWindowPosition(100,100);   //位置  
	glutInitWindowSize(400,400);//窗口大小  
	glutCreateWindow("OpenGL");  //创建窗口，设置标题  
	glutDisplayFunc(&myDisplay);  // 当绘制窗口时调用myDisplay，像Cocos2d-x刷帧Draw中的操作  
	glutMainLoop();  //消息循环  
	return 0;
}

