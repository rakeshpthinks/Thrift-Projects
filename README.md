# Thrift-Based Calculator Service

## 📌 Overview
This project demonstrates a **Thrift-based RPC (Remote Procedure Call) system** for performing arithmetic operations, including addition of integers and complex numbers. It consists of a **Thrift-defined service**, a **C++ server**, and a **C++ client**, all managed using **CMake**.

---

## 🛠 Features
- Implements a **Calculator service** using Apache Thrift
- Supports operations:
  - **Integer Addition** (`add`)
  - **Integer Subtraction** (`subtract`)
  - **Complex Number Addition** (`addComplex`)
- Uses **CMake** for project building and dependency management
- Runs a **Thrift server** and communicates via a **Thrift client**

---

## 📂 Project Structure
```
Calculator_Thrift/
├── CMakeLists.txt             # CMake build configuration
├── calculator.thrift          # Thrift IDL file defining the service
├── gen-cpp/                   # Auto-generated Thrift C++ files
│   ├── Calculator.h
│   ├── Calculator.cpp
│   ├── ComplexNumber.h
│   ├── ComplexNumber.cpp
│   ├── calculator_types.h
│   ├── calculator_types.cpp
├── src/
│   ├── Calculator_server.cpp  # Server implementation
│   ├── Calculator_client.cpp  # Client implementation
├── build/                     # Build directory (after compilation)
├── README.md                  # Project documentation
```

---

## 🚀 Getting Started

### 1️⃣ **Install Dependencies**
Ensure you have **Apache Thrift** installed:
```sh
sudo apt update && sudo apt install thrift
```

### 2️⃣ **Generate Thrift Code**
Run the following command to generate the required C++ files:
```sh
thrift --gen cpp calculator.thrift
```
This will create the **gen-cpp/** folder containing `Calculator.cpp`, `ComplexNumber.cpp`, etc.

### 3️⃣ **Build the Project**
```sh
mkdir build && cd build
cmake ..
make
```

### 4️⃣ **Run the Server**
Start the Thrift server:
```sh
./server
```
Expected Output:
```
Starting the server on port 9090...
```

### 5️⃣ **Run the Client**
In a separate terminal:
```sh
./client
```
Expected Output:
```
Result of Complex Addition: (4.5 + 6.5i)
```

---

## 📝 Thrift IDL Definition (`calculator.thrift`)
```thrift
namespace cpp tutorial

struct ComplexNumber {
    1: double real,
    2: double imaginary
}

service Calculator {
    i32 add(1: i32 num1, 2: i32 num2),
    i32 subtract(1: i32 num1, 2: i32 num2),
    void addComplex(1: ComplexNumber num1, 2: ComplexNumber num2, 3: out ComplexNumber result)
}
```

---

## 🖥 Server Implementation (`src/Calculator_server.cpp`)
```cpp
void addComplex(tutorial::ComplexNumber& _return, const tutorial::ComplexNumber& num1, const tutorial::ComplexNumber& num2) override {
    _return.real = num1.real + num2.real;
    _return.imaginary = num1.imaginary + num2.imaginary;

    std::cout << "Adding Complex Numbers: ("
              << num1.real << " + " << num1.imaginary << "i) + ("
              << num2.real << " + " << num2.imaginary << "i) = ("
              << _return.real << " + " << _return.imaginary << "i)" << std::endl;
}
```

---

## 🛠 CMake Configuration (`CMakeLists.txt`)
```cmake
cmake_minimum_required(VERSION 3.10)
project(ThriftCalculator)

find_package(Threads REQUIRED)

set(THRIFT_GEN_DIR ${CMAKE_SOURCE_DIR}/gen-cpp)
set(THRIFT_INCLUDE_DIR /usr/local/include/thrift)
set(THRIFT_LIB thrift)

include_directories(${THRIFT_GEN_DIR} ${THRIFT_INCLUDE_DIR})
link_directories(/usr/local/lib)

add_executable(server src/Calculator_server.cpp ${THRIFT_GEN_DIR}/Calculator.cpp ${THRIFT_GEN_DIR}/calculator_types.cpp)
add_executable(client src/Calculator_client.cpp ${THRIFT_GEN_DIR}/Calculator.cpp ${THRIFT_GEN_DIR}/calculator_types.cpp)

target_link_libraries(server ${THRIFT_LIB} Threads::Threads)
target_link_libraries(client ${THRIFT_LIB} Threads::Threads)
```

---

## 📌 Troubleshooting

### **❌ Error: `undefined reference to ComplexNumber::~ComplexNumber()`**
✅ Solution: Ensure `ComplexNumber.cpp` is included in `CMakeLists.txt` and rebuild.
```sh
rm -rf build && mkdir build && cd build
cmake ..
make
```

### **❌ Error: `thrift: command not found`**
✅ Solution: Install Thrift:
```sh
sudo apt install thrift
```

## ✨ Contributors
- **Rakesh U** (rakeshu.0904@gmail.com)

---

## 🔗 References
- [Apache Thrift Official Documentation](https://thrift.apache.org/docs/)

