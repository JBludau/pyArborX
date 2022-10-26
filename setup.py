from setuptools import setup, find_packages

setup(
    name="arborx",
    version="0.1",
    packages=find_packages(include=["arborx", "arborx.*"]),
    include_package_data=True
)
