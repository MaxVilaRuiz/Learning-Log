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


'''
Loop control statements
* Break: 
    -> To break the loop in some specific case.
* Continue:
    -> Skips the actual iteration & continue with the next one.
* Pass:
    -> Allows you to include an empty block of code without causing a syntax error (it does nothing).
'''


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


# Try Statement:
#   -> To handle errors.
try:
    ans = 40 / 0
except Exception as e:
    print('Something went wrong!', e)
except:
    print("Something went wrong & I don't know why!")


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