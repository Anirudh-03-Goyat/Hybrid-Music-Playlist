#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
struct Song *front = NULL;
struct Song *rear = NULL;
struct Song* createSong(int id, char* title){
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    newSong->id = id;
    strcpy(newSong->title, title);
    newSong->next = NULL;
    newSong->prev = NULL;
    newSong->left = NULL;
    newSong->right = NULL;
    return newSong;
}
void addtolist(struct Song* newSong){
    if(front==NULL){
        front = rear =newSong;
        newSong->next = front;
        newSong->prev = front;
    }else{
        rear->next = newSong;
        newSong->prev = rear;
        newSong->next = front;
        front->prev = newSong;
        rear = newSong;
    }
}
struct Song* addtotree(struct Song* root , struct Song* newSong){
    if(root == NULL)
        return newSong;
    if(newSong->id < root->id)
    root->left = addtotree(root->left , newSong);
    else if(newSong->id > root->id)
    root->right = addtotree(root->right , newSong);
    return root;
}
struct Song* search(struct Song* root, int id){
    if(root == NULL || root->id == id)
    return root;
    if(id <root->id)
    return search(root->left , id);
    return search(root->right , id);
}
void menu(struct Song* root){
    int choice, searchid;
    struct Song* current = front;
    if(current == NULL){
        printf("Playlist is empty.\n");
        return;
    }
    while(1){
        printf("\n====================================");
        printf("\n  MUSIC PLAYER | NOW PLAYING");
        printf("\n====================================");
        printf("\nNOW PLAYING: [%s] (ID: %d)\n", current->title, current->id);
        printf("1. Next Song\n");
        printf("2. Previous Song\n");
        printf("3. Search Song by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            current = current->next;
        }else if(choice == 2){
            current = current->prev;
        }else if(choice == 3){
            printf("Enter Song ID to search: ");
            scanf("%d", &searchid);
            struct Song* foundSong = search(root, searchid);
            if(foundSong){
                printf("Song Found: [%s] (ID: %d)\n", foundSong->title, foundSong->id);
                current = foundSong;
            }else{
                printf("Song with ID %d not found.\n", searchid);
            }
        }else{
            break;
        }
    }
}