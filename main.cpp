/**
 * Lisence MIT.
 * Made by @SaitamaSama [https://github.com/SaitamaSama].
 * Distribution of this application is allowed, although
 * upon distribution kindly do mention the author.
 */
// See: https://stackoverflow.com/a/37435682/4332216
#define _BSD_SOURCE
#include "Server.h"

int main () {
  std::ifstream ifs("Resources/file.html");
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
  Server server(content);
  server.start();
}
