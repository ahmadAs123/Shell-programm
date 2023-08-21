#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>


//id: 322786757
int j=0;
char nohup[512];
int j4=0;
int  count4=0;
int j2=0;
int m=0;
int j11=0;
int count2=0;
int count = 0;
char res[512];
char res4[512];
char res1[512];
char res3[512];
char** argv;
char** argv1;
char**argv2;
char**argv3;

int count1=0;

int counterpipes=0;


int wordcounterf(char a[]){
    int i=0;
    int wordcounter1=0;
    while (a[i] != '\0')      //while we don't finish the string
    {



        if (a[i] != ' ' && a[i + 1] == '\0') //it is a word
        {
            wordcounter1++;
            break;
        }

        if (a[i] != ' ' && a[i + 1] == ' ') // it is also a word
        {
            wordcounter1++;
            i++;
        }

        i++;
    }
    return wordcounter1;
}



int lettercounterf( char a[]) {
    int i = 0;
    int lettercounter1 = 0;

    while (a[i] != '\0')      //while we don't finish the string
    {
        if (a[i]!=' '&& a[i]!='\0')
            lettercounter1++;
        i++;
    }
    return  lettercounter1;
}





void find_words_right1_pipe( char a[]) {  //the word in the right of the pipe |
    j2++;
    count2++;
    int l=0;
    count1=0;
    j11=0;
    strncpy(res1,&a[count2], (strlen(a)-count2));
    res1[(strlen(a)-count2)]='\0';
    argv1= (char **) malloc((wordcounterf(res1) + 1) * sizeof(char *));
    while(res1[j11]!='\0'){

        if(res1[j11]!=' '){

            j11++;
        }


        if(res1[j11]==' ') {

            strncpy(res, &res1[count1], j11 - count1);
            res[j11 - count1] = '\0';


            if (strcmp(res,"")!=0) {      //ther is a space in the first of the word that on the right of the pipe
                argv1[l] = (char *) malloc((lettercounterf(res) + 1) * sizeof(char));
                strcpy(argv1[l], res);
                l++;
            }

            while(res1[j11]==' '){

                j11++;
            }
            count1=j11;
        }

    }
    strncpy(res,&res1[count1],j11-count1);
    res[j11-count1] = '\0';
    argv1[wordcounterf(res1)-1] = (char*)malloc((lettercounterf(res)+1)*sizeof(char));
    strcpy(argv1[wordcounterf(res1)-1],res);
    argv1[wordcounterf(res1)] = NULL;
    j11=0;
    count2=0;
    count1=0;



}




void find_words_middle_pipe( char a[]) {  //the word in the right of the pipe |
    j2++;
    count2++;
    int s=0;
    int sec_pipe=0;
     j4=0;
     count4=0;

    for (int d=count2; a[d]!='|'&&d< strlen(a);d++){    // to take the first sentence on the the left pipe and work on ut after that

        sec_pipe++;

    }

    strncpy(res4,&a[count2], sec_pipe);
    res4[sec_pipe]='\0';


    argv3= (char **) malloc((wordcounterf(res4) + 1) * sizeof(char *));

    while(res4[j4]!='\0'){


        j4++;



        if(res4[j4]==' ') {

            strncpy(res, &res4[count4], j4 - count4);
            res[j4 - count4] = '\0';


            if (strcmp(res,"")!=0) {      //ther is a space in the first of the word that on the right of the pipe
                argv3[s] = (char *) malloc((lettercounterf(res) + 1) * sizeof(char));
                strcpy(argv3[s], res);
                s++;
            }

            while(res4[j4]==' '){

                j4++;
            }
            count4=j4;
        }

    }
    strncpy(res,&res4[count4],j4-count4);
    res[j4-count4] = '\0';
    if(strcmp(res,"")==0);
    else {
        argv3[wordcounterf(res4) - 1] = (char *) malloc((lettercounterf(res) + 1) * sizeof(char));
        strcpy(argv3[wordcounterf(res4) - 1], res);
        argv3[wordcounterf(res4)] = NULL;

        count4 = j4;
    }

}



