from distutils.core import setup, Extension
 
module1 = Extension('rdtsc', sources = ['rdtscmodule.c'])
 
setup (name = 'PackageName',
        version = '1.0',
        description = 'RDTSC package',
        ext_modules = [module1])
