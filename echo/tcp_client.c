#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFSIZE 8192

int main(int argc, char** argv)
{
	int sock;
	char buf[BUFSIZE];
	int len;
	struct sockaddr_in server_addr;

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		printf("sock() error\n");
		return 0;
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(7905);

	if (connect(sock,
				(struct sockaddr*)&server_addr,
				sizeof(server_addr)) == -1) {
		printf("connect() error\n");
		return 0;
	}

	while (1) {

		printf("Input Data: ");
		fgets(buf, BUFSIZE, stdin);

		write(sock, buf, strlen(buf));

		len = read(sock, buf, BUFSIZE-1);
		buf[len] = '\0';
		printf("read(%d:%s)\n", len, buf);
	}

	close(sock);

	return 0;
}

