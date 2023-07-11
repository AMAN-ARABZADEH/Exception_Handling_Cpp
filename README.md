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

## How to use Exception Handling using  try-catch blocks?
In C++, you can use the following syntax for exception handling:
To use try-catch blocks, you need to enclose the code that may throw an exception in a `try` block, and then provide one or more `catch` blocks to handle the possible exceptions. 
Each `catch` block specifies the type of exception it can handle as a parameter. 
For example, you can use try-catch blocks like this:

```
try {
  // Some code that may throw an exception
}
catch (std::invalid_argument& e) {
  // Code for handling invalid argument exception
}
catch (std::runtime_error& e) {
  // Code for handling runtime error exception
}
catch (...) {
  // Code for handling any other unknown exception
}
```


The `try` block contains the code that may throw an exception, and the `catch` block(s) handle the exception(s) if they occur. 
Each `catch` block specifies the type of exception it can handle. 
You can have multiple `catch` blocks for different types of exceptions, or a single `catch` block for all types of exceptions.

When an exception is thrown, the normal flow of control is interrupted, and the program looks for a suitable `catch` block that can handle the thrown exception. 
If a matching `catch` block is found, the code within that block is executed. 
If no matching `catch` block is found, the program terminates and may display an error message.


The order of the `catch` blocks matters. The program will look for the first `catch` block that matches the type of the thrown exception. 
If no matching `catch` block is found, the program will terminate with an error message. 
Therefore, it is recommended to place the more specific exception types before the more general ones, and to use a catch-all block (`catch (...)`) at the end to handle any other unknown exceptions.


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


## What is Stack Unwinding? 
Stack Unwinding:
- When an exception is thrown, the program unwinds the call stack, searching for an appropriate catch block.
- It means that the program jumps out of the current scope and looks for a matching catch block in the enclosing scopes.
- If a catch block is found, the corresponding code is executed. If not, the program terminates with an error message.


For example, consider the following code:
```
void thirdLevel() {
    std::cout << "Inside thirdLevel()" << std::endl;
    throw std::runtime_error("Exception occurred in thirdLevel()");
}

void secondLevel() {
    std::cout << "Inside secondLevel()" << std::endl;
    thirdLevel();
}

void firstLevel() {
    std::cout << "Inside firstLevel()" << std::endl;
    secondLevel();
}



```


##  BankAccount class

The BankAccount class  with the ability to deposit and withdraw money. 
Exception handling is implemented to handle scenarios such as invalid amounts and insufficient funds.


## Class Members
The BankAccount class has one private data member:
- `balance`: Represents the current balance of the bank account.
  
## Member Functions
The BankAccount class has three public member functions:

- `deposit(double amount)`: Deposits the specified amount into the account.
    - Throws an `std::invalid_argument` exception if the deposit amount is invalid (less than or equal to zero).
    - Updates the balance and prints a success message.
- `withdraw(double amount)`: Withdraws the specified amount from the account.
    - Throws an `std::invalid_argument` exception if the withdrawal amount is invalid (less than or equal to zero).
    - Throws an `std::runtime_error` exception if the withdrawal amount exceeds the available balance.
    - Updates the balance and prints a success message.
- `getBalance()`: Retrieves the current account balance.

## Exception Handling
The main function in the `main.cpp` file demonstrates how to use exception handling with the BankAccount class. It uses the following syntax:

```
    /// bank Account class.


    BankAccount account;

    try {
        // Perform deposit and withdrawal operations
        account.deposit(100.0);
        account.withdraw(50.0);
        account.withdraw(80.0); // This will throw an exception
    } catch (const std::invalid_argument& e) {
        // Catch invalid argument exceptions and display the error message
        std::cout << "Invalid argument exception: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        // Catch runtime error exceptions and display the error message
        std::cout << "Runtime error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Catch other standard exceptions and display the error message
        std::cout << "Caught exception: " << e.what() << std::endl;
    } catch (...) {
        // Catch any other unknown exceptions
        std::cout << "Caught unknown exception!" << std::endl;
    }

```
The `try` block contains the code that may throw exceptions, such as calling the deposit and withdraw functions with invalid or insufficient amounts. The `catch` blocks handle specific types of exceptions and display corresponding error messages using the `e.what()` function. 
The `catch (...)` block is a catch-all block that handles any other unknown exceptions.


## How to Run
To run this program, you need to have a C++ compiler installed on your system. You can use any IDE or command-line tool of your choice, CLion was used for creation of these example. For example, you can use g++ on Linux or Mac OS like this:

```

g++ main.cpp -o main
./main

```

This will compile and run the program, and display the output on the terminal.

## Output
The output of this program is:

```
Deposit successful. Current balance: 100            
Withdrawal successful. Current balance: 50          
Runtime error: Insufficient funds    

```


As you can see, when we try to deposit or withdraw invalid amounts, an invalid argument exception is thrown with a corresponding message. 
When we try to withdraw more money than we have in our account, a runtime error exception is thrown with the message “Insufficient funds”. 
When we encounter any other unknown exception, we catch it using the catch-all block and print a generic message.




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
- [What is Stack Unwinding?](https://stackoverflow.com/questions/2331316/what-is-stack-unwinding)



## How to Contribute

This project is open source and free to use. 
If you find it useful or interesting, feel free to clone the code and use it for your own purposes.
You can also contribute to this project by submitting issues, suggestions, or pull requests on GitHub. 
I appreciate any feedback or support that can help me improve this project. 

Thank you for your interest and collaboration. 😊

