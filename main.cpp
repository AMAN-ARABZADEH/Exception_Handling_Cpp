#include <iostream>

/*
 * Auther: Aman Arabzadeh
 * Exception Handling in C++
 *
 * Sources are used for further understanding of Exception Handling in C++.
 *
 *
 * sources:
 *    - https://en.cppreference.com/w/cpp/error/exception
 *    - https://en.cppreference.com/w/cpp/error/exception/what
 *    - https://en.cppreference.com/w/cpp/error/exception/exception
 *    - https://en.cppreference.com/w/cpp/error/runtime_error
 *    - https://rollbar.com/blog/cpp-custom-exceptions/
 *    - https://stackoverflow.com/questions/41753358/creating-custom-exceptions-in-c
 *    - https://www.geeksforgeeks.org/exception-handling-c/
 *    - https://stackoverflow.com/questions/2331316/what-is-stack-unwinding
 *
 *
 */
// Exception Handling C++

/*
 * throw
 * try { code that may throw an exception }
 * catch(ExceptionType e) { code for handling exception e.what() }
 *
 * What is an Exception?
 * - An exception is an abnormal condition or error that occurs during the execution of a program.
 *   It can be caused by various factors, such as invalid input, resource unavailability, or unexpected behavior.
 *
 * What is Exception Handling?
 * - Exception handling is a mechanism in C++ that allows you to deal with exceptional conditions that may occur
 *   during the execution of a program. It provides a structured way to handle errors and exceptions by separating
 *   the error-handling code from the normal flow of control.
 *
 * What do we throw and catch?
 * - In C++, you can throw exceptions using the `throw` keyword followed by an expression or an object.
 *   Exceptions can be of any type, including built-in types, user-defined types, or objects derived from
 *   the `std::exception` class or its subclasses.
 * - Exceptions are caught using `try-catch` blocks. The `try` block contains the code that may throw an exception,
 *   and the `catch` block(s) handle the exception(s) if they occur. Each `catch` block specifies the type of
 *   exception it can handle.
 *
 * How does it affect the flow of control?
 * - When an exception is thrown, the normal flow of control is interrupted, and the program looks for a suitable
 *   `catch` block that can handle the thrown exception. If a matching `catch` block is found, the code within that
 *   block is executed. If no matching `catch` block is found, the program terminates and may display an error message.
 *
 * Defining our own exception classes.
 * - In C++, you can define your own exception classes by deriving them from the `std::exception` class or its subclasses.
 *   This allows you to create custom exception types with specific behaviors or additional data members to convey
 *   information about the exception.
 *
 * The Standard Library Exception Hierarchy.
 * - The C++ Standard Library provides a hierarchy of exception classes derived from `std::exception`.
 *   This hierarchy includes classes such as `std::runtime_error`, `std::logic_error`, and `std::invalid_argument`,
 *   among others. These classes provide common exception types for different categories of errors and can be used
 *   directly or as base classes for user-defined exceptions.
 *   (Note: The custom exception class `MyException` used in this example is derived from `std::exception`.)
 *
 * std::exception and wait()
 * - `std::exception` is the base class for all standard library exceptions. It provides a virtual member function `what()`
 *   that returns a C-style string describing the exception. Derived exception classes can override this function to provide
 *   custom exception messages.
 */

// Here I give example on how to create your own exception class use by inheriting from base class std::exception class.
// Custom exception class for demonstrating user-defined exceptions, inheriting from std::exception
// The what() function is a virtual member function defined in the std::exception class.
// By overriding it in our derived class, such as MyException, we can provide a custom implementation of the function that returns a C-style string describing the exception.
//
//This is useful because different types of exceptions may have different error messages or additional information that we want to convey to the user.
// By overriding the what() function, we can customize the exception message for our specific exception class.
class MyException : public std::exception {
public:
    // Override the what() function to provide a custom exception message
    // The const noexcept qualifiers indicate that the function is const and noexcept,
    // meaning it won't modify the object's state and won't throw any exceptions.
    // As it is implemented in source code since 2011.
    const char* what() const noexcept override {
        return "My Exception occurred!";
    }
};

// Custom exception class for division by zero
// Two classic example, you need to handle exceptions, and implement your own custom class for handling exceptions.
class DivideByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Division by zero exception";
    }
};

// Custom exception class for negative sum or total
class NegativeValueException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Negative value exception";
    }
};

double calculate_avg(int sum, int total) {
    if (total == 0) {
        throw DivideByZeroException();
    }
    if (sum < 0 || total < 0) {
        throw NegativeValueException();
    }
    return static_cast<double>(sum) / total;
}


