//ring_buffer.c
#include "ring_buffer.h"

//返回当前可写入的位置
int32_t rb_w_get( rb_h_t *rb_h )
{
	uint32_t s=rb_h->s-1;
	if(((rb_h->i+1)&s)==(rb_h->o&s))
	{
		return -1;//no buffer space
	}
	else
	{
		return (int32_t)rb_h->i;
	}
}
//返回当前可读的位置
int32_t rb_r_get(rb_h_t *rb_h )
{
	if(rb_h->o==rb_h->i)
	{
		return -1;
	}
	else
	{
		return rb_h->o;
	}
}

int32_t rb_w_push(rb_h_t *rb_h)
{
	uint32_t s=rb_h->s-1;
	if(((rb_h->i+1)&s)==(rb_h->o&s))
	{
		return -1;
	}
	
	rb_h->i=(rb_h->i+1)&s;//i++
	return rb_h->i;
}
int32_t rb_r_pop(rb_h_t *rb_h)
{
	uint32_t s=rb_h->s-1;
	if(rb_h->o!=rb_h->i)
	{
		rb_h->o=(rb_h->o+1)&s;
		return rb_h->o;
	}
	else
	{
		return -1;
	}
}

void rb_clear(rb_h_t *rb_h)
{
	rb_h->o=rb_h->i;
}

/*
*nb_ploy:
*/
void rb_init(rb_h_t *rb_h,uint32_t nb_ploy)
{
	rb_h->o=rb_h->i=0;
	rb_h->s=nb_ploy;
}

/*
*根据rb头和index过去负载首地址
* rb_h:指针
* ploy_t :负载类型
* index: 负载数组序号
*/
#define rb_get_array(rb_h,ploy_t,index) ( ( (ploy_t *)(((uint8_t *)(&((rb_h)->end__)))+sizeof(((rb_h)->end__)))) +index)

struct 
{
	rb_h_t h;
	uint8_t ploy[4];
	
}rb_test_val;

void rb_test_fun(void)
{
	uint32_t i,j;
	
	uint8_t *p;
	rb_init(&rb_test_val.h,sizeof(rb_test_val.ploy)/sizeof(rb_test_val.ploy[0]));
	for(j=0;j<3;j++)
	{
		i=rb_w_get(&rb_test_val.h);
		if(j!=i)
		{
			while(1);//错误
		}
		p=rb_get_array( &rb_test_val.h,uint8_t,i);
		*p=((j+1)<<4)|i;
		if( (((j+1)<<4)|i)!=rb_test_val.ploy[j])
		{
			while(1);
		}
		rb_w_push(&rb_test_val.h);
		
	}

	for(j=0;j<3;j++)
	{
		i=rb_r_get(&rb_test_val.h);
		if(j!=i)
		{
			while(1);//错误
		}
		p=rb_get_array( &rb_test_val.h,uint8_t,i);
		if( (((j+1)<<4)|i)!=*p)
		{
			while(1);
		}
		rb_r_pop(&rb_test_val.h);
		
	}

	
	
}


