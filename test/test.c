#include "op_epoll.h"

void handle(void * clisockfd)
{	
	char line[255] = {0};

	int n = op_read(clisockfd, line, 255);
	if(n<-1)
	{
		return;
	}	
	n = op_write(clisockfd, line, strlen(line));
	if(n < -1)
	{
		return;
	}	
	memset(line, 0, 255);
}

int main()
{

	start_server("0.0.0.0", 8001);

	return 0;
}