# Ulatrasonic_test

 This sketch reads a ultrasonic rangefinder thatt is mounted over a conveyor and returns the distance to the closest object in range.
    To do this, it sends a pulse to the sensor to initiate a reading, then listens for a pulse to return.
    The length of the returning pulse is proportional to the time of the returning pulse is converted into a distance in mm.
    The conveyor transports three types of objects (Object 1, 2 and 3).
    If a object is whithin a specified interval it will be counted as one of the three objects and printed to the serial monitor, with a measure on that specific object.
    Ther are also 4 LED's in tree different colors (Green, Red, Yellow and white)
    The will flash in tree different ways (Green ones, Red twice, yellow three times and White constant) when the objects pass.
