namespace cpp tutorial

struct ComplexNumber {
    1: double real,
    2: double imaginary
}

service Calculator {
    i32 add(1: i32 num1, 2: i32 num2),
    i32 subtract(1: i32 num1, 2: i32 num2)
    ComplexNumber addComplex(1: ComplexNumber num1, 2: ComplexNumber num2)
}

