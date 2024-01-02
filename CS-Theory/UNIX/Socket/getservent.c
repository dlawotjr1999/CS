#include <netdb.h>
#include <stdio.h>

int main(void)
{
	struct servent *port;
	int n;

	setservent(0);

	while((port = getservent()) != NULL)
		printf("Name = %s, Port = %d\n", port->s_name, port->s_port);
	endservent();
}
