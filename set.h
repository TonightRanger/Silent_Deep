/* an free vacation~~~ */

#pragma once
#ifndef SET_H
#define SET_H
#endif

extern "C" {

	#define wide 800//��Կ�
    #define high 600//��Ը�

struct me{
	char *lat;
	char *lng;
};

struct traget{
	char *name;
	double lat;//����
	double lng;//γ��
	double far_away;
};

void into_ownwhere(traget ooo);//�����ҷ�����

void show_radar_line();//����ͼ��

void show_faraway(traget* i);//��ʾ����

void done_faraway(traget* i);//�������

void show_traget_where(traget* i);//��ʾĿ��

void showclean_target(traget* i);//����Ŀ������Ļ�ϵ���ʾ

void show_ownmessage();//��ʾ�ҷ�����

int target_meet(traget* a,traget* b);//�ж���Ŀ���Ƿ�����

void create_traget(traget* stack[100]);//����Ŀ��
void clean_traget(traget* stack[100]);//���Ŀ��
}