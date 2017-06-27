//ring_buffer.h
#ifndef __RING_BUFFER__H_
#define __RING_BUFFER__H_

#ifdef __cplusplus
 extern "C" {
#endif


#include <stdint.h>
#define __rb_packet  __attribute__((__packed__))
/*
* 使用注意事项:
* 
*/


 typedef  struct 
{
	uint32_t  i;
	uint32_t  o;
	uint32_t  s;//rb管理的容量
	/*扩展...*/
	
	void *  end__;//结束
}__rb_packet rb_h_t;



//返回当前可写入的位置
int32_t rb_w_get( rb_h_t *rb_h );
//写队列入栈
int32_t rb_w_push(rb_h_t *rb_h);


//返回当前可读的位置
int32_t rb_r_get(rb_h_t *rb_h );

//读队列出栈
int32_t rb_r_pop(rb_h_t *rb_h);

//清空读写队列,操作时需要加锁
void rb_clear(rb_h_t *rb_h);


/*
*nb_ploy:负载数组有多少个负载,不是负载数组按byte的长度
*/
void rb_init(rb_h_t *rb_h,uint32_t nb_ploy);


/*
*根据rb头和index过去负载首地址
* rb_h:指针
* ploy_t :负载类型
* index: 负载数组序号
*/
#define rb_get_array(rb_h,ploy_t,index) ( ( (ploy_t *)(((uint8_t *)(&((rb_h)->end__)))+sizeof(((rb_h)->end__)))) +index)

#ifdef __cplusplus
 }
#endif

#endif

