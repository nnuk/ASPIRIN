# Description and Queries
This file contains the step by step process from setting up the software to the results obtained in the end.


# Contents
1) Prerequisite
2) Installation of concerned compiler libraries
3) Reading from molfile
4) Extracting molecular formula from molfile


## (1) Prerequisite:
Before jumping into the problem itself, first, we must understand what softwares we want to work on so that it helps us in solving the problem quickly.
To solve this problem I worked with the following softwares.

###### (a) Microsoft Visual Studio 2017 (VS2017):
I worked with the community free version of VS2017. It has a very nice extension for github where you can easily make changes to your exsiting code and push the changes on Github.
The Github extension comes with all the features like push, pull, commit, add files etc.. It tells you which brach you are working on and so on with other useful information.

To avail this extension you have to go to Tools -> Extension and Updates -> Online (in a new pop window) and then search for Github for Visual Studio.
After downloading this extension, in a new pop window, you will be asked to enter the Github account details if you already have an account or else you can create a new account and follow up the process.
Now as your account is linked so now you can easily see in the right side menu about Github. You can create a new repo or clone a preexsisting repo on Github.
You can also make a project folder on your computer a repo.

The link to VS2017 is https://docs.microsoft.com/en-us/visualstudio/releasenotes/vs2017-relnotes. Here, you can download the latest version.

###### (b) Microsoft Visual Studio Code (VSCode):
This is also one of the best code editors as it supports multiple programming languages. You can easily install the specific programming extension which you prefer.
I in this case chose the C/C++ extension to support my code. To install the extension just click on the extension icon on the left side of VSCode window on the bar.
There are very easy to understand features like debugging and compiling the code.

The download link to VSCode for latest version is https://code.visualstudio.com/.


## (2) Installation of concerned compiler libraries:
The most important libraries needed to run the C code in VSCode are gcc, g++ and gdb. These are basically used for compiling the code.
To download and install these libraries, first, we must install MinGW-w64 which is a runtime enviroment created to support the GCC compiler on windows.
The download link for MinGW-w64 is https://www.mingw-w64.org/downloads/. In downloads pick the MSYS2 package and click on Installation : GitHub.
This will take you to the download page where you can select the installer execution file. The step by step process is given on this page https://www.msys2.org/.
Always choose the 64 bit version of MSYS2 because it only supports 64 bit machines (windows 7 or newer). While installing GCC, G++, GDB choose the 64 bit versions as they will be compatible with your machine and run smoothly.

Note: All the installations of GCC, GDB and G++ will take place in the MSYS2 MinGW x 64 app icon which can be found in windows search bar.

The next part is very important because now we want want our compilers to be added to the enviroment path.
For this, look into the folder you have installed MSYS2 (it will have name "msys64") open the folder then open "mingw64" folder go to bin and copy the path from the above search tab.
Now in the windows search tab write "Edit the enviroment variable", click on it. New window of "system properties" will pop up. At the bottom click on Enviroment Variables.
A new window pops up, look for "path" variable in System Variables and click once on it. Then click on edit.
A new "Edit Enviroment Variables" window pops up, click on add button on the top right and paste the path that you copied earlier. At the end click OK on all the open windows and now we are good to go with our C code in VSCode atlast.