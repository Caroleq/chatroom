
# Chatroom application

Following application can be used for LAN communication. It is built on socket connections.

## Installation
Just enter the main catalogue and type:
1)
```
make
```
for client application
or
2) 
```
make ARG=server
```
for server application

Executable file should appear in bin/ folder.

To remove executable and object files type:
```
make clean
```

## Usage
For client:
```
./bin/client -h [server address] -p_recv [receiving port] -p_send [sending port]
```

For server:
```
./bin/server -h [server address] -p_recv [receiving port] -p_send [sending port]
```


