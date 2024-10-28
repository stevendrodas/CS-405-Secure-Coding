// CS405Mod4Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//
// Developer: Steven Rodas | CS-405 | Exception Handling Activity | 9.27.2024 | steven.rodas@snhu.edu
//

#include <iostream>
#include <exception>
#include <stdexcept>

// this class is used as a constructor that takes a custom message and passes it to the base class constructor
class CustomException : public std::exception 
{
public:
    CustomException(const char* message) : std::exception(message) {}
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception
    throw std::runtime_error("Standard exception thrown in do_even_more_custom_application_logic().");

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try
    {
        do_even_more_custom_application_logic(); // attemps to run function that may throw an exception
    }
    catch (const std::exception& e) //catching standard exceptions
    {
        std::cerr << "Caught an exception in do_custom_application_logic(): " << e.what() << std::endl; // displays exception message
    }

    if (true)
    {
        std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    throw CustomException("Custom exception thrown in do_custom_application_logic.");

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    if (den == 0)
    {
        throw std::invalid_argument("Division by zero is not allowed, Error Raised."); //throws exception if denominator is zero
    }

    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try
    {
        auto result = divide(numerator, denominator); //attempts to run divide function
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::invalid_argument& e) //catches only invalid_argument exceptions
    {
        std::cerr << "Error in  do_division(): " << e.what() << std::endl; //displays exception message
    }


}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    try
    {
        do_division(); //attempts to run do_division function
        do_custom_application_logic(); //attempts to run do_custom_application_logic function, which throws a custom exception
    }
    catch (const CustomException& e) //catches custom exceptions
    {
		std::cerr << "Caught a custom exception in main: " << e.what() << std::endl; //displays exception message
	}
    catch (const std::exception& e) //catches standard exceptions
    {
		std::cerr << "Caught a standard exception in main: " << e.what() << std::endl; //displays exception message
	}
    catch (...) //catches all other exceptions
    {
		std::cerr << "Caught an unhandled exception in main." << std::endl; //displays exception message
	}
    
    return 0;



    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu