# Ayozawa

To compile do:

```
$ g++ -std=c++11 -O3 main.cpp -o server.o
```

Start the executable with:

```
$ ./server.o
```

By default, it uses the port `8080`.

Now, open the browser and send a request to http://localhost:8080
You should be able to now see the sample page!

Uses the following headers:

 - `<iostream>`
 - `<stdio.h>`
 - `<stdlib.h>`
 - `<string.h>`
 - `<unistd.h>`
 - `<sys/types.h>`
 - `<sys/socket.h>`
 - `<netinet/in.h>`
 - `<arpa/inet.h>`
 - `<fstream>`
 - `<sstream>`
 - `<regex>`

### NOTE:
> This is \*nix only, since it uses sockets. To use in windows, it must be ported. :-)