void find_words_right_pipe( char a[]) {  //the word in the right of the pipe |
    j4++;
    count4++;
    int z;
    int l=0;
    j11=0;
    // printf("%d\n",z);

    int back_slash_locatoion=0;
    for (z=count4+count2; z<strlen(a)&&a[z]!='\0';z++){    // to take the first sentence on the the left pipe and work on ut after that

        back_slash_locatoion++;

    }
  //   printf("%d\n",back_slash_locatoion);
    strncpy(res1,&a[count4+count2], back_slash_locatoion);
    res1[back_slash_locatoion]='\0';
    // printf("%s",res1);
    argv1= (char **) malloc((wordcounterf(res1) + 1) * sizeof(char *));

    while(res1[j11]!='\0'){


        j11++;


        if(res1[j11]==' ') {

            strncpy(res, &res1[count1], j11 - count1);
            res[j11 - count1] = '\0';

            if (strcmp(res,"")!=0) {
                //ther is a space in the first of the word that on the right of the pipe
                argv1[l] = (char *) malloc((lettercounterf(res) + 1) * sizeof(char));
                strcpy(argv1[l], res);
                l++;
            }


            while(res1[j11]==' '){

                j11++;
            }
            count1=j11;
        }

    }
    strncpy(res,&res1[count1],j11-count1);
    res[j11-count1] = '\0';
    if(strcmp(res,"")==0);
    else {
        argv1[wordcounterf(res1) - 1] = (char *) malloc((lettercounterf(res) + 1) * sizeof(char));
        strcpy(argv1[wordcounterf(res1) - 1], res);
        argv1[wordcounterf(res1)] = NULL;
        count1 = 0;
        j11 = 0;
    }
}







void find_words_left_pipe( char a[]) {  //the word in the left of the pipe |
j2=0;
    int pipe_mark=0;
    count2=0;
    int h= 0;




    for (m=0; a[m]!='|';m++){    // to take the first sentence on the the left pipe and work on ut after that

        pipe_mark++;

    }

    strncpy(res3,&a[0], pipe_mark);
    res3[pipe_mark]='\0';
    argv2 = (char **) malloc((wordcounterf(res3) + 1) * sizeof(char *));
    while (res3[j2] != '\0') {


        j2++;


        if (res3[j2] == ' ') {

            strncpy(res, &res3[count2], j2 - count2);
            res[j2 - count2] = '\0';


            argv2[h] = (char *) malloc((lettercounterf(res) + 1) * sizeof(char));
            strcpy(argv2[h], res);
            h++;


            while (res3[j2] == ' ') {

                j2++;
            }
            count2 = j2;
        }

    }
    strncpy(res, &res3[count2], j2- count2);
    res[j2 - count2] = '\0';
    if(strcmp(res,"")==0);
    else{
        argv2[wordcounterf(res3) - 1] = (char *) malloc((lettercounterf(res) + 1) * sizeof(char));
        strcpy(argv2[wordcounterf(res3) - 1], res);
        argv2[wordcounterf(res3)] = NULL;}
    count2 = j2;

}






    void find_words_and_save( char a[]){

     j=0;
    int k=0;
    count=0;
    argv= (char**)malloc((wordcounterf(a)+1)*sizeof(char*));

    while(a[j]!='\0'){

        if(a[j]!=' '){

            j++;
        }


        if(a[j]==' ')  {

            strncpy(res,&a[count],j-count);
            res[j-count] = '\0';



                argv[k] = (char*)malloc((lettercounterf(res)+1)*sizeof(char));
                strcpy(argv[k],res);
                k++;


           while(a[j]==' '){

                j++;
            }
            count=j;
        }

    }
    strncpy(res,&a[count],j-count);
    res[j-count] = '\0';
    argv[wordcounterf(a)-1] = (char*)malloc((lettercounterf(res)+1)*sizeof(char));
    strcpy(argv[wordcounterf(a)-1],res);
    argv[wordcounterf(a)] = NULL;



}







