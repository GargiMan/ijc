// ppm.c
// Řešení IJC-DU1, příklad B), 18.3.2020
// Autor: Marek Gergel, FIT
// Přeloženo: gcc 7.5.0
// nacita subor formatu ppm a nacita z neho data

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "ppm.h"

struct ppm *ppm_read(const char *filename) {

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        warning_msg("%s : Subor sa nepodarilo otvorit\n", filename);
        fclose(file);
		return NULL;
    }

    char imgformat[3];
    unsigned int imgxsize,imgysize;
    int tmp;

    if ((fscanf(file, "%s %u %u %d\n", imgformat, &imgxsize, &imgysize, &tmp)) != 4) {
        warning_msg("%s : Hlavicka suboru sa nepodarila nacitat\n", filename);
        fclose(file);
		return NULL;
    }

    unsigned long imgsize = imgxsize*imgysize*3;

	if (imgsize > IMG_SIZE_LIMIT) {
		warning_msg("%s : Velkost obrazku je vacsia ako limit (%d)\n", filename, IMG_SIZE_LIMIT);
		fclose(file);
		return NULL;
	}

    if (strcmp(imgformat,"P6") != 0) {
        warning_msg("%s : Subor ma nespravny format\n", filename);
        fclose(file);
		return NULL;
    }

    struct ppm *img = malloc(sizeof(struct ppm)+imgsize);

    if (img == NULL) {
        warning_msg("%s : Alokacia pamate sa nepodarila\n", filename);
        fclose(file);
		return NULL;
    }

    img->xsize=imgxsize;
    img->ysize=imgysize;
    
    if (fread(img->data, sizeof(char), imgsize, file) != imgsize) {
        warning_msg("%s : Velkost obrazku v hlavicke suboru sa nazhoduje s velkostou obrazku v datach\n", filename);
        fclose(file);
        free(img);
		return NULL;
    }

	if (fgetc(file) != EOF) {
		warning_msg("%s : Subor nie je ukonceny alebo sa nenacitali vsetky znaky\n", filename);
		fclose(file);
		free(img);
		return NULL;
	}

    fclose(file);
    return img;
}

void ppm_free(struct ppm *p) {
    free(p);
}