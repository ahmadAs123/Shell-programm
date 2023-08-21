shell programm final 
‏Authored by Ahmad Abu Sbeih
322786757

‏==Description==
‏The program is a shell programm, this progrem read a sentence from the user and then check if this sentence is a legal and the shell can run this command or  the shell will print on the screen that this sentence is not suppported in the shell after that we save this command in a fule called file.txt and count all the command that the user input in a variable countwords  also we add the pipes that can make two prosses in the same time we can use one or 2 ,and the & that will activates the command that we write in the background of the shell ,also we add the nohup that will make the  result of the command appears in a file and when we use this word the programm will continue  after we write the word

Program DATABASE
 like the second proggram ,every sentence we write it into the programm ,  it will be saved in a file with a name"file.txt" if the file wasnt existed then the programm will make and open a new file after that we can take commands from this file and run it on the shell also we can 

‏Functions
‏ functions in the programm  is  the main function and wordcounterf  and lettercounterf and find_words_and_save,find_words_left_pipe,find_words_right_pipe,find_words_middle_pip,find_words_right1_pipe the woedcounterf its a function that  sum all the words in the sentence that the user input ,  the same thing with lettercunterf but the diffrence is the lettercounterf sum all the letters in the sentence, and find_words_and_save it a function that make an array 2d according to the wordcounter +1 and the lettercountter+1 and puts all the words into this  array with NULLin the last undex of the array and make a fork function and send to the son to run on all the command by execvp function ,the find_words_left_pipe will find the word that is on the left of the | ,find_words_right1_pipe will also find the word on the right of | 
find_words_middle_pipe will find the word that between 2 pipes,find_words_right_pipe will find the word in right of the second pipe all these function also put these words in arrays for activating them by using excvp function ,

‏==Program Files==

‏ex3.c: this file  contains the main programm. and all the functions

‏==How to compile?==
 
for ex3.c :     ‏compile: gcc ex3.c -o ex3
‏run: ./ex3


‏==Input==
‏a string  that the length of it is less than 512  characters

‏==Output:== 
the job of the command that the user puts in the shell
‏int ( number of the words in all comands after we write done  in the input)
‏int ( number of the comands after we write done  in the input)
string (the history of all the words that the user input)
string(if we put cd there will be a message that tell us that this command is not supported yet)
string (if we use nohup the output will appears in file)
