#include <stdio.h>
#include "playlist.h"
int main(){
    struct Song* root = NULL;
    struct Song* song1 = createSong(1, "We Go!");
    struct Song* song2 = createSong(2, "Overtaken");
    struct Song* song3 = createSong(3, "Arcade");
    struct Song* song4 = createSong(4, "You say run");
    addtolist(song1);
    addtolist(song2);
    addtolist(song3);
    addtolist(song4);
    root = addtotree(root, song1);
    root = addtotree(root, song2);
    root = addtotree(root, song3);
    root = addtotree(root, song4);
    menu(root);
    return 0;
}