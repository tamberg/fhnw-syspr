#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>

#define BUF_SIZE 1024
#define BACKLOG 5

int main(void) {
    printf("main\n");
    struct sockaddr_in addr;
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    printf("addr\n");
    char *host = "0.0.0.0"; // any
    int port = 8080;
    struct in_addr ip_addr;
    if (inet_pton(AF_INET, host, &ip_addr) != 1) {
        perror("inet_pton");
        exit(-1);
    }
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = ip_addr;

    printf("bind\n");
    if (bind(server_sock, (struct sockaddr *) &addr, sizeof(struct sockaddr_in)) == -1) {
        perror("bind");
        exit(-1);
    }

    printf("listen\n");
    if (listen(server_sock, BACKLOG) == -1) {
        perror("listen");
        exit(-1);
    }

    for (;;) {
        printf("accept\n");
        int client_sock = accept(server_sock, NULL, NULL);
        if (client_sock == -1) {
            perror("accept");
            exit(-1);
        }

        printf("recv request\n");
        // read HTTP request
        //    "GET /syspr HTTP/1.1\r\n"
        //    "Host: 127.0.0.1\r\n"
        //    "Connection: close\r\n"
        //    "\r\n";
        
        //char request_buf[BUF_SIZE];
        //int bytes_read = recv(client_sock, request_buf, BUF_SIZE, 0);
        //while (bytes_read > 0) {
        //    printf("read %d bytes\n", bytes_read);
        //    write(STDOUT_FILENO, request_buf, bytes_read);
        //    bytes_read = recv(client_sock, request_buf, BUF_SIZE, 0);
        //}

        const int INIT = 0;
        const int CR = 1;
        const int CRLF = 2;
        const int CRLFCR = 3;
        const int CRLFCRLF = 4;

        int state = INIT;

        char request_buf[1];
        int bytes_read = recv(client_sock, request_buf, 1, 0);
        while ((state != CRLFCRLF) && (bytes_read == 1)) {
            if ((state == INIT) && (request_buf[0] == '\r')) {
                state = CR;
            } else if ((state == CR) && (request_buf[0] == '\n')) {
                state = CRLF;
            } else if ((state == CR) && (request_buf[0] != '\n')) {
                state = INIT;
            } else if ((state == CRLF) && (request_buf[0] == '\r')) {
                state = CRLFCR;
            } else if ((state == CRLF) && (request_buf[0] != '\r')) {
                state = INIT;
            } else if ((state == CRLFCR) && (request_buf[0] == '\n')) {
                state = CRLFCRLF;
            } else if ((state == CRLFCR) && (request_buf[0] != '\n')) {
                state = INIT;
            }
            if (state != CRLFCRLF) {
                bytes_read = recv(client_sock, request_buf, 1, 0);
            }
        }

        printf("send response\n");
        // send HTTP response
        char response_buf[] =
            "HTTP/1.1 200 OK\r\n"
            "Connection: close\r\n"
            "Content-Length: 5\r\n"
            "\r\n"
            "hello";
        size_t size = sizeof(response_buf) / sizeof(response_buf[0]);
        int bytes_written = send(client_sock, response_buf, size, 0);
        if (bytes_written == -1) {
            perror("send");
            exit(-1);
        }
        printf("wrote %d bytes\n", bytes_written);

        printf("close\n");
        close(client_sock);
        printf("closed\n");

    }
    return 0;
}
