typedef struct
{
	char *ch;	//若是非空串，则按长分配存储区，否则 ch 为NULL
	int length;	//串长度 
} HString;
