<h2>MultiCast program, HOW TO RUN ONLINE AND OFFLINE?</h2>
<h4>This program works only when the system is connected to the internet.</h4>
<h4>First start the client side and then the server side.</h4>
<h4>To run the program offline replace</h4>
  ```groupSock.sin_addr.s_addr=inet_addr("226.1.1.1");```** with ** ```groupSock.sin_addr.s_addr=inet_addr("127.0.0.1");```
<h4>in both the files i.e client and in server.c .</h4>
