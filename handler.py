import serial
import csv
import matplotlib
matplotlib.use("tkAgg")
import matplotlib.pyplot as plt
import numpy as np
import json
import os
import sys
import datetime

ser = serial.Serial('COM10')
ser.flushInput()

plot_window = 20
y_var = np.array(np.zeros([plot_window]))

plt.ion()
fig, ax = plt.subplots()
line, = ax.plot(y_var) 

while True:
    try:


        ser_bytes = ser.readline()
        s = ser_bytes.decode("utf-8")
        s = s[:(s.index("}") + 1)]
        print(s)
        data = json.loads(s)
        micorphone = data["Microphone"]
        with open("test_data.csv","a") as f:
            writer = csv.writer(f,delimiter=",")
            writer.writerow([f"Mic: {micorphone}", "Time: " + str(datetime.datetime.now())])
        y_var = np.append(y_var,micorphone)
        y_var = y_var[1:plot_window+1]
        line.set_ydata(y_var)
        ax.relim()
        ax.autoscale_view()
        fig.canvas.draw()
        fig.canvas.flush_events()
    except Exception as e:
        print(e)
        exc_type ,exc_obj,exc_tb = sys.exc_info()
        print(exc_type,exc_tb.tb_lineno)
        break