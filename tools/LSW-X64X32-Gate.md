# LSW X64-X32 Gate

LSW Windows x64 32-Bit Gate

A small thunk layer to mix 32 bit & 64 Bit code in a new way.

The **LSW x64-32-Bit Gate** ( is a 64-bit Dll named LSWx64-32-Gate.dll )
can load 32-bit Dlls into a 64 bit process.

The LSW x64-32-Bit Gate ( in short *LSWX6432G* ) is implemented in pure
C with MSVC 2015.

- **LSWX6432G** enables to run 32 Bit code under x64 Bit Windows.

- **LSWX6432G** is based on the _AMD64_ feature to switch between 32-bit
and 64 Bit.

It doesn't use WOW64 - so it works also under systems where _WOW64_
isn't installed.

- **LSWX6432G** uses JIT technology to create on the fly wrapper-code
based on API-Specifications of corresponding 64 Bit API functions if the
32 Bit function is invoked.

- As a neat side effect for instance using _MS UCRT_ memcpy's bandwidth
is increased by a factor of 2 when invoked from 32 Bit code since the
underlying implementation is the 64 bit memcpy.

- **LSWX6432G** will not break in the future as the _Heaven's Gate_ which
enabled 32 bit code running under WOW64 to reload the 64-bit
Kernel32-dll since it is a pure 64-Bit Dll.

- **LSWX6432G** can be used to freely mix 64-Bit and 32-Bit code without
the need to design complex communications between 32-Bit and 64-Bit
processes.

 **LSWX6432G** provides a small set of functions to load use 32-bit
code:

- ### LoadModule32[AW] (LP[W]STR) moduleName) :

  Loads a 32 Bit PE ( Dll or Exe ) into a 64-Bit Process
performing all necessary operations as imports, relocations or execution
of entry-points.

  Returns a HModule32 or NULL

- ### GetProcAddress32(HModule32, hModule32, LPSTR *procName):
  Returns a pointer to the 32-Bit function which can be invoked
from 64-Bit

- ### BOOL UnloadModule32(HModule32, hModule32)

  Discards a 32-Bit Module

There is a set of functions providing extra-control:

  - LoadModule32 [AW]Ex, 
  - GetProcAddress32Ex, 
  - UnloadModule32Ex.

 

**LSWX6432G** provides a larger set of functions (GenXXX ) to control
the custom wrapper generation of 64bit code not described here.

32 Bit code loaded with LoadModule32[AW] can access the 64-Bit world
using a small set of functions:

- LoadLibrary64 [AW], 
- GetProcAddress64, 
- FreeLibrary64.

 **LSWX6432G** wrapper specifications are compiled as 64 Bit Dll's -
which are loaded on-demand in the 64 Bit process. For each 32-Bit DLL (
e.g. kernel32, user32, gdi32 or vcruntime140 ) exists a corresponding
64bit wrapper in the lsw64-32 subdirectory.

The wrapper covers all complex scenarios like calling back from 64 bit
code to 32 bit code & handling varargs.

**LSWX6432G** is in an early development state it is used to access 64
Bit in or *LSWGVM* Smalltalk VirtualMachine. It will be available under
various licence conditions.
