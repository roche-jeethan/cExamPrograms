#include<stdio.h>
void compare(char *,char *);
void concat(char *, char *);
int len(char *);
void reverse(char *);
void occurence(char *);
void delete_substring(char *, const char *);
void lower_to_upper(char *);
void upper_to_lower(char *);
int main(){
    char str1[100], str2[100];
    printf("Enter the two strings: ");
    scanf("%s %s",str1,str2);
    int choice;
    do{
        printf("Choices:\n1. Compare\n2. Concatenate\n3. Length\n4. Reverse\n5. Occurences\n6. Delete Substring\n7. Lower to Upper\n8. Upper to Lower\n9. Exit\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: compare(str1,str2); break;
            case 2: concat(str1,str2); break;
            case 3: printf("Length 1: %d\nLength 2: %d\n",len(str1),len(str2)); break;
            case 4: reverse(str1); break;
            case 5: occurence(str2); break;
            case 6: delete_substring(str1, str2);
                    printf("String after deletion: %s\n", str1); break;
            case 7: lower_to_upper(str1); break;
            case 8: upper_to_lower(str1); break;
            case 9: break;
            default: printf("Invalid option");
        }
    } while(choice!=7);
    return 0;
}
void compare(char *str1, char *str2){
    int i = 0, res;
    while(str1[i]!='\0' && str2[i]!='\0'){
        if(str1[i]!=str2[i]){
            res = str1[i]-str2[i];
        }
        i++;
    }
    if(str1[i]=='\0' && str2[i]=='\0'){
        res = 0;
    } else{
        res = str1[i]-str2[i];
    }
    if(res>0){
        printf("String 1 is greater than string 2\n");
    } else if(res<0){
        printf("String 1 is lesser than string 2\n");
    } else {
        printf("Both strings are equal\n");
    }
} 
void concat(char *str1, char *str2){
    int i=0,j=0;
    while(str1[i]!='\0'){
        i++;
    }
    while(str2[j]!='\0'){
        str1[i] = str2[j]; i++; j++;
    }
    str1[i] = '\0';
    printf("Concatenated string: %s\n",str1);
}
int len(char *str){
    int i = 0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}
void reverse(char *str){
    int lens = len(str);
    for(int i=0;i<lens/2;i++){
        char temp = str[i];
        str[i] = str[lens - i -1];
        str[lens - i -1] = temp;
    }
    printf("Reversed String: %s\n",str);
} 
void occurence(char *str){
    int i=0,freq[256]={0};
    while(str[i]!='\0'){
        freq[(int)str[i]]++; i++;
    }
    printf("Character Frequency: ");
    for(i=0;i<256;i++){
        if(freq[i]>0){
            printf("%c: %d\n",i,freq[i]);
        }
    }
}
void delete_substring(char *main_str, const char *sub_str) {
    int i, j, k;
    int main_len = len(main_str);
    int sub_len = len(sub_str);
    for (i = 0; i <= main_len - sub_len; i++) {
        for (j = 0; j < sub_len; j++) {
            if (main_str[i + j] != sub_str[j]) {
                break;
            }
        }
        if (j == sub_len) {
            for (k = i; k <= main_len - sub_len; k++) {
                main_str[k] = main_str[k + sub_len];
            }
            main_len -= sub_len;
            main_str[main_len] = '\0';
            i--;
        }
    }
}
void lower_to_upper(char *str){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>='a' && str[i]<='z'){
            str[i] = str[i] - 32;
        }
        i++;
    }
    printf("String in Upper Case: %s\n",str);
}
void upper_to_lower(char *str){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>='A' && str[i]<='Z'){
            str[i] = str[i] + 32;
        }
        i++;
    }
    printf("String in Lower Case: %s\n",str);
}