# AIzaSyCgXTfS9Cau7Z4UpV4zy6WcqDUYNOtHfK4

import google.generativeai as genai
import os

genai.configure(api_key="AIzaSyCgXTfS9Cau7Z4UpV4zy6WcqDUYNOtHfK4")

### Text Question
# model = genai.GenerativeModel("gemini-1.5-flash")
# response = model.generate_content("Write a story about a magic backpack.")
# print(response.text)
### Text Question


### Image Question
# model = genai.GenerativeModel("gemini-1.5-flash")
# myfile = genai.upload_file("test_img.jpeg")
# result = model.generate_content(
#     [myfile, "\n\n", "Can you tell me about the photo?"]
# )
# print(f"{result.text=}")
### Image Question


### Function Calling
############# LLM Function Defination #############
# def power_disco_ball(power: bool) -> bool:
#     """Powers the spinning disco ball."""
#     print(f"Disco ball is {'spinning!' if power else 'stopped.'}")
#     return True


# def start_music(energetic: bool, loud: bool, bpm: int) -> str:
#     """Play some music matching the specified parameters.

#     Args:
#       energetic: Whether the music is energetic or not.
#       loud: Whether the music is loud or not.
#       bpm: The beats per minute of the music.

#     Returns: The name of the song being played.
#     """
#     print(f"Starting music! {energetic=} {loud=}, {bpm=}")
#     return "Never gonna give you up."


# def dim_lights(brightness: float) -> bool:
#     """Dim the lights.

#     Args:
#       brightness: The brightness of the lights, 0.0 is off, 1.0 is full.
#     """
#     print(f"Lights are now set to {brightness:.0%}")
#     return True
# ############# LLM Function Defination #############

# ############# Python Function Call #############
# def python_power_disco_ball(power):
#     print("power_disco_ball: This is a function from actual python function call")
#     print(power)
#     print("----------------")

# def python_start_music(energetic, loud, bpm):
#     print("start_music: This is a function from actual python function call")
#     print(energetic, loud, bpm)
#     print("----------------")

# def python_dim_lights(brightness):
#     print("dim_lights: This is a function from actual python function call")
#     print(brightness)
#     print("----------------")
# ############# Python Function Call #############

# house_fns = [power_disco_ball, start_music, dim_lights]

# function_handler_dict = {
#     "power_disco_ball": python_power_disco_ball,
#     "start_music": python_start_music,
#     "dim_lights": python_dim_lights
# }



# model = genai.GenerativeModel(model_name="gemini-1.5-flash", tools=house_fns)

# chat = model.start_chat()
# response = chat.send_message("Turn this place into a party!")

# function_responses = {}
# for part in response.parts:
#     if fn := part.function_call:
#         args = ", ".join(f"{key}={val}" for key, val in fn.args.items())
#         function_responses[fn.name] = function_handler_dict[fn.name](**fn.args)
#         print(f"{fn.name}({args}) ==> {function_responses[fn.name]}")
### Function Calling