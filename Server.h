/**
 * Lisence MIT.
 * Made by @SaitamaSama [https://github.com/SaitamaSama].
 * Distribution of this application is allowed, although
 * upon distribution kindly do mention the author.
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fstream>
#include <sstream>
#include <regex>

typedef sockaddr_in sockaddr_in_t;
typedef sockaddr sockaddr_t;


class Server {
private:
  int socketfd, newsocketfd, port;
  socklen_t remote_addr_length;
  char buffer[1024];
  sockaddr_in_t serv_addr, remote_addr;
  std::string _file_content;

  std::string replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    return str.replace(start_pos, from.length(), to);
  }

  void err(std::string message) {
    std::cout << message << "\n";
    close(socketfd);
    exit(1);
  }

public:
  Server(std::string static_file_content) {
    _file_content = static_file_content;

    socketfd =  socket(AF_INET, SOCK_STREAM, 0);

    if(socketfd < 0) {
      err("Error creating INET socket.");
      memset(&serv_addr, 0, sizeof(serv_addr));
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    int bind_result = bind(socketfd, (sockaddr_t *) &serv_addr, sizeof(serv_addr));

    if(bind_result < 0) {
      err("Error binding address to socket.");
    }
  }

  void start() {
    listen(socketfd, 2);
    do {
      remote_addr_length = sizeof(remote_addr);

      memset(&newsocketfd, 0, sizeof(newsocketfd));

      newsocketfd = accept(socketfd, (sockaddr_t *) &remote_addr, &remote_addr_length);

      if(newsocketfd < 0) {
        err("Error accepting incoming request");
      }

      // Let's log an incoming request.
      printf("Incoming Request From %s:%d\n",
        inet_ntoa(remote_addr.sin_addr),
        htons(remote_addr.sin_port)
      );

      memset(&buffer, 0, sizeof(buffer));

      int read_result = read(newsocketfd, buffer, 1023);

      if(read_result < 0) {
        err("Error reading data from remote.");
      }

      printf("Incoming Headers: %s\n", buffer);

      // We shall send just a static file for now...
      std::string response("HTTP/1.1 200 OK\r\nContent-Length: "
        + std::to_string(strlen(_file_content.c_str()))
        + "\r\nX-Server: Ayozawa-1.0\r\n\r\n"
        + _file_content
      );
      send(newsocketfd, response.c_str(), response.length(), 0);

      close(newsocketfd);
    } while (1);
  }
};
