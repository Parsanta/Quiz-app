#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> 
void quizz();
void quizzer(char *ans_fname, char *ques_fname);
int main(){
      quizz();
}
void quizz(){
    int subject;
    do{
        printf("_____________Select Subject______________\n");
        printf("\n\t1: PF.\n\t2: Physics.\n\t3: English.");
        printf("\n\nChoose the course from above: ");
        scanf("%d",&subject);
        printf("\n");
         if (subject == 1)
        {
            quizzer("pfans.txt","pfQuiz.txt");
        }
         else if (subject == 2)
        {
            quizzer("phyans.txt","phyQuiz.txt");
        }
         else if (subject == 3)
        {
            quizzer("engans.txt","engQuiz.txt");
        }
         else if (subject == 4)
        {
            printf("Calculus");
        }
        else{
            printf("\nInvalid Input..\nTry Agin!\n");
        }
    }
    while(!(subject >= 1 && subject <= 3));
}
void quizzer(char *ans_fname, char *ques_fname){
    FILE *quiz;
    FILE *ans;
    int answer=1,lenght,marks=0,counter = 0,i;
    char str;
    
    ans = fopen(ans_fname,"r");
    if(ans == NULL){
        printf("File does not exist or cannot be opened0.\n");
        exit(0);
    }
    fscanf(ans, "%d,", &lenght);
    int correct_ans_list[lenght],user_ans_list[lenght];
    for (i = 0; i < lenght; i++){   
        fscanf(ans, "%d,", &correct_ans_list[i] ); 
    }
    fclose(ans);
    quiz = fopen(ques_fname,"r");
    if(quiz == NULL){
        printf("File does not exist or cannot be opened1.\n");
        exit(0);
    }
    printf("\n\n__________Quiz Started__________\n\n");
    char question[400];
    char all_questions[lenght][400];
    for(i = 0; i < lenght;i++){
        int c = 0;
        str = fgetc(quiz);
        while(str != '$' && str != EOF){
            question[c] = str;
            c++;
            str = fgetc(quiz);
        }
        for(i = c;i < 400;i++){
            question[i] = 0;
        }
        strcpy(all_questions[i], question);
        strcpy(question,"");
    }
    fclose(quiz);
    for(i = 0;i < lenght;i++){
        printf("%s\n\n",all_questions[i]);
        printf("Choose Your Answer: ");
        scanf("%d",&user_ans_list[i]);
        while(user_ans_list[i] < 1 || user_ans_list[i]>4){
            printf("\nInvalid Choice..\nChoose Again: ");
            scanf("%d",&user_ans_list[i]);
        }
    }
    for(i=0;i<lenght;i++){
        if(user_ans_list[i] == correct_ans_list[i]){
            marks ++;
        }
    }
    int choice;
    printf("\n__________Quiz Done__________\n");
    printf("\nyou score %d / %d",marks,lenght);
    printf("\n1: See Correct Answers.\n2: Next Quiz\n3: Exit.\n");
    scanf("%d",&choice);
    while(choice<1 || choice>3){
        printf("Invalide Choice.\nChoose Again: ");
        scanf("%d",&choice);
    }
    if(choice == 1){
        printf("\n\n__________Correct Ansers__________\n\n");
        for(i=0; i < lenght; i++){
            if(user_ans_list[i] != correct_ans_list[i]){
                printf("%s\n",all_questions[i]);
                printf("\nYou choose: %d\n", user_ans_list[i]);
                printf("Correct ans was: %d\n\n",correct_ans_list[i]);
            }
        }
    }
    else if(choice == 2){
        quizz();
    }
}