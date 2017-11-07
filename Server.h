class Server {
private:
  int socketfd, newsocketfd, port;
  socklen_t cl;
  char buffer[1024];
public:
  void Server(string stroke) {
    std::cout << stroke << "\n";
  }
};
