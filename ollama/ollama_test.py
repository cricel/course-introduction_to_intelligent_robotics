from ollama import Client

client = Client(host='http://172.21.255.131:11434')

response = client.chat(model='llama3.2', messages=[
  {
    'role': 'usesr',
    'content': 'how are you',
  },
])

print(response['message']['content'])