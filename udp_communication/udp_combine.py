import socket
import threading

# Server IP and Port
server_ip = "10.42.0.202"  # Replace with your Arduino's IP address
server_port = 8888         # Port where the Arduino is listening
local_port = 8889          # Port on which you will listen for responses from Arduino

# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the local port to listen for incoming messages
client_socket.bind(("", local_port))  # "" binds to all available interfaces

# Flag to control the while loop in the threads
running = True

# Function to handle receiving messages
def receive_messages():
    while running:
        try:
            # Receive response from Arduino (listening on local port)
            data, addr = client_socket.recvfrom(1024)  # Buffer size of 1024 bytes
            print(f"\nReceived message '{data.decode()}' from {addr}")
        except socket.timeout:
            pass  # Ignore timeout errors and keep looping

# Function to handle sending messages
def send_messages():
    global running
    try:
        while running:
            # Get user input from the keyboard
            message = input("Enter your message: ")
            if message.lower() == 'exit':  # Allow exiting the loop gracefully
                running = False
                break
            # Send the message to the Arduino
            client_socket.sendto(message.encode(), (server_ip, server_port))
            print(f"Sent '{message}' to the server.")
    except KeyboardInterrupt:
        running = False

# Start the thread for receiving messages
receive_thread = threading.Thread(target=receive_messages)
receive_thread.start()

# Handle sending messages in the main thread
send_messages()

# Wait for the receiving thread to finish
receive_thread.join()

# Close the socket after exiting
client_socket.close()
