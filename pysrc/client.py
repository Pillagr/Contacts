#!/usr/bin/env python3
import socket

HOST = '127.0.0.1'
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    msg = '<BEGIN MESSAGE>\n'
    while msg != 'exit':
        s.sendall(msg.encode('utf-8'))
        #data = s.recv(1024)
        #print ('Received:', data.decode('utf-8'))
        msg = input("New Message: ")
    s.sendall('\n<END MESSAGE>'.encode('utf-8'))