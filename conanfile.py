from conans import ConanFile, CMake
import os

class CPP_rtype(ConanFile):
   name = "client"
   version = "0.1"
   settings = "os_build", "compiler", "build_type", "arch"
   requires = "sfml/2.5.1@bincrafters/stable", "boost_base/1.69.0@bincrafters/stable" # comma-separated list of requirements
   generators = "cmake", "cmake_paths", "txt", "cmake_find_package"
   exports_sources = ['CMakeLists.txt', '0001-find-libraries.patch']
#
   options = {
        'shared': [True, False],
        'fPIC': [True, False],
        'window': [True, False],
        'graphics': [True, False],
        'network': [True, False],
        'audio': [True, False],
   }
   default_options = {
        'shared': True,
        'fPIC': True,
        'window': True,
        'graphics': True,
        'network': True,
        'audio': True
   }
  # _source_subfolder = 'source_subfolder'
  # _build_subfolder = 'build_subfolder'

   def build(self):
      cmake = CMake(self)
      cmake.configure()
      cmake.build()