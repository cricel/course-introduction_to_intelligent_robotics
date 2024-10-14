from gtts import gTTS
import os
import playsound

class TTS_Core():
    # def __init__(self):
        
    def tts_play(self, input_text):
        # Initialize the gTTS object with the text
        tts = gTTS(input_text)

        # Save the generated speech as an audio file
        tts.save("output.mp3")

        # Play the generated speech directly through speakers
        playsound.playsound("output.mp3")

        # Clean up by deleting the temporary audio file
        os.remove("output.mp3")

if __name__ == '__main__':
    tts_core = TTS_Core()
    tts_core.tts_play("hello this is a test speech I am teaching CS3 lab and we gonna cover the topic of dynamic array with C++ today")