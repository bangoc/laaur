from setuptools import setup, Extension

setup(name = 'sohoc',
      version = '1.1.1',
      ext_modules = [
        Extension(name = "sohoc", 
                  sources = ['sohoc.c'])
     ],
     description = "Thư viện số học được viết bằng C",
     author = "Nguyễn Bá Ngọc",
     author_email = "ngocnb@soict.hust.edu.vn")