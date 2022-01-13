# import socket module
from socket import *

serverSocket = socket(AF_INET, SOCK_STREAM)

# Prepare a server socket
serverPort = 12000

serverSocket.bind(('', serverPort))

serverSocket.listen(1)

while True:

	# Establish the connection
	print("Ready to serve...")

	connectionSocket, addr = serverSocket.accept()

	try:
		message = connectionSocket.recv(4096).decode()

		print(message)

		filename = message.split()[1]

		f = open(filename[1:])

		outputdata = f.read()

		# Send one HTTP header line into socket
		header = "HTTP/1.0 200 OK\r\n"
		connectionSocket.send(header.encode())

		# Send the content of the requested file to the client
		for i in range(0, len(outputdata)):
			connectionSocket.send(outputdata[i].encode())

		connectionSocket.close()

	except IOError:

		# Send response message for file not found
		errorMessage = "HTTP/1.0 404 Not found\r\n"
		connectionSocket.send(errorMessage.encode())

	finally:
		# Close client socket
		connectionSocket.close()

serverSocket.close()
