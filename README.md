# cs50
## My solutions for Harvards famous CS50x course 2020 - 2021
Harvard's Introduction to computer Science and the art of programming.  
Please keep in mind Harvards policy on academic integrity and dont submit my solutions as they are

### Pset1
**Mario** 

*Description:* Draw a tower in the Mario game using the '#' character     
*What I learned:*

**Cash**   
*Description:*   
*What I learned:*  


**Credit**     
*Description:*     
*What I learned:*      

### Pset2
**Readability**  
*Description:*  
*What I learned:*

**Caesar**   
*Description:*   
*What I learned:*

**Substitution**  
*Description:*    
*What I learned:*

### Pset3     
**Plurality**      
*Description:* Implement a program that runs a plurality election in C programming language.         
*What I learned:*

**Runoff**      
*Description:* Implement a program that runs a runoff election in the C progamming language.    
*What I learned:*


### Pset4
**Filter**
1. Black and White Filter/GrayScale
2. Sepia
3. Reflection
4. Blur
*Description:*
*What I learned:*

**Recover**.     
*Description:* Implement a program that recovers JPEGs from a forensic image.    
*What I learned:* Memory management

### Lab5
**Inheritance**
*Description:* Simulating the inheritance of blood types for each member of a family.     
*What I learnt:* I learnt how to use the C programming language to build various data structures using typedef. I also learned how to allocate memory, using pointers and freeing memory after the program has run. I also learned how to make programs more robust by always checking pointers for NULL.    


### Pset5
An Array - memory must be contiguous.    
Binary Search Trees - A recursive data structure therefore its an opportunity to use recurssive code.
Hash Tables - an array of linked lists.    
Tries - Tree whose nodes are arrays.
**SPELLER**
*Description:* Implement the fastest possible spell checker that spell checks a file using a hash table   
*What I learnt:* Always check pointers for NULL    


### Pset6     
**Mario**     
*Description:* Implement a program that prints a double half pyramid, inspired by the video game Mario.     
*What I learnt:* Practice working with print statements in python and validating user input.    


**Credit**     
*Description:*     
*What I learned:* Validating user input in python using the regular expression module re. The need to be careful when converting C code into python with floor division which is // in python.     


**DNA**\
*Description* Write a python program that takes a DNA sequence and checks for a possible match in a dna database. By checking for consequtive STR repeats in the DNA sequence\
*What I learnt:* I learned how easy it is to work with python especially when it comes to string manipulation. As Strings in python are an object type with their own methods that can act on them. In a language like C, strings are actually pointers to a char as they are not a defined object type. C programs however run faster on average becuase when one runs a C program, they are running machine code which is what is produced from the compile stage. As python is an interpreted language - it has to be translated line by line into machine language and this adds onto the running time of a program. In addition with python you are using a librabry of code with allot of things already prebuilt for you and some of these solutions would be more general purpose solutions as opposed to a very specific one that you might code for your problem and this could make the code run slower than a C program.\

### Pset7
**MOVIES**  
*Description:* Write 12 sql queries to answer questions on movies in the imdb database.  
*What I learnt:* How to write sql queries, compute averages and combine tables.  

**Fiftyville**      
*Description:* Write sql queries to query a database of various tables inorder to solve a crime. To find out who stole the CS50 duck, which city the thief is headed to and who the accomplice is.\
*What I learnt:* I got lots of practice writing sql queries, escpecially nested sql queries to combine tables. I also learned how efficient an sql database is at storing large amounts of data while using the least amount of space. I also learned about normalisations and using join tables to reduce data redundancies.
### Pset8
**Lab8**     
*Description:* Create a trivia question game, one with buttons to select and the other a free response question which will react to user input. When the user selects the correct answer for examply the button will turn green and text will appear below saying "Correct!"    
*What I learnt:* I learned how to make web pages dynamic using JavaScript code by adding script tags in the html page. The script tag can be added at the bottom of the body section so that the contents of the document have hopefully all been loaded OR the script tags can be added in the head section. When the script tags are in the head section you can add some logic to check that the contents of the DOM have all loaded before the javascript code can run otherwise you may get an error.
    
**HOMEPAGE**   
*Description:* Create a simple webpage that introduces me, my favourite hobby or extracurricular activities.  
*What I learnt:* .  


### Pset9
Flask framework.   
A server is just a piece of software that is constantly listening for http requests on port 80 and port 443
By convention we capitalise global variables.      
Flask framework - a way to structure your code and you will typically organise your flask project like this:
1. application.py (most of your code goes here)
2. requirements.txt (list of all the libraries that your application will use.
3. static/
4. templates/        
You should never trust user input hence defensive programming.    
Shopping carts on websited are implemented using cookies.    
Use python on the server to dynamically generate html pages.    
Ajax
Best practice is to store sensitive information like email or passwords in environment variables. Do not type this private information directly inside your code and this is why we imported the 'os' module. A library that comes with Python.

**FINANCE**   
*Description:* Implement a website via which users can “buy” and “sell” stocks using Flask.    
*What I learnt:* I learnt that web applications are built using many different languages - for example with finance I used python, sql and JavaScript (html and CSS for the static pages). I learnt how to design and construct tables in a database to store in this case transactions data and that a "session" is how you go about storing user specific information. I also gained familiarity with using library code for example python functions to hash passwords. 
