#!/usr/bin/env python3
import socket

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432        # non-privileged ports > 1023

def write_file(f, data):
    f = open("pytest.in", 'a')
    f.write(data)



def run_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # socket.AF_INET = IPv4
        s.bind((HOST, PORT)) # since IPv4, pass tuple (HOST, PORT)
        s.listen()
        conn, addr = s.accept()
        with conn:
            print('New Connection:', addr)
            msg = 'Hello'
            f = open("pytest.in", 'a')
            while msg != 'exit':
                data = conn.recv(1024)
                f.write((data).decode('utf-8'))
                #print(data.decode('utf-8'))
                if not data:
                    break
                #conn.sendall(data) #repeat back
                #msg = input("New Message: ")
                #conn.sendall(msg.encode('utf-8'))
            #work on sending files
            f.close()
        print('Connection closed.')



if __name__ == "__main__":
    run_server()
    #write_file("\nHello again")
