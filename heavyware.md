# Software became Heavyware ...

In advance - I am biased - I am a "Smalltalker" - **Smalltalk** is a programming Language one of its inventors is [Alan Kay](https://en.wikipedia.org/wiki/Alan_Kay).
I am not going to convince you the reader about anything - just I am typing my thoughts into this document.

So what what is Heavyware - A first indication that Software is Heavyware is its pure size.
I am using **LOC** (Lines of code), executing it at a main folder of a software package - often the result is millions of lines. Heavy means here too large to understand just TL;TR. But Source code is for read and understand by human and a neat side effect is that it can be compiled & executed on a machine.

Millions of lines -  it must be a huge complex work - ok just browsing it a little and encounter statements like 
**Header only Library** - written in modern C++ ...

I am suspicious if something is called modern - I supposed a decade later it will be obsolete ...

## "Modern" C++
Header only means that for a Mini- "Hello-World" App which shows an OK button written in a modern C++ more than one million LOCs in hidden C++ .h files are generated to finally produce a 19k executable.

Software has changed - Smalltalk has failed when the Internet Language Java appeared - Software is mostly open-source - 
is compiled using large toolchains.

## back in the 80ies
When I started to write Software very few people could write software - and I was very proud to know the BSD-Kernel in the mid 80ies
I remember weakly it was about 500.000 lines of code and I spend 2 years almost reading every line of the C code.

I was always looking for improving my Software, used languages like Scheme & Prolog. After discovering Smalltalk I decided to make my living with it.

## Two types of languages
When I was young there were mainly 2 groups of languages - Pascal like & Lisp like.

## Two ways of writing software
And as today there were 2 ways of developing a program - the traditional write compile & test cycle & the way
interpreted languages did it: you change a system by adding functionality which is immediatly available. 

Smalltalk is object oriented - OO simply means you group functions with data. So the function name print can be reused on different data structures.
Data-Structure + functions = Object.

## Evolution of C
OO is more elegant - where you need to write Date_print & Time_print in C 
and pass the data structure ( here a Date or a Time) usually as the first parameter - also

``` Date_print(Date *p_date, ...)``` and 
``` Time_print(Date *p_time, ...)```

Arguments to functions should fit into a stack slot. And the * denotes a pointer to data.If you allocate a Date in pure C then you write 

```Date *p_date = malloc(...)``` or if you have a global date then you write 
```Data date &``` to obtain a pointer then it is ```p_date = &date; ```.
To access an element of a Date you write 
```date.month``` or ```p_date->month```
The * denotes a pointer declaration or a dereference operation wile the & is 
the opposite of a "deref" operation -namely the reference operation.

then you can pass the p_date pointer to a function.
if you want to pass date to a function which expects a pointer you simple have to reference it: 

```Date_print(&date)```

## C + OO = C++ ?
The transition from C to C++ was simple: structures where extended to classes
which made it possible to invoke print ( now print is a method because its 
obligatory parameter is a pointer to the class instance ) - the pointer to the 
structure where it is operating on.
you don't need to list this pointer in the argument list - but if you need it is the method body it is simply the this. 

As said pointers where disliked and a source of errors.
And so the next invention was to allow variables to be References - naturally the & is the way how to declare a variable to be a reference.

So C was evolving into C++ ( the ++ denotes the "enhanced C ) . Bit since then
C++ was constantly enhanced with new features and C became C98, C99 and finally C17 and C21.

## Smalltalk (excursus)
Not so with Smalltalk - Smalltalk's syntax fits on one A4 page.
Smalltalk has many dialects - and despite its simple syntax it is difficult to port fro one dialect to another. Dialects denotes differences in the language runtime - the predefined classes & methods.
There are a few enhancements & differences in semantic of the Smalltalk blocks (extension was full block closures) and a Mixin's ( Smalltalk traits )
& name spaces.

Why Smalltalk failed ? - For long time Smalltalk was said to be slow. While C & C++ are compiled Smalltalk was interpreted & is today jitted. Because everything is an object - you can't allocate objects on the stack. only Object-pointers live on the stack.

- Smalltalk is image-based and lacked a good import system so it was difficult to exchange Smalltalk source code.

- In Smalltalk everything can be changed so you can add methods to classes which would be sealed in other languages.

- So name clashes and other incompatibilities are the things when you want to take Smalltalk code from someone else.

- The image is just a snapshot of the running Smalltalk-System which can be saved on the disk & restored later.

- Smalltalk vendors failed to recognize the importance of enhancing the Web-Pages on the client side with methods - so java took that opportunity - Java can be thought of a sandboxed Smalltalk with C++ like Syntax.

- the statement Smalltalk has failed doesn't mean that companies are not using Smalltalk today - -it is just not mainstream - a modern Smalltalk with a large community is [Pharo](http://pharo.org) and a Windows Smalltalk is [Dolphin](https://github.com/dolphinsmalltalk).

## Other failures ( next excursus)
Another big player also missed the Internet age, Microsoft & fighting on a license issue with Sun, the inventor of Java - who disallowed change of the Java syntax - but Microsoft extended Java with delegates ( a notion for declaring method for callback) - So MS own Java, C# was born but Java ruled the browser world for some time until it was replaced by a more "smalltalkish" dynamic language Javascript.
Javascript has only the  "Java" in common with Java - it is more Smalltalk than Java - but it has a few semantic differences to Smalltalk - namely the way how classes are created. And again Microsoft missed it - Google took the turn and has a very sophisticated Javascript engine it its Chrome browser the Google V8 Javascript engine.
MS extended Javascript to be more "smalltalkish" and coming from a typed language background it invented Typescript - but Typescript is "transpiled" to Javascript.

## Back to C++ & again a bit Smalltalk
you can write in C++ ( its OO variant ) 
``` p_date->print(...)``` and ```p_time->print(...)```

But Smalltalk allows to write 
```date print``` and ```time print```
Smalltalk follow the english language and you write 
```object message ```
or
```object message: arg1```
or
```object message: arg1 and: arg2```

Smalltalk uses **infix** names. In the above example the method name is ```message:and:```

Smalltalk is readable - because everything is a pointer you don't need to denote a pointer.
### Caution: Different execution order

In C if you have ```f1(f2(),f3())``` you should be aware that evaluation takes place from **right to left** ( R2L).
In Smalltalk you would have self f1: self f2 arg2: self f3. And evaluation is from **left to right** (L2R). 
Pointers are disliked and so the reference operator & was introduced.

f2 and f3 can produce side effects and to make it clear you need to expand the more readable Smalltalk form in C to
```
arg1 = f2();
arg2 = f3();
f1(arg1, arg2);
```
To make the evaluation order explicit. The R2L evaluation order in C has a technical reason. It is allowed in C that you pass a variable number of arguments to a function. Because arguments are passed onto the system stack the convention is that the first arg is always on the stack top ( after the saved frame pointer & the return address). So the compiler evaluates the right most argument first and pushes it onto the stack, ending wit the first argument.

This historical way of passing arguments adds to the LOCs of a C program because you will need to expand the nested short form where you pass evaluation results directly as arguments to avoid the R2L evaluation 

The name Smalltalk denotes a **small talk** to a machine. Today's C++ is just a **huge mess** - which luckily can be executed by computers.

Software consists more of declaring types - which exact meaning is only obvious to the writer ( hopefully ) and restricting the use ( public / private / sealed) and whether it can be modified ( const ) or whether it is "virtual" which has more than one meaning namely a way to declare that it can or has to be defined in the subclasses.

Another "trick" or maybe technique is to preprocess the source code before passing it to the compiler.

Preprocessor statements starts with #.

Preprocessing allows to abbreviate things - that you would like to have somehow as a language feature. On the first glance this seems to solve a lot of problems - but every medal has two sides.

Because of the compiler has no view of the real source - debugging code which contains preprocessor statements becomes a nightmare.
Because this downside is accepted for years - more obscure things where added to the C++ language: templates.

Without the existence of templates you would have to duplicate some type of C++ code a lot.

Image you have a single linked list of integers

``` typedef struct { struct integer_linked_list*next; int value; } integer_linked_list;```

If you want to have a similar list of float you would need a new type

``` typedef struct { struct integer_linked_list*next; float value; } integer_linked_list;```

With templates you can abbreviate this 

```typedef template struct { struct integer_linked_list<T> *next; <T> value; } integer_linked_list<T>;```

```
integer_linked_list<int> int_list;
integer_linked_list<float> float_list;
```

The compiler generates internally an instance class for every T. Because of the pointer arithmetic (PA) every method which uses PA on a a template class type must be generated of its own. This is why an executable grows so big as today.

Templates, macros, operators and implicit casting adds to the unreadability of today's source code.

## Another dispute Memory Management
C++ has no automatic memory management but a mechanism - [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) to achieve it.

But memory management bois down to allocate/free memory on the Heap which is rather slow.
**RAII** introduces another bunch of implicit operations in your code.

Implicit casting of arguments
To avoid to have to write casting operations when you pass incompatible variables C++ generates implicit casts based on the lookup of available operators of the source type to compute the target type.

f(a) generates f(a->argType1()).

Innovation seem to need single persons - a new C like language which exactly avoids all the C++ implicitness appeared - [ZIG](https://ziglang.org) Andrew Kelley - its inventor explains the different design [here](https://github.com/ziglang/zig/wiki/Why-Zig-When-There-is-Already-CPP,-D,-and-Rust%3F).
