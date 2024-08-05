from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        'python_api',
        ['bindings.cpp', 'rate_calculator/rate_calculator.cpp'],
        include_dirs=[pybind11.get_include()],
        language='c++',
        extra_compile_args=['-std=c++17'],
    )
]

setup(
    name='python_api',
    version='0.1',
    ext_modules=ext_modules,
    install_requires=[
        'pybind11>=2.10.0',
    ],
    extras_require={
        'dev': [
            'pytest>=6.0',
        ],
    },
    python_requires='>=3.6',
)