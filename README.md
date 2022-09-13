# Restaurant_VideoGame

## Description

<p>This project was build using the open source C++ toolkit OpenFrameworks. The project was part of the 
course Advance Programming or also known as Object Oriented Programming course. <p/>


## Set Up Everything

> Only for Windows OS.  
<br>  

1. Go to the [OpenFrameworks](https://openframeworks.cc/download/) download section and look for the [setup guide for msys2](https://openframeworks.cc/setup/msys2/).
2. Follow the docs on how to install everything.
> If an error occur while compiling related to 'ofOpenALSoundPlayer.h' go to "libs/openFrameworks/sound/ofOpenALSoundPlayer.h" file and change 
>the line "typedef	struct SNDFILE_tag	SNDFILE;" for "typedef	struct sf_private_tag	SNDFILE;".

3. Clone the repo into the "your_oF_directory/apps/myApps" directory. It should look like this "your_oF_directory/apps/myApps/Restaurant_VideoGame/src".
4. Open the workspace on Visual Studio Code, open the terminal and run the command **_make_**.
> It should start compiling, it would take a while.  
> After the program compile run the command **_make RunRelease_**. A window will pop up with the game. Enjoy!  



> **Note:** If only interested on seing the different levels go to "src\Game\States\MenuState.cpp" and change "int State::lever = 1" to '2' or '3'.
<br>
<br>  

> ## Menu  

![image](https://user-images.githubusercontent.com/70610617/189815940-84955fe1-1d7b-43e3-b82d-fe87cb773711.png)  
<br>
<br>  

> ## Level 1
![image](https://user-images.githubusercontent.com/70610617/189816043-01ef02b0-7785-4e95-a5c2-6ff3cf135029.png)  
<br>
<br>  

> ## Level 2
![image](https://user-images.githubusercontent.com/70610617/189816217-e906fb42-b252-496e-9e5b-fa0a29c25c56.png)  
<br>  
<br>  

> ## Level 3
![image](https://user-images.githubusercontent.com/70610617/189816413-866e877e-987e-4995-a86e-8aec8339436e.png)
