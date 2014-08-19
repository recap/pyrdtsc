#include <Python.h>

unsigned long long ehz = 0;
unsigned long long talpha = 0;

unsigned long long int 
rdtsc_imp(void){
   unsigned a, d;

   __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));

   return ((unsigned long long)a) | (((unsigned long long)d) << 32);;
}
 
static PyObject*
rdtsc(PyObject* self, PyObject* args)
{
    unsigned long long t;
    t = rdtsc_imp();
    //printf("from C: %lld\n",t);
    return Py_BuildValue("l", t);
}

static PyObject*
hz(PyObject* self, PyObject* args)
{
    return Py_BuildValue("l", ehz);
}


static PyObject*
rdtsc_s(PyObject* self, PyObject* args)
{
   unsigned long long tomega;
   double tdelta, tsecs, lhz;
   lhz = ehz;
   tomega = rdtsc_imp();
   tdelta = tomega - talpha;
   tsecs = tdelta / lhz;
   //printf("From C: %lf\n",tsecs);
   return Py_BuildValue("d", tsecs);
}

 
static PyMethodDef RdtscMethods[] =
{
     {"rdtsc", rdtsc, METH_VARARGS, "RDTSC register read"},
     {"hz", hz, METH_VARARGS, "RDTSC Hz"},
     {"rdtsc_s", rdtsc_s, METH_VARARGS, "RDTSC in seconds since init"},
     {NULL, NULL, 0, NULL}
};
 
PyMODINIT_FUNC
initrdtsc(void)
{
     unsigned long long t1,t2;
     t1 = rdtsc_imp();
     sleep(1);
     t2 = rdtsc_imp();
     ehz = t2 - t1;
     talpha = t1;
     (void) Py_InitModule("rdtsc", RdtscMethods);
}
