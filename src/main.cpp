#include "server.h"
#include "unistd.h" 

#include "json.h"

void signal_cb(evutil_socket_t sig, short events, void *user_data)
{
	 log_out("hello  my cb .....")
}

int main()
{
	server my_server(6666,"192.168.88.49",AF_INET);
	/*while (1)
	{
		sleep(2);
		log_out("hello ....   ");
	}*/
}
