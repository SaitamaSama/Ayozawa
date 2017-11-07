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
#include "Server.h"

int main () {
  Server server("name");
  server.do_something();
}
