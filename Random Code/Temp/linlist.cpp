#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student
{
  int score;
  char name[100];
  Student *next;
} *head, *tail, *curr;

int x;

void insert (int score, char name[100])
{
  curr = (Student *) malloc (sizeof (Student));
  // strcpy((*curr).name, name);
  // (*curr).score = score;
  strcpy (curr->name, name);
  curr->score = score;

  if (head == NULL)
    {
      head = curr;
      tail = curr;
    }
  else
    {
      tail->next = curr;
      tail = curr;
    }
  tail->next = NULL;
}

void deleteTail(){
    
}

void insertHead(int score, char name[100]){
    
}

void deletse (int score){
    
}

void deleteHead(){
    curr=head;
    head = head->next;
    free(curr);
}


void printAll (){
    curr = head;
    if(head == NULL) return;

    while(curr -> next != NULL){
        curr = curr -> next;
        if(curr -> next != NULL) printf("%s -> ", curr -> name);
        else printf("%s", curr -> name);
    }
    printf("\n");
}

int main ()
{
    system("cls");
  int a = 5;
  Student *head, *tail, *curr;
  insert (90, "Mukhtar");

  insert (100, "Ali");

  insert (70, "Budi");

  insert (85, "Charlie");


//   delete[100];
  deleteHead();
  //cetak head
  //   printf ("%s - %d\n", head->name, head->score);
  //   printf ("%s - %d\n", head->next->name, head->next->score);

  printAll ();

  return 0;
}