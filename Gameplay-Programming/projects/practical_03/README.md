# README #

This project is a Makefile starter kit for a console-based turn-based game titled **Player vs NPC**. It serves as a foundation for learning object-oriented programming concepts in C++ through a simple game structure.

## Project Overview
**Player vs NPC** is a console-based turn-based game where players can engage in strategic battles against non-player characters (NPCs). The game emphasizes object-oriented programming concepts in C++, allowing players to develop their skills while enjoying gameplay.

## Table of Contents
- [Project Overview](#project-overview)
- [Code Structure](#code-structure)
- [Classes Diagram](#classes-diagram)
- [Prerequisites](#prerequisites)
- [Instructions for Linux](#instructions-for-linux)
- [Instructions for Windows using MSYS2](#instructions-for-windows-using-msys2)
- [Set Up Your Environment](#set-up-your-environment)
- [Clone the Repository](#clone-the-repository)
- [Build the Project](#build-the-project)
- [Running the Game](#running-the-game)
- [Useful Resources](#useful-resources)
- [Who do I talk to?](#who-do-i-talk-to)

## Code Structure

- **GameObject**: An abstract class that defines common properties and methods for all game objects, including:
    - **Health**: Represents the current health of the game object.
    - **Methods**: Includes pure virtual methods for `attack` and `walk`, as well as a virtual method for `defend`.

- **Player**: Inherits from `GameObject` and represents the player character in the game. It includes:
    - **Methods**: Specific implementations for `walk`, `attack`, and `defend`, as well as a unique method for `charge`.

- **NPC**: Also inherits from `GameObject` and represents the non-player character. It includes:
    - **Methods**: Specific implementations for `walk`, `attack`, and `defend`, as well as a unique method for `taunt`.

### Classes Diagram
[![](https://mermaid.ink/img/pako:eNrdVE2P0zAQ_Ssjn1q0y5ZrgQMUBAgtrdQ95jJrTxqzjh0546Jq2f_OOOm2abOiB25YkeKPN2_evDjzqHQwpOZKO2zbTxY3EevC-8AEhVouYRF8GxzBF6zpNdxVtgV5ENaMkcl8twwcYBWDSZpk_y5FDx-xJXMSWqg9aRlit7G8_0maJceH-5YjynSRFWRc4TsxA1jhQcYg7N3v62tYOdxRfPnsx2pxfjAfzCfWM1TwHt7MZtMxMJ9uiL8SOq4mU9BSCY9hWxs5oYNtsAaQGfXDZCDklVgkLFNJM7sQbKgkbyZjKSeoX-geMuZoUW_BYx92SUbYUozWUMbe3MC3unFUk2dkGzyEEpoU6aCrJ4KauApmkOBZ6gndeEiCZZOJ0bndEdtHj1n70i5wdqzrhrQtrQY70v_sz4FVV7l04f37ENbbTlB3O3tP863uw4Er6u_T09F4Wf8HrjMmzxftOfNHSs_mdLGdN83gP3zpY779548p1qsrVVOs0RppVp31hZLkubPMZSoVYnKc20eGYuKw3nmt5hwTXakY0qZS8xJdK6vUGGTaN7uz3c_GcoiHTeqWt_semV9PfwDTXKYh?type=png)](https://mermaid-js.github.io/mermaid-live-editor/edit#pako:eNrdVE2P0zAQ_Ssjn1q0y5ZrgQMUBAgtrdQ95jJrTxqzjh0546Jq2f_OOOm2abOiB25YkeKPN2_evDjzqHQwpOZKO2zbTxY3EevC-8AEhVouYRF8GxzBF6zpNdxVtgV5ENaMkcl8twwcYBWDSZpk_y5FDx-xJXMSWqg9aRlit7G8_0maJceH-5YjynSRFWRc4TsxA1jhQcYg7N3v62tYOdxRfPnsx2pxfjAfzCfWM1TwHt7MZtMxMJ9uiL8SOq4mU9BSCY9hWxs5oYNtsAaQGfXDZCDklVgkLFNJM7sQbKgkbyZjKSeoX-geMuZoUW_BYx92SUbYUozWUMbe3MC3unFUk2dkGzyEEpoU6aCrJ4KauApmkOBZ6gndeEiCZZOJ0bndEdtHj1n70i5wdqzrhrQtrQY70v_sz4FVV7l04f37ENbbTlB3O3tP863uw4Er6u_T09F4Wf8HrjMmzxftOfNHSs_mdLGdN83gP3zpY779548p1qsrVVOs0RppVp31hZLkubPMZSoVYnKc20eGYuKw3nmt5hwTXakY0qZS8xJdK6vUGGTaN7uz3c_GcoiHTeqWt_semV9PfwDTXKYh)

### Prerequisites
1. **Visual Studio Code**
   - Download and install [Visual Studio Code](https://code.visualstudio.com/).

2. **C/C++ Extension for Visual Studio Code**
   - Install the C/C++ extension by searching for `@ext:ms-vscode.cpptools` in the Extensions view (`Ctrl+Shift+X`).

### Instructions for Linux
1. **Build Tools for Linux**
   - Run the following command in your terminal:
     ```bash
     sudo apt install build-essential gdb
     ```
   - This installs essential build tools and the GDB debugger.

### Instructions for Windows using MSYS2
1. **Install MSYS2**
   - Download MSYS2 from [msys2.org](https://www.msys2.org/).
   - Follow the installation instructions provided on the website.

2. **Update the Package Database**
   - Open the MSYS2 terminal and run:
     ```bash
     pacman -Syu
     ```
   - Close the terminal and reopen it.

3. **Install Necessary Packages**
   - Install the GCC compiler and make utility:
     ```bash
     pacman -S mingw-w64-x86_64-toolchain make
     ```
   - Make sure to add MSYS2 to your system path to access the tools from anywhere.

## Set Up Your Environment

- Open the **MSYS2 MinGW 64-bit** terminal to ensure you are using the correct environment.

## Clone the Repository

- Navigate to your desired directory and clone the repository:

    ```bash
    git clone https://MuddyGames@bitbucket.org/MuddyGames/oo-console-game.git
    cd oo-console-game
    ```

## Build the Project

- Run the `make` command to build the project:

    ```bash
    make
    ```

## Running the Game

- After building the project, you can run the game with the following command:

    ```bash
    ./game
    ```

## Useful Resources ##
* [GNU Make Manual](http://www.gnu.org/software/make/manual/make.html)
* [Makefile Tutorial](https://makefiletutorial.com/)
* [GDB GNU Debugger Project](https://www.gnu.org/software/gdb/)
* [Enabling build and debugging in Visual Studio Code](https://dev.to/talhabalaj/setup-visual-studio-code-for-multi-file-c-projects-1jpi)
* Debugging with VSC beyond return point may result in the following error message being displayed [pop up](https://github.com/Microsoft/vscode-cpptools/issues/1123)

## Who do I talk to? ##
* philip.bourke@setu.ie