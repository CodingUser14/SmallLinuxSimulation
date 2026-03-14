#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct Node {
    char *name;
    struct Node *next;
} Node;

void getFileName(char *name);
void display(Node *head);

int main() {
    Node *head = NULL;
    Node *temp = NULL;
    Node *p = NULL;

    char cmd[80];
    char name[80];

    printf("Welcome to CodingUser's recreation of the Linux Terminal\n");
    printf("Command options:\n");
    printf("vd Y - view different absolute path. Y = ../ and ./\n");
    printf("APATH - Print the absolute path\n");
    printf("mkdir Y - make new directory to the end of path. Y = STR\n");
    printf("rm Y - remove directory. Y = STR\n");
    printf("q - quit program\n");

    while(1) {
        int c;

        printf("CodingUser14;~$ ");
        if(scanf("%79s", cmd) != 1) return 0;

        if (strcmp(cmd, "q") == 0) {
            break;
        } 

        else if (strcmp(cmd, "mkdir") == 0) {
            getFileName(name); 

            temp = malloc(sizeof(Node));
            temp->name = strdup(name);
            temp->next = NULL;

            // strdup creates a new memory address and copies the text into it.
            // This prevents new calls to getFileName from overwriting the stored names.

            if(head == NULL) {
                head = temp;
            } else {
                p = head;
                while(p->next != NULL) {
                    p = p->next;
                }
                p->next = temp;
            }
        }
        else if (strcmp(cmd, "APATH") == 0) {
            display(head);
         
        }
        else if (strcmp(cmd, "rm") == 0) {
            getFileName(name);          

            if(head != NULL && strcmp(name, head->name) == 0){
                Node *toDelete = head;
                head = head->next;
                free(toDelete->name); //Cause we strdup earlier
                free(toDelete);
            } else {
                p = head;
                while(p != NULL && p->next != NULL) {
                    
                    if(strcmp(p->next->name, name) == 0){
                        Node *toDelete = p->next;
                        p->next = p->next->next;

                        free(toDelete->name);
                        free(toDelete);
                        break;
                    }
                    p = p->next;
                }
            }
        }
        else if(strcmp(cmd, "vd") == 0){
            getFileName(name);

            if(head == NULL) {
                printf("Error: No Files\n");
            } else {
                int dots = 0;
                for (int i = 0; i < strlen(name); i++){
                    if(name[i] == '.' && name[i + 1] == '/'){
                        i++;
                    }
                    else if (name[i] == '.' && name[i + 1] == '.'&& name[i + 2] == '/'){
                        dots++;
                        i+= 2;
                    }
                }

                if (dots != 0) {
                    int count = 0;
                    p = head;
                    while(p != NULL){
                        count++;
                        p = p->next;
                    }

                    if( dots >= count) {
                        printf("No more nodes");
                    }

                    int limit = count - dots;
                    p = head; 

                    for(int k = 0; k < limit; k++) {
                        printf("/%s", p->name);
                        p = p->next;
                    }
                    printf("\n");
                }
            }
    
        }
        else {
            printf("Not valid command or exceeded required arguments. If exceeded, cut to valid args.\n");
            while(c = getchar() != '\n' && c != EOF);
        }
    }
    return 0;
}

void getFileName(char *name) {
    scanf("%79s", name);
}

void display(Node *head) {
    Node *p = head;
    if (p == NULL) {
        printf("(empty directory)\n");
        return;
    }
    printf("CodingUser14;~$");
    while(p != NULL) {
        printf("/%s", p->name);
        p = p->next;
    }
    printf("\n");
}