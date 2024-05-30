/*
 * lwip.c
 *
 *  Created on: May 28, 2024
 *      Author: 김유민
 */


#include "lwip/api.h"
#include "lwip/netdb.h"
#include "lwip/sockets.h"

void http_get_request(const char *server, const char *path) {
    struct netconn *conn;
    struct netbuf *buf;
    err_t err;
    ip_addr_t server_ip;

    // DNS resolution
    err = netconn_gethostbyname(server, &server_ip);
    if (err != ERR_OK) {
        printf("DNS resolution failed: %d\n", err);
        return;
    }

    // Create a new connection
    conn = netconn_new(NETCONN_TCP);
    if (conn == NULL) {
        printf("Failed to create connection\n");
        return;
    }

    // Connect to the server
    err = netconn_connect(conn, &server_ip, 80);
    if (err != ERR_OK) {
        printf("Failed to connect to server: %d\n", err);
        netconn_delete(conn);
        return;
    }

    // Create the GET request
    char request[256];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n",
             path, server);

    // Send the GET request
    err = netconn_write(conn, request, strlen(request), NETCONN_COPY);
    if (err != ERR_OK) {
        printf("Failed to send request: %d\n", err);
        netconn_close(conn);
        netconn_delete(conn);
        return;
    }

    // Read the response
    while ((err = netconn_recv(conn, &buf)) == ERR_OK) {
        do {
            char *data;
            u16_t len;
            netbuf_data(buf, (void**)&data, &len);
            printf("Received: %.*s\n", len, data);
        } while (netbuf_next(buf) >= 0);
        netbuf_delete(buf);
    }

    // Close the connection and cleanup
    netconn_close(conn);
    netconn_delete(conn);
}
