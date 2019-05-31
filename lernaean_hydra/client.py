import sys, socket

def send_message(str):
    s = socket.socket()
    s.connect(('10.113.2.21', 5555))
    s.send(str.encode())
    print(s.recv(1024).decode())
    s.close()

if len(sys.argv) == 2:
    send_message(sys.argv[1])
