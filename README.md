# Arduino traffic light controller
Program for the control of a traffic light system at a street junction with pedestrian crossing.

![Traffic light Diagram final ](https://user-images.githubusercontent.com/73448401/100377399-19c34a80-3009-11eb-96f0-6580a9321f37.png)

**Figure** :Traffic light at junction diagram

# Conditions

The requirements for the timing cycles for the traffic lights are the following:

- Initially the main road vehicles will have a green light.

- Pedestrians can request a green light by pressing either pushbutton. The pedestrian green
light should blink before going to red. Pedestrians should get a green light only if all road
traffic lights are red. A POT is used to determine the time the pedestrian traffic light should
stay green (for simulation purposes, a full scale POT value, 1024, should correspond to a
time of 10 seconds).

- The coils buried in the side road next to the traffic light can detect whether one or more
than one car is waiting in front of the traffic light. Note, a second POT is used in this traffic
light model to emulate the function of the coils. A value of 512 simulates that a car is waiting.
When cars coming out of the side road get a green light, main road light should be red.

# Demonstration video

The progrem is simulated using Tinkercad shown in the video below.

[![](http://img.youtube.com/vi/zFze7DTGLpc/0.jpg)](http://www.youtube.com/watch?v=zFze7DTGLpc "")
