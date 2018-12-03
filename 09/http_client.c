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

int main(void) {
    struct sockaddr_in addr;
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);

    // ping tmb.gr => IP address
    char *host = "52.218.49.114";
    struct in_addr dst_ip_addr;
    int result = inet_pton(AF_INET, host, &dst_ip_addr);
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = dst_ip_addr;
    printf("inet_pton result = %d\n", result);

    result = connect(
        client_sock,
        (struct sockaddr *) &addr,
        sizeof(struct sockaddr_in));
    printf("result = %d\n", result);

    // send HTTP request
    char request_buf[] =
        "GET /syspr HTTP/1.1\r\n"
        "Host: tmb.gr\r\n"
        "Connection: close\r\n"
        "\r\n";
    size_t size = sizeof(request_buf) / sizeof(request_buf[0]);
    int bytes_written = send(client_sock, request_buf, size, 0);
    if (bytes_written == -1) {
        perror("send");
        exit(-1);
    }
    printf("wrote %d bytes\n", bytes_written);

    // read HTTP response
    char response_buf[BUF_SIZE];
    int bytes_read = recv(client_sock, response_buf, BUF_SIZE, 0);
    while (bytes_read > 0) {
        printf("read %d bytes\n", bytes_read);
        write(STDOUT_FILENO, response_buf, bytes_read);
        bytes_read = recv(client_sock, response_buf, BUF_SIZE, 0);
    }
    close(client_sock);
    printf("closed\n");
    return 0;
}
