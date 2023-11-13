#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text) {
    int sentence=0, paragraph=0, word=0, letter=0,noofparagraphs=1,flag=0;
    char buff[MAX_CHARACTERS];
    char**** document;
    for(int i=0;i<strlen(text);i++){
        if(text[i]=='\n'){
            noofparagraphs++;
        }
    }
    int nosentences[noofparagraphs];
    int x=0;
    for(int i=0;i<strlen(text);i++){
        if(text[i]=='\n'){
            flag=0;
            x++;
            continue;
        }
        if(text[i]=='.'){
            flag++;
            nosentences[x]=flag;
        }
    }
    document=malloc((noofparagraphs)*sizeof(char***));
    for(int i=0;i<noofparagraphs;i++){
        document[i]=malloc(nosentences[i]*sizeof(char**));
        for(int j=0;j<nosentences[i];j++){
            document[i][j]=malloc(sizeof(char*));
        }
    }
    for(int i=0;i<strlen(text);i++){
        if((text[i]<='z' && text[i]>='a')||(text[i]>='A'&&text[i]<='Z')){
            buff[letter]=text[i];
            letter++;
            continue;
        }
        buff[letter]='\0';
        if(text[i]==' '){
            document[paragraph][sentence]=realloc(document[paragraph][sentence],(word+1)*sizeof(char*));
            document[paragraph][sentence][word]=malloc((strlen(buff)+1)*sizeof(char));
            strcpy(document[paragraph][sentence][word],buff);
            letter=0;
            word++;
            continue;
        }
        if(text[i]=='.'){
            document[paragraph][sentence]=realloc(document[paragraph][sentence],(word+1)*sizeof(char*));
            document[paragraph][sentence][word]=malloc((strlen(buff)+1)*sizeof(char));
            strcpy(document[paragraph][sentence][word],buff);
            letter=0;
            word=0;
            sentence++;
            continue;
        }
        if(text[i]=='\n'){
            letter=0;
            word=0;
            sentence=0;
            paragraph++;
            continue;
        }
    }
    return document;
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);
    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}