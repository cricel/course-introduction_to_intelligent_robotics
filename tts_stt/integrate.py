import speech_recognition as sr
from tts_core import TTS_Core

class MechLMMChatBot:
    def __init__(self):
        self.tts_core = TTS_Core()

        self.recognizer = sr.Recognizer()

    def get_speech_input(self):
        with sr.Microphone() as source:
            self.recognizer.adjust_for_ambient_noise(source, duration=0.2)
            audio = self.recognizer.listen(source)
            try:
                speech_text = self.recognizer.recognize_google(audio)
                return speech_text.lower()
            except sr.RequestError as e:
                print(f"Could not request results; {e}")
                return None
            except sr.UnknownValueError:
                print("Unknown error occurred")
                return None

    def send_request(self, _msg):
        print("Do Something")
        return "dummy text for test tts"

    def play_response(self, response_text):
        self.tts_core.tts_play(response_text)

    def run(self):
        while True:
            print("How can I help you?")
            user_input = self.get_speech_input()
            if user_input:
                print(f"You Said: {user_input}")
                result = self.send_request(user_input)
                if result:
                    self.play_response(result["result"])

if __name__ == "__main__":
    bot = MechLMMChatBot()
    bot.run()