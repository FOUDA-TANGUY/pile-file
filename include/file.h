#ifndef __FILE__H__
#define __FILE__H__

    typedef struct File
    {
        int nombre;
        element* tete;
        element* queue;
    }File;
    
    void init_file(File*);
    bool file_vide(File*);
    int nombre_file(File*);
    void emfiler(File*, info);
    info defiler(File*);
    void vide_file(File*);
    
#endif