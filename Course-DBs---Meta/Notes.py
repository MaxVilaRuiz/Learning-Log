# STATEMENTS:
# Match Statement: 
#   -> allows comparations with literal values and not with boolean expressions, like if statements.
http_status = 200
match http_status:
    case 200 | 201:
        print('Success')
    case 400:
        print('Not Found')
    case 500 | 501:
        print('Server Error')
    case _: # else ('_' to ignore) 
        print('Unknown')

# Try Statement:
#   -> To handle errors.
try:
    ans = 40 / 0
except Exception as e:
    print('Something went wrong!', e)
except:
    print("Something went wrong & I don't know why!")

# Loop control statements:
'''
* Break: 
    -> To break the loop in some specific case.
* Continue:
    -> Skips the actual iteration & continue with the next one.
* Pass:
    -> Allows you to include an empty block of code without causing a syntax error (it does nothing).
'''


# FUNCTIONS PARAMS:
# Args & Kwargs:
# Args: 
#   -> Use all the arguments that can be assigned as a parameters in a function.
def sum_v(*args):
    sum = 0
    for x in args:
        sum += x
    return sum
print(sum_v(2, 3, 4, 5))

# Kwargs: 
#   -> Use all arguments assigned as a parameters with each keys.
def show_info(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}: {value}")
show_info(name="Max", age=19, city="Barcelona")


# File Handling:
#   * Open funcs: 
#       -> Two arguments
#       -> Mode: Action required (Reading, Writing or creating) & Output format (text or binary)

#        - Modes:
#           Mode = 'r'  # Open & read (text format)
#           Mode = 'rb' # Open & read (binary format)
#           Mode = 'r+' # Open for reading & writing
#           Mode = 'w'  # Open for writing
#           open(<FILE_NAME>, a) # Open for editing or appending data
#           Handling with binary format: add the letter 'b' after the mode (e.g. rb)
    
#        - Syntax (two ways):
#           open(<FILE_NAME> <FILE_LOCATION>, <MODE>)
#           with open('testing.txt', 'r') as file:  # No close func needed

#   * Close funcs:
#       -> No arguments
#       - Syntax: 
#           close()

#   -> Use other funcs to handling the data: 
#       file.readline(<optional_num_of_chars_to_read>)
#       file.readlines() -> reads the entire content of the file & returns it in an ordered list
#       file.read() -> reads the entire content of the file & store it as a string
#       file.writelines()


# Classes:
class MyClass:
    a = 5
    def hello():
        print('Hello, world!')

    def __new__(cls: type[Self]) -> Self: # 'cls' = convention for passing the class as its first argument, which will be used for creating the new empty obj
        pass

    # To initialize the constructor of the class
    def __init__(self, dish, items, time) -> None: # 'self' = convention.
        self.dish = dish
        self.items = items
        self.time = time

    def contents(self):
        print("The " + str(self.dish) + " has " + str(self.items) + " and takes " + str(self.time) + " min to prepare.")

myc = MyClass()
print(MyClass.a)
print(myc.a)
print(myc.hello())
pizza = MyClass('Pizza', ['cheese', 'bread', 'tomato'], 45)
pasta = MyClass('Pasta', ['penne', 'sauce'], 55)
print (pizza.items)
print(pasta.items)

# Abstract classes
# -> Class that is designed to be specifically used as a base class.
# Steps:
#   * Import ABC
#   * Create inheriting class
#   * Import abstract method
#   * Call abstract method
# Structure:
from abc import ABC, abstractmethod
class SomeAbstractClass(ABC):
    @abstractmethod
    def someabstractmethod(self):
        pass


# Modules:
import math # importing math library
import math as m # importing math library & using a pseudo to the library name
m.acosh();
from math import sqrt, factorial # importing only the function sqrt from the math library
print(sqrt(9))
from math import sqrt as s # all together

# Scopes:
def func1():
    id = 1
    def func2():
        nonlocal id # 'nonlocal' to modify a variable with the same name outside the nestedd function
        id = 2
        print('Inside the nested function: ' + id)
    print('Before calling the function: ' + id)
    func2()
    print('After nested function: ' + id)

id = 3
func1()
print('Global id: ' + id)

# Reload: to make dynamic changes within your code with import statements
import importlib
import module
importlib.reload(module) # executes again the module 'module'

# Packages: you import modules from packages (parent of a module, but with a similar structure)
#   -> Most populars: OS, SYS, CSV, JSON, importlib, re, math, intertools
#       * Data Science: NumPy, SciPy, NLTK, Pandas
#       * Data analysis: Numpy, Scipy, Matplotlib, Scikit-Learn
#       * Image processing & data visualization: open CV, matplotlib
#       * ML & AI: Tensor Flow, PyTorch, Keras, SciPy, Scikit-learn, Theano
#       * Web development (Flash & Django): cherry pie, pyramid, beautiful soup, selenium


# Testing:
#   -> Pytest: python testing framework
import file_name # file that I want to test
import pytest
def test_add():
    assert file_name.func1(4, 5) == 9 # If the output is true, the func passed this test
#   -> For running a test file: 'python -m pytest name_of_this_file.py'
#   -> To run only a function of the test file: 'python -m pytest name_of_this_file.py::func_name'