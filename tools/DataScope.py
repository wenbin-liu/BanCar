import pyqtgraph as pg
import numpy as np
from pyqtgraph.Qt import QtCore, QtGui
import serial
s=serial.Serial("COM10")
win=pg.GraphicsWindow()
win.setWindowTitle("DataScope")
p=win.addPlot()
data=np.random.normal(size=400)
curve=p.plot(data)
pos=0
def dataLoad():
    global data
    i=10
    while i>0:
        string = s.readline().decode("ASCII").strip().split()
        try:
            string[1]
        except IndexError:
            print("Lost one package")
            continue
        data[:-1]=data[1:]
        data[-1]=float(string[1])
        i-=1
    
def update():
    dataLoad()
    global data
    global pos
    print(data[-1])
    curve.setData(data)
    #curve.setPos(pos,0)
    pos+=1

timer= pg.QtCore.QTimer()
timer.timeout.connect(update)
timer.start(5)
QtGui.QApplication.instance().exec_()