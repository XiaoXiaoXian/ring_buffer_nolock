//ring_buffer.h
#ifndef __RING_BUFFER__H_
#define __RING_BUFFER__H_

#ifdef __cplusplus
 extern "C" {
#endif


#include <stdint.h>
#define __rb_packet  __attribute__((__packed__))
/*
* ʹ��ע������:
* 
*/


 typedef  struct 
{
	uint32_t  i;
	uint32_t  o;
	uint32_t  s;//rb���������
	/*��չ...*/
	
	void *  end__;//����
}__rb_packet rb_h_t;



//���ص�ǰ��д���λ��
int32_t rb_w_get( rb_h_t *rb_h );
//д������ջ
int32_t rb_w_push(rb_h_t *rb_h);


//���ص�ǰ�ɶ���λ��
int32_t rb_r_get(rb_h_t *rb_h );

//�����г�ջ
int32_t rb_r_pop(rb_h_t *rb_h);

//��ն�д����,����ʱ��Ҫ����
void rb_clear(rb_h_t *rb_h);


/*
*nb_ploy:���������ж��ٸ�����,���Ǹ������鰴byte�ĳ���
*/
void rb_init(rb_h_t *rb_h,uint32_t nb_ploy);


/*
*����rbͷ��index��ȥ�����׵�ַ
* rb_h:ָ��
* ploy_t :��������
* index: �����������
*/
#define rb_get_array(rb_h,ploy_t,index) ( ( (ploy_t *)(((uint8_t *)(&((rb_h)->end__)))+sizeof(((rb_h)->end__)))) +index)

#ifdef __cplusplus
 }
#endif

#endif

