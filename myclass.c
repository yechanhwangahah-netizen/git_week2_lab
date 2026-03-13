#include "class.h"

// You must complete these functions.
int addNewClass(struct st_class* c[], int csize){
// Caution : Don't allow the duplicate class code.
// You must complete this function.
struct st_class*p;
int code;
	

while(1){
	int d=0;
	printf("code number:");
	scanf("%d",&code);

	for(int i=0; i<csize; i++){
		if(c[i] ->code ==code){
			printf("Code duplicate! retry\n");
			d=1;
			break;
		}
	}
	if(d==0){
		break;
	}
}
p = (struct st_class*)malloc(sizeof(struct st_class));
p -> code = code;

	printf(">> class name > ");
	scanf("%s", p->name);
	printf(">> credits > ");
	scanf("%d", &(p->unit));
	printf(">> grading (1: A+~F, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;
	return csize+1;
}
void editClass(struct st_class* c[], int csize){
    struct st_class* p = NULL;
    int code;
    printf(">> Enter a code of class > ");
    scanf("%d", &code);

    for(int i=0; i<csize; i++){
        if(c[i]->code == code){
            p = c[i];
            break;
        }
    }
    if(p == NULL){
        printf("> No such class.\n");
        return;
    }

    printf("> Current: [%d] %s [credits %d - %s]\n",
           p->code, p->name, p->unit, kname[p->grading-1]);
    printf("> Enter new class name > ");
    scanf("%s", p->name);
    printf("> Enter new credits > ");
    scanf("%d", &(p->unit));
    printf("> Enter new grading(1:Grade, 2: P/F) > ");
    scanf("%d", &(p->grading));

    printf("> Modified.\n");
}



// You must make all these functions.

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){

    while(1){
        int code;
        printf(">> Enter a class code > ");
        scanf("%d", &code);

        int idx = -1;
        for(int i=0; i<csize; i++){
            if(c[i]->code == code){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            printf(">> No such code of class.\n");
        }
        else{
            int dup = 0;
            for(int i=0; i<msize; i++){
                if(my[i] == code){
                    dup = 1;
                    break;
                }
            }

            if(dup){
                printf(">> Already applied.\n");
            }
            else{
                my[msize++] = code;
                printf(">> [%d] %s [credit %d - %s]\n",
                       c[idx]->code, c[idx]->name, c[idx]->unit,
                       kname[c[idx]->grading-1]);
            }
        }

        int more;
        printf(">> Add more?(1:Yes 2:No) > ");
        scanf("%d", &more);
        if(more != 1) break;
    }

    return msize;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize) {

    int total = 0;
    for(int i=0; i<msize; i++){
        int code = my[i];
        struct st_class* p = NULL;

        for(int j=0; j<csize; j++){
            if(c[j]->code == code){
                p = c[j];
                break;
            }
        }

        printf("%d. [%d] %s [credit %d - %s]\n", i+1, p->code, p->name, p->unit, kname[p->grading-1]);
        total += p->unit;
    }
    printf("All : %d credits\n", total);

}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){

    FILE* file = fopen("my_classes.txt", "w");
    if(file == NULL) return;

    int total = 0;
    int cnt_grade = 0, cnt_pf = 0;
    int credit_grade = 0, credit_pf = 0;

    fprintf(file, "My Classes\n");

    for(int i=0; i<msize; i++){
        int code = my[i];
        struct st_class* p = NULL;

        for(int j=0; j<csize; j++){
            if(c[j]->code == code){
                p = c[j];
                break;
            }
        }
        if(p == NULL) continue;

        fprintf(file, "%d. [%d] %s [credit %d - %s]\n",
                i+1, p->code, p->name, p->unit, kname[p->grading-1]);

        total += p->unit;

        if(p->grading == 1){
            cnt_grade++;
            credit_grade += p->unit;
        }
        else if(p->grading == 2){
            cnt_pf++;
            credit_pf += p->unit;
        }
    }

    fprintf(file, "All : %d classes, %d credits (A+~F %d credits, P/F %d credits)\n",
            msize, total, credit_grade, credit_pf);

    fclose(file);
}
