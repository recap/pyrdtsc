import rdtsc
import time

t1 = rdtsc.rdtsc_s()
time.sleep(0.0001)
t2 = rdtsc.rdtsc_s()

mhz = float(rdtsc.hz())/1000000

tj = rdtsc.rdtsc()
tt = time.time()

tdelta = t2 - t1
print "Elapsed Time using pyrdtsc: "+str(tdelta)

t1 =  time.time()
time.sleep(0.0001)
t2 = time.time()
#st1 = "{:.12f}".format(t1)
#st2 = "{:.12f}".format(t2)
#nt1 = float(st1)
#nt2 = float(st2)
tdelta = t2 - t1
print "Elapsed Time using time: "+str(tdelta)

print "Estimated MHz "+str(mhz)

print "Raw time stamp pyrdtsc: "+str(tj)+" time: "+str(tt)
