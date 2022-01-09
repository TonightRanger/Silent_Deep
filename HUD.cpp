#include "stdafx.h"
#include<graphics.h>
#include<process.h>
#include<Windows.h>
#include"SETHUD.h"

struct wlin obb[36];

void show_basic_line(){
	initgraph(wide, high+50,EW_SHOWCONSOLE);
	setlinecolor(GREEN);
#define smc 5//小圆圆心
	circle(wide/2, high/2, smc);
	line(wide/2,high/2,wide/2+smc*4,high/2);
	line(wide/2,high/2,wide/2,high/2-smc*2);
	line(wide/2,high/2,wide/2,high/2+smc*2);
	line(wide/2,high/2,wide/2-smc*4,high/2);
	

	line(0,high/2-100,int(wide/3),high/2-100);//横线
	line(int(wide/3*2),high/2-100,wide,high/2-100);

	line(0,high/2-200,int(wide/3),high/2-200);
	line(int(wide/3*2),high/2-200,wide,high/2-200);

	line(0,high/2-300,int(wide/3),high/2-300);
	line(int(wide/3*2),high/2-300,wide,high/2-300);

	line(0,high/2,int(wide/3),high/2);
	line(int(wide/3*2),high/2,wide,high/2);

	line(0,high/2+100,int(wide/3),high/2+100);
	line(int(wide/3*2),high/2+100,wide,high/2+100);

	line(0,high/2+200,int(wide/3),high/2+200);
	line(int(wide/3*2),high/2+200,wide,high/2+200);

	line(0,high/2+300,int(wide/3),high/2+300);
	line(int(wide/3*2),high/2+300,wide,high/2+300);
	Sleep(5000);
}
void show__line(wlin wlin){//注意：这个没有设置颜色，[don't like set.h->show_traget_where(traget* i);]
	TCHAR la[5];
	_stprintf(la, _T("%d"),wlin.num);

	if(wlin.thigh<high+50&&wlin.thigh>0){
	line(0,wlin.thigh,int(wide/3),wlin.thigh);
	line(int(wide/3*2),wlin.thigh,wide,wlin.thigh);
	outtextxy(0,wlin.thigh,la);
	outtextxy(wide,wlin.thigh,la);
	}
}
void clean__line(wlin wlin){//清除线
	setlinecolor(BLACK);
	settextcolor(BLACK);
	show__line(wlin);
	setlinecolor(GREEN);
	settextcolor(GREEN);
}





void abc(){
	for(int i=0;i<36;++i){
		 clean__line(obb[i]);
		 obb[i].thigh-=1;
		 show__line(obb[i]);
	}
}
void add(){
	
for(int j=0;j<2700;j++){
	for(int i=0;i<18;++i){
		 clean__line(obb[i]);
		 obb[i].thigh+=1;
		 show__line(obb[i]);
		 Sleep(0.5);
	};//这条单独运行可以
}
Sleep(10);
for(int j=0;j<2700;j++){
    for(int i=0;i<36;++i){
		 clean__line(obb[i]);
		 obb[i].thigh-=1;
		 show__line(obb[i]);
		 Sleep(0.5);
	}
}
}
VOID T_main(){

	initgraph(wide+200, high+50,EW_SHOWCONSOLE);

	for(int i=0;i<36;++i){//生成36个线结构
		if(i<=18){
	       obb[i].num=i*5;
		   obb[i].thigh=high/2-i*150;
		}
		else{
			obb[i].num=(i-18)*5*-1;
		    obb[i].thigh=high/2+(i-18)*150;
		}
	    }

	setlinecolor(GREEN);
	settextcolor(GREEN);
	outtextxy(wide/2,high/2,'W');

	DWORD thrdID0, thrdID1;
	//CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)abc,NULL,0,&thrdID0);
	
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)add,NULL,0,&thrdID1);
    for(;;);
}