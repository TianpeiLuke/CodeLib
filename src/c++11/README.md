# C++ 11 features and practice

This section contains several important features for C++ 11 and C++ 14. For advanced users, these features would be a very important bonus for programming. 

## Lambda function

The concept of Lambda function is closely related to __functinal programming__, where the programmer defines functional that takes functor as input. A Lambda function is an anonymous function object. It is usually used as a replacement of the defintion of a named class with an operator (). This function is particularly useful when we want to pass an operation as an argument to an algorithm. (Such operations usually referred as _callbacks_) 

Lambda function can be implemented in other ways. However, if the function is simple and is used as a passing operator, Lambda function is very effective and no need for additional codes.

   1. The basic gramma

    `[capture](arg)->ret{ body }` 

    a. The `arg` means the argument passed to the body
    
    b. The main function in `body`
    
    c. `->ret` specify the return type. If it can be specified in compiler, then do not need it. Usually used when multiple branches with multiple output

    d. `capture`, specify what from the outside of the lambda function should be available inside the function body and how. 
   
       For instance, capture `x` by value `[x]`, by reference `[&x]`, where `x` is an input argument from the outside function

       `[&]` means captures everything outside the lambda function by reference
  
       `[=]` means captures everything outside the lambda function by value

       `[x, &y]` the capture statement can be combined

       `[&, x]` means the default is to capture by reference, but variable x is captured by value


    This is equivalent to 

       ` struct f{ ret operator()(arg){body;};  }   `


   2. Initialize variable using Lambda function

  
      `int s=4; auto x = [&r = s, s= s+1]()-> int { r+= 2; return s+2; }();  `

      This part of code initialized the variable `x` with a lambda function. This lambda function find an outside variable `s`, capture it by reference to inner variable `r` and also capture it  by value to inner variable `s`. During the execution, `r` will be updated to `2`, the return is specified as `int` type, and it is the value of `4+1+2 = 7`; finally, the parenthese `()` at the end means that the lambda function is executed immediately upon definition. If the `arg` is not empty, this parenthese should include the value of arg. 


   3. Useful functions that have Lambda functions as callbacks (defined in package `algorithm`)


      a. `std::sort(container.begin(), container.end(), Compare comp);`

         It sorts the `container [begin(), end()]`;

         In this function, the `Compare` is defined as `struct Compare { bool operator()(T x, T y){ return x < y; }  }`

         Use a lambda function we can define `[](auto x, auto y){ return x < y;}`


      b. `std::transform(Input_container.begin(), Input_container.end(), Ouput_container.begin(), Unary_Operation op);`

         or

          `std::transform(Input_container1.begin(), Input_container1.end(), Input_container2.begin(), Ouput_container.begin(), Unary_Operation op);`


         It applies the `op` operation to each elements in one range such as `Input_container` from `begin()` to `end()` and output begins with `Output_container.begin()`; It can also applied to two ranges `Input_*1` and `Input_*2`;

         The operator `op` can be defined by a lambda function.



      c. `std::for_each(Input_container.begin(), Input_container.end(), Function f)` 

          Similar as above, applies function `f` to each element within a range


## move, move semantics, perfect forwarding

  Defined in 'utility' package. This is a helper function to avoid copies. A class may define additional _move-constructor_.  For instance, using a move constructor, a 'vector' could just copy its internal pointer to data to the new object, leaving the moved object in an incorrect state, avoiding copying all data. 


