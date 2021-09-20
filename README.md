# FoxitFlashcards
Foxit PDF plugin for creating study flashcards

To create a new icon for the plugin ribbon buttons:
> FoxitFlashcards/RibbonElements/res/
1. Open existing icon (pdf file) in Foxit PDF editor
2. Edit -> Add Shapes -> Add Path -> select the line path
The "Format" side bar should now appear
3. Click anywhere on the image (without drawing any new lines)
4. You should now be able to edit elements of the icon image.
5. Save your new icon image as a separate file

Icons are handled by "RibbonElements.cpp"
You will need to search the entire solution for "fs_bitmap", "IDR_PDF1", and "FR_Button". New instances of these elements will have to be created and implemented
