#pragma once
#include<mytypes.h>
#include<stdio.h>

struct Vec2
{
	i16 x=0,y=0;
	Vec2():x(0),y(0)
	{
	
	}	
	
	Vec2(i16 fx,i16 fy):x(fx),y(fy)
	{
		
	}
	void print()
	{
		printf("x is %d,y is %d.\n",x,y);	
	}
};
