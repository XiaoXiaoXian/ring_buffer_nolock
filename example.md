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
