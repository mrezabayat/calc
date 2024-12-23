from conan import ConanFile
from conan.tools.cmake import CMakeDeps

class CalculatorRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "gtest/1.15.0"

    def generate(self):
        cmake = CMakeDeps(self)
        cmake.generate()
