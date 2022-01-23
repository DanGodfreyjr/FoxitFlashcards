# Foxit Flashcards
Tool for creating study flashcards in a PDF file \

## Installation
To access Foxit Flashcards, first install [Foxit PDF editor](https://www.foxit.com/pdf-editor/). 
You will find the Foxit Plug-ins button under the Help tab.
\
\
![](https://i.snipboard.io/0IgGKP.jpg)

Install Foxit Flashcards. The plugin should appear in the ribbon bar next to the Help tab \
\
To begin creating a flashcard deck, open a PDF and highlight text. \
A prompt will appear. Enter text to represent the front side of the flashcard. \
Repeat for all other flashcards. 

## Features
New Flashcard - creates a new flashcard in the current deck \
Go to First - loads and relocates to the first flashcard in the current deck \
Previous Card - loads the card before the current card \
Next Card - loads the card after the current card \
Delete Card - deletes the current loaded card \
Quiz Mode - launches the quiz window; shuffles the flashcard deck \

## Additional Development
Open RibbonElements project folder in Visual Studio Code 2017 (version specific) \
Build the project (make sure Foxit PDF Editor is closed) \
Open RibbonElements.cpp. This file contains base ribbon elements, displays buttons and commands in the Flashcards tab. \
ElementsProc.cpp will assign functionality to elements declared in RibbonElements.cpp
NewFlashcard class handles flashcard creation and quiz mode

> Created by Jane Ran and Daniel Godfrey, 2021