int main() {
    int current = 1;
    char num_line[10];
    char command[512];
    pid_t pid;
    char a[512];
    char str[512];
    FILE *fp;
    int i = 0;
    int commandscounter = 0; //count the words
    int wordcounter = 0;//count the letters




    while (1)    {  // loop

        char cwd[200];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s->", cwd);
        }

        else {
            perror("getcwd() error");
            return 1;
        }


        fgets(a, 512, stdin);       //get from the user a string
        a[strlen(a) - 1] = '\0';



        strncpy(nohup,&a[0],5); //check if the first word is nohup
        nohup[5]='\0';
      //  printf("%s",nohup);

      /*  if(strcmp(nohup,"nohup")==0){

            int file_nohup_ = open("nohup.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
            if (dup2(file_nohup_, STDOUT_FILENO) == -1) {//Make the output appear in a file named nohup.txt
                fprintf(stdout, "error!!!! \n");
                exit(1);
            }



            char nohup_res[512];
            strncpy(nohup_res, &a[6], strlen(a) - 6);
            nohup_res[strlen(a) - 6] = '\0';
          //  printf("%s\n", nohup_res);
            find_words_and_save(nohup_res);
          int  pid = fork();//make a son
            if (pid < 0) {
                perror("error!");
                exit(0);
            } else if (pid == 0) { //its the son

                int status = execvp(argv[0], argv);

                if (status == -1) {
                    perror("Terminated Incorrectly\n");
                    exit(1);

                }
            } else {
                wait(NULL);


        }


    }*/



        for (int aj = 0; aj < strlen(a);aj++){ //search for | in the string we ,usr find or 1 or 2 that will work anything else will be error
            if (a[aj] == '|') {
                counterpipes += 1;
            }
        }



        if (wordcounterf(a) != 0)
            commandscounter++;


        if (strcmp(a, "done") == 0) {         //check if the string was  the word exit
            wordcounter++;
            printf("Num of commands: %d \n", commandscounter);
            printf("Total number of words in all commands: %d \n", wordcounter);
            break;
        }




        else if (strcmp(a, "cd") == 0) {
            printf("command not supported (Yet)\n");
            printf("%d", commandscounter);
        }


        else if(a[strlen(a)-1]=='&') { //if there & in the command them turn on in back ground

            find_words_and_save(a);
            argv[wordcounterf(a)-1] = NULL;
            printf("%s,%s\n", argv[0], argv[1]);
            int pid_ambersent = fork();


            if (pid_ambersent == 0) {
                execvp(argv[0], argv);
            }
           // signal(SIGCHLD, SIG_IGN); //    clear the difunct prosses
        }


        else if (a[0] == '!') {  // if ther is a ! then go to the history and search on the command


            FILE *f = fopen("file.txt", "r");

            if (f == NULL) {
                printf("error while opening this file!");
                return 1;
            }


            int b = strlen(a);
            strncpy(num_line, &a[1], b - 1);
            num_line[b - 1] = '\0';
            int num = atoi(num_line);

            while (1) {

                fgets(command, 512, f);
                //  printf("%s",command);
                int sus = strlen(command);
                command[sus - 1] = '\0';


                if (feof(f)) {

                    printf("NOT IN HISTORY\n");
                    fclose(f);
                    current = 1;
                    break;
                } else if (current == num) {

                    if (strcmp(command, "history") == 0) {     //check if the string was  the word history
                        fp = fopen("file.txt", "a");
                        if (fp == NULL) //if the file was null
                            exit(0);
                        fprintf(fp, "%s\n", command);   //print into the file all the strings
                        fclose(fp);   // clos the file after we finished
                        wordcounter++;
                        int kak = 1;
                        fp = fopen("file.txt", "r");  //open a file

                        while (fgets(str, 512, fp) != NULL) {  //while the file not finished print all the rows
                            printf("%d: %s", kak, str);
                            kak++;
                        }
                        fclose(fp);   //closing the file



                    } else {
                        find_words_and_save(command);
                        fp = fopen("file.txt", "a");
                        if (f == NULL) //if the file was null
                            exit(0);
                        fprintf(fp, "%s\n", command);   //print into the file all the strings
                        fclose(fp);   // close the file after we finished
                        wordcounter += wordcounterf(command);
                        current = 1;
                        pid_t id = fork();


                        if (id < 0) {
                            perror("error!");
                            exit(0);


                        } else if (id == 0) { //its the son

                            int status = execvp(argv[0], argv);
                            if (status == -1) {
                                perror("Terminated Incorrectly\n");
                                exit(1);


                            }
                            // printf("%s",command);
                        } else {
                            wait(NULL);
                            int z;
                            for (z = 0; z <= wordcounterf(a); z++) //free to the array
                                free(argv[z]);
                            free(argv);
                            current = 1;
                            break;

                        }
                        fclose(f);


                    }
                } else
                    current++;

            }

        }



        else if (strcmp(a, "history") == 0) {     //check if the string was  the word history
            fp = fopen("file.txt", "a");
            if (fp == NULL) //if the file was null
                exit(0);
            fprintf(fp, "%s\n", a);   //print into the file all the strings
            fclose(fp);   // clos the file after we finished
            wordcounter++;
            int kak = 1;
            fp = fopen("file.txt", "r");  //open a file

            while (fgets(str, 512, fp) != NULL) {  //while the file not finished print all the rows
                printf("%d: %s", kak, str);
                kak++;
            }
            fclose(fp);   //closing the file



        }



        else if (a[strlen(a) - 1] == ' ' || (a[0] == ' ')) {     // if there was space in the first of the word or in the last of the word
            if (wordcounterf(a) == 0)
                continue;
            else {
                printf("Error there is a space in the first/last command !\n");
                commandscounter--;
            }
        }



else if(counterpipes == 1){ // one pipe

            fp = fopen("file.txt", "a");   //open a file for write and append
            if (fp == NULL)     //if the file was null
                exit(0);
            if (a[0] == '\0');    // if there was no word input then dont copy to file history
            else {
                fprintf(fp, "%s\n", a);   //print into the file all the strings
                fclose(fp);   // clos the file after we finished
            }

            while (a[i] != '\0')      //while we don't finish the string rise the counter of the words by one
            {


                if (a[i] != ' ' && a[i + 1] == '\0') //it is a word
                {
                    wordcounter++;
                    break;
                }

                if (a[i] != ' ' && a[i + 1] == ' ') // it is also a word
                {
                    wordcounter++;
                    i++;
                }

                i++;
            }

            int f[2];
            if (pipe(f) == -1) {
                return 1;
            }
            find_words_left_pipe(a);
           // printf("%s,%s\n",argv2[0],argv2[1]);
           find_words_right1_pipe(a);
           // printf("%s,%s\n",argv1[0],argv1[1]);
            if(strcmp(argv1[0],"echo")==0) {
                char new_echo1[10];
                char new_res1[10];
                strcpy(new_echo1, argv1[1]);
                if (new_echo1[0] == '"') {
                    strncpy(new_res1, &new_echo1[1], strlen(new_echo1) - 2);
                    new_res1[strlen(new_echo1)-2]='\0';
                    strcpy(argv1[1], new_res1);
                }
            }
            if(strcmp(argv2[0],"echo")==0) {
                char new_echo2[10];
                char new_res2[10];
                strcpy(new_echo2, argv2[1]);
                if (new_echo2[0] == '"') {
                    strncpy(new_res2, &new_echo2[1], strlen(new_echo2) - 2);
                    new_res2[strlen(new_echo2)-2]='\0';
                    strcpy(argv2[1], new_res2);
                }
            }
            int p1 = fork();

            if (p1 < 0) {
                perror("error");
                exit(1);
            }
            if (p1 == 0) {

                dup2(f[1], STDOUT_FILENO);
                close(f[0]);
                close(f[1]);
                int status = execvp(argv2[0], argv2);
                if (status == -1) {
                    perror("error");
                    exit(1);
                }
            }
            int p2 = fork();
            if (p2 < 0) {
                perror("error2");
                exit(1);
            }
            if (p2 == 0) {
                dup2(f[0], STDIN_FILENO);
                close(f[0]);
                close(f[1]);
                int status1 = execvp(argv1[0], argv1);
                if (status1 == -1) {
                    perror("error");
                    exit(1);
                }
            }
            close(f[0]);
            close(f[1]);
            waitpid(p1, NULL, 0);
            waitpid(p2, NULL, 0);


        }



     else if(counterpipes==2){
            fp = fopen("file.txt", "a");   //open a file for write and append
            if (fp == NULL)     //if the file was null
                exit(0);
            if (a[0] == '\0');    // if there was no word input then dont copy to file history
            else {
                fprintf(fp, "%s\n", a);   //print into the file all the strings
                fclose(fp);   // clos the file after we finished
            }

            while (a[i] != '\0')      //while we don't finish the string
            {


                if (a[i] != ' ' && a[i + 1] == '\0') //it is a word
                {
                    wordcounter++;
                    break;
                }

                if (a[i] != ' ' && a[i + 1] == ' ') // it is also a word
                {
                    wordcounter++;
                    i++;
                }

                i++;
            }

            int f1[2];
            int f2[2];
            if (pipe(f1) == -1||pipe(f2)==-1) {
                perror("ther is something wrong in pipe");
                exit(1);
            }
            find_words_left_pipe(a);
            find_words_middle_pipe(a);
            find_words_right_pipe(a);
          //  printf("%s,%s\n",argv2[0],argv2[1]);
            //printf("%s,%s\n",argv3[0],argv3[1]);
            //printf("%s,%s\n",argv1[0],argv1[1]);


            if(strcmp(argv1[0],"echo")==0) {
                char new_echo1[10];
                char new_res1[10];
                strcpy(new_echo1, argv1[1]);
                if (new_echo1[0] == '"') {
                    strncpy(new_res1, &new_echo1[1], strlen(new_echo1) - 2);
                    new_res1[strlen(new_echo1)-2]='\0';
                    strcpy(argv1[1], new_res1);
                }
            }


            if(strcmp(argv2[0],"echo")==0) {
                char new_echo2[10];
                char new_res2[10];
                strcpy(new_echo2, argv2[1]);
                if (new_echo2[0] == '"') {
                    strncpy(new_res2, &new_echo2[1], strlen(new_echo2) - 2);
                    new_res2[strlen(new_echo2)-2]='\0';
                    strcpy(argv2[1], new_res2);
                }
            }

                if(strcmp(argv3[0],"echo")==0) {
                    char new_echo3[10];
                    char new_res3[10];
                    strcpy(new_echo3, argv3[1]);
                    if (new_echo3[0] == '"') {
                        strncpy(new_res3, &new_echo3[1], strlen(new_echo3) - 2);
                        new_res3[strlen(new_echo3)-2]='\0';
                        strcpy(argv3[1], new_res3);
                    }
                }

            int p1 = fork();
            if (p1 < 0) {
                perror("error");
                exit(1);
            }
            if (p1 == 0) {
                close(f2[0]);
                close(f2[1]);
                dup2(f1[1], STDOUT_FILENO);

                int status = execvp(argv2[0], argv2);
                if (status == -1) {
                    perror("error");
                    exit(1);
                }
            }
            int p2 = fork();
            if (p2 < 0) {
                perror("error2");
                exit(1);
            }
            if (p2 == 0) {
                close(f1[1]);
                close(f2[0]);
                dup2(f1[0], STDIN_FILENO);
                dup2(f2[1], STDOUT_FILENO);

                int status1 = execvp(argv3[0], argv3);
                if (status1 == -1) {
                    perror("error");
                    exit(1);
                }
            }
            int p3=fork();
            if (p3 < 0) {
                perror("error2");
                exit(1);
            }
            if (p3 == 0) {
                close(f1[0]);
                close(f1[1]);
                close(f2[1]);
                dup2(f2[0], STDIN_FILENO);
                int status1 = execvp(argv1[0], argv1);
                if (status1 == -1) {
                    perror("error");
                    exit(1);
                }
            }
            close(f1[0]);
            close(f1[1]);
            close(f2[0]);
            close(f2[1]);
            waitpid(p1, NULL, 0);
            waitpid(p2, NULL, 0);
            waitpid(p3, NULL, 0);
        }





        else {
            while (a[i] != '\0')      //while we don't finish the string
            {


                if (a[i] != ' ' && a[i + 1] == '\0') //it is a word
                {
                    wordcounter++;
                    break;
                }

                if (a[i] != ' ' && a[i + 1] == ' ') // it is also a word
                {
                    wordcounter++;
                    i++;
                }

                i++;
            }


            fp = fopen("file.txt", "a");   //open a file for write and append
            if (fp == NULL)     //if the file was null
                exit(0);
            if (a[0] == '\0');    // if there was no word input then dont copy to file history
            else {
                fprintf(fp, "%s\n", a);   //print into the file all the strings
                fclose(fp);   // clos the file after we finished

            }



                find_words_and_save(a);
                pid = fork();//make a son
                if (pid < 0) {
                    perror("error!");
                    exit(0);
                } else if (pid == 0) { //its the son

                    int status = execvp(argv[0], argv);

                    if (status == -1) {
                        perror("Terminated Incorrectly\n");
                        exit(1);

                    }
                } else {
                    wait(NULL);

                }
            }





        i = 0;
        counterpipes=0;
       // int y;
      //   for (y = 0; y <= wordcounterf(a); y++); //free to the array
         //   free(argv[y]);
          //  free(argv);

}
        }