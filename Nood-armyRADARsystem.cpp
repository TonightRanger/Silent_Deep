// Nood-armyRADARsystem.cpp : �������̨Ӧ�ó������ڵ㡣
//
/* ��ɫ
#define	BLACK			0
#define	BLUE			0xAA0000
#define	GREEN			0x00AA00
#define	CYAN			0xAAAA00
#define	RED				0x0000AA
#define	MAGENTA			0xAA00AA
#define	BROWN			0x0055AA
#define	LIGHTGRAY		0xAAAAAA
#define	DARKGRAY		0x555555
#define	LIGHTBLUE		0xFF5555
#define	LIGHTGREEN		0x55FF55
#define	LIGHTCYAN		0xFFFF55
#define	LIGHTRED		0x5555FF
#define	LIGHTMAGENTA	0xFF55FF
#define	YELLOW			0x55FFFF
#define	WHITE			0xFFFFFF
*/

#include "stdafx.h"
#include<graphics.h>
#include<process.h>
#include<Windows.h>
#include"set.h"

traget* stack[100];//����ɸ���ŵ�ջ
traget* stac;//����ָ��
traget test,test2,test3;//����Ŀ�꣨������ʵĿ�꣩
traget ownn;//�ҷ���Ϣ
DWORD thrdID0, thrdID1;

void import(){
	show_ownmessage();
	show_faraway(stack[1]);
	show_faraway(stack[2]);
	show_faraway(stack[3]);
	show_traget_where(stack[1]);
	show_traget_where(stack[2]);
	show_traget_where(stack[3]);
	//showclean_target(stack[2]);	
}
void move_ownner(){
	for(;;){
	showclean_target(stack[1]);
	showclean_target(stack[2]);
	showclean_target(stack[3]);
	//if(stac)
	//showclean_target(stac);

    show_faraway(stack[1]);
	show_faraway(stack[2]);
	show_faraway(stack[3]);
	//if(stac)
	//show_faraway(stac);

	ownn.lng+=0.01;
	into_ownwhere(ownn);
	//ownn.lat-=0.1;
	show_ownmessage();

	printf("==================================\n");
	//if(stac)
	//show_traget_where(stac);
	show_traget_where(stack[1]);
	show_traget_where(stack[2]);
	show_traget_where(stack[3]);
	stack[0]=&ownn;//stack0Ϊ�ҷ���Ϣ
	Sleep(500);
	}
}
void woe(){
	for(;;){
	Sleep(100);
    show_radar_line();
	}
}
void wee(){//ģ�⵼��
	for(;;){
	showclean_target(stac);
	printf("===============\n");
	show_faraway(stac);
	stac->lat+=0.01;
	stac->lng+=0.005;
	show_traget_where(stac);
	Sleep(500);
	}
}

void move_test(){
	for(;;){
	showclean_target(stack[1]);
    Sleep(20);
	test.lat-=0.1;
    test.lng-=0.001;
	stack[1]=&test;
	show_faraway(stack[1]);
	show_traget_where(stack[1]);
	Sleep(500);
	}
}
void move_test3(){
	for(;;){
	showclean_target(stack[3]);
	test3.lat+=0.1;
    //test3.lng-=1;
	stack[3]=&test3;
	show_faraway(stack[3]);
	show_traget_where(stack[3]);
	Sleep(500);
	}
}
void sf(){
	for(;;){
	show_ownmessage();
	for(int i=0;i<=100;i++){
		if(stack[i] != NULL){
			done_faraway(stack[i]);
		}
	else i++;
	}
	}
}
void watch(){
	for(;;){
	show_ownmessage();
	for(int i=0;i<=100;i++){
		if(stack[i] != NULL){
			show_traget_where(stack[i]);
		}
	else i++;
	}
	}//go wrong
}
void conturl_NoodarmyRADARsystem(){
	char buf[700],ch[5];
	int len;
	FILE *fp;
	if(fp=fopen("zlt.txt","r"));else{printf("���ļ�ʧ��\n");}
	system("cls");
	while(fgets(buf,700,fp)!=NULL){
	len=strlen(buf);
	buf[len-1]='\0';
	printf("%s\n",buf);
	}
	for(;;){
	printf("����ִ��ָ��:");
	gets(ch);
	

	if(ch[0]=='o'){//��ʾ��ͼ o s
		show_radar_line();
		CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)watch,NULL,0,&thrdID1);
	}
	if(ch[0]=='c'){
		if(ch[1]=='t')clean_traget(stack);//���Ŀ�� c t
		if(ch[1]=='s')closegraph();//�ر�ʾ��ͼ c s
	}
	if(ch[0]=='b')create_traget(stack);//���Ŀ�� b t
	if(ch[0]=='s'){
		if(ch[1]=='f')CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)sf,NULL,0,&thrdID0);
		if(ch[1]=='t'){
			if(ch[2]=='v');//����Ŀ���ٶ� s t v
			if(ch[2]=='h');//����Ŀ�귽�� s t h
	    }
	}
	if(ch[0]=='e')system("exit");//�˳� e 
}
}
int tmain(int argc, _TCHAR* argv[])
{  
	test.lat=116.3945;
	test.lng=39.9045;
	test.name="test";
	stack[1]=&test;

	test2.lat=117.3245;
	test2.lng=37.905;
	test2.name="test2";
	stack[2]=&test2;

	test3.lat=118.3265;
	test3.lng=40.955;
	test3.name="test3";
	stack[3]=&test3;

    //�ҷ�λ��
	
    ownn.lat=116.68930;
    ownn.lng=39.15184;
	stack[0]=&ownn;//stack0Ϊ�ҷ���Ϣ
    into_ownwhere(ownn);
//   
//***********************************************************************************
//
	DWORD thrdID0, thrdID1;
	
	
	import();
    Sleep(1000);
	//CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)move_test3,NULL,0,&thrdID0);
	//CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)move_test,NULL,0,&thrdID0);
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)move_ownner,NULL,0,&thrdID0);
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)woe,NULL,0,&thrdID0);
	Sleep(1000);
	traget ui;
	ui=ownn;
	stac=&ui;
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)wee,NULL,0,&thrdID0);
	getchar();
	/*char as[20];
	printf("shil");
	getchar();
	gets(as);
	if(as!=NULL)
		
	
	
	*/return 0;
}
void main(){
	
	CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)conturl_NoodarmyRADARsystem,NULL,0,&thrdID0);
	for(;;);

}