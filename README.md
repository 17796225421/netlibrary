# ping_pong测试

## 测试前须知

我的电脑是6核12线程，可以客户端服务器各跑6个线程。必须要跑满CPU，否则不同网络库CPU利用率不相同，将会带来系统误差。在跑满CPU的前提下，比较吞吐量（每秒传输的数据量）。

参与测试的网络库：

libevent、libev、libuv、libhv、asio、poco、netlibrary。

## 测试一

Running 10s test @ 127.0.0.1:2002
4 threads and 100 connections, send 1024 bytes each time

```shell
root@ubuntu:~/project/netlibrary/echo-servers# ./benchmark.sh 
libevent running on port 2001
libev running on port 2002
libuv running on port 2003
libhv running on port 2004
asio running on port 2005
poco running on port 2006
netlibrary running on port 2007

==============2001=====================================
Running 10s test @ 127.0.0.1:2001
4 threads and 100 connections, send 1024 bytes each time
total readcount=929359 readbytes=951663616
throughput = 90 MB/s

==============2002=====================================
Running 10s test @ 127.0.0.1:2002
4 threads and 100 connections, send 1024 bytes each time
total readcount=1298197 readbytes=1329353728
throughput = 126 MB/s

==============2003=====================================
Running 10s test @ 127.0.0.1:2003
4 threads and 100 connections, send 1024 bytes each time
total readcount=976314 readbytes=999745536
throughput = 95 MB/s

==============2004=====================================
Running 10s test @ 127.0.0.1:2004
4 threads and 100 connections, send 1024 bytes each time
total readcount=1204228 readbytes=1233129472
throughput = 117 MB/s

==============2005=====================================
Running 10s test @ 127.0.0.1:2005
4 threads and 100 connections, send 1024 bytes each time
total readcount=1101312 readbytes=1127743488
throughput = 107 MB/s

==============2006=====================================
Running 10s test @ 127.0.0.1:2006
4 threads and 100 connections, send 1024 bytes each time
total readcount=996805 readbytes=1020728320
throughput = 97 MB/s

==============2007=====================================
Running 10s test @ 127.0.0.1:2007
4 threads and 100 connections, send 1024 bytes each time
total readcount=912280 readbytes=934174720
throughput = 89 MB/s
./benchmark.sh：行 25: 67536 已杀死               bin/libevent_echo $port
./benchmark.sh：行 25: 67537 已杀死               bin/libev_echo $port
./benchmark.sh：行 25: 67538 已杀死               bin/libuv_echo $port
./benchmark.sh：行 25: 67539 已杀死               bin/libhv_echo $port
./benchmark.sh：行 25: 67540 已杀死               bin/asio_echo $port
./benchmark.sh：行 25: 67541 已杀死               bin/poco_echo $port
./benchmark.sh：行 25: 67542 已杀死               bin/netlibrary_echo $port
```

## 测试二

Running 10s test @ 127.0.0.1:2001
12 threads and 100 connections, send 1024 bytes each time

```shell
root@ubuntu:~/project/netlibrary/echo-servers# ./benchmark.sh 
libevent running on port 2001
libev running on port 2002
libuv running on port 2003
libhv running on port 2004
asio running on port 2005
poco running on port 2006
netlibrary running on port 2007

==============2001=====================================
Running 10s test @ 127.0.0.1:2001
12 threads and 100 connections, send 1024 bytes each time
total readcount=786856 readbytes=805740544
throughput = 76 MB/s

==============2002=====================================
Running 10s test @ 127.0.0.1:2002
12 threads and 100 connections, send 1024 bytes each time
total readcount=1146830 readbytes=1174353920
throughput = 111 MB/s

==============2003=====================================
Running 10s test @ 127.0.0.1:2003
12 threads and 100 connections, send 1024 bytes each time
total readcount=838877 readbytes=859010048
throughput = 81 MB/s

==============2004=====================================
Running 10s test @ 127.0.0.1:2004
12 threads and 100 connections, send 1024 bytes each time
total readcount=1083647 readbytes=1109654528
throughput = 105 MB/s

==============2005=====================================
Running 10s test @ 127.0.0.1:2005
12 threads and 100 connections, send 1024 bytes each time
total readcount=855036 readbytes=875556864
throughput = 83 MB/s

==============2006=====================================
Running 10s test @ 127.0.0.1:2006
12 threads and 100 connections, send 1024 bytes each time
total readcount=1013434 readbytes=1037756416
throughput = 98 MB/s

==============2007=====================================
Running 10s test @ 127.0.0.1:2007
12 threads and 100 connections, send 1024 bytes each time
total readcount=750047 readbytes=768048128
throughput = 73 MB/s
./benchmark.sh：行 25: 68321 已杀死               bin/libevent_echo $port
./benchmark.sh：行 25: 68322 已杀死               bin/libev_echo $port
./benchmark.sh：行 25: 68323 已杀死               bin/libuv_echo $port
./benchmark.sh：行 25: 68324 已杀死               bin/libhv_echo $port
./benchmark.sh：行 25: 68325 已杀死               bin/asio_echo $port
./benchmark.sh：行 25: 68326 已杀死               bin/poco_echo $port
./benchmark.sh：行 25: 68327 已杀死               bin/netlibrary_echo $port
```

## 测试三

Running 10s test @ 127.0.0.1:2001
12 threads and 100 connections, send 4096 bytes each time

```shell
root@ubuntu:~/project/netlibrary/echo-servers# ./benchmark.sh 
libevent running on port 2001
libev running on port 2002
libuv running on port 2003
libhv running on port 2004
asio running on port 2005
poco running on port 2006
netlibrary running on port 2007

==============2001=====================================
Running 10s test @ 127.0.0.1:2001
12 threads and 100 connections, send 4096 bytes each time
total readcount=693154 readbytes=2839158784
throughput = 270 MB/s

==============2002=====================================
Running 10s test @ 127.0.0.1:2002
12 threads and 100 connections, send 4096 bytes each time
total readcount=1094459 readbytes=4482904064
throughput = 427 MB/s

==============2003=====================================
Running 10s test @ 127.0.0.1:2003
12 threads and 100 connections, send 4096 bytes each time
total readcount=711854 readbytes=2915753984
throughput = 278 MB/s

==============2004=====================================
Running 10s test @ 127.0.0.1:2004
12 threads and 100 connections, send 4096 bytes each time
total readcount=1024398 readbytes=4195934208
throughput = 400 MB/s

==============2005=====================================
Running 10s test @ 127.0.0.1:2005
12 threads and 100 connections, send 4096 bytes each time
total readcount=823514 readbytes=843970560
throughput = 80 MB/s

==============2006=====================================
Running 10s test @ 127.0.0.1:2006
12 threads and 100 connections, send 4096 bytes each time
total readcount=687176 readbytes=705963008
throughput = 67 MB/s

==============2007=====================================
Running 10s test @ 127.0.0.1:2007
12 threads and 100 connections, send 4096 bytes each time
total readcount=671278 readbytes=2749554688
throughput = 262 MB/s
./benchmark.sh：行 25: 69092 已杀死               bin/libevent_echo $port
./benchmark.sh：行 25: 69093 已杀死               bin/libev_echo $port
./benchmark.sh：行 25: 69094 已杀死               bin/libuv_echo $port
./benchmark.sh：行 25: 69095 已杀死               bin/libhv_echo $port
./benchmark.sh：行 25: 69096 已杀死               bin/asio_echo $port
./benchmark.sh：行 25: 69097 已杀死               bin/poco_echo $port
./benchmark.sh：行 25: 69098 已杀死               bin/netlibrary_echo $port
```

