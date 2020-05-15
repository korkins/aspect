import numpy as np
import matplotlib.pyplot as plt
font_size = 12
fname = 'O2.txt'
data = np.loadtxt(fname, skiprows=1)
x = data[:,0]
y = data[:,1]
plt.plot((10000.0/x)*1000, y, '-b')
plt.title(fname, size=font_size)
plt.ylabel('$\\tau$', size=font_size)
plt.yscale('log')
#plt.xlabel('$\\nu$ (cm-1)', size=font_size)
plt.xlabel('$\\lambda$ (nm)', size=font_size)
plt.tick_params(axis='x', labelsize=font_size)
plt.tick_params(axis='y', labelsize=font_size)
plt.grid('True')
#plt.legend(['H'16'], fontsize=font_size)
print('done!')