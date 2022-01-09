
#include "StdAfx.h"
#include"set.h"
#include<graphics.h>
#include<math.h>
#include<string.h>
#define PI                      3.1415926
#define EARTH_RADIUS            6378.137        //地球近似半径
#define magnify 75          //等示意图比例
#define sign '+'
traget own;



void into_ownwhere(traget ooo){//传入我方信息
	own=ooo;
}

//**************************************求距离模块******************************************************
// 求弧度
double radian(double d)
{
    return d * PI / 180.0;   //角度1˚ = π / 180
}
static double round(double r){
	return(r>0.0)?floor(r+0.5):ceil(r-0.5);
}

void done_faraway(traget* i)
{
    double radLat1 = radian(own.lat);
    double radLat2 = radian(i->lat);
    double a = radLat1 - radLat2;
    double b = radian(own.lng) - radian(i->lng);
    
    double dst = 2 * asin((sqrt(pow(sin(a / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2) )));
    
    dst = dst * EARTH_RADIUS;
    dst= round(dst * 10000) / 10000;

	i->far_away=dst;
}

//*******************************************************************************************************
void show_faraway(traget* i){
	if(i->far_away!=NULL){
        done_faraway(i);
		printf("\n\n%s更新：距离为%fkm(%f,%f)\n",i->name,i->far_away,i->lat,i->lng);
	}
	else{
		done_faraway(i);
		printf("\n\n%s的距离为%fkm(%f,%f)\n",i->name,i->far_away,i->lat,i->lng);
	}
}

void show_traget_where(traget* i){

	if(abs(long double(own.lat-i->lat))>=6||abs(long double(own.lng-i->lng)>=5));
	else{
		if(i->far_away!=NULL && i->far_away<100) //距离小于100画线
		{
		    settextcolor(LIGHTRED);
			setlinecolor(RED);
			if(i->lat-own.lat<0){
		    if(i->lng-own.lng>0)
				line(wide/2-4,high/2-2,int(wide/2-abs(long double(own.lat-i->lat))*magnify),int(high/2-abs(long double(own.lng-i->lng))*magnify));//第二象限
			if(i->lng-own.lng<0)
				line(wide/2-4,high/2-2,int(wide/2-abs(long double(own.lat-i->lat))*magnify),int(high/2+abs(long double(own.lng-i->lng))*magnify));//第三象限
		}
		if(i->lat-own.lat>0){
		    if(i->lng-own.lng>0)
				line(wide/2-4,high/2-2,int(wide/2+abs(long double(own.lat-i->lat))*magnify),int(high/2-abs(long double(own.lng-i->lng))*magnify));//第一象限
			if(i->lng-own.lng<0)
				line(wide/2-4,high/2-2,int(wide/2+abs(long double(own.lat-i->lat))*magnify),int(high/2+abs(long double(own.lng-i->lng))*magnify));//第四象限		    	
		}
		setlinecolor(GREEN);
		}

		//画点
		if(i->lat-own.lat<0){
		    if(i->lng-own.lng>0)
				outtextxy(int(wide/2-abs(long double(own.lat-i->lat))*magnify),int(high/2-abs(long double(own.lng-i->lng))*magnify),'+');//第二象限
			if(i->lng-own.lng<0)
				outtextxy(int(wide/2-abs(long double(own.lat-i->lat))*magnify),int(high/2+abs(long double(own.lng-i->lng))*magnify),'+');//第三象限
		}
		if(i->lat-own.lat>0){
		    if(i->lng-own.lng>0)
				outtextxy(int(wide/2+abs(long double(own.lat-i->lat))*magnify),int(high/2-abs(long double(own.lng-i->lng))*magnify),'+');//第一象限
			if(i->lng-own.lng<0)
				outtextxy(int(wide/2+abs(long double(own.lat-i->lat))*magnify),int(high/2+abs(long double(own.lng-i->lng))*magnify),'+');//第四象限
		}
		settextcolor(GREEN);
	}
}
void show_ownmessage(){
	TCHAR latt[16],lngg[16];
	_stprintf(latt, _T("%f"),own.lat);
	_stprintf(lngg, _T("%f"),own.lng);

	outtextxy(5,high-10,latt);
	outtextxy(100,high-10,lngg);
	/*
	char la[]=latt,lb=lngg;
	strcat(latt,",");
	settextcolor(BLUE);
	strcat(latt,lngg);

	RECT rect;
	rect.left=0;
	rect.top=0;
	rect.right=wide;
	rect.bottom=high-10;
	drawtext("abc',&rect,DT_SINGLELINE| DT_SINGLELINE);
	*/
}
void show_radar_line(){
	initgraph(wide+100, high+50,EW_SHOWCONSOLE);
	setlinecolor(GREEN);
	line(wide/2,0,wide/2,high);//竖线
	line(0,high/2,wide,high/2);//横线
    circle(wide/2, high/2, 300); // 画圆，圆心(400, 300)，半径 300
	circle(wide/2, high/2, 200);
	circle(wide/2, high/2, 100);
    settextcolor(GREEN);
	outtextxy(wide/2-4,high/2-2,'0');//原点
	outtextxy(wide/2,high/2-100,'1');
	outtextxy(wide/2,high/2-200,'2');
	outtextxy(wide/2,high/2-300,'3');
	
}
void showclean_target(traget* i){ 
	   settextcolor(BLACK);
	if(i->far_away!=NULL && i->far_away<100) //距离小于100画线
		{
			setlinecolor(BLACK);
	    if(i->lat-own.lat<0){
		    if(i->lng-own.lng>0)
				line(wide/2-4,high/2-2,int(wide/2-abs(long double(own.lat-i->lat))*magnify),int(high/2-abs(long double(own.lng-i->lng))*magnify));//第二象限
			if(i->lng-own.lng<0)
				line(wide/2-4,high/2-2,int(wide/2-abs(long double(own.lat-i->lat))*magnify),int(high/2+abs(long double(own.lng-i->lng))*magnify));//第三象限
		}
		if(i->lat-own.lat>0){
		    if(i->lng-own.lng>0)
				line(wide/2-4,high/2-2,int(wide/2+abs(long double(own.lat-i->lat))*magnify),int(high/2-abs(long double(own.lng-i->lng))*magnify));//第一象限
			if(i->lng-own.lng<0)
				line(wide/2-4,high/2-2,int(wide/2+abs(long double(own.lat-i->lat))*magnify),int(high/2+abs(long double(own.lng-i->lng))*magnify));//第四象限		    	
		}
		setlinecolor(GREEN);
		}
	   
	 if(i->lat-own.lat<0){
		    if(i->lng-own.lng>0)
				outtextxy(int(wide/2-abs(long double(own.lat-i->lat))*magnify),int(high/2-abs(long double(own.lng-i->lng))*magnify),'+');//第二象限
			if(i->lng-own.lng<0)
				outtextxy(int(wide/2-abs(long double(own.lat-i->lat))*magnify),int(high/2+abs(long double(own.lng-i->lng))*magnify),'+');//第三象限
		}
     if(i->lat-own.lat>0){
		    if(i->lng-own.lng>0)
				outtextxy(int(wide/2+abs(long double(own.lat-i->lat))*magnify),int(high/2-abs(long double(own.lng-i->lng))*magnify),'+');//第一象限
			if(i->lng-own.lng<0)
				outtextxy(int(wide/2+abs(long double(own.lat-i->lat))*magnify),int(high/2+abs(long double(own.lng-i->lng))*magnify),'+');//第四象限
		}
		settextcolor(GREEN);
}
int target_meet(traget* a,traget* b){
	if(a->lat==b->lat && a->lng==b->lng){
	return 1;
	}
	else return 0;
}
void clean_traget(traget* stack[100]){
	char name[10];
	printf("\n输入目标名称：");
	gets(name);
	for(int i=0;i<=100;i++){
		if(name==stack[i]->name)
		stack[i]=NULL;
		printf("清除成功\n");
		break;
	}
}
void create_traget(traget* stack[100]){
	traget a;
	int i=0;
	for(;;){
	if(stack[i] == NULL)break;
	else i++;
	}
	printf("\n输入目标经度：");
	scanf("%s",&a.lat);
	printf("\n输入目标纬度：");
	scanf("%s",&a.lng);
	printf("\n输入目标名称（推荐名称：test%d）：",i);
	scanf("%s",&a.name);
	stack[i]=&a;
	show_traget_where(stack[i]);
	done_faraway(stack[i]);
}