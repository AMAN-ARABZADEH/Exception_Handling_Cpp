# Exception Handling C++
This repository contains code examples and explanations for exception handling in C++. 
Exception handling is a mechanism in C++ that allows you to deal with exceptional conditions or errors that may occur during the execution of a program. 
It provides a structured way to handle errors and exceptions by separating the error-handling code from the normal flow of control.




## What is an Exception?
An exception is an abnormal condition or error that occurs during the execution of a program. 
It can be caused by various factors, such as invalid input, resource unavailability, or unexpected behavior.

## What is Exception Handling?
Exception handling is a mechanism in C++ that allows you to deal with exceptional conditions that may occur during the execution of a program. 
It provides a structured way to handle errors and exceptions by separating the error-handling code from the normal flow of control.

## How to use Exception Handling?
In C++, you can use the following syntax for exception handling:

try {
  // code that may throw an exception
}
catch (ExceptionType e) {
  // code for handling exception e
}


The `try` block contains the code that may throw an exception, and the `catch` block(s) handle the exception(s) if they occur. 
Each `catch` block specifies the type of exception it can handle. 
You can have multiple `catch` blocks for different types of exceptions, or a single `catch` block for all types of exceptions.

When an exception is thrown, the normal flow of control is interrupted, and the program looks for a suitable `catch` block that can handle the thrown exception. 
If a matching `catch` block is found, the code within that block is executed. 
If no matching `catch` block is found, the program terminates and may display an error message.

How to throw Exceptions?
In C++, you can throw exceptions using the `throw` keyword followed by an expression or an object. 
Exceptions can be of any type, including built-in types, user-defined types, or objects derived from the `std::exception` class or its subclasses.

For example, you can throw an integer exception like this:
```
throw 42;
```
Or you can throw a string exception like this:
```
throw "Something went wrong";
````
Or you can throw an object of a user-defined class like this:
```
throw MyException("Custom message");
```

## How to define Custom Exceptions?
In C++, you can define your own exception classes by deriving them from the std::exception class or its subclasses. 
This allows you to create custom exception types with specific behaviors or additional data members to convey information about the exception.

For example, you can define a custom exception class like this:

```
//This is useful because different types of exceptions may have different error messages or additional information that we want to convey to the user.
// By overriding the what() function, we can customize the exception message for our specific exception class.
class MyException : public std::exception {
public:
    // Override the what() function to provide a custom exception message
    // The const noexcept qualifiers indicate that the function is const and noexcept, meaning it won't modify the object's state and won't throw any exceptions.
    // As it is implemented in source code since 2011.
    const char* what() const noexcept override {
        return "My Exception occurred!";
    }
};



```
The `what()` function is a virtual member function defined in the std::exception class.
By overriding it in our derived class, such as MyException, we can provide custom exception messages.


## How to use Custom Exceptions?
To use custom exceptions, you need to include the header file where they are defined, and then throw and catch them as usual.

For example, you can use the custom exception class defined above like this:

```

    try {
        std::cout << "Hello, World!" << std::endl;
        // Throw a custom exception to simulate an error condition
        throw MyException();
    } catch (const MyException& e) {
        // Catch the custom exception and handle it
        std::cout << "Caught custom exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Catch any other standard library exceptions
        std::cout << "Caught standard exception: " << e.what() << std::endl;
    } catch (...) { // catch all block
        // Catch any other unknown exceptions
        std::cout << "Caught unknown exception!" << std::endl;
    }

```

## The Standard Library Exception Hierarchy
The C++ Standard Library provides a hierarchy of exception classes derived from std::exception. 
This hierarchy includes classes such as std::runtime_error, std::logic_error, and std::invalid_argument, among others. 
These classes provide common exception types for different categories of errors and can be used directly or as base classes for user-defined exceptions.

The following diagram shows some of the standard library exception classes and their relationships:

![The Standard Library Exception Hierarchy](https://github.com/AMAN-ARABZADEH/Exception_Handling_Cpp/blob/main/Exception_flow.png)

You can find more information about these classes and their usage on [cppreference.com](https://en.cppreference.com/w/cpp/error/exception).

## Sources
The sources used for this codes are:
- [cppreference.com - std::exception](https://en.cppreference.com/w/cpp/error/exception)
- [cppreference.com - std::exception::what](https://en.cppreference.com/w/cpp/error/exception/what)
- [cppreference.com - std::runtime_error](https://en.cppreference.com/w/cpp/error/runtime_error)
- [Rollbar - C++ Custom Exceptions: How to Make and Use Them](https://rollbar.com/blog/cpp-custom-exceptions/)
- [Stack Overflow - Creating custom exceptions in C++](https://stackoverflow.com/questions/41753358/creating-custom-exceptions-in-c)
- [GeeksforGeeks - Exception Handling in C++](https://www.geeksforgeeks.org/exception-handling-c/)


