#include<stdio.h>
#include<stdbool.h>
void Linerror(){
    printf("WordCount.exe��ʽ����Ϊ[parameter] [input_file_name]\n");
    printf("[parameter]������ѡ�\n");
    printf("                        -c:ͳ���ļ��ַ���\n");
    printf("                        -w:ͳ���ļ�������\n");
}
void Filerror(char *file){
    printf("%s�ļ�������,���ٴ���ϸȷ���ļ���\n",file);
}
void CountWords(char *file){
    FILE *fp;
    if((fp = fopen(file,"r")) == NULL){
       Filerror(file);
       exit(0);
    }
    int numwords = 0;
    char ch;
    bool flag = false;
    while((ch = fgetc(fp)) != EOF){
        if(ch != ' '&&ch != ',')
            flag = true;
        else{
            if(flag){
                numwords++;
                flag = false;
            }
        }
    }
    printf("��������%d",numwords);
    fclose(fp);
}
void CountChars(char *file){
    FILE *fp;
    if((fp = fopen(file,"r")) == NULL){
       Filerror(file);
       exit(0);
    }
    int numchars = 0;
    char ch;
    while((ch = fgetc(fp)) != EOF){
        numchars++;
    }
    printf("�ַ�����%d",numchars);
    fclose(fp);
}
int main(int argc,char *argv[]){
    char *select[2] = {"-c","-w"};
    if(argc == 3){
        if(strcmp(select[0],argv[1]) == 0)
            CountChars(argv[2]);
        else if(strcmp(select[1],argv[1]) == 0)
            CountWords(argv[2]);
        else
            Linerror();
    }
    else
        Linerror();
    return 0;
}
