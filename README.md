a very small http server with routing

need to add:

	[x] a new routing function
	
	[?] simple html page generation (new project)
	
todo:

    [x] fix httpserver - add router functionality
    
    [x] make router module
    
    [x] test httpserver
    
    [x] append file types dynamically
    
    [] get address/port from user input
    
    [x] why is the server so slow for mobile requests? Is the socket being blocked for ~15s while reading? 

	(thread pool should help soon)
	 
    [] move to thread pool

	[] write bindings to thread pool

	[] figure out how to send a c style function pointer from scheme
