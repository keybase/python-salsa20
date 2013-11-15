"""
This file is part of Python Salsa20
a Python bridge to the libsodium C [X]Salsa20 library

Released under The BSD 3-Clause License
Copyright (c) 2013 Keybase

setup.py - build and package info
"""

from distutils.core import setup, Extension
from glob import glob

salsa20_module = Extension('_salsa20',
                          sources=glob('libsodium-salsa20/*.c')+['salsa20.c'],
                          include_dirs=['libsodium-salsa20'])

setup(name='salsa20',
      version='0.3.0',
      description='Bindings for the NaCL implementation of Salsa20 and XSalsa20 by D. J. Bernstein',
      author='Filippo Valsorda',
      author_email='filippo.valsorda@gmail.com',
      url='http://github.com/keybase/python-salsa20',
      py_modules=['salsa20'],
      ext_modules=[salsa20_module],
      classifiers=['Development Status :: 4 - Beta',
                   'Intended Audience :: Developers',
                   'License :: OSI Approved :: BSD License',
                   'Programming Language :: Python :: 2.6',
                   'Programming Language :: Python :: 2.7',
                   'Programming Language :: Python :: 3.3',
                   'Topic :: Security :: Cryptography',
                   'Topic :: Software Development :: Libraries'],
      license='3-clause BSD',
      long_description=open('README.rst').read())
