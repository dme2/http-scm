a very small http server with routing

build with
	csc httpserv.scm
	./httpserv

need to add:

	[x] a new routing function

	[?] simple html page generation (new project)

todo:

    [x] fix httpserver - add router functionality

    [x] make router module

    [x] test httpserver

    [x] append file types dynamically

    [x] why is the server so slow for mobile requests? Is the socket being blocked for ~15s while reading?

    [x] kill PIDS marked DONE

	[] wrap exit()
