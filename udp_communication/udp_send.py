import socket
# Server IP and Port
server_ip = "192.168.252.124" # Replace PICO_IP_ADDRESS with the actual IP address of your Pico
server_port = 8888
# Create a UDP socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

try:
    while True:
        # Get user input from the keyboard
        message = input("Enter your message: ")
        # Send the message to the server
        client_socket.sendto(message.encode(), (server_ip, server_port))
        print(f"Sent '{message}' to the server.")
except KeyboardInterrupt:
    print("Program exited.")
finally:
    client_socket.close()

