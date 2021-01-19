import itertools
import matplotlib.pyplot as plt
import pandas as pd

d = pd.read_csv('out.csv')
step = d['STEP']
runtime = d['RUNTIME']


fig = plt.figure()
ax = fig.add_subplot(111)

count = 1

for i,j in zip(step, runtime):
    
    label = f"({i},{j})"
    if(i == 16):
        dis = (i-1000, j)
    else:
        dis = (i, j)
    plt.annotate(label, xy=(i,j), xytext=dis)
    plt.scatter(i, j, c='black' if count%2==1 else 'red')
    count = count + 1

plt.xlabel('STEP')
plt.ylabel('Runtime (Nanoseconds)')
plt.title('Runtime vs STEP')
plt.show()
