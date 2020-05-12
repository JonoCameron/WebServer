all: client server st wp wf time rp

client: client.c
	gcc -o client client.c

server: server.c
	gcc -o server server.c

st: clientSendTime.c
	gcc -o st clientSendTime.c

wp: serverWritePackets.c
	gcc -o wp serverWritePackets.c

wf: writefile.c
	gcc -o wf writefile.c

time: time.c
	gcc -o time time.c

rp: serverReceivePackets.c
	gcc -o rp serverReceivePackets.c

clean:
	rm client server st wp wf time rp 