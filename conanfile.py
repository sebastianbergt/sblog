from conans import ConanFile, CMake, tools
import os


class SblogConan(ConanFile):
    name = "sblog"
    version = "1.0.0"
    license = "MIT"
    author = "Sebastian"
    url = "https://github.com/luminartech/LumPDK"

    exports_sources = "src/**"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "with_tests": [True, False],
        "with_coverage": [True, False],
    }
    default_options = {
        "shared": False,
        "fPIC": True,
        "with_tests": True,
        "with_coverage": False,
        "catch2:with_main": True,
    }
    generators = "cmake", "cmake_find_package"

    _cmake = None

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def configure(self):
        if self.options.shared:
            del self.options.fPIC

    def requirements(self):
        if self.options.with_tests:
            self.requires("catch2/2.13.7")
            self.requires("trompeloeil/41")
        self.requires("oatpp/1.2.5")
        self.requires("maddy/1.1.2")

    def _report_coverage(self):
        self.run("gcovr -r .".split())
        self.run("gcovr -r . --html --html-details -o coverage.html".split())
        cwd = os.getcwd()
        self.output.highlight("coverage report was created here: " + cwd + "/coverage.html")

    def _configure_cmake(self):
        if self._cmake:
            return self._cmake
        self._cmake = CMake(self)
        self._cmake.definitions["WITH_TESTS"] = self.options.with_tests
        self._cmake.definitions["CONAN_CXX_FLAGS"] = "-Wall -Wextra -Wpedantic -Werror "
        if self.options.with_coverage:
            self._cmake.definitions["CONAN_CXX_FLAGS"] += "--coverage -g -O0 "
        self._cmake.configure(source_folder="src")
        return self._cmake

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
