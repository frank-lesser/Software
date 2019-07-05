# LSW-WinFile
Recently Microsoft released its old Windows 3.1 File-Manager [WinFile](https://github.com/microsoft/winfile), which this tool is build on.

It is a Test-bed for my AI-Tools which helps to "renovate" Software.

It contains [Scintilla](https://scintilla.org).
Clicking on a file displays its content in a Scintilla MDI-Child Window - the **Terminal-Window**. Clicking on files in the right pane of a **Folder-Window** shows
the File-Content in the **Terminal-Window**.

- Terminal-Window ( **TW**)

  if you run Windows 1903, the **TW** acts as an Output-Console for Consol-Programs started via Context-Menu **Run..** 
## Addons
WinFile-Addons are DLLs which are listed in **WinFile.ini** [Addons] inserts into the Main-Menu. All the Addons are WIP and in an early state.

 - Binary

   allows to view the structure of an Windows Binary ( exe & dll). Currently only Exports are supported.

- [C](https://bellard.org/tcc/) 

  C can be directly evaluated. The C code is compiled to memory and executed from there. Compilation is fast & instant.
  
  Save the text below in a C-File, select it in a Folder-Window and click on Menu **C -> Execute**.
  The result is shown in the Terminal-Window (result = 3628800)

    int fac(n) {
	   if (n == 0)
		    return 1;
	   else
		    return fac(n-1) * n;
    }
    int main(int argc, char **argv) {
	    return fac(10);
    }

  The C-File is compiled dynamically before the main is executed. The underlying TCC is very fast - Windows GUI is also supported & an example will be added soon.

  **New**
  - Win32 GUI

    [hello_win.c](C/hello_win.c) is an example for win32 GUI compilation.
       
    
  - [Nuklear](https://github.com/vurtun/nuklear) was added to InstantC.

    [gdidemo.c](nuklear/example/gdidemo.c) is an example of a "Nuklear-Window" driven by GDI, GDIPlus, OpenGL & D3D11 will be implemented soon. Currently executing gdidemo.c shows warnings which can be ignored. On some computers it gives errors that style.c can't be found. Simply comment INCLUDE_STYLE to get it executed.
    gdidemo includes calculator.c, node_editor.c & overview.c. The Node_editor window hides the other windows in the sample (it can be moved away by clicking & dragging at the upper border) .
  

- [Compressed](https://www.7-zip.org)

  Menu **Compressed->View** List the contents of a 7z-File.

- Hash
  Shows CRC32, MD5 & SHA1 Hashes of files. Currently only files < 4GB are supported.

- [Javascript](https://github.com/microsoft/ChakraCore)

  Javascript can be directly evaluated.
  You need to Add the JavaScript Plugin in **WinFile.ini**.
  Select a Javascript file & click on Menu **Javascript->Execute**.
  The result is displayed in the Terminal Window.

- JSON
  **JSON** allows to execute commands which are build by building a "shell command" from JSON incorporating the current File/Directoy as arguments
   
- [PDB](https://msdn.microsoft.com/en-us/library/windows/desktop/aa363368(v=vs.85).aspx) (Program Database Symbol File format)

Menu **PDB->Dump** will show the contents of PDB in the Terminal-Window. Caution because PDB-Files can be a few 100 MB this can take longer. 

- [Python](https://cython.org)

  C-Python based python execution ( WIP )

- URL

  Menu **URL->Download** will show the content of an URL in the TW. **URL** is based on [CURL](https://curl.haxx.se) 

## LSW-WinFile.ini

**LSW-WinFile.ini** is located at <C:\Users\<YourName>\AppData\Roaming\LSW>


## Bugs
- If you close the **TW** there is no way to open the **TW** other than to restart **WinFile-LSW**
- Saved Windows are duplicated so you have to edit WinFile.ini manually to delete the Windows. 

I plan to add:
- [Rust](rust-lang.org)

  Rust-Files can be directly evaluated

- Smalltalk

  Smalltalk can be directly evaluated

- Mercury

  Mercury can be directly evaluated

- ZIG

  Mercury can be directly evaluated