// Exception Handling /  Stack Unwinding: C++

/*
 * try { code that may throw an exception }
 * catch(ExceptionType e) { code for handling exception e.what() }
 *
 * Stack Unwinding:
 * - When an exception is thrown, the program unwinds the call stack, searching for an appropriate catch block.
 *   It means that the program jumps out of the current scope and looks for a matching catch block in the enclosing scopes.
 *   If a catch block is found, the corresponding code is executed. If not, the program terminates with an error message.
 */

void thirdLevel() {
    std::cout << "Inside thirdLevel()" << std::endl;
    throw std::runtime_error("Exception occurred in thirdLevel()"); // throw an exception of type runtime_error
    std::cout << "Still inside thirdLevel()\n"; // Will not execute because of the exception
}

void secondLevel() {
    std::cout << "Inside secondLevel()" << std::endl;
    try {
        thirdLevel(); // call the thirdLevel() function
    }
    catch (const std::runtime_error& e) { // catch the exception of type runtime_error
        std::cout << "Caught exception: " << e.what() << std::endl; // print the error message
    }
    catch (...) { // catch any other exception
        std::cout << "Caught unknown exception" << std::endl; // print a generic message
    }
    std::cout << "Still inside secondLevel()" << std::endl; // this will execute because the exception was handled
}

void firstLevel() {
    std::cout << "Inside firstLevel()" << std::endl;
    try {
        secondLevel(); // call the secondLevel() function
    }
    catch (const std::runtime_error& e) { // catch the exception of type runtime_error
        std::cout << "Caught exception: " << e.what() << std::endl; // print the error message
    }
    catch (...) { // catch any other exception
        std::cout << "Caught unknown exception" << std::endl; // print a generic message
    }
    std::cout << "Still inside firstLevel()" << std::endl; // this will execute because the exception was handled
}



/// BankAccount class
/*
The BankAccount class represents a bank account with the ability to deposit and withdraw money.
Exception handling is implemented to handle scenarios such as invalid amounts and insufficient funds.

 Class Members:

- balance: Represents the current balance of the bank account.

Member Functions:
- deposit(double amount): Deposits the specified amount into the account.
    - Throws an std::invalid_argument exception if the deposit amount is invalid (less than or equal to zero).
    - Updates the balance and prints a success message.

- withdraw(double amount): Withdraws the specified amount from the account.
        - Throws an std::invalid_argument exception if the withdrawal amount is invalid (less than or equal to zero).
        - Throws an std::runtime_error exception if the withdrawal amount exceeds the available balance.
        - Updates the balance and prints a success message.

- getBalance(): Retrieves the current account balance.

Exception Handling:
    - The try block in the main function encloses the code that may throw exceptions.
    - The catch blocks handle specific types of exceptions and display corresponding error messages using the e.what() function.
    - The catch (...) block is a catch-all block that handles any other unknown exceptions.

Program Flow:
    - Create a BankAccount object.
    - Perform deposit and withdrawal operations.
    - Handle specific exceptions and display error messages.
    - Output success messages for successful operations.

*/


// BankAccount class with exception handling
class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0.0) {}

    // Deposit money into the account
    void deposit(double amount) {
        // Check if the deposit amount is valid
        if (amount <= 0.0) {
            throw std::invalid_argument("Invalid deposit amount");
        }

        // Perform the deposit operation
        balance += amount;
        std::cout << "Deposit successful. Current balance: " << balance << std::endl;
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        // Check if the withdrawal amount is valid
        if (amount <= 0.0) {
            throw std::invalid_argument("Invalid withdrawal amount");
        }

        // Check if there are sufficient funds for the withdrawal
        if (amount > balance) {
            throw std::runtime_error("Insufficient funds");
        }

        // Perform the withdrawal operation
        balance -= amount;
        std::cout << "Withdrawal successful. Current balance: " << balance << std::endl;
    }

    // Get the current account balance
    double getBalance() const {
        return balance;
    }
};

///

int main() {

    auto newLines = [](){
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    };
    newLines();
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

    newLines();
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

    newLines();
    // Example of exception handling in a function
    try {
        int sum = 100;
        int total = -10;

        double average = calculate_avg(sum, total);
        std::cout << "Average: " << average << std::endl;
    } catch (const DivideByZeroException& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    } catch (const NegativeValueException& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught unknown exception!" << std::endl;
    }
    newLines();
// Example of  Stack Unwinding:
    try {
        std::cout << "Inside main()" << std::endl;
        firstLevel();
    } catch (const std::exception& e) {
        // Catch the exception and handle it
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    newLines();
    return 0;
}
