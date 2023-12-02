# C Dotenv

A C program/library to read environment variables from a .env file, similar to other packages/libraries available in various programming languages.

## Usage

  1. To use dotenv library in your project simply add the `dotenv.c` and `dotenv.h` files in your project along with your `.env` file as shown below or create a <a href="https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html">
  shared library</a> as per your need:


  ```
  ├── .env
  ├── dotenv.c
  ├── dotenv.h
  └── main.c
  ```
  2. Once `dotenv.h` is included in your file, invoke the `load_env` function which takes filepath of the `.env` file as an argument:
     
   ```c
     // filename: main.c 
     // other include statements
     #include <stdlib.h>
     #include "dotenv.h"

     int main()
     {
        load_env(".env"); // if the .env file is in the current directory.
         // use the getenv method in the <stdlib.h> to get the value of your environment variable.
         char myVar[] = getenv("myVar");
         // other logic...
     }
   ```
  3. Your `.env` file can look something like this:
  ```python
  myVar="myVarValue"
  myvar = "myvarvalue"
  #mycommentedvar = "mycommentedvarvalue"
  ```
  4. Then compile you're program using `gcc` or similar compiler:
  ```sh
  gcc main.c dotenv.c -o main

  ```

  5. Or if you created a shared library:
  ```sh
  gcc main.c -ldotenv -o main # or whatever you named your library
  ```

