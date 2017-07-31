# C++ 11 features and practice

This section contains several important features for C++ 11 and C++ 14. For advanced users, these features would be a very important bonus for programming. 

## Lambda function

A Lambda function is an anonymous function object. It is usually used as a replacement of the defintion of a named class with an operator (). This function is particularly useful when we want to pass an operation as an argument to an algorithm. (Such operations usually referred as _callbacks_) 

Lambda function can be implemented in other ways. However, if the function is simple and is used as a passing operator, Lambda function is very effective and no need for additional codes.

   1. The basic gramma

    ` [capture](arg)->ret{ body }  ` 

    a. The `arg` means the argument passed to the body
    
    b. The main function in `body`
    
    c. `->ret` specify the return type. If it can be specified in compiler, then do not need it. Usually used when multiple branches with multiple output

    d. `capture`, specify what from the outside of the lambda function should be available inside the function body and how. 
   
       For instance, capture `x` by value `[x]`, by reference `[&x]`, where `x` is an input argument from the outside function

       `[&]` means captures everything outside the lambda function by reference
  
       `[=]` means captures everything outside the lambda function by value

       `[x, &y]` the capture statement can be combined

       `[&, x]` means the default is to capture by reference, but variable x is captured by value



   2. Initialize variable using Lambda function

  
      `int s=4; auto x = [&r = s, s= s+1]()-> int { r+= 2; return s+2; }();  `

      This part of code initialized the variable `x` with a lambda function. This lambda function find an outside variable `s`, capture it by reference to inner variable `r` and also capture it  by value to inner variable `s`. During the execution, `r` will be updated to `2`, the return is specified as `int` type, and it is the value of `4+1+2 = 7`; finally, the parenthese `()` at the end means that the lambda function is executed immediately upon definition. If the `arg` is not empty, this parenthese should include the value of arg. 

