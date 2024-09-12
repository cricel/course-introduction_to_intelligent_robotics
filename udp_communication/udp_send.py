import socket  # Import the socket library for creating UDP communication

# Server IP and Port
server_ip = "192.168.1.83"  # Replace this with the actual IP address of your server (e.g., Pico)
server_port = 8888  # The port on which the server is listening

# Create a UDP socket using IPv4 (AF_INET) and Datagram (SOCK_DGRAM) protocol
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

try:
    while True:
        # Get user input from the keyboard
        message = input("Enter your message: ")
        
        # Send the message to the server as a UDP packet (message encoded to bytes)
        client_socket.sendto(message.encode(), (server_ip, server_port))
        print(f"Sent '{message}' to the server.")  # Confirmation message after sending
except KeyboardInterrupt:
    # Handle keyboard interrupt (Ctrl+C) to exit the loop gracefully
    print("Program exited.")
finally:
    # Close the UDP socket to release resources
    client_socket.close()