#Overview

This repository is a Proof of Concept (POC) demonstrating how to share a C++ package across two different programming languages: Node.js and Python. This project showcases the integration of C++ code within Node.js and Python environments, leveraging the performance benefits of C++ while maintaining the flexibility and ease of use provided by Node.js and Python.

#Installation
Follow these steps to set up the project and run the code in both Node.js and Python.

1. Clone - First, clone the repository to your local machine using the following command:
   ```
   git clone https://github.com/sjlouji/shared-cpp-package.git
   ```
2. Node JS
    1. Install node packages
      ```
       npm install
      ```
    2. Node gyp installation
      ```
       npm install -g node-gyp
      ```
    3. Build cpp modules
      ```
      node-gyp clean
      node-gyp configure
      node-gyp build
     ```
    4. Run node js code
     ```
     node index.js
     ```
3. Python
    1. Install necessary packages - `setuptools`, `pybind11`
    2. Build cpp modules for python
       ```
        python3 python-setup.py build_ext --inplace
       ```
   3. Run python code
      ```
      python3 index.py
      ```
       
