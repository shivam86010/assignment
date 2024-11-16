
/*
 
difference b/t Constructor and Method

It is a block of code that initializes a newly created object.

It is a group of statements that can be called at any point in the program using its name to perform a specific task.

It has the same name as the class name.

It should have a different name than the class name.

It has no return type.

It needs a valid return type if it returns a value; otherwise void.

It is called implicitly at the time of object creation

It is called explicitly by the programmer by making a method call

If a constructor is not present, a default constructor is provided by Java

In the case of a method, no default method is provided.



What is the difference between class and structure?

Class: User-defined blueprint from which objects are created. It consists of methods or sets of instructions that are to be performed on the objects.

Structure: A structure is basically a user-defined collection of variables of different data types.

Interview Questions
 
What is the difference between deep copy and shallow copy?

Shallow Copy stores the references of objects to the original memory address.   	
Deep copy stores copies of the object’s value.
Shallow Copy reflects changes made to the new/copied object in the original object.
	Deep copy doesn’t reflect changes made to the new/copied object in the original object.
Shallow Copy stores the copy of the original object and points the references to the objects.	
Deep copy stores the copy of the original object and recursively copies the objects as well.
Shallow copy is faster.	Deep copy is comparatively slower.




Advantages Of Abstraction
Only you can make changes to your data or function, and no one else can.
It makes the application secure by not allowing anyone else to see the background details.
Increases the reusability of the code.
Avoids duplication of your code.


Interview Questions

What is the difference between Abstraction and Encapsulation?
 
Abstraction

Encapsulation

Abstraction is the method of hiding unnecessary details from the necessary ones.	
Encapsulation is the process of binding data members and methods of a program together to do a specific job
 without revealing unnecessary details.
Achieved through encapsulation.	You can implement encapsulation using Access Modifiers (Public, Protected
 & Private.)
Abstraction allows you to focus on what the object does instead of how it does it.	Encapsulation enables 
you to hide the code and data into a single unit to secure the data from the outside world.
In abstraction, problems are solved at the design or interface level.	While in encapsulation, 
problems are solved at the implementation level.
 

How much memory does a class occupy?
Classes do not consume any memory. They are just a blueprint based on which objects are created. When objects 
are created, they initialize the class members and methods and therefore consume memory.


What is the difference between overloading and overriding?
Overloading is a compile-time polymorphism feature in which an entity has multiple implementations with the 
same name—for example, Method overloading and Operator overloading.

Whereas Overriding is a runtime polymorphism feature in which an entity has the same name, 
but its implementation changes during execution. For example, Method overriding.



What are the advantages of Polymorphism?
There are the following advantages of polymorphism in C++:

a. Using polymorphism, we can achieve flexibility in our code because we can perform various operations by using methods
with the same names according to requirements.

b. The main benefit of using polymorphism is when we can provide implementation to an abstract base class or an interface.

What are the differences between Polymorphism and Inheritance in C++?
The differences between polymorphism and inheritance in C++ are as follows:

a. Inheritance represents the parent-child relationship between two classes. On the other hand, polymorphism takes advantage
of that relationship to make the program more dynamic.

 

b. Inheritance helps in code reusability in child class by inheriting behavior from the parent class. On the other hand, 
polymorphism enables child class to redefine already defined behavior inside parent class.

Without polymorphism, a child class can’t execute its own behavior.


Virtual Function

Virtual Function-

A virtual function is a member function in the base class that we expect to redefine in derived classes. It is declared using
the virtual keyword.

A virtual function is used in the base class to ensure that the function is overridden. This especially applies to cases where
a pointer of base class points to a derived class object.

 

Example:

#include <iostream>using namespace std;class Base {   public:    virtual void print() {        cout << "Base Function" << endl;    }};class Derived : public Base {   public:    void print() {        cout << "Derived Function" << endl;    }};int main() {    Derived derived1;    // pointer of Base type that points to derived1    Base* base1 = &derived1;    // calls member function of Derived class    base1->print();    return 0;}Output: Derived Function
 

 

C++ determines which function is invoked at the runtime based on the type of object pointed by the base class pointer when 
the function is made virtual.

 

Pure Virtual Function:

A pure virtual function is a virtual function in C++ for which we need not write any function definition and only have to
declare it. It is declared by assigning 0 in the declaration. 

Syntax:

class A {   public:      virtual void s() = 0; // Pure Virtual Function};
 

A pure virtual function (or abstract function) in C++ is a virtual function for which we can implement, But we must override
that function in the derived class; otherwise, the derived class will also become an abstract class.

The virtual function should be declared in the base class. So that when the derived class inherits from the base class, the 
functions can be differentiated from the one in the base class and another in the derived class.






Friend Function-

If a function is defined as a friend function in C++, then the protected and private data of a class can be accessed using 
the function.

 

A class’s friend function is defined outside that class’s scope, but it has the right to access all private and protected 
members of the class. Even though the prototypes for friend functions appear in the class definition, friends are not member
functions.

 

A friend function in C++ is a function that is preceded by the keyword “friend.”

 

Syntax:

class class_name {    friend data_type function_name(argument); // syntax of friend function.  };
 

The function can be defined anywhere in the program like a normal C++ function. The function definition does not use either
the keyword friend or scope resolution operator.

 

Example:

#include <iostream>using namespace std;class Rectangle {    private:        int length;    public:        Rectangle() {            length = 10;        }    friend int printLength(Rectangle); //friend function    };int printLength(Rectangle b) {    b.length += 10;    return b.length;}int main() {    Rectangle b;    cout << "Length of Rectangle: " << printLength(b) << endl;    return 0;}Output:Length of Rectangle: 20 
 

Characteristics of friend function:

A friend function can be declared in the private or public section of the class.

It can be called a normal function without using the object.

A friend function is not in the scope of the class, of which it is a friend.

A friend function is not invoked using the class object as it is not in the class’s scope.

A friend function cannot access the private and protected data members of the class directly. It needs to make use of a class 
object and then access the members using the dot operator.

A friend function can be a global function or a member of another class.

The keyword friend is placed only in the function declaration of the friend function and not in the function definition because
it is used to access a class member.


Interview Questions

 

Does every virtual function need to be always overridden?
No, It is not always mandatory to redefine a virtual function. It can be used as it is in the base class.

 

What is an abstract class?
An abstract class is a class that has at least one pure virtual function in its definition. An abstract class can never 
be instanced (creating an object). It can only be inherited, and the methods could be overwritten.

 

Can we have a constructor as Virtual?
Constructors cannot be virtual because they need to be defined in the class.


What is a pure virtual function?
A pure virtual function (or abstract function) in C++ is a virtual function for which we don’t have an implementation.
We only declare it. A pure virtual function is declared by assigning 0 in the declaration. See the following example.

 
What are the characteristics of Friend Function?
          A friend function is not in the scope of the class, in which it has been declared as friend.

          It cannot be called using the object of that class.

          It can be invoked like a normal function without any object.

          Unlike member functions, it cannot use the member names directly.

          It can be declared in public or private parts without affecting its meaning.

          Usually, it has objects as arguments.






.
Disadvantages of OOp

Steeper learning curve: OOP introduces complex concepts like classes, objects, inheritance, 
and polymorphism, making it harder for new programmers to grasp and apply them effectively.








































