#include <bits/stdc++.h>
using namespace std;

// fcnPtr is a pointer to a function that takes no arguments and returns an integer
// The type (parameters and return type) of the function pointer must match the type of the function


// [ captures ] (parameters) -> returnTypesDeclaration { lambdaStatements; }
/*

[ captures ]: The capture clause, also known as the lambda introducer, specifies which outside variables are available for the lambda function 
and whether they should be captured by value (copying) or by reference. You will always be able to identify the start of a lambda expression
with the presence of the capture clause. An empty capture clause [] means capture nothing, in which case the lambda expression body doesn't 
access variables in the enclosing scope. I'll dive deeper into capture defaults later.
[=] capture option captures any referenced variable within the lambda by value (making a copy).
[&] for reference.

( parameters ): This is the optional parameters list, also known as the lambda declarator. 
You can omit the parameters list if you want a function that takes zero arguments.

-> returnTypeDeclaration: This is the return type. Most of the time, compilers can deduce the return type of the lambda expression when you have zero or one return statement.
However, if it makes it easier to understand the code, you can specify the return type. 
There are some differences among compilers regarding the automatic detection of return types when you have more than one return statement 
because the standard doesn't guarantee the automatic detection of return types. Notice that the specification of the return types is based 
on the optional return value syntax introduced with C++11, which puts the return value after the function.

{ lambdaStatements; }: This is the lambda body. The statements within the lambda body can access the captured variables and the parameters.
*/

int foo() 
{
   return 0;
}

int main()
{
   int (*fcnPtr)() = foo;
}