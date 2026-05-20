#ifndef PLAYLIST_H
#define PLAYLIST_H
struct Song{
    int id;
    char title[50];
    struct Song *next, *prev;
    struct Song *left, *right;
};
extern struct Song* front;
extern struct Song* rear;
struct Song* createSong(int id, char* title);
void addtolist(struct Song* newSong);
struct Song* addtotree(struct Song* root , struct Song* newSong);
struct Song* search(struct Song* root, int id);
void menu(struct Song* root);
#endif