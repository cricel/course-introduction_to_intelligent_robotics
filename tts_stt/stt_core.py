import speech_recognition as sr
import pyttsx3

class STTCore:
    def __init__(self):
        self.listener = None  # Placeholder for listener function

    def add_listener(self, func):
        """Add a listener function that will be called with the recognized text."""
        self.listener = func

    def listen_loop(self):
        """Main loop to listen for speech and call the listener function."""
        while True:
            try:
                print("say something")
                r = sr.Recognizer()
                with sr.Microphone() as source2:
                    r.adjust_for_ambient_noise(source2, duration=0.2)
                    audio2 = r.listen(source2)
                    MyText = r.recognize_google(audio2)
                    MyText = MyText.lower()

                    print("Did you say ", MyText)
                    
                    # Call the listener function if one is set
                    if self.listener:
                        self.listener(MyText)

            except sr.RequestError as e:
                print("Could not request results; {0}".format(e))

            except sr.UnknownValueError:
                print("unknown error occurred")

# Usage example:
# def my_custom_function(recognized_text):
#     print(f"Custom function received: {recognized_text}")

# stt = STTCore()
# stt.add_listener(my_custom_function)
# stt.listen_loop()