import socket     # Import the socket library for UDP communication
import threading  # Import the threading library to handle concurrent tasks

# Server IP and Port (Arduino)
server_ip = "192.168.1.83"  # Replace with the Arduino's actual IP address
server_port = 8888         # Port on which the Arduino is listening
local_port = 8889          # Port on which this client will listen for responses from Arduino

# Create a UDP socket for communication
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the local port to listen for incoming messages from Arduino
client_socket.bind(("", local_port))  # Bind to all available network interfaces with specified port

# Flag to control the execution of the while loops in the threads
running = True

# Function to handle receiving messages from the Arduino
def receive_messages():
    while running:
        try:
            # Receive a response from Arduino (listening on local port 8889)
            data, addr = client_socket.recvfrom(1024)  # Buffer size of 1024 bytes for incoming data
            print(f"\nReceived message '{data.decode()}' from {addr}")  # Print the received message and sender's address
        except socket.timeout:
            pass  # Ignore timeout errors to avoid breaking the loop

# Function to handle sending messages to the Arduino
def send_messages():
    global running  # Use the global 'running' flag to control the loop
    try:
        while running:
            # Get user input to send to the Arduino
            message = input("Enter your message: ")
            if message.lower() == 'exit':  # Allow user to type 'exit' to break the loop gracefully
                running = False
                break
            # Send the message to the Arduino via UDP
            client_socket.sendto(message.encode(), (server_ip, server_port))
            print(f"Sent '{message}' to the server.")  # Confirm the message has been sent
    except KeyboardInterrupt:
        running = False  # Set running to False when Ctrl+C is pressed

# Start a separate thread for receiving messages from the Arduino
receive_thread = threading.Thread(target=receive_messages)
receive_thread.start()

# The main thread handles sending messages
send_messages()

# Wait for the receiving thread to finish execution before closing
receive_thread.join()

# Close the socket after the program finishes
client_socket.close()