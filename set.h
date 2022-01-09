/* an free vacation~~~ */

#pragma once
#ifndef SET_H
#define SET_H
#endif

extern "C" {

	#define wide 800//相对宽
    #define high 600//相对高

struct me{
	char *lat;
	char *lng;
};

struct traget{
	char *name;
	double lat;//经度
	double lng;//纬度
	double far_away;
};

void into_ownwhere(traget ooo);//传入我方坐标

void show_radar_line();//基础图形

void show_faraway(traget* i);//显示距离

void done_faraway(traget* i);//计算距离

void show_traget_where(traget* i);//显示目标

void showclean_target(traget* i);//擦除目标在屏幕上的显示

void show_ownmessage();//显示我方坐标

int target_meet(traget* a,traget* b);//判断两目标是否相遇

void create_traget(traget* stack[100]);//创建目标
void clean_traget(traget* stack[100]);//清除目标
}