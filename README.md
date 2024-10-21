# C++ Module 05 - Repetition and Exceptions

## Overview
This repository contains the solutions for Module 05 of the 42 School's C++ curriculum. The focus of this module is on exceptions and the design of repetitive structures with classes, including forms and bureaucrats, while adhering to fundamental OOP principles.

## Status
Validated on **2024/02/09**.  
Grade: **100%**.

## General Information
- **Compiler used:** `c++`
- **Compilation flags:** `-Wall -Wextra -Werror -std=c++98`
- **Standard:** C++98 for compliance with the 42 School curriculum requirements.

## Projects
This module is divided into four exercises, each exploring different aspects of C++ class design, exception handling, and form management.

### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
- **Directory:** `ex00/`
- **Files:** `Makefile`, `main.cpp`, `Bureaucrat.{h, hpp}`, `Bureaucrat.cpp`
- **Description:**  
  Implement the `Bureaucrat` class, which represents an individual with a name and grade (from 1 to 150). Ensure that invalid grades throw exceptions: `GradeTooHighException` or `GradeTooLowException`. Member functions allow for incrementing and decrementing the grade, and you will overload the insertion (`<<`) operator to print the bureaucrat's details.
- **Key Concepts:** Class design, exception handling, constructor/destructor, I/O operator overloading.

### Exercise 01: Form up, maggots!
- **Directory:** `ex01/`
- **Files:** `Makefile`, `main.cpp`, `Bureaucrat.{h, hpp}`, `Bureaucrat.cpp`, `Form.{h, hpp}`, `Form.cpp`
- **Description:**  
  Add a `Form` class with attributes for the form's name, its signed status, and the grades required to sign and execute it. Implement a `beSigned()` function to enable signing the form by a bureaucrat if their grade is high enough. Modify the `Bureaucrat` class to include a `signForm()` function to handle signing and provide proper messaging for success or failure.
- **Key Concepts:** Inheritance, exception handling, interaction between classes, operator overloading.

### Exercise 02: No, you need form 28B, not 28C...
- **Directory:** `ex02/`
- **Files:** `Makefile`, `main.cpp`, `Bureaucrat.{h, hpp}, Bureaucrat.cpp`, `AForm.{h, hpp}, AForm.cpp`, `ShrubberyCreationForm.{h, hpp}, ShrubberyCreationForm.cpp`, `RobotomyRequestForm.{h, hpp}, RobotomyRequestForm.cpp`, `PresidentialPardonForm.{h, hpp}, PresidentialPardonForm.cpp`
- **Description:**  
  Expand the project by making `Form` an abstract class (`AForm`), and implement three specific forms: `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`, each with distinct actions and required grades. Implement the `execute()` function to trigger these actions and ensure proper exception handling for invalid grades and unsigned forms.
- **Key Concepts:** Abstract classes, inheritance, exception handling, concrete implementations of abstract concepts.

### Exercise 03: At least this beats coffee-making
- **Directory:** `ex03/`
- **Files:** `Makefile`, `main.cpp`, `Bureaucrat.{h, hpp}, Bureaucrat.cpp`, `AForm.{h, hpp}, AForm.cpp`, `Intern.{h, hpp}, Intern.cpp`
- **Description:**  
  Introduce an `Intern` class that can create forms via the `makeForm()` function. This function takes a form name and a target, returning a pointer to a new form. Ensure invalid form names are handled gracefully.
- **Key Concepts:** Factory pattern, exception handling, function overloading.

## Compilation and Usage
Each exercise includes a `Makefile` for convenient compilation. You can compile and run each exercise as follows:

```bash
cd ex00 && make && ./bureaucrat
cd ex01 && make && ./form_up
cd ex02 && make && ./form_exec
cd ex03 && make && ./intern_form
