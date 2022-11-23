from distutils.core import setup, Extension

setup(name="vector2d", version="1.0", 
    ext_modules=[Extension("vector2d", ["vector2dmodule.c", "vector2dobject.c"])])
