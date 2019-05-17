<h2>MultiCast program, HOW TO RUN ONLINE AND OFFLINE?</h2>
<h3>This program works only when the system is connected to the internet.</h3>
<h3>First start the client side and then the server side.</h3>
<h3>To run the program offline replace ```groupSock.sin_addr.s_addr=inet_addr("226.1.1.1");``` with ```groupSock.sin_addr.s_addr=inet_addr("127.0.0.1");``` in both the files i.e client and in server.c .